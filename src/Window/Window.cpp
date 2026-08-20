#include "Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
// TODO: move glad to renderer class
#include <glad/glad.h>

Window::Window(unsigned int width, unsigned int height) :
	width{ width },
	height{ height }
{
	initializeGLFW();
	create();
}

Window::~Window()
{
	glfwDestroyWindow(id);
	glfwTerminate();
}

bool Window::isOpen() const
{
	return !glfwWindowShouldClose(id);
}

void Window::processEvents() const
{
	glfwPollEvents();
}

void Window::update() const
{
	glfwSwapBuffers(id);
	glfwSwapInterval(1);
}

void Window::clear() const
{
	glClearColor(1.0f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::initializeGLFW() const
{
	glfwSetErrorCallback(errorCallback);
	const int initStatus{ glfwInit() };
	if (initStatus == GLFW_FALSE)
	{
		std::cerr << "Error initializing GLFW" << std::endl;
	}
}

void Window::create()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	id = glfwCreateWindow(width, height, "", nullptr, nullptr);
	if (id == NULL)
	{
		std::cerr << "Error creating GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(id);

	glfwSetFramebufferSizeCallback(id, framebufferSizeCallback);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

inline void Window::errorCallback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}

inline void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
