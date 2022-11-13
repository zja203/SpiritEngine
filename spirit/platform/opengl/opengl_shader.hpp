#pragma once

#include "renderer/shader.hpp"
#include <unordered_map>

namespace Spirit {
	class OpenGLShader : public Shader {
		public:
			OpenGLShader(const std::string& filepath);
			virtual ~OpenGLShader();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual const std::string& getName() const override { return m_Name; }

			virtual void SetUniformMat4f(const std::string& name, const glm::mat4& matrix) const override;
		private:
			std::string readShader(const std::string& path);
			std::unordered_map<unsigned int, std::string> Preprocess(const std::string& source);
			void createProgram();
			unsigned int m_RendererID;
			std::string m_Path;
			std::string m_Name;
			std::unordered_map<unsigned int, std::string> m_OpenGLShaders;
	};
}
