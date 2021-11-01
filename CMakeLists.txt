cmake_minimum_required(VERSION 3.21)
project(pmp_server_cli)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(pmp_server_cli
        include/DBHandle.h
        src/DBHandle.cpp
        src/main.cpp)

target_link_libraries(pmp_server_cli LINK_PUBLIC sqlite3)