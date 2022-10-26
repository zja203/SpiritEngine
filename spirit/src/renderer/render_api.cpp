#include "sprtpch.hpp"
#include "renderer/render_api.hpp"

#include "platform/opengl/opengl_renderapi.hpp"

namespace Spirit {
	RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;

	Scope<RenderAPI> RenderAPI::Create() {
		switch (s_API) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateScope<OpenGLRenderAPI>();
		}

		SPRT_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
}
