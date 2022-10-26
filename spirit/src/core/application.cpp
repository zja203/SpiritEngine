#include "sprtpch.hpp"
#include "core/application.hpp"
#include "events/app_event.hpp"
#include "log.hpp"
#include <GL/glew.h>
#include <GL/glut.h>
#include "renderer/shader.hpp"
#include "renderer/renderer.hpp"
#include <filesystem>

namespace Spirit {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(BIND_EVENT_FN(OnEvent));
		m_Specification.WorkingDir = "/home/zack/Documents/proj/spirit";
		std::filesystem::current_path(m_Specification.WorkingDir);
		SPRT_CORE_INFO("Current Directory: {0}", m_Specification.WorkingDir);
		Renderer::Init();
	}

	Application::~Application() {}

	void Application::pushLayer(Layer *layer) {
		m_LayerStack.pushLayer(layer);
		layer->OnAttach();
	}

	void Application::pushOverlay(Layer *layer) {
		m_LayerStack.pushOverlay(layer);
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		if (e.getWidth() == 0 || e.getHeight() == 0) {
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.getWidth(), e.getHeight());

		return false;
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer *layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}
