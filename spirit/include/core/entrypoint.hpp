#pragma once

extern Spirit::Application* Spirit::CreateApplication();

int main(int argc, char *argv[]) {
	auto app = Spirit::CreateApplication();
	app->Run();
	delete app;
}
