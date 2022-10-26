#pragma once

#include "renderer/vertex_array.hpp"

namespace Spirit {
	class RenderAPI {
		public:
			enum class API { None = 0, OpenGL = 1 };
		public:
			virtual ~RenderAPI() = default;

			virtual void Init() = 0;
			virtual void drawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;

			static API getAPI() { return s_API; }
			static Scope<RenderAPI> Create();
		private:
			static API s_API;
	};
}
