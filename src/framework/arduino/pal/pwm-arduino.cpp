/** 
 * @file        pwm-arduino.hpp
 * @brief       Arduino PWM PAL
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include <Arduino.h>
#include "pwm-arduino.hpp"


PWMIno::PWMIno()
{

}

PWMIno::~PWMIno()
{

}

PWMIno::Error_t PWMIno::init()
{
    TCCR0A = (1<<WGM01);        // Set timer in CTC - Mode
}

PWMIno::Error_t PWMIno::deinit()
{
    TCCR0A = (0<<WGM01);        // Set timer in back to default mode
}

PWMIno::Error_t PWMIno::config(uint32_t freq, float duty)
{
    float period = 0;

    period = 1/freq;        // period in second
    


}

PWMIno::Error_t PWMIno::enable()
{

}

PWMIno::Error_t PWMIno::disable()
{
    
}