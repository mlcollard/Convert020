# @file CMakeLists.txt
# 
# CMake files for the convert example

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.28)

# project info
project(convert)

# convert
add_executable(convert)
target_sources(convert PRIVATE convert.cpp)
target_compile_features(convert PRIVATE cxx_std_17)
target_compile_options(convert PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall>
)

# Demo run command
add_custom_target(demo
        COMMENT "Run demo"
        COMMAND echo convert --lower "ABCD"
        COMMAND $<TARGET_FILE:convert> --lower "ABCD"
        COMMAND echo convert --upper "ABCD"
        COMMAND $<TARGET_FILE:convert> --upper "abcd"
        COMMAND echo convert --invalid "ABCD"
        COMMAND $<TARGET_FILE:convert> --invalid "ABCD" || true
        DEPENDS convert
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
