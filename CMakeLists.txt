cmake_minimum_required(VERSION 3.19)
project(GLFWCMake VERSION 1.0)

add_executable(${PROJECT_NAME} src/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# set(CMAKE_CXX_FLAGS "-stdlib=libstdc++")
set(CMAKE_CXX_FLAGS "-stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -v -Wall -Wextra -Wno-long-long -pedantic -fno-exceptions -fno-rtti")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Og -g")

target_include_directories(${PROJECT_NAME} PUBLIC
                            "${CMAKE_SOURCE_DIR}/src"
                            "${CMAKE_SOURCE_DIR}/lib"
                            )

# https://cmake.org/cmake/help/latest/module/FindOpenGL.html
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/glad/")

target_link_libraries(${PROJECT_NAME} PRIVATE
                        glad
                        glfw
                        OpenGL::GL
                        "${CMAKE_DL_LIBS}"
                    )
