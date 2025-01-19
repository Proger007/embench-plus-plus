//
// Created by Alexey on 12.10.2024.
//

#ifndef EMBENCH_EXAMPLES_FUTS_CRC_H
#define EMBENCH_EXAMPLES_FUTS_CRC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t crc32_eth_simple(void);
//uint32_t crc32_eth_bitwise(void);
uint32_t crc32_eth_lut(void);
uint32_t crc32_eth_hw(void);

#ifdef __cplusplus
}
#endif

#endif //EMBENCH_EXAMPLES_FUTS_CRC_H
