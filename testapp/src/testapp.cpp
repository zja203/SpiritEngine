#include <Spirit.hpp>

class Sandbox : public Spirit::Application {
public:
	Sandbox() { }

	~Sandbox() { }
};

Spirit::Application* Spirit::CreateApplication() {
	return new Sandbox();
}
