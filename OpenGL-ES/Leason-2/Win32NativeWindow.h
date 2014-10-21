#pragma once

#include "NativeWindow.h"

class Win32NativeWindow : public NativeWindow
{

public:
	virtual bool CreateNativeWindow(int width, int height, ...) override;
	virtual int run() override;

	Win32NativeWindow();
	virtual ~Win32NativeWindow();

	Win32NativeWindow(const Win32NativeWindow&) = delete;
	Win32NativeWindow& operator=(const Win32NativeWindow&) = delete;
	// Win32NativeWindow(const Win32NativeWindow&& o);
	// Win32NativeWindow& operator=(const Win32NativeWindow&& o);
};