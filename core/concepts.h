//
// Created by Alexey on 08.04.2025.
//

#ifndef EMBENCH_CORE_CONCEPTS_H
#define EMBENCH_CORE_CONCEPTS_H

#include <cstdint>
#include <span>
#include <type_traits>

namespace embpp
{

/**
 * @brief Concept to define a metric for benchmarking.
 *
 * The `Metricable` concept ensures that the type passed as a Metric
 * implements the `get_metric_start()`, `get_metric_end()` and `setup()` methods.
 * - `get_metric_start()` should return a 32-bit unsigned integer representing the metric start value (e.g., cycle count).
 * - `get_metric_end()` should return a 32-bit unsigned integer representing the metric end value (e.g., cycle count - 1).
 * - `setup()` should initialize or reset the metric system before the benchmark starts.
 */
template <typename T>
concept Metricable = requires(T t)
{
{ t.get_metric_start() } -> std::same_as<std::uint32_t>; ///< Metric should return a value of used metric.
{ t.get_metric_start() }; ///< Metric should return a value of used metric.
{ t.get_metric_end() } -> std::same_as<std::uint32_t>; ///< Metric should return a value of used metric.
{ t.setup() }; ///< Setup should initialize or reset the metric, can be empty.
};

/**
 * @brief Concept to define a Processor to process the results after benchmark run.
 * @tparam T - Class implementing process method
 */
template <typename T>
concept ResultsProcessor = requires(T t, std::span<const std::uint32_t> results)
{
{ t.process(results) } -> std::same_as<void>; ///< Processor should take a uint32_t sequence
{ t.c_str() } -> std::same_as<const char*>; ///< Should be convertible to char*
};

/**
 *
 * @brief Concept to define a Printer implementation to output the results after processing
 * @tparam T - Class implementing print method
 */
template <typename T>
concept PrinterImpl = requires(T t, char *s) {
{ T::instance() } -> std::same_as<T&>;
{ T::instance().print(s) } -> std::same_as<void>;
};

namespace print
{
template<PrinterImpl PrinterImpl_>
class Printer
{
public:
    void
    operator()(const char *text)
    {
        PrinterImpl_::instance().print(text);
    }
};

} // namespace print

}

#endif //EMBENCH_CORE_CONCEPTS_H
