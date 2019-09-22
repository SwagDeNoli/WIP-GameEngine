cmake_minimum_required(VERSION 3.14)
project(G)

set(CMAKE_CXX_STANDARD 17)

link_libraries(raylib)

set(SOURCE_FILES src/main.cpp src/Engine.cpp src/Engine.h src/Paddle.cpp src/Paddle.h)
add_executable(Pong ${SOURCE_FILES} ${SOURCES} src/Paddle.cpp src/Paddle.h)