cmake_minimum_required(VERSION 3.10)
project(withoutStrategy)
set(CMAKE_CXX_STANDARD 20)
file(GLOB SOURCE_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_SOURCE_DIR}/include)


