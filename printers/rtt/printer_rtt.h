//
// Created by Alexey on 19.01.2025.
//

#ifndef EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H
#define EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H

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

    RTT(const RTT &) = delete;
    RTT &operator=(const RTT &) = delete;
    RTT(RTT &&) = delete;
    RTT &operator=(RTT &&) = delete;

    void print(const char *text);

private:
    RTT() = default;
};

}

#endif //EMBENCH_INCLUDE_PRINTERS_PRINTER_RTT_H
