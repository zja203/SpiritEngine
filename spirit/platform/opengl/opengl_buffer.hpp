#pragma once

#include "renderer/buffer.hpp"

namespace Spirit {
	class OpenGLVertexBuffer : public VertexBuffer {
		public:
			OpenGLVertexBuffer(uint32_t size);
			OpenGLVertexBuffer(float* vertices, uint32_t size);
			virtual ~OpenGLVertexBuffer();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual void setData(const void* data, uint32_t size) override;

			virtual const BufferLayout& getLayout() const override { return m_Layout; }
			virtual void setLayout(const BufferLayout& layout) override { m_Layout = layout; }
		private:
			uint32_t m_RendererID;
			BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer {
		public:
			OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
			virtual ~OpenGLIndexBuffer();

			virtual void Bind() const;
			virtual void Unbind() const;

			virtual uint32_t getCount() const { return m_Count; }
		private:
			uint32_t m_RendererID;
			uint32_t m_Count;
	};
}
