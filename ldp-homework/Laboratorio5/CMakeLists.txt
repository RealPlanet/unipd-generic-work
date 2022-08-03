cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(Laboratorio5)
add_library(Controller Controller.h Controller.cpp)
add_library(PrintController PrintController.h PrintController.cpp)
add_library(Iterator Iterator.h Iterator.cpp)
add_library(List_iterator List_iterator.h List_iterator.cpp)
add_library(Vector_iterator Vector_iterator.h Vector_iterator.cpp)

add_executable(main main.cpp)

target_link_libraries(main Controller)
target_link_libraries(main PrintController)
target_link_libraries(main Iterator)
target_link_libraries(main List_iterator)
target_link_libraries(main Vector_iterator)
