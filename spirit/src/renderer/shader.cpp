#include <GL/glew.h>
#include "renderer/shader.hpp"
#include <fstream>
#include <string>

namespace Spirit {
	std::string Shader::readShader(const char *path) {
		std::ifstream ifs(path);
		std::string content(
				(std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>())
				);
		return content;
	}
}
