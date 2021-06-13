cmake_minimum_required(VERSION 3.17)
project(progalap C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(item)

add_library(kiir kiir.c)

target_include_directories(kiir PUBLIC .)


add_executable(progalap main.c beolvaso.c)
target_link_libraries(kiir item)
target_link_libraries(progalap kiir)
