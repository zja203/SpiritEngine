#pragma once

#include <glm/glm.hpp>

namespace Spirit {
	class Shader {
		public:
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual const std::string& getName() const = 0;

			virtual void SetUniformMat4f(const std::string& name, const glm::mat4& matrix) const = 0;

			static Ref<Shader> Create(const std::string& filepath);
	};
}
