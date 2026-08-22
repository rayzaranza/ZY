#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

namespace ZY
{
	class Shader
	{
	private:
		unsigned int id;

	public:
		Shader(const std::string& name);
		~Shader();

		inline void bind() const;
		void setUniform(const std::string& name, const float& value) const;
		void setUniform(const std::string& name, const glm::vec2& vector) const;
		void setUniform(const std::string& name, const glm::vec3& vector) const;
		void setUniform(const std::string& name, const glm::vec4& vector) const;
		void setUniform(const std::string& name, const glm::mat4& matrix) const;

	private:
		unsigned int compileShader(const std::string& source, GLenum type) const;
	};
}