cmake_minimum_required(VERSION 3.1)

project(direct)

include_directories(/usr/local/include)

set (direct_SRC
    direct.cpp
    sample.cpp
)

add_executable( direct ${direct_SRC} )

target_link_libraries( direct pthread )