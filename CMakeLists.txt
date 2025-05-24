cmake_minimum_required(VERSION 3.10)
project(GenericProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_language(CXX)

# Find all .cpp files in the current directory
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "*.cpp")

