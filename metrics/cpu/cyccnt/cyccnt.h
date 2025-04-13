//
// Created by Alexey on 15.09.2024.
//

#ifndef EMBENCH_INCLUDE_METRICS_CORE_CYCCNT_H
#define EMBENCH_INCLUDE_METRICS_CORE_CYCCNT_H

#include "core_cm4.h"

namespace embpp::metrics::core::cyccnt {

class CycleCounter
    {
public:
    inline void setup()
    {
        if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk))
        {
            CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        }
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }

    inline uint32_t get_metric_start() const
    {
        return DWT->CYCCNT;
    }

    inline uint32_t get_metric_end() const
    {
        return DWT->CYCCNT - 2;
    }
};

}  // namespace embpp::metrics::cpu::cyccnt

#endif //EMBENCH_INCLUDE_METRICS_CORE_CYCCNT_H
