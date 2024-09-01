//
// Created by Alexey on 01.09.2024.
//

#ifndef EMBENCH_EMBENCH_H
#define EMBENCH_EMBENCH_H

#include <array>
#include <cstdint>
#include <type_traits>

namespace embpp
{

template <typename T>
concept Metricable = requires(T t) {
    { t.get_metric() } -> std::same_as<std::uint32_t>;
};

template<std::size_t N, Metricable Metric, auto FUT>
class Benchmark {
public:
    Benchmark() {}
    void run()
    {
        for (std::size_t i = 0; i < number; ++i)
        {
            // Hot path start
            std::uint32_t start = metric.get_metric();
            FUT();
            std::uint32_t end = metric.get_metric();
            // Hot path end
            results[i] = end - start;
        }
    }
private:
    Metric metric;
    const std::size_t number {N};
    std::array<std::uint32_t, N> results;
};

}

#endif //EMBENCH_EMBENCH_H
