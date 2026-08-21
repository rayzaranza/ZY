#pragma once
#include "../Buffer//VertexArray.h"
#include <glad/glad.h>

namespace ZY
{
	class Renderer
	{
	public:
		static void setViewport(unsigned int width, unsigned int height);
		static void loadAPI(GLADloadproc address);
		static void clear();
		static void draw(const VertexArray& vertexArray);
	};
}