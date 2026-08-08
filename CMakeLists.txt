cmake_minimum_required(VERSION 3.16)

project(Taraengine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Taraengine)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

target_sources(Taraengine PRIVATE ${SRC_FILES})

target_include_directories(Taraengine
    PRIVATE
    include
)

find_package(OpenGL REQUIRED)

target_link_libraries(Taraengine
    PRIVATE
    OpenGL::GL
)