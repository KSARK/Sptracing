cmake_minimum_required(VERSION 3.6)
project(Sptracing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

set(INCLUDE_DIRS Lib)
include_directories(${INCLUDE_DIRS})

add_executable(Sptracing ${SOURCE_FILES} Detile/Vector.hpp Detile/Ray3.hpp Detile/Sphere.hpp Detile/common/Intersect_result.hpp Detile/Camera_F.hpp)