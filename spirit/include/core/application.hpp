#pragma once

#include "core/base.hpp"

namespace Spirit {
	class SPIRIT_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
