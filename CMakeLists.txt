cmake_minimum_required(VERSION 3.9)
project(quad_edge VERSION 0.1.0 DESCRIPTION "Quad-Edge Implementation in C++")

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")
target_compile_features(Catch2::Catch INTERFACE cxx_std_17)

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
target_compile_features(quad_edge INTERFACE cxx_std_17)

add_executable(tests tests.cc)
target_link_libraries(tests quad_edge Catch2::Catch)

add_executable(test-obj test-obj.cc)
target_link_libraries(test-obj quad_edge Catch2::Catch)

include(CTest)
enable_testing()
add_test(NAME tests COMMAND tests)
add_test(NAME test-obj COMMAND test-obj)
