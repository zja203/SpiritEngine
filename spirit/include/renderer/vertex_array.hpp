#pragma once
#include "renderer/buffer.hpp"

#include <memory>

namespace Spirit {
	class VertexArray {
		public:
			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void addVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
			virtual void setIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

			virtual const std::vector<Ref<VertexBuffer>>& getVertexBuffers() const = 0;
			virtual const Ref<IndexBuffer>& getIndexBuffer() const = 0;

			static Ref<VertexArray> Create();
	};
}
