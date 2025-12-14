cmake_minimum_required(VERSION 3.16)
project(raytracing_in_a_weekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(raytracer main.cc
        vec3.h)
