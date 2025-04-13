# CRC Benchmark Example (NUCLEO-F411RE)

This folder contains a minimal working example demonstrating the use of **embench++** on the STM32F411RE development board using STM32Cube HAL, DWT-based cycle counting, and SEGGER RTT output.

## Features
- Benchmarks a simple CRC32 Ethernet function
- Uses DWT (Data Watchpoint and Trace) cycle counter for precise measurement
- Outputs results via SEGGER RTT to terminal
- Compatible with `embench++` modular architecture

## Folder Structure
```
crc_test/
├── Core/Inc                  # User and STM32 HAL headers
├── Core/Src                  # HAL init and main logic
├── Drivers/                  # STM32 HAL drivers (CMSIS, device-specific)
├── FUTs/                     # Functions-under-test (e.g., crc32_eth_simple)
├── cmake/                    # CMake build helpers (toolchain, startup code)
├── .devcontainer/            # VSCode Dev Container configuration
├── CMakeLists.txt            # Project build script
└── main.cpp                  # Benchmark entry point
```

## Getting Started

## Prerequisites
### Common
- SEGGER J-Link software (SEGGER RTT Viewer
- On-board ST-LINK reprogrammed to J-Link firmware

### Option 1: Native Build
- CMake >= 3.22
- Ninja
- GNU Arm Embedded Toolchain (tested on 10.3-2021.10)

bash:
```bash
cd crc_test
mkdir cmake-build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-gcc.cmake . -B cmake-build
cmake --build cmake-build/
```

### Option 2: Dev Container (Recommended)
- Docker
- Visual Studio Code with Remote Containers extension (optional)

VSCode:
1. Open this folder in VSCode
2. When prompted, reopen in container
3. Select build type: Release or RelWithDebug
4. Use CMake Tools to build

OR

bash:
```bash
cd embench-plus-plus
docker build -t embpp docker/
docker run --rm -it -v $(pwd):/workspace -w /workspace embpp bash
[in container]
mkdir cmake-build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake . -B cmake-build
cmake --build cmake-build/
```

## Usage
1. Connect the STM32 board
2. Flash the firmware using VSCode tasks, STM32CubeProgrammer, JLink, or OpenOCD
3. Open SEGGER RTT Viewer
4. Observe output metrics printed by `embench++`

## License
MIT

---
Part of the [embench++](https://github.com/Proger007/embench-plus-plus) project.
