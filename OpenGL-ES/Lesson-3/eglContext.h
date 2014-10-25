#pragma once

#include <EGL/egl.h>
#include <exception>
#include <string>

namespace egl
{
	struct egl_error : public std::exception {
		typedef std::exception _Base;
		egl_error(const std::string &s) : _Base(s.c_str()) { }
		egl_error(const char *s) : _Base(s) { }
	};

	class Context
	{
		EGLDisplay	m_eglDisplay;
		EGLConfig	m_eglConfig;
		EGLSurface	m_eglSurface;
		EGLContext	m_eglContext;
		EGLint m_eglMajorVersion, m_eglMinorVersion;
		EGLNativeDisplayType m_deviceContext;
		EGLNativeWindowType m_nativeWindow;

	public:
		Context(EGLNativeWindowType nativeWindow, EGLNativeDisplayType deviceContext);
		~Context();

		Context(const Context&) = delete;
		Context(Context&&) = delete;
		Context& operator=(const Context&) = delete;
		Context& operator=(Context&&) = delete;

		void SwapBuffer();
		EGLSurface GetSurface() const { return m_eglSurface; }

		bool CreateEGLDisplay();
		bool ChooseEGLConfig();
		bool CreateEGLSurface();
		bool SetupEGLContext();
	};
}
