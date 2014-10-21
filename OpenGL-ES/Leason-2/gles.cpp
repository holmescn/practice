#include <memory>
#include "gles.h"

gles::Program::Program(const std::string &vertexShader, const std::string &fragmentShader)
{
	m_vertexShaderSource = vertexShader;
	m_fragmentShaderSource = fragmentShader;
	m_vertexShader = 0;
	m_fragmentShader = 0;
}

gles::Program::Program(Program&& o)
{
	m_vertexShaderSource = o.m_vertexShaderSource;
	m_fragmentShaderSource = o.m_fragmentShaderSource;
	m_bits = o.m_bits;

	if (compiled()) {
		m_vertexShader = o.m_vertexShader;
		m_fragmentShader = o.m_fragmentShader;
	}
	if (linked()) {
		m_shaderProgram = o.m_shaderProgram;
	}
}

gles::Program::~Program()
{
	if (compiled()) {
		glDeleteShader(m_fragmentShader);
		glDeleteShader(m_vertexShader);
	}

	if (linked()) {
		// Frees the OpenGL handles for the program and the 2 shaders
		glDeleteProgram(m_shaderProgram);
	}
}

gles::Program& gles::Program::operator=(Program&& o)
{
	m_vertexShader = o.m_vertexShader;
	m_fragmentShader = o.m_fragmentShader;
	m_bits = o.m_bits;
	return *this;
}

void gles::Program::use()
{
	if (!compiled()) {
		compile();
	}
	if (!linked()) {
		link();
	}

	/*	Use the Program
	Calling glUseProgram tells OpenGL ES that the application intends to use this program for rendering. Now that it's installed into
	the current state, any further glDraw* calls will use the shaders contained within it to process scene data. Only one program can
	be active at once, so in a multi-program application this function would be called in the render loop. Since this application only
	uses one program it can be installed in the current state and left there.
	*/
	glUseProgram(m_shaderProgram);
}

GLuint gles::Program::CompileShader(GLenum shaderType, const std::string &src)
{
	// Create a fragment shader object
	GLuint shader = glCreateShader(shaderType);
	CheckGLESError("glCreateShader", __LINE__);

	const char *shaderSrc = src.c_str();
	// Load the source code into it
	glShaderSource(shader, 1, &shaderSrc, NULL);

	// Compile the source code
	glCompileShader(shader);

	// Check that the shader compiled
	GLint isShaderCompiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isShaderCompiled);
	if (!isShaderCompiled) {
		// If an error happened, first retrieve the length of the log message
		int infoLogLength, charactersWritten;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		// Allocate enough space for the message and retrieve it
		auto infoLog = std::auto_ptr<char>(new char[infoLogLength]);
		glGetShaderInfoLog(shader, infoLogLength, &charactersWritten, infoLog.get());
		glDeleteShader(shader);

		throw gles_error(infoLog.get());
	}

	return shader;
}

void gles::Program::compile()
{
	m_fragmentShader = CompileShader(GL_FRAGMENT_SHADER, m_fragmentShaderSource);
	m_vertexShader = CompileShader(GL_VERTEX_SHADER, m_vertexShaderSource);
	m_bits.set(eCompiled);
}

void gles::Program::link()
{
	if (!m_bits.test(eCompiled))
		return;

	GLuint shaderProgram = glCreateProgram();
	CheckGLESError("glCreateProgram", __LINE__);

	// Attach the fragment and vertex shaders to it
	glAttachShader(shaderProgram, m_fragmentShader);
	glAttachShader(shaderProgram, m_vertexShader);

	// Link the program
	glLinkProgram(shaderProgram);

	// Check if linking succeeded in the same way we checked for compilation success
	GLint isLinked = 0;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);
	if (!isLinked) {
		// If an error happened, first retrieve the length of the log message
		int infoLogLength, charactersWritten;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);

		// Allocate enough space for the message and retrieve it
		auto infoLog = std::unique_ptr<char>(new char[infoLogLength]);
		glGetProgramInfoLog(shaderProgram, infoLogLength, &charactersWritten, infoLog.get());

		glDeleteProgram(shaderProgram);
		throw gles_error(infoLog.get());
	}

	m_shaderProgram = shaderProgram;
	m_bits.set(eLinked);
}

void gles::CheckGLESError(const char *funcName, int lineNum)
{
	/*	glGetError returns the last error that occurred using OpenGL ES, not necessarily the status of the last called function. The user
	has to check after every single OpenGL ES call or at least once every frame. Usually this would be for debugging only, but for this
	example it is enabled always
	*/
	GLenum lastError = glGetError();
	if (lastError != GL_NO_ERROR) {
		char stringBuffer[1024] = { 0 };
		sprintf_s(stringBuffer, "%s:%d failed (%x).", funcName, lineNum, lastError);
		throw gles_error(stringBuffer);
	}
}
