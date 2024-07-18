cmake_minimum_required(VERSION 3.25)
project(testhiredis)

set(CMAKE_CXX_STANDARD 14)

add_executable(testhiredis main.cpp)

find_package(hiredis)

target_link_libraries(testhiredis hiredis::hiredis)