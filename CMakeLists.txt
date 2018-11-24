cmake_minimum_required(VERSION 3.12)
project(CMD-Parser)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCES
        "${SRC_DIR}/CMDParser.h"
        "${SRC_DIR}/CMDParser.cpp"
        "${SRC_DIR}/CMDArgument.h"
        "${SRC_DIR}/CMDArgument.cpp")

# Executable definition and properties
add_library(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
