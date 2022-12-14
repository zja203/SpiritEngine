#include <GL/glew.h>
#include "renderer/shader.hpp"
#include "renderer/renderer.hpp"
#include "platform/opengl/opengl_shader.hpp"

namespace Spirit {
	Ref<Shader> Shader::Create(const std::string& filepath) {
		switch (Renderer::getAPI()) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateRef<OpenGLShader>(filepath);
		}

		SPRT_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
}
