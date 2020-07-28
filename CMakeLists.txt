cmake_minimum_required(VERSION 3.16)
project(StaticWebServer)
add_subdirectory(StaticWebServer)
add_subdirectory(Google_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(StaticWebServer main.cpp)