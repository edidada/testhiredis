cmake_minimum_required(VERSION 3.25)
project(testhiredis)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR}/third_party)
add_executable(testhiredis main.cpp
        third_party/hiredis/alloc.c
        third_party/hiredis/async.c
        third_party/hiredis/hiredis.c
        third_party/hiredis/net.c
        third_party/hiredis/read.c
        third_party/hiredis/sds.c
        third_party/hiredis/sockcompat.c
)

TARGET_LINK_LIBRARIES(testhiredis PUBLIC ws2_32 crypt32)

#find_package(hiredis CONFIG REQUIRED)
#target_link_libraries(testhiredis hiredis::hiredis)
