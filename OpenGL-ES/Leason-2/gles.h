#pragma once

#include <exception>
#include <string>
#include <bitset>
#include <GLES2/gl2.h>

namespace gles
{
	struct gles_error : public std::exception {
		typedef std::exception _Base;
		gles_error(const std::string &s) : _Base(s.c_str()) { }
		gles_error(const char *s) : _Base(s) { }
	};

	class Program {
		GLuint m_vertexShader, m_fragmentShader, m_shaderProgram;
		std::bitset<8> m_bits;
		std::string m_vertexShaderSource;
		std::string m_fragmentShaderSource;

		enum {eCompiled, eLinked};
	public:
		Program(const std::string &vertexShader, const std::string &fragmentShader);
		~Program();
		Program(const Program& o) = delete;
		Program(Program&& o);
		Program& operator=(const Program& o) = delete;
		Program& operator=(Program&& o);

		void use();
		void compile();
		void link();

		inline bool compiled() const { return m_bits.test(eCompiled); }
		inline bool linked() const { return m_bits.test(eLinked); }
		GLuint GetProgram() const { return m_shaderProgram; }

	private:
		GLuint CompileShader(GLenum shaderType, const std::string &src);
		void CreateProgram();
	};

	void CheckGLESError(const char *funcName, int lineNum);
}
