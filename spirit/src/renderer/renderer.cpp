#include "renderer/renderer.hpp"

namespace Spirit {
	void Renderer::Init() {
		RenderCommand::Init();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height) {
		RenderCommand::setViewport(0, 0, width, height);
	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray) {
		shader->Bind();
		vertexArray->Bind();
		RenderCommand::drawIndexed(vertexArray);
	}
}
