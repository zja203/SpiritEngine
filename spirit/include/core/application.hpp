#pragma once

#include "core/base.hpp"
#include "events/event.hpp"
#include "events/app_event.hpp"
#include "window.hpp"

namespace Spirit {
	class SPIRIT_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
		private:
			bool OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};


	// To be defined in CLIENT
	Application* CreateApplication();
}
