//
// Created by Alexey on 13.10.2024.
//

#include "main.h"
#include "gpio.h"
#include "crc.h"
#include "usart.h"

#include "embench++.h"
#include "cyclecount_cm4.h"
#include "proc_min_max_avg.h"
#include "printer_rtt.h"

#include "crc_fut.h"

void dummy0()
{

}

void dummy1()
{
    asm volatile ("NOP");
}

void dummy2()
{
    asm volatile ("NOP");
    asm volatile ("NOP");
}

void dummy3()
{
    asm volatile ("NOP");
    asm volatile ("NOP");
    asm volatile ("NOP");
}

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

    embpp::Benchmark<128, embpp::metrics::core::cm4::CycleCounter, crc32_eth_simple> simple;
    simple.run();
    embpp::proc::MinMaxAvg simpleMinMaxAvg;
    simple.process_results(simpleMinMaxAvg);
    output(simpleMinMaxAvg);

    embpp::Benchmark<128, embpp::metrics::core::cm4::CycleCounter, crc32_eth_lut> lut;
    lut.run();
    embpp::proc::MinMaxAvg lutMinMaxAvg;
    lut.process_results(lutMinMaxAvg);

    embpp::Benchmark<128, embpp::metrics::core::cm4::CycleCounter, crc32_eth_hw> hw;
    hw.run();
    embpp::proc::MinMaxAvg hwMinMaxAvg;
    hw.process_results(hwMinMaxAvg);

    embpp::Benchmark<8, embpp::metrics::core::cm4::CycleCounter, dummy0> dummy0;
    dummy0.run();
    embpp::proc::MinMaxAvg dummy0MMA;
    dummy0.process_results(dummy0MMA);

    embpp::Benchmark<8, embpp::metrics::core::cm4::CycleCounter, dummy1> dummy1;
    dummy1.run();
    embpp::proc::MinMaxAvg dummy1MMA;
    dummy1.process_results(dummy1MMA);

    embpp::Benchmark<8, embpp::metrics::core::cm4::CycleCounter, dummy2> dummy2;
    dummy2.run();
    embpp::proc::MinMaxAvg dummy2MMA;
    dummy2.process_results(dummy2MMA);

    embpp::Benchmark<8, embpp::metrics::core::cm4::CycleCounter, dummy3> dummy3;
    dummy3.run();
    embpp::proc::MinMaxAvg dummy3MMA;
    dummy3.process_results(dummy3MMA);

    for (;;)
    {

    }
}
