cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(Laboratorio6)
add_library(Shape Shape.h Shape.cpp)
add_library(Square Square.h Square.cpp)
add_library(Rhombus Rhombus.h Rhombus.cpp)
add_library(Rect Rect.h Rect.cpp)
add_library(Parallelogram Parallelogram.h Parallelogram.cpp)

add_executable(main main.cpp)

target_link_libraries(main Shape)
target_link_libraries(main Square)
target_link_libraries(main Rhombus)
target_link_libraries(main Rect)
target_link_libraries(main Parallelogram)
