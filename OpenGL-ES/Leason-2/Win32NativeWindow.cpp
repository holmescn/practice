#include <windows.h>
#include <tchar.h>
#include <cstdarg>

#include "Win32NativeWindow.h"

/*******************************************************************************************************************************************
Defines
*******************************************************************************************************************************************/
// Windows class name to register
#define	WINDOW_CLASS_NAME _T("OpenGL-ES-Learn-Class")

// Name of the application
#define APPLICATION_NAME _T("OpenGL-ES-Learn-Leason-2")

// Title to display for errors.
#define ERROR_TITLE _T("OpenGL-ES-Learn-Leason-2-Error")


/*!*****************************************************************************************************************************************
@Function		WndProc
@Input			nativeWindow                Handle to the window
@Input			message                     The message to handle
@Input			windowParameters            Additional message information
@Input			longWindowParameters        Additional message information
@Return		    Result code to send to the OS
@Description	Processes event messages for the main window
*******************************************************************************************************************************************/
LRESULT CALLBACK WndProc(HWND nativeWindow, UINT message, WPARAM windowParameters, LPARAM longWindowParameters)
{
    switch (message) {
    case WM_SYSCOMMAND:
        // Handle 2 system messages: screen saving and monitor power. We need to prevent them whilst we're rendering for a short time.
		if (windowParameters == SC_SCREENSAVE || windowParameters == SC_MONITORPOWER) {
            // Return 0 to let Windows know we don't want to sleep or turn the monitor off right now.
			return 0;
		}
		break;
    case WM_CLOSE:
		// Handle the close message when a user clicks the quit icon of the window
        // Post a quit message
        PostQuitMessage(0);
        // Return 1 to let Windows know the message has been successfully handled
        return 1;
	default:
		break;
    }

    // Calls the default window procedure for messages we did not handle
    return DefWindowProc(nativeWindow, message, windowParameters, longWindowParameters);
}

bool Win32NativeWindow::CreateNativeWindow(int width, int height, ...)
{
	std::va_list ap;
	va_start(ap, height);
    HINSTANCE hInstance = va_arg(ap, HINSTANCE);
	va_end(ap);

    // Describe the native window in a window class structure
    WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(0, IDC_ARROW);
    wcex.lpszMenuName = 0;
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszClassName = WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    // Register the windows class with the OS.
    ATOM registerClass = RegisterClassEx(&wcex);
    if (!registerClass) {
		MessageBox(NULL, _T("Failed to register the window class"), _T("ERROR"), MB_OK|MB_ICONERROR);
		return false;
	}

    // Create a rectangle describing the area of the window
    RECT windowRectangle;
    SetRect(&windowRectangle, 0, 0, width, height);
    AdjustWindowRectEx(&windowRectangle, WS_CAPTION | WS_SYSMENU, false, 0);

    // Create the window from the available information
    m_nativeWindow = CreateWindow(WINDOW_CLASS_NAME,
        APPLICATION_NAME, WS_VISIBLE | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
        windowRectangle.right - windowRectangle.left, windowRectangle.bottom - windowRectangle.top,
        NULL, NULL, hInstance, NULL);

    if (!m_nativeWindow) {
		MessageBox(NULL, _T("Failed to create the native window"), _T("ERROR"), MB_OK|MB_ICONERROR);
        return false;
    }

    // Get the associated device context from the window
    m_deviceContext = GetDC(m_nativeWindow);
    if (!m_deviceContext) {
        MessageBox(m_nativeWindow, _T("Failed to create the device context"), _T("ERROR"), MB_OK | MB_ICONERROR);
        return false;
    }

	return true;
}

Win32NativeWindow::Win32NativeWindow()
{
}

Win32NativeWindow::~Win32NativeWindow()
{
	// Release the device context.
	if (m_deviceContext) {
		ReleaseDC(m_nativeWindow, m_deviceContext);
	}

	// Destroy the window
	if (m_nativeWindow) {
		DestroyWindow(m_nativeWindow);
	}
}

int Win32NativeWindow::run()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

