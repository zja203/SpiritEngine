#include <Spirit.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <filesystem>

using Spirit::Ref;
using Spirit::VertexBuffer;
using Spirit::IndexBuffer;
using Spirit::VertexArray;
using Spirit::ShaderDataType;
using Spirit::Shader;

class TestLayer : public Spirit::Layer {
	public:
		TestLayer() : Layer("Test") {
			float positions[] {
				-0.5f, -0.5f,
				 0.5f, -0.5f,
				 0.5f,  0.5f,
				-0.5f,  0.5f
			};

			// First 2 numbers -aspect to +aspect 1
			// Second 2, the second.
			// So for 16:9, +-1.77 and +-1.
			glm::mat4 proj = glm::ortho(-1.77f, 1.77f, -1.0f, 1.0f, -1.0f, 1.0f);

			m_va = VertexArray::Create();
			m_vb = VertexBuffer::Create(positions, sizeof(positions));
			m_vb->setLayout(Spirit::BufferLayout({{ShaderDataType::Float2,"position"}}));
			m_va->addVertexBuffer(m_vb);

			uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
			Ref<IndexBuffer> m_ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
			m_va->setIndexBuffer(m_ib);

			m_Shader = Spirit::Shader::Create("basic.glsl");
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", proj);
		}

		void OnUpdate() override {
			Spirit::Renderer::Submit(m_Shader, m_va);
		}

		void OnAttach() override {
		}

		void OnDetach() override {
		}

		void OnEvent(Spirit::Event& event) override {
			if(event.getEventType() != Spirit::EventType::WindowResize) {
				SPRT_TRACE("{0}", event);
			}
		}
	private:
		Ref<Shader> m_Shader;
		Ref<VertexBuffer> m_vb;
		Ref<VertexArray> m_va;
};

class Sandbox : public Spirit::Application {
	public:
		Sandbox() {
			pushLayer(new TestLayer());
		}

		~Sandbox() { }
};

Spirit::Application* Spirit::CreateApplication() {
	return new Sandbox();
}
