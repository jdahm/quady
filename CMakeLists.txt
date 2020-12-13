cmake_minimum_required(VERSION 3.9)
project(quad_edge VERSION 0.1.0 DESCRIPTION "Quad-Edge Implementation in C++")

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")


add_library(quad_edge SHARED
    array.cc
    array.hh
    cell.cc
	cell.hh
	edge.cc
	edge.hh
	face.cc
	face.hh
	list.cc
	list.hh
	obj.cc
	obj.hh
	vertex.cc
	vertex.hh
)

set_target_properties(quad_edge PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(quad_edge PROPERTIES SOVERSION 1)
set_property(TARGET quad_edge PROPERTY CXX_STANDARD 11)

add_executable(test test.cc)
target_link_libraries(test quad_edge)
