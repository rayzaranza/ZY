#include "Main.h"

int main(int argc, char* argv[])
{
	ZY::Window window{ 1920, 1080 };

	ZY::VertexBuffer vertexBuffer{ {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	} };
	vertexBuffer.setAttributes({ ZY::VertexAttribute{ 0, 2, GL_FLOAT } });
	ZY::IndexBuffer indexBuffer{ { 0, 1, 2 } };
	ZY::VertexArray vertexArray;
	vertexArray.addBuffer(vertexBuffer, indexBuffer);

	while (window.isOpen())
	{
		window.processEvents();
		ZY::Renderer::clear();
		ZY::Renderer::draw(vertexArray);
		window.update();
	}
}