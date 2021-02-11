/** 
 * @file        pwm-arduino.hpp
 * @brief       Arduino PWM PAL
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef PWM_ARDUINO_HPP_
#define PWM_ARDUINO_HPP_

#include "../../../pal/pwm.hpp"

/**
 * @addtogroup arduinoPal
 * @{
 */

class PWMIno: virtual public PWM
{
    public:
        PWMIno          ();
        ~PWMIno         ();
        Error_t init    ();
        Error_t deinit  ();        
        Error_t config  (uint32_t freq, float duty);
        Error_t enable  ();
        Error_t disable ();

    private:
    /* add some arduino stuff */
};
/** @} */

#endif /** PWM_ARDUINO_HPP_ **/