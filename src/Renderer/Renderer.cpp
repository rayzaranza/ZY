#include "Renderer.h"

void ZY::Renderer::setViewport(unsigned int width, unsigned int height)
{
	glViewport(0, 0, width, height);
}

void ZY::Renderer::loadAPI(GLADloadproc addressCallback)
{
	gladLoadGLLoader((GLADloadproc)addressCallback);
}

void ZY::Renderer::clear()
{
	glClearColor(1.0f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
