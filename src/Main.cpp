#include "Main.h"

int main(int argc, char* argv[])
{
	ZY::Window window{ 1920, 1080 };
	ZY::Shader defaultShader{ "default" };

	ZY::VertexBuffer quadVertexBuffer{ {
		 0.5f,  0.5f,	1.0f, 1.0f,
		 0.5f, -0.5f,	1.0f, 0.0f,
		-0.5f, -0.5f,	0.0f, 0.0f,
		-0.5f,  0.5f,	0.0f, 1.0f
	} };

	defaultShader.setUniform("u_Color", glm::vec4{ 1.0f, 0.0f, 0.0f, 1.0f });

	quadVertexBuffer.setAttributes({ { 2 }, { 2 } });

	ZY::IndexBuffer quadIndexBuffer{ { 0, 1, 3, 1, 2, 3 } };
	ZY::VertexArray quadVertexArray;
	quadVertexArray.addBuffer(quadVertexBuffer, quadIndexBuffer);

	while (window.isOpen())
	{
		window.processEvents();
		ZY::Renderer::clear();
		ZY::Renderer::draw(quadVertexArray, defaultShader);
		window.update();
	}
}