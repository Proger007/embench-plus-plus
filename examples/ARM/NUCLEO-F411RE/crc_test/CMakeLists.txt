cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
project(crc_test_f411 C CXX ASM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME crc_test)

# Include toolchain file
# include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_compile_options(-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16
        -mfloat-abi=hard -ffunction-sections -fdata-sections -fmessage-length=0 -fsigned-char -fshort-enums
        -fno-exceptions -fno-rtti
        -fomit-frame-pointer -O2 -g --specs=nosys.specs)

add_link_options(-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Xlinker -Map=${PROJECT_NAME}.map)
add_link_options(-T${CMAKE_CURRENT_LIST_DIR}/STM32F411RETx_FLASH.ld)

# Core project settings
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

add_subdirectory(${CMAKE_SOURCE_DIR}/../../../../
        ${CMAKE_BINARY_DIR}/embench)
add_subdirectory(${CMAKE_SOURCE_DIR}/FUTs/)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        main.cpp
        ${CMAKE_SOURCE_DIR}/../../../../src/proc/proc_min_max_avg.cpp
        ${CMAKE_SOURCE_DIR}/../../../../src/printers/rtt/printer_rtt.cpp
        ${CMAKE_SOURCE_DIR}/../../../../src/printers/rtt/segger_rtt/RTT/SEGGER_RTT.c
        ${CMAKE_SOURCE_DIR}/../../../../src/printers/rtt/segger_rtt/RTT/SEGGER_RTT_printf.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
        stm32cubemx
        embench++
        stm32_crc_fut
        # Add user defined libraries
)
