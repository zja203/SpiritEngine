#pragma once

#include "renderer/render_api.hpp"
#include "renderer/vertex_array.hpp"

namespace Spirit {
	class RenderCommand {
		public:
			static void Init() {
				s_RenderAPI->Init();
			}
			static void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) {
				s_RenderAPI->drawIndexed(vertexArray, indexCount);
			}
		private:
			static Scope<RenderAPI> s_RenderAPI;
	};
}
