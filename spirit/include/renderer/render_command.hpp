#pragma once

#include "renderer/render_api.hpp"
#include "renderer/vertex_array.hpp"

namespace Spirit {
	class RenderCommand {
		public:
			static void Init() {
				s_RenderAPI->Init();
			}
			static void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
				s_RenderAPI->setViewport(x, y, width, height);
			}

			static void setClearColor(const glm::vec4& color) {
				s_RenderAPI->setClearColor(color);
			}

			static void clear() {
				s_RenderAPI->Clear();
			}

			static void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) {
				s_RenderAPI->drawIndexed(vertexArray, indexCount);
			}
		private:
			static Scope<RenderAPI> s_RenderAPI;
	};
}
