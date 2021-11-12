/**
 * @file        hss-bts500xxShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include "hss-shield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"
#include "hss.hpp"

using namespace hss;

class Bts500xxShield : public HssShield 
{
    public:
                    Bts500xxShield(Hss *hsw1);
                    ~Bts500xxShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x);
        Error_t         switchHxOff(uint8_t x);
        DiagStatus_t    readDiagx(uint8_t x=1);   // TODO: To be implemented in next ticket
        DiagStatus_t    diagnosisOff(float currentOn, float currentOff);
        float           readIsx(uint8_t x=1);
        float           readVss();
        bool            analogReadButton();
    
    protected:
        ExponentialFilter *filterVbat;

        GPIO *led1;
        GPIO *led2;

        Hss *hss1;

        Timer *timer;
        
        AnalogDigitalConverter *pushButtonAnalog;
        AnalogDigitalConverter *vBat;   

        BtsVariants_t          *btsVariant;
        const float vBatGain = 1.0;
        const float vBatOffset = 0.0;

        float  getIs(uint8_t x=1);
};