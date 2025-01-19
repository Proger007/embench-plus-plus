//
// Created by Alexey on 19.01.2025.
//

#ifndef EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H
#define EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H

#include "printer.h"

namespace embpp::print
{
class RTT
{
public:
    static RTT& instance()
    {
        static RTT instance_; // Singleton instance
        return instance_;
    }

    // Prevent copy/move semantics
    RTT(const RTT &) = delete;
    RTT &
    operator=(const RTT &) = delete;
    RTT(RTT &&) = delete;
    RTT &
    operator=(RTT &&) = delete;

    void
    print(std::string_view text);

private:
    RTT() = default;
};

}

#endif //EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H
