cmake_minimum_required(VERSION 3.15)

add_library(cortexm4_cyccnt INTERFACE)
target_include_directories(cortexm4_cyccnt INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/
)
target_link_libraries(cortexm4_cyccnt INTERFACE embpp_core)
