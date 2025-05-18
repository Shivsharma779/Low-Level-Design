cmake_minimum_required(VERSION 3.10)
project(GenericProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Find all .cpp files in the current directory
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "*.cpp")

# Create an executable for each .cpp file
foreach(src_file ${SRC_FILES})
    get_filename_component(exec_name ${src_file} NAME_WE)
    get_filename_component(parent_dir ${src_file} DIRECTORY)
    get_filename_component(parent_dir_name ${parent_dir} NAME)
    set(full_exec_name "${parent_dir_name}_${exec_name}")
    add_executable(${full_exec_name} ${src_file})
endforeach()
