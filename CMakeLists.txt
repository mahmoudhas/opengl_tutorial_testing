cmake_minimum_required(VERSION 3.8)
project(helloworld)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Display.cpp Display.h Shader.cpp Shader.h Mesh.cpp Mesh.h)


add_executable(helloworld ${SOURCE_FILES})


target_link_libraries(helloworld GL)
target_link_libraries(helloworld SDL2)
target_link_libraries(helloworld GLEW)