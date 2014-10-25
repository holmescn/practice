#pragma once

#include <vector>

class NativeWindow;

namespace gles {
	class Program;
}

namespace egl {
	class Context;
}

class Render {
	NativeWindow *m_nativeWindow;
	std::vector<gles::Program> m_programCache;

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