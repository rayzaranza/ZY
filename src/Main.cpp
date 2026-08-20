#include "Window/Window.h"

int main(int argc, char* argv[])
{
	Window window{ 1920, 1080 };

	while (window.isOpen())
	{
		window.processEvents();
		window.clear();
		window.update();
	}
}