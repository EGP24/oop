cmake_minimum_required(VERSION 3.27)
project(cppLR2)

set(CMAKE_CXX_STANDARD 23)

add_executable(cppLR2 main.cpp
        Matrix.cpp
        MatrixTest.cpp
        MatrixTest.h)
