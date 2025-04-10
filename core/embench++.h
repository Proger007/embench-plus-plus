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

#include "concepts.h"

namespace embpp
{

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
class Benchmark
{
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
            std::uint32_t start = metric.get_metric_start();
            FUT();
            std::uint32_t end = metric.get_metric_end();
            // Hot path end
            results[i] = end - start;
        }
    }

    /**
     * @brief Processes the results for the specified output
     *
     * Processes the results obtained from the benchmark run to prepare user defined output.
     * This can include calculating simple statistics (MinMaxAvg, MeanStdDev, Histogram etc), prettify raw data,
     * or performing custom calculations.
     */
    template <ResultsProcessor... Processors>
    void process_results(Processors&... proc)
    {
        (proc.process(results), ...);
    }
private:
    Metric metric; ///< Instance of the metric used to measure performance.
    const std::size_t number{N}; ///< Number of iterations to run the benchmark.
    std::array<std::uint32_t, N> results; ///< Array to store the results of each benchmark run.
};

}

#endif //EMBENCH_EMBENCH_H
