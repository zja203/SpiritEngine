#include <GL/glew.h>
#include "platform/opengl/opengl_shader.hpp"

namespace Spirit {
	OpenGLShader::OpenGLShader(const char *path, unsigned int type) {
		unsigned int id = glCreateShader(type);
		std::string srcStr = readShader(path);
		const char *src = srcStr.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if(!result) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char *message = (char*)alloca(length*sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			printf("%s\n", message);
			glDeleteShader(id);
		}
		m_Id = id;
	}
}
