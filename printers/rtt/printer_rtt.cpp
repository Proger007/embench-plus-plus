//
// Created by Alexey on 19.01.2025.
//

#include "printer_rtt.h"

#include "segger_rtt/RTT/SEGGER_RTT.h"

void embpp::print::RTT::print(const char *text)
{
    SEGGER_RTT_printf(0, text);
}
