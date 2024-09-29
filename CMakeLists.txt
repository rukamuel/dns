cmake_minimum_required(VERSION 3.10)

project(dns VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(dns ${SRC_FILES})

target_include_directories(dns PUBLIC "${PROJECT_SOURCE_DIR}/src")
