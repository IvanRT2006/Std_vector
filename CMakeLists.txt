cmake_minimum_required(VERSION 3.10)
project(std_vector)

set(CMAKE_C_STANDARD 11)

add_executable(test std_vector.c)

# Optionally, to link against libraries
# target_link_libraries(test <library_name>)
