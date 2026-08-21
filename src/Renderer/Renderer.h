#pragma once
#include <glad/glad.h>

namespace ZY
{
	class Renderer
	{
	public:
		static void setViewport(unsigned int width, unsigned int height);
		static void loadAPI(GLADloadproc address);
		static void clear();
	};
}