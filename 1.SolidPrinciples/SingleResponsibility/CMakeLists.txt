cmake_minimum_required(VERSION 3.10)
project(SingleResponsibility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SRC_FILES "*.cpp")
foreach(src_file ${SRC_FILES})
    get_filename_component(src_name ${src_file} NAME_WE)
    add_executable(${src_name} ${src_file})
endforeach()

file(GLOB SOURCES "*.cpp")

# add_executable(SingleResponsibility ${SOURCES})