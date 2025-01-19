//
// Created by Alexey on 19.01.2025.
//

#include <string_view>

#include "printer_rtt.h"

#include "segger_rtt/RTT/SEGGER_RTT.h"

void embpp::print::RTT::print(std::string_view text)
{
    SEGGER_RTT_printf(0, text.data());
}
