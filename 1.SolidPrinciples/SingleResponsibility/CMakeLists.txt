cmake_minimum_required(VERSION 3.10)
project(SingleResponsibility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES "*.cpp")

add_executable(SingleResponsibility ${SOURCES})