cmake_minimum_required(VERSION 3.16)
project(end_2_main_program)

message(STATUS "Compiler")
message(STATUS " - ID\t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version\t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path\t: ${CMAKE_CXX_COMPILER}")

add_executable (receiving_program main.cc)
add_subdirectory(func)
add_subdirectory(mq)
target_link_libraries (receiving_program func mq)

find_package (Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
