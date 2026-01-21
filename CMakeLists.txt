# CMakeLists.txt file for Base64 module
#
# © 2024 by Hatem Nabli

cmake_minimum_required(VERSION 3.20)
set(this Base64)

set(Headers 
    include/Base64/Base64.hpp
)

set(Sources
    src/Base64.cpp
)

add_library(${this} STATIC ${Headers} ${Sources})
set_target_properties(${this} PROPERTIES 
    FOLDER Libraries
)

target_include_directories(${this} PUBLIC include)

add_subdirectory(test)