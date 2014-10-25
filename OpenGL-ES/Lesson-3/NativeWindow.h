#pragma once

#include <EGL/egl.h>

class NativeWindow
{
protected:
	EGLNativeDisplayType m_deviceContext;
	EGLNativeWindowType m_nativeWindow;
public:
	NativeWindow();
	virtual ~NativeWindow();

	NativeWindow(const NativeWindow&) = delete;
	NativeWindow(const NativeWindow&&);
	NativeWindow& operator=(const NativeWindow&) = delete;
	NativeWindow& operator=(const NativeWindow&&);

	inline EGLNativeWindowType GetNativeWindow() const {
		return m_nativeWindow;
	}
	inline EGLNativeDisplayType GetNativeDisplay() const {
		return m_deviceContext;
	}

	virtual bool CreateNativeWindow(int width, int height, ...) = 0;
	virtual int run() = 0;
};