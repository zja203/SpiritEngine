#include "utils.hpp"

namespace Spirit {	
	const std::string Utils::readFile(const std::string& path) {
		std::ifstream ifs(path);
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
				(std::istreambuf_iterator<char>()    ) );
		return content;
	}
}
