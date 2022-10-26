#pragma once

#include "renderer/render_command.hpp"
#include "renderer/vertex_array.hpp"
#include "renderer/shader.hpp"

namespace Spirit {
	class Renderer {
		public:
		static void Init();
		static void Shutdown();
		static void OnWindowResize(uint32_t width, uint32_t height);
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray);

		static RenderAPI::API getAPI() { return RenderAPI::getAPI(); }
	};
}
