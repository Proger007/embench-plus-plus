cmake_minimum_required(VERSION 3.15)

add_library(embpp_core INTERFACE)
target_include_directories(embpp_core INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/
)
