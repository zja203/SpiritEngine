#include <Spirit.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <filesystem>
#include "renderer/orthographic_camera.hpp"

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

			Spirit::OrthographicCamera mainCam = Spirit::OrthographicCamera(-1.77, 1.77, -1, 1);

			m_va = VertexArray::Create();
			m_vb = VertexBuffer::Create(positions, sizeof(positions));
			m_vb->setLayout(Spirit::BufferLayout({{ShaderDataType::Float2,"position"}}));
			m_va->addVertexBuffer(m_vb);

			uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
			Ref<IndexBuffer> m_ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
			m_va->setIndexBuffer(m_ib);

			m_Shader = Spirit::Shader::Create("basic.glsl");
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", mainCam.getProjectionMatrix());
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
