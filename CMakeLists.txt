cmake_minimum_required(VERSION 3.22)

project(embench++ C CXX ASM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/
)
target_link_libraries(${PROJECT_NAME} INTERFACE
        embpp_core
        cortexm4_cyccnt
        printer_rtt
        proc_min_max_avg)

add_subdirectory(core)
add_subdirectory(metrics)
add_subdirectory(printers)
add_subdirectory(proc)
