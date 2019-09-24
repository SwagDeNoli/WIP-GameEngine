cmake_minimum_required(VERSION 3.14)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

link_libraries(raylib)

set(SOURCE_FILES src/main.cpp src/Engine.cpp src/Engine.h src/Player.cpp src/Player.h)
add_executable(EXECUTABLE_NAME ${SOURCE_FILES})