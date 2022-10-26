#pragma once

#include "renderer/render_api.hpp"

namespace Spirit {
	class OpenGLRenderAPI : public RenderAPI {
		public:
			virtual void Init() override;
			virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
			virtual void setClearColor(const glm::vec4& color) override;
			virtual void Clear() override;
			virtual void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}
