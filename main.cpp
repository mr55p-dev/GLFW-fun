#include <cstdio>
#include <iostream>
#include <GLFW/glfw3.h>

#define DBG(msg) (std::cout << msg << std::endl);

void error_callback(int error, const char* description)
{
    std::fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main() {
    DBG("init")
    if (!glfwInit())
    {
        std::cerr << "Failed to init glfw" << std::endl;
        return -1; // Added return statement
    }
    glfwSetErrorCallback(error_callback);
    DBG("Initialised glwf");

    GLFWwindow *window = glfwCreateWindow(640, 480, "My window", NULL, NULL);
    if (!window)
    {
        DBG("Window failed to open");
        glfwTerminate(); 
        return -1; 
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

    // This is the main event loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        glfwPollEvents();

        // Swap front and back buffers
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    DBG("Program finished.");
    return 0; // Added return 0 for success
}
