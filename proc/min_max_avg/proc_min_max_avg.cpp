//
// Created by Alexey on 02.11.2024.
//

#include "proc_min_max_avg.h"

#include <algorithm>
#include <numeric>
#include <cstdint>
#include <cstdio>
#include <span>

void embpp::proc::MinMaxAvg::process(std::span<const uint32_t> results)
{
    auto [p_min, p_max] = std::minmax_element(begin(results), end(results));
    min = *p_min;
    max = *p_max;
    uint64_t sum = std::accumulate(begin(results), end(results), 0);
    avg = sum / results.size();
    snprintf(text, sizeof(text), "Max = %lu, min = %lu, avg = %lu", max, min, avg);
}

const char* embpp::proc::MinMaxAvg::c_str() const
{
    return this->text;
}
