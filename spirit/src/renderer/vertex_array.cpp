#include "sprtpch.hpp"
#include "renderer/vertex_array.hpp"

#include "renderer/renderer.hpp"
#include "platform/opengl/opengl_vertex_array.hpp"

namespace Spirit {
	Ref<VertexArray> VertexArray::Create() {
		switch (Renderer::getAPI()) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		SPRT_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
}
