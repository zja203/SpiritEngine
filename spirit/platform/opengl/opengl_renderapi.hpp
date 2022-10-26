#pragma once

#include "renderer/render_api.hpp"

namespace Spirit {
	class OpenGLRenderAPI : public RenderAPI {
		public:
			virtual void Init() override;
			virtual void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}
