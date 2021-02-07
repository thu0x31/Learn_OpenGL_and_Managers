# ----------------------------------------------
# EMSCRIPTEN
# ----------------------------------------------
# $ cd emscripten/build
# $ emcmake cmake ..
# $ emmake make
# ----------------------------------------------

cmake_minimum_required(VERSION 3.10)
project(GLFWCMake VERSION 1.0)

set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")
set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g -v -Wall -Wextra -Wno-long-long -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "{CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS_MINSIZEREL "{CMAKE_CXX_FLAGS} -Os")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "{CMAKE_CXX_FLAGS} -Og -g")

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${CMAKE_SOURCE_DIR}/src"
                           )
