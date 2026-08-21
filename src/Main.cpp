#include "Main.h"

int main(int argc, char* argv[])
{
	ZY::Window window{ 1920, 1080 };

	while (window.isOpen())
	{
		window.processEvents();
		ZY::Renderer::clear();
		window.update();
	}
}