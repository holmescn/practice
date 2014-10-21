#include <iostream>
#include "GLProgram.h"


GLProgram::GLProgram(const std::string &vertexShader, const std::string &fragmentShader)
{
	m_bValid = false;
	m_vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
	m_fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	if (m_vertexShader > 0 && m_fragmentShader > 0) {
		m_bValid = true;
	}
}

GLProgram::GLProgram(const GLProgram& o)
{

}

GLProgram::GLProgram(const GLProgram&& o)
{

}

GLProgram::~GLProgram()
{

}

GLProgram& GLProgram::operator=(const GLProgram& o)
{

}

GLProgram& GLProgram::operator=(const GLProgram&& o)
{

}

void GLProgram::use()
{

}

GLuint GLProgram::CompileShader(GLenum shaderType, const std::string &src)
{

}

void GLProgram::CreateProgram()
{

}
