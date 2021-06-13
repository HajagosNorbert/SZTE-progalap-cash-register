cmake_minimum_required(VERSION 3.17)
project(progalap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(item)
add_subdirectory(kiir)
add_subdirectory(beolvaso)

add_executable(progalap main.c)
target_link_libraries(progalap kiir beolvaso)
