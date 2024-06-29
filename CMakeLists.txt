cmake_minimum_required(VERSION 3.16)
project(rational_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(rational_project
        main.cpp
        rational.cpp
        rational.h)
