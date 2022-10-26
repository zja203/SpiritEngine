#pragma once

#include "renderer/vertex_array.hpp"

namespace Spirit {
	class OpenGLVertexArray : public VertexArray {
		public:
			OpenGLVertexArray();
			virtual ~OpenGLVertexArray();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual void addVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
			virtual void setIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

			virtual const std::vector<Ref<VertexBuffer>>& getVertexBuffers() const { return m_VertexBuffers; }
			virtual const Ref<IndexBuffer>& getIndexBuffer() const { return m_IndexBuffer; }
		private:
			uint32_t m_RendererID;
			uint32_t m_VertexBufferIndex = 0;
			std::vector<Ref<VertexBuffer>> m_VertexBuffers;
			Ref<IndexBuffer> m_IndexBuffer;
	};
}
