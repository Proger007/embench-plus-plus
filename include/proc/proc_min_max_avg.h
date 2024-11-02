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
    uint32_t min;
    uint32_t max;
    uint32_t avg;
public:
    void process(std::span<const std::uint32_t> results);
};
}

#endif //EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H
