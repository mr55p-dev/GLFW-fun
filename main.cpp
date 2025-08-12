#include <cstdio>
#include <iostream>
#include <GLFW/glfw3.h>
#include <ostream>
#include <thread>

#define DBG(msg) (std::cout << msg << std::endl);

void error_callback(int error, const char* description) 
{
	std::fprintf(stderr, "Error: %s\n", description);
}

int main() {
	DBG("init")
	if (!glfwInit())
	{
		std::cerr << "Failed to init glfw" << std::endl;
	}
	glfwSetErrorCallback(error_callback);
	DBG("Initialised glwf");

	GLFWwindow *window = glfwCreateWindow(200, 200, "My window", NULL, NULL);
	if (!window)
	{
		std::cerr << "Window didnt open :(" << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::seconds(10));

	glfwDestroyWindow(window);
	glfwTerminate();
}
