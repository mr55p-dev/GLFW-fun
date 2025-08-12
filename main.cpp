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

	GLFWwindow *window = glfwCreateWindow(400, 400, "My window", NULL, NULL);
	if (!window)
	{
		DBG("Window failed to open");
	}

	std::this_thread::sleep_for(std::chrono::seconds(10));

	glfwDestroyWindow(window);
	glfwTerminate();
}
