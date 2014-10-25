#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <cstdio>
#include <cstring>

#include "NativeWindow.h"
#include "eglContext.h"

#define ERROR_TITLE _T("OpenGL-ES-Learn-Error")

bool CheckEGLError(const char* functionLastCalled, int lineNum)
{
    /*	eglGetError returns the last error that occurred using EGL, not necessarily the status of the last called function. The user has to
    check after every single EGL call or at least once every frame. Usually this would be for debugging only, but for this example
    it is enabled always.
    */
    EGLint lastError = eglGetError();
	if (lastError == EGL_SUCCESS)
		return true;

	char errorMessage[256] = { 0 };
    sprintf_s(errorMessage, "%s:%d failed (%x).\n", functionLastCalled, lineNum, lastError);

	throw egl::egl_error(errorMessage);
}

egl::Context::Context(EGLNativeWindowType nativeWindow, EGLNativeDisplayType deviceContext) :
m_nativeWindow(nativeWindow),
m_deviceContext(deviceContext),
m_eglContext(0),
m_eglConfig(0),
m_eglDisplay(0),
m_eglSurface(0)
{
	CreateEGLDisplay();
	ChooseEGLConfig();
	CreateEGLSurface();
	SetupEGLContext();
}

egl::Context::~Context()
{
	// To release the resources in the context, first the context has to be released from its binding with the current thread.
	eglMakeCurrent(m_eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

	// Terminate the display, and any resources associated with it (including the EGLContext)
	eglTerminate(m_eglDisplay);
}

bool egl::Context::CreateEGLDisplay()
{
	/*	Get an EGL display.
	EGL uses the concept of a "display" which in most environments corresponds to a single physical screen. After creating a native
	display for a given windowing system, EGL can use this handle to get a corresponding EGLDisplay handle to it for use in rendering.
	Should this fail, EGL is usually able to provide access to a default display.
	*/
	m_eglDisplay = eglGetDisplay(m_deviceContext);
	if (m_eglDisplay == EGL_NO_DISPLAY) {
		m_eglDisplay = eglGetDisplay((EGLNativeDisplayType)EGL_DEFAULT_DISPLAY);
	}

	// If a display still couldn't be obtained, return an error.
	if (m_eglDisplay == EGL_NO_DISPLAY) {
		throw egl_error("Failed to get an EGLDisplay");
	}

	/*	Initialize EGL.
	EGL has to be initialized with the display obtained in the previous step. All EGL functions other than eglGetDisplay
	and eglGetError need an initialised EGLDisplay.
	If an application is not interested in the EGL version number it can just pass NULL for the second and third parameters, but they
	are queried here for illustration purposes.
	*/

	if (!eglInitialize(m_eglDisplay, &m_eglMajorVersion, &m_eglMinorVersion)) {
		throw egl_error("Failed to initialize the EGLDisplay");
	}

	return true;
}

bool egl::Context::ChooseEGLConfig()
{
	/*	Specify the required configuration attributes.
	An EGL "configuration" describes the capabilities an application requires and the type of surfaces that can be used for drawing.
	Each implementation exposes a number of different configurations, and an application needs to describe to EGL what capabilities it
	requires so that an appropriate one can be chosen. The first step in doing this is to create an attribute list, which is an array
	of key/value pairs which describe particular capabilities requested. In this application nothing special is required so we can query
	the minimum of needing it to render to a window, and being OpenGL ES 2.0 capable.
	*/
	const EGLint configurationAttributes[] =
	{
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
		EGL_NONE
	};

	/*	Find a suitable EGLConfig
	eglChooseConfig is provided by EGL to provide an easy way to select an appropriate configuration. It takes in the capabilities
	specified in the attribute list, and returns a list of available configurations that match or exceed the capabilities requested.
	Details of all the possible attributes and how they are selected for by this function are available in the EGL reference pages here:
	http://www.khronos.org/registry/egl/sdk/docs/man/xhtml/eglChooseConfig.html
	It is also possible to simply get the entire list of configurations and use a custom algorithm to choose a suitable one, as many
	advanced applications choose to do. For this application however, taking the first EGLConfig that the function returns suits
	its needs perfectly, so we limit it to returning a single EGLConfig.
	*/
	EGLint configsReturned;
	if (!eglChooseConfig(m_eglDisplay, configurationAttributes, &m_eglConfig, 1, &configsReturned) ||
		(configsReturned != 1)) {
		throw egl_error("eglChooseConfig() failed.");
	}

	return true;
}

bool egl::Context::CreateEGLSurface()
{
	/*	Create an EGLSurface for rendering.
	Using a native window created earlier and a suitable eglConfig, a surface is created that can be used to render OpenGL ES calls to.
	There are three main surface types in EGL, which can all be used in the same way once created but work slightly differently:
	- Window Surfaces  - These are created from a native window and are drawn to the screen.
	- Pixmap Surfaces  - These are created from a native windowing system as well, but are offscreen and are not displayed to the user.
	- PBuffer Surfaces - These are created directly within EGL, and like Pixmap Surfaces are offscreen and thus not displayed.
	The off-screen surfaces are useful for non-rendering contexts and in certain other scenarios, but for most applications the main
	surface used will be a window surface as performed below.
	*/
	m_eglSurface = eglCreateWindowSurface(m_eglDisplay, m_eglConfig, m_nativeWindow, NULL);
	if (m_eglSurface == EGL_NO_SURFACE) {
		eglGetError(); // Clear error
		m_eglSurface = eglCreateWindowSurface(m_eglDisplay, m_eglConfig, NULL, NULL);
	}

	// Check for any EGL Errors
	return CheckEGLError("eglCreateWindowSurface", __LINE__);
}

bool egl::Context::SetupEGLContext()
{
	/*	Create a context.
	EGL has to create what is known as a context for OpenGL ES. The concept of a context is OpenGL ES's way of encapsulating any
	resources and state. What appear to be "global" functions in OpenGL actually only operate on the current context. A context
	is required for any operations in OpenGL ES.
	Similar to an EGLConfig, a context takes in a list of attributes specifying some of its capabilities. However in most cases this
	is limited to just requiring the version of the OpenGL ES context required - In this case, OpenGL ES 2.0.
	*/
	EGLint contextAttributes[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	// Create the context with the context attributes supplied
	m_eglContext = eglCreateContext(m_eglDisplay, m_eglConfig, NULL, contextAttributes);
	if (!CheckEGLError("eglCreateContext", __LINE__)) {
		return false;
	}

	/*	Make OpenGL ES the current API.
	After creating the context, EGL needs a way to know that any subsequent EGL calls are going to be affecting OpenGL ES,
	rather than any other API (such as OpenVG).
	*/
	eglBindAPI(EGL_OPENGL_ES_API);
	if (!CheckEGLError("eglBindAPI", __LINE__)) {
		return false;
	}

	/*	Bind the context to the current thread.
	Due to the way OpenGL uses global functions, contexts need to be made current so that any function call can operate on the correct
	context. Specifically, make current will bind the context to the thread it's called from, and unbind it from any others. To use
	multiple contexts at the same time, users should use multiple threads and synchronise between them.
	*/
	eglMakeCurrent(m_eglDisplay, m_eglSurface, m_eglSurface, m_eglContext);

	return CheckEGLError("SetupEGLContext", __LINE__);
}

void egl::Context::SwapBuffer()
{
	/*	Present the display data to the screen.
	When rendering to a Window surface, OpenGL ES is double buffered. This means that OpenGL ES renders directly to one frame buffer,
	known as the back buffer, whilst the display reads from another - the front buffer. eglSwapBuffers signals to the windowing system
	that OpenGL ES 2.0 has finished rendering a scene, and that the display should now draw to the screen from the new data. At the same
	time, the front buffer is made available for OpenGL ES 2.0 to start rendering to. In effect, this call swaps the front and back
	buffers.
	*/
	if (!eglSwapBuffers(m_eglDisplay, m_eglSurface)) {
		CheckEGLError("eglSwapBuffers", __LINE__);
	}
}
