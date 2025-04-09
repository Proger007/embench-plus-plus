cmake_minimum_required(VERSION 3.15)

add_library(proc_min_max_avg STATIC
		proc_min_max_avg.cpp)
target_include_directories(proc_min_max_avg PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
)
target_link_libraries(proc_min_max_avg INTERFACE embpp_core)
