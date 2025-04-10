# embench++

**embench++** is a modern, modular, and hardware-independent benchmarking framework for embedded systems, designed with C++20 for maximum flexibility and zero-runtime overhead.

This framework enables developers to evaluate performance-critical functions across various environments and configurations. It supports plugin-like extensions for metric collection, data processing, and result output — allowing benchmarking on platforms ranging from bare-metal microcontrollers to more complex setups.

## Features
- **Modular architecture** with clear separation of concerns
- **Header-only core** with optional modules (metrics, processors, printers)
- **Zero dynamic allocation** for real-time embedded compatibility
- **C++20 concepts** for compile-time validation
- **Optional Docker-based development setup** for fast onboarding and reproducibility

## Repository Structure
```
embench-plus-plus
├── core                        # Core benchmarking logic and concepts
├── docker                      # Dockerfile and related container setup
├── docs                        # Documentation and output folders
│   ├── html
│   │   └── search
│   └── latex
├── examples
│   └── ARM
│       └── NUCLEO-F411RE
│           └── crc_test       # Example benchmark for STM32F411RE
├── metrics
│   └── cpu
│       └── cyccnt             # Cortex-M cycle counter metric
├── printers
│   └── rtt
│       └── segger_rtt         # SEGGER RTT-based output
│           ├── Config
│           ├── RTT
│           └── Syscalls
└── proc
    └── min_max_avg            # Result processors (e.g., Min/Max/Avg)
```

## Getting Started
See [examples/ARM/NUCLEO-F411RE/crc_test](./examples/ARM/NUCLEO-F411RE/crc_test) for a working example, including:
- STM32Cube HAL-based hardware initialization
- Integration with RTT for output
- Measurement using DWT cycle counter

You can build this example locally or in a Docker-based environment provided in the repository.

## Development Environment
This project supports VSCode Dev Containers using a Docker-based setup. It ensures:
- Consistent toolchain across platforms
- Easy onboarding with zero manual dependency setup

To use:
1. Open `examples/ARM/NUCLEO-F411RE/crc_test` in VSCode
2. Reopen in Dev Container when prompted

## License
This project is licensed under the BSD-3-Clause License.

## Contribution
Contributions, ideas, and extensions are very welcome!
Please open an issue or a pull request to get involved.

