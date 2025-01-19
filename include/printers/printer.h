//
// Created by Alexey on 10.11.2024.
//

#ifndef EMBENCH_INCLUDE_PRINTERS_PRINTER_H
#define EMBENCH_INCLUDE_PRINTERS_PRINTER_H

#include <string_view>

/**
 * @brief Concept to define a Printer implementation to output the results after processing
 * @tparam T - Class implementing print method
 */
template <typename T>
concept PrinterImpl = requires(T t, std::string_view s) {
    { T::instance() } -> std::same_as<T&>;
    { T::instance().print(s) } -> std::same_as<void>;
};

namespace embpp::print
{
template <PrinterImpl PrinterImpl_>
class Printer
{
public:
    void operator()(std::string_view text)
    {
        PrinterImpl_::instance().print(text);
    }
};

}

#endif //EMBENCH_INCLUDE_PRINTERS_PRINTER_H
