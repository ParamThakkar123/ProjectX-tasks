cmake_minimum_required(VERSION 3.28.0)
project(labyrinth)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES lab.cpp)

add_executable(labyrinth ${SOURCES})
