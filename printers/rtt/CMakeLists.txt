cmake_minimum_required(VERSION 3.15)

add_library(printer_rtt STATIC 
		printer_rtt.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/segger_rtt/RTT/SEGGER_RTT.c
		${CMAKE_CURRENT_SOURCE_DIR}/segger_rtt/RTT/SEGGER_RTT_printf.c)
target_include_directories(printer_rtt PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/segger_rtt/
        ${CMAKE_CURRENT_SOURCE_DIR}/segger_rtt/Config
        ${CMAKE_CURRENT_SOURCE_DIR}/segger_rtt/RTT
)
target_link_libraries(printer_rtt INTERFACE embpp_core)
