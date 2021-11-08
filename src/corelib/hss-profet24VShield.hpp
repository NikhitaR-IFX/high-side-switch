/**
 * @file        hss-profet24VShield.hpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_PROFET24VSHIELD_HPP_
#define HSS_PROFET24VSHIELD_HPP_

#include "hss-arduino.hpp"
#include "hss-shield.hpp"
#include "hss.hpp"
#include "variants.hpp"

using namespace hss;

class Profet24VBTTShield : HssShield
{
    public:

                        Profet24VBTTShield(Hss *hsw0, Hss *hsw1, Hss *hsw2, Hss *hsw3, Hss *hsw4);
                        ~Profet24VBTTShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn   (uint8_t x);
        Error_t         switchHxOff  (uint8_t x);
        Error_t         switchesHxOn (bool h1_0 = NULL, bool h2_0 = NULL, bool h1_1 = NULL, bool h2_1 = NULL, bool h2 = NULL);
        Error_t         switchesHxOff(bool h1_0 = NULL, bool h2_0 = NULL, bool h1_1 = NULL, bool h2_1 = NULL, bool h2 = NULL);
        DiagStatus_t    readDiagx    (uint8_t x);
        float           readIsx      (uint8_t x);
    
    protected:

        Hss *hss0;
        Hss *hss1;
        Hss *hss2;
        Hss *hss3;
        Hss *hss4;

        Timer *timer;
        
        float           getIs(uint8_t x);

    private:
    
        const uint16_t ris_Ohm = 1200;
        const float iisFault      = 0.006;
        const float iisOl_btt6030 =  0.000005;
        const float iisOl_btt6020 =  0.000004;

        
};

#endif /**HSS_PROFET24VSHIELD_HPP_*/