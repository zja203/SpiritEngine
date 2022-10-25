#include <Spirit.hpp>
#include <GL/glew.h>
#include <filesystem>

static void GLClearError() {
	while(glGetError() != GL_NO_ERROR);
}

static void GLCheckError() {
	while(GLenum error = glGetError()) {
		SPRT_ERROR("[OpenGL Error] {0}", error);
	}
}

class TestLayer : public Spirit::Layer {
	public:
		TestLayer() : Layer("Test") { }

		void OnUpdate() override {
			// SPRT_INFO("TestLater::Update");
			glDrawArrays(GL_TRIANGLES, 0, 3);
			GLCheckError();
		}

		void OnAttach() override {
			float positions[] {
				-0.5f, -0.5f,
					0.5f, -0.5f,
					0.0f, 0.5f
			};

			unsigned int buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ARRAY_BUFFER, buffer);
			glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

			unsigned int program = glCreateProgram();
			unsigned int vs = Spirit::OpenGLShader("tri.vert", GL_VERTEX_SHADER).m_Id;
			unsigned int fs = Spirit::OpenGLShader("tri.frag", GL_FRAGMENT_SHADER).m_Id;
			SPRT_TRACE("VERT: {0}", vs);
			SPRT_TRACE("FRAG: {0}", fs);

			glAttachShader(program, vs);
			glAttachShader(program, fs);
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vs);
			glDeleteShader(fs);

			glUseProgram(program);
		}
		
		void OnDetach() override {
		}

		void OnEvent(Spirit::Event& event) override {
			SPRT_TRACE("{0}", event);
		}
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
