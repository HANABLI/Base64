# CMakeLists.txt for Base64Tests test Module.
#
# © 2024 by Hatem Nabli

cmake_minimum_required(VERSION 3.8)
set(this Base64Tests)

set(Sources src/Base64Tests.cpp)

add_executable(${this} ${Sources})
set_target_properties(${this} PROPERTIES
    FOLDER Tests
)

target_include_directories(${this} PRIVATE ..)

target_link_libraries(${this}
    gtest_main
    Base64
)

add_test(
    NAME ${this}
    COMMAND ${this}
)