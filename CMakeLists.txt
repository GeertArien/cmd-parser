cmake_minimum_required(VERSION 3.12)
project(cmd-parser)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURCES
        "${SRC_DIR}/Parser.cpp"
        "${SRC_DIR}/Argument.cpp")

# Executable definition and properties
add_library(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
