# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "/usr/include/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(simplescheduler CXX)

set(PROJECT_SOURCE_DIR "src/simple_scheduler")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(TBB CONFIG REQUIRED)
find_package(Threads)
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(simplescheduler ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(simplescheduler PRIVATE TBB::tbb ${CMAKE_THREAD_LIBS_INIT})
