#pragma once

#include "core/base.hpp"
#include "events/event.hpp"
#include "events/app_event.hpp"
#include "layer_stack.hpp"
#include "window.hpp"

namespace Spirit {
	struct ApplicationCommandLineArgs {
		int Count = 0;
		char **Args = nullptr;

		const char *operator[](int index) const {
			SPRT_CORE_ASSERT(index < Count, "Invalid Index on CommandLineArgs!");
			return Args[index];
		}
	};

	struct AppSpec {
		std::string Name = "Spirit Application";
		std::string WorkingDir;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class SPIRIT_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
			bool OnWindowResize(WindowResizeEvent& e);
			void pushLayer(Layer *layer);
			void pushOverlay(Layer *layer);

			static Application& Get() { return *s_Instance; }

			const AppSpec& getSpecification() const { return m_Specification; }
		private:
			AppSpec m_Specification;
			static Application* s_Instance;
			bool OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			bool m_Minimized = false;
			LayerStack m_LayerStack;
	};


	// To be defined in CLIENT
	Application* CreateApplication();
}
