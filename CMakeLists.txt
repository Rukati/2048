cmake_minimum_required(VERSION 3.30)
project(2048)

set(CMAKE_CXX_STANDARD 20)

add_executable(2048 main.cpp
        Block.cpp
        Block.h)
