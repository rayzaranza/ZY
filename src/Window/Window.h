#pragma once

struct GLFWwindow;

class Window
{
public:
	GLFWwindow* id;
	unsigned int width;
	unsigned int height;

public:
	Window(unsigned int width, unsigned int height);
	~Window();

public:
	bool isOpen() const;

	void update() const;
	// TODO: move to renderer 
	void clear() const;
	// TODO: decouple events from windows
	void processEvents() const;

private:
	void initializeGLFW() const;
	void create();

private:
	inline static void errorCallback(int error, const char* description);
	inline static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};