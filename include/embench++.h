//
// Created by Alexey on 01.09.2024.
//

/**
 * @file
 * @brief Header file defining the benchmarking framework for embedded systems.
 *
 * This header provides the `Benchmark` class template for running benchmarks
 * on functions, with minimal overhead using a metric system.
 * The framework uses template metaprogramming to inline the function under test (FUT)
 * and optimize the hot path.
 */

#ifndef EMBENCH_EMBENCH_H
#define EMBENCH_EMBENCH_H

#include <array>
#include <cstdint>
#include <type_traits>

namespace embpp
{

/**
 * @brief Concept to define a metric for benchmarking.
 *
 * The `Metricable` concept ensures that the type passed as a Metric
 * implements both the `get_metric()` and `setup()` methods.
 * - `get_metric()` should return a 32-bit unsigned integer representing the metric value (e.g., cycle count).
 * - `setup()` should initialize or reset the metric system before the benchmark starts.
 */
template <typename T>
concept Metricable = requires(T t) {
    { t.get_metric() } -> std::same_as<std::uint32_t>; ///< Metric should return a value of used metric.
    { t.setup() }; ///< Setup should initialize or reset the metric, can be empty.
};

/**
 * @brief Class template for benchmarking functions.
 *
 * The `Benchmark` class runs a function under test (FUT) multiple times
 * while measuring its performance using the provided metric. The metric setup is done
 * before the benchmark starts, and the results are stored in an array.
 *
 * @tparam N The number of iterations for the benchmark.
 * @tparam Metric A type satisfying the `Metricable` concept.
 * @tparam FUT The function under test (FUT), passed as a template parameter.
 */
template<std::size_t N, Metricable Metric, auto FUT>
class Benchmark {
public:
    /**
     * @brief Default constructor.
     *
     * Constructs a `Benchmark` object. The actual benchmarking is done in the `run()` method.
     */
    Benchmark() = default;

    /**
     * @brief Runs the benchmark for the specified function.
     *
     * The `run()` method first calls the `setup()` method of the metric to initialize
     * the metric system. It then executes the function under test (FUT) `N` times, recording
     * the start and end metric values around each execution to calculate the duration.
     *
     * The results are stored in the `results` array.
     */
    void run()
    {
        metric.setup();
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
    Metric metric; ///< Instance of the metric used to measure performance.
    const std::size_t number{N}; ///< Number of iterations to run the benchmark.
    std::array<std::uint32_t, N> results; ///< Array to store the results of each benchmark run.
};

}

#endif //EMBENCH_EMBENCH_H
