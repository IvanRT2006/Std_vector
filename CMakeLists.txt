cmake_minimum_required(VERSION 3.10)
project(graph_project)

set(CMAKE_C_STANDART 11)

file(GLOB SOURCES "*.c")

file(GLOB HEADERS "*.h")

add_executable(graph_app ${SOURCES} ${HEADERS})
