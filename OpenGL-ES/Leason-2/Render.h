#pragma once

#include "NativeWindow.h"
#include "eglContext.h"

class Render {
	NativeWindow *m_nativeWindow;
public:
	Render(NativeWindow *nativeWindow);
	~Render();
	Render(const Render &o);
	Render(Render &&o);
	Render& operator=(const Render &o);
	Render& operator=(Render &&o);

	int run();

	void render1(egl::Context &context);
};