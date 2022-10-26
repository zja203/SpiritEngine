#pragma once

#include "glm/glm.hpp"
#include "renderer/vertex_array.hpp"

namespace Spirit {
	class RenderAPI {
		public:
			enum class API { None = 0, OpenGL = 1 };
		public:
			virtual ~RenderAPI() = default;

			virtual void Init() = 0;
			virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
			virtual void setClearColor(const glm::vec4& color) = 0;
			virtual void Clear() = 0;
			virtual void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;

			static API getAPI() { return s_API; }
			static Scope<RenderAPI> Create();
		private:
			static API s_API;
	};
}
