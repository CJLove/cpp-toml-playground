cmake_minimum_required(VERSION 3.1)

project(generic)

include_directories(/usr/local/include)

set (generic_SRC
    generic.cpp
)

add_executable( generic ${generic_SRC} )

target_link_libraries( generic pthread )