cmake_minimum_required(VERSION 3.19)
project(Glad)

add_library(glad glad.h glad.c)
target_include_directories(glad PUBLIC "${CMAKE_SOURCE_DIR}")