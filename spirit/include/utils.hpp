#pragma once

#include <string>
#include <fstream>

namespace Spirit {
	class Utils {
		public:
			static const std::string readFile(const std::string& path);
	};
}
