cmake_minimum_required(VERSION 3.15)
project(chap1)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

find_package(GTest REQUIRED)

add_executable(bin_result main.cpp q1.cpp)

target_link_libraries(bin_result GTest::GTest)

include(GoogleTest)
gtest_discover_tests(bin_result)