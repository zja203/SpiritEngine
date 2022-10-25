#include <Spirit.hpp>

class TestLayer : public Spirit::Layer {
	public:
		TestLayer() : Layer("Test") { }

		void OnUpdate() override {
			// SPRT_INFO("TestLater::Update");
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
