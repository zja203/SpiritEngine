#include "sprtpch.hpp"
#include "renderer/buffer.hpp"

#include "renderer/renderer.hpp"

#include "platform/opengl/opengl_buffer.hpp"

namespace Spirit {
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size) {
		switch (Renderer::getAPI()) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(size);
		}

		SPRT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::getAPI()) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		SPRT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size) {
		switch (Renderer::getAPI()) {
			case RenderAPI::API::None:    SPRT_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
			case RenderAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		SPRT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
