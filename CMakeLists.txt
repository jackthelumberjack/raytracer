cmake_minimum_required(VERSION 3.3)
project(RayTracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Color.hpp
    Geometry.hpp
    Image.hpp
    Intersection.cpp
    Intersection.hpp
    Line.hpp
    main.cpp
    Material.hpp
    Scene.hpp
    Sphere.cpp
    Sphere.hpp
    Vector.hpp)

add_executable(RayTracer ${SOURCE_FILES})