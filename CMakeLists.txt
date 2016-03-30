cmake_minimum_required(VERSION 3.4)
project(P1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c textsm.h textsm.c main_test.cpp bool.h)
add_executable(P1 ${SOURCE_FILES})