#include "renderer/renderer.hpp"

namespace Spirit {
	void Renderer::Init() {
		RenderCommand::Init();
	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray) {
		shader->Bind();
		vertexArray->Bind();
		RenderCommand::drawIndexed(vertexArray);
	}
}
