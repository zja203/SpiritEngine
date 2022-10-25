#include "sprtpch.hpp"
#include <GL/glew.h>
#include "events/app_event.hpp"
#include "platform/linux/linux_window.hpp"
#include "core/application.hpp"

namespace Spirit {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new LinuxWindow(props);
	}

	LinuxWindow::LinuxWindow(const WindowProps& props) {
		init(props);
	}

	LinuxWindow::~LinuxWindow() {
		shutdown();
	}

	void LinuxWindow::init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SPRT_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			SPRT_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = glewInit();
		if (status != GLEW_OK) {
			SPRT_CORE_ERROR("glew error");
		}
		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
				});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
				});
	}

	void LinuxWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void LinuxWindow::OnUpdate() {
		glfwPollEvents();
	}
}
