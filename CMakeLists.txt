cmake_minimum_required(VERSION 2.8)
project(compiler)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(expr_unit expr_ut.cpp expr.cpp eval.cpp check.cpp)