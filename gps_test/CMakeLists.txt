cmake_minimum_required(VERSION 3.10)

set(TARGET_APP gps_test)

add_executable(${TARGET_APP})

target_include_directories(${TARGET_APP} PRIVATE include)
target_link_libraries(${TARGET_APP} PRIVATE gps)
target_link_directories(${TARGET_APP} PRIVATE lib)
target_sources(${TARGET_APP} PRIVATE main.cc)
