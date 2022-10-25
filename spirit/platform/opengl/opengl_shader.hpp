#pragma once

#include "renderer/shader.hpp"

namespace Spirit {
	class OpenGLShader : public Shader {
		public:
			OpenGLShader(const char *path, unsigned int type);
			unsigned int m_Id;
	};
}
