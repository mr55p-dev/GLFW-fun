cmake_minimum_required(VERSION 3.10) 

project(glfwFun CXX) 

add_subdirectory(vendor/glfw)

add_executable(main main.cpp) 

target_link_libraries(main glfw)
