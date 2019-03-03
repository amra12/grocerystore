cmake_minimum_required(VERSION 3.4)
project(Homework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Products.hpp Products.cpp Log.hpp log.cpp)
add_executable(Homework ${SOURCE_FILES})