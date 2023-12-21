cmake_minimum_required(VERSION 3.27)
project(cppLR5)

set(CMAKE_CXX_STANDARD 23)

add_executable(cppLR5 main.cpp
        TextHandler.cpp
        TextHandlerTest.cpp
        TextHandlerTest.h)
