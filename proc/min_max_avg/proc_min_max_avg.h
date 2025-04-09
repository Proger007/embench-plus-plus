//
// Created by Alexey on 02.11.2024.
//

#ifndef EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H
#define EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H

#include <cstdint>
#include <span>
//#include <string_view>

namespace embpp::proc
{
class MinMaxAvg
{
private:
    uint32_t min;
    uint32_t max;
    uint32_t avg;
    char text[128];
public:
    void process(std::span<const std::uint32_t> results);
    operator char*();
};
}

#endif //EMBENCH_INCLUDE_PROC_PROC_MIN_MAX_AVG_H
