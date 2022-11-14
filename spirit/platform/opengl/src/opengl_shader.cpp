#include <GL/glew.h>
#include <fstream>
#include "utils.hpp"
#include "platform/opengl/opengl_shader.hpp"
#include "log.hpp"

namespace Spirit {
	static GLenum ShaderTypeFromString(const std::string& type) {
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;

		SPRT_CORE_ASSERT(false, "Unknown shader type!");
		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string& path) : m_Path(path) {
		std::string source = Utils::readFile(path);
		m_OpenGLShaders = Preprocess(source);
		createProgram();
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteProgram(m_RendererID);
	}

	std::unordered_map<unsigned int, std::string> OpenGLShader::Preprocess(const std::string& source) {
		std::unordered_map<unsigned int, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0); //Start of shader type declaration line
		while (pos != std::string::npos) {
			size_t eol = source.find_first_of("\n", pos); //End of shader type declaration line
			SPRT_CORE_ASSERT(eol != std::string::npos, "Syntax error");
			size_t begin = pos + typeTokenLength + 1; //Start of shader type name (after "#type " keyword)
			std::string type = source.substr(begin, eol - begin);
			SPRT_CORE_ASSERT(ShaderTypeFromString(type), "Invalid shader type specified");

			size_t nextLinePos = source.find_first_not_of("\n", eol); //Start of shader code after shader type declaration line
			SPRT_CORE_ASSERT(nextLinePos != std::string::npos, "Syntax error");
			pos = source.find(typeToken, nextLinePos); //Start of next shader type declaration line

			shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}

		return shaderSources;
	}

	void OpenGLShader::createProgram() {
		GLuint program = glCreateProgram();
		std::vector<GLuint> shaderIDs;
		for (auto [shaderType, src] : m_OpenGLShaders) {
			GLuint shaderID = shaderIDs.emplace_back(glCreateShader(shaderType));
			const char *shaderSrc = src.c_str();
			glShaderSource(shaderID, 1, &shaderSrc, nullptr);
			glCompileShader(shaderID);
			int result;
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
			if(!result) {
				int length;
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
				char *message = (char*)alloca(length*sizeof(char));
				glGetShaderInfoLog(shaderID, length, &length, message);
				printf("%s\n", message);
				glDeleteShader(shaderID);
			}
			glAttachShader(program, shaderID);
		}
		glLinkProgram(program);
		GLint isLinked;
		glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE) {
			GLint maxLength;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());
			SPRT_CORE_ERROR("Shader linking failed ({0}):\n{1}", m_Path, infoLog.data());

			glDeleteProgram(program);

			for (auto id : shaderIDs) {
				glDeleteShader(id);
			}
		}

		for (auto id : shaderIDs) {
			glDetachShader(program, id);
			glDeleteShader(id);
		}
		m_RendererID = program;
	}
	void OpenGLShader::Bind() const {
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const {
		glUseProgram(0);
	}

	void OpenGLShader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) const {
		// TODO: Make GetUniformLocation member function
		glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
	}
}
