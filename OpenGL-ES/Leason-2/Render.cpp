#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "gles.h"
#include "Render.h"

Render::Render(NativeWindow *nativeWindow)
{
	m_nativeWindow = nativeWindow;
}

Render::Render(const Render &o)
{
	m_nativeWindow = o.m_nativeWindow;
}

Render::Render(Render &&o)
{
	m_nativeWindow = o.m_nativeWindow;
}

Render::~Render()
{

}

Render& Render::operator=(const Render &o)
{
	if (this == &o) return *this;
	m_nativeWindow = o.m_nativeWindow;
	return *this;
}

Render& Render::operator=(Render &&o)
{
	if (this == &o) return *this;
	m_nativeWindow = o.m_nativeWindow;
	return *this;
}

int Render::run()
{
	std::mutex mtx;
	std::condition_variable cv;

	std::thread th([&mtx, &cv, this]() {
		egl::Context context(m_nativeWindow->GetNativeWindow(), m_nativeWindow->GetNativeDisplay());

		std::unique_lock<std::mutex> lck(mtx);
		while (cv.wait_for(lck, std::chrono::milliseconds(16)) == std::cv_status::timeout) {
			render1(context);
		}
	});

	int rc = m_nativeWindow->run();
	cv.notify_one();
	th.join();
	return rc;
}

void Render::render1(egl::Context &context)
{
	GLbyte vShaderSrc[] =
		"attribute vec4 a_Position; \n"
		"void main() \n"
		"{\n"
		"    gl_Position = a_Position; \n"
		"}";
	GLbyte fShaderSrc[] =
		"precision mediump float; \n"
		"void main() \n"
		"{\n"
		"    gl_FragColor = vec4(1.0, 1.0, 0.0, 0.8); \n"
		"}";
	gles::Program program((char*)vShaderSrc, (char*)fShaderSrc);
	program.compile();
	program.link();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLfloat vVertices[] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};
	glViewport(0, 0, 800, 600);
	glClear(GL_COLOR_BUFFER_BIT);
	program.use();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	context.SwapBuffer();
}
