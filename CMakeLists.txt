cmake_minimum_required(VERSION 3.10)
project(OOP_labs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

find_package(GTest REQUIRED)
include(GoogleTest)
add_compile_options(-Wno-psabi)

add_executable(lab3 main.cpp src/array.cpp src/figure.cpp src/hexagon.cpp src/octagon.cpp src/triangle.cpp)
add_executable(test_lab3 tests/test_lab3.cpp src/array.cpp src/figure.cpp src/hexagon.cpp src/octagon.cpp src/triangle.cpp)
target_link_libraries(test_lab3 GTest::gtest GTest::gtest_main)
gtest_discover_tests(test_lab3)
