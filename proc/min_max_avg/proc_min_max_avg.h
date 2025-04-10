//
// Created by Alexey on 02.11.2024.
//

#ifndef EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H
#define EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H

#include <cstdint>
#include <span>

namespace embpp::proc
{
class MinMaxAvg
{
private:
    uint32_t min {0};
    uint32_t max {0};
    uint32_t avg {0};
    char text[128] {};
public:
    void process(std::span<const std::uint32_t> results);
    const char* c_str() const;
};
}

#endif //EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H
