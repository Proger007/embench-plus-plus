//
// Created by Alexey on 13.10.2024.
//

#include "main.h"
#include "gpio.h"
#include "crc.h"
#include "usart.h"

#include "embench++.h"
#include "cyccnt.h"
#include "proc_min_max_avg.h"
#include "printer_rtt.h"

#include "crc_fut.h"


void bsp_init()
{
    SystemClock_Config();
    MX_GPIO_Init();
    MX_CRC_Init();
    MX_USART2_UART_Init();
}

[[noreturn]]
int main()
{
    bsp_init();
    embpp::print::Printer<embpp::print::RTT> output;

    embpp::Benchmark<128, embpp::metrics::core::cyccnt::CycleCounter, crc32_eth_simple> simple;
    simple.run();
    embpp::proc::MinMaxAvg simpleMinMaxAvg;
    simple.process_results(simpleMinMaxAvg);
    output(simpleMinMaxAvg.c_str());

    embpp::Benchmark<128, embpp::metrics::core::cyccnt::CycleCounter, crc32_eth_lut> lut;
    lut.run();
    embpp::proc::MinMaxAvg lutMinMaxAvg;
    lut.process_results(lutMinMaxAvg);
    output(lutMinMaxAvg.c_str());

    embpp::Benchmark<128, embpp::metrics::core::cyccnt::CycleCounter, crc32_eth_hw> hw;
    hw.run();
    embpp::proc::MinMaxAvg hwMinMaxAvg;
    hw.process_results(hwMinMaxAvg);
    output(hwMinMaxAvg.c_str());

    for (;;)
    {

    }
}
