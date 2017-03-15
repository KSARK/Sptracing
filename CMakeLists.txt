cmake_minimum_required(VERSION 3.6)
project(Sptracing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

find_package(SDL2)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Sptracing ${SOURCE_FILES} Detile/Vector.hpp Detile/Ray3.hpp Detile/Sphere.hpp Detile/common/Intersect_result.hpp Detile/Camera_F.hpp Detile/Lens.hpp)
target_link_libraries(Sptracing ${SDL2_LIBRARIES})