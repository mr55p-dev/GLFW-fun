cmake_minimum_required(VERSION 3.10) 

project(glfwFun CXX) 

# find_package(glfw3 3.4 REQUIRED)
add_subdirectory(vendor/glfw)

add_executable(main main.cpp) 

target_link_libraries(main glfw)
