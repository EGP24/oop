cmake_minimum_required(VERSION 3.27)
project(untitled3)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled3 main.cpp
        Polygon.cpp
        Polygon.h
        Triangle.cpp
        Triangle.h
        Tetragon.cpp
        Tetragon.h
        Factory.cpp
        Factory.h
        Menu.cpp
        Menu.h
        TestTriangle.cpp
        TestTriangle.h
        TestTetragon.cpp
        TestTetragon.h
        LogDuration.cpp
        LogDuration.h
)
