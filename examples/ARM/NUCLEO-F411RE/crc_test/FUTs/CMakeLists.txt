cmake_minimum_required(VERSION 3.22)

project(stm32_crc_fut C ASM)

add_library(${PROJECT_NAME} STATIC crc_fut.c)
target_link_libraries(${PROJECT_NAME} stm32cubemx)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
