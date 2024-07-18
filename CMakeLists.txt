cmake_minimum_required(VERSION 3.25)
project(testhiredis)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR}/third_party)
SET(hiredis_sources
        third_party/hiredis/alloc.c
        third_party/hiredis/async.c
        third_party/hiredis/hiredis.c
        third_party/hiredis/net.c
        third_party/hiredis/read.c
        third_party/hiredis/sds.c
        third_party/hiredis/sockcompat.c)

SET(hiredis_sources ${hiredis_sources})
add_executable(main src/main.cpp
        ${hiredis_sources}
)
add_executable(testhiredis src/testhiredis.cpp
        ${hiredis_sources}
)

TARGET_LINK_LIBRARIES(main PUBLIC ws2_32 crypt32)
TARGET_LINK_LIBRARIES(testhiredis PUBLIC ws2_32 crypt32)

#find_package(hiredis CONFIG REQUIRED)
#target_link_libraries(main hiredis::hiredis)
#target_link_libraries(testhiredis hiredis::hiredis)
