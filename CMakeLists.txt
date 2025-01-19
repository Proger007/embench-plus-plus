cmake_minimum_required(VERSION 3.15)

project(embench++ C CXX ASM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/metrics/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/metrics/core
        ${CMAKE_CURRENT_SOURCE_DIR}/include/proc/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/printers/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/printers/rtt/segger_rtt/Config
)
