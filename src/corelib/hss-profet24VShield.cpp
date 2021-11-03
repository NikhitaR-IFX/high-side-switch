/** 
 * @file        hss-profet24VShield.cpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-profet24VShield.hpp"

using namespace hss;

/**
 * @brief   Profet 24V BTT6030 Shield constructor
 */
Profet24VBTTShield::Profet24VBTTShield(Hss *hss0, Hss *hss1, Hss *hss2, Hss *hss3, Hss *hss4)
{

}

/**
 * @brief   Destructor of the Profet 24V Shield
 * 
 */
Profet24VBTTShield::~Profet24VBTTShield()
{

}

/**
 * @brief   Initialize all necessary objects of the Profet 24V Shield
 * 
 * This function initializes all necessary objects of the Profet 24V Shield.
 * It returns an error code to see if everything was initialized correctly.
 * 
 * @return  Error_t
 */
Error_t Profet24VBTTShield::init()
{
    hss0->init();
    hss1->init();
    hss2->init();
    hss3->init();
    hss4->init();

    timer->init();

    return OK;
}

/**
 * @brief   Deinitialize all necessary objects of the Profet 24V Shield
 * 
 * This function deinitializes all necessary objects of the Profet 24V Shield.
 * It retruns an error code to see if everything was deinitialized correctly.
 * 
 * @return Profet24VShield::Error_t
 */
Error_t Profet24VBTTShield::deinit()
{

    hss0->deinit();
    hss1->deinit();
    hss2->deinit();
    hss3->deinit();
    hss4->deinit();

    timer->deinit();

    return OK;
}

/**
 * @brief Switch on the selected High-Side-Switch
 * 
 * This function turns on the desired High-Side-Switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned on (0-2). Possible values:
 *                  Switch 0    -   Profet 0 (BTT6030 - 2 channel)
 *                  Switch 1    -   Profet 1 (BTT6030 - 2 channel)
 *                  Switch 2    -   Profet 2 (Single channel)
 * @param[in]   ch  Channel no. in the switch. Possible values:
 *                  CHANNEL0    -   Channel 0
 *                  CHANNEL1    -   Channel 1
 * 
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchHxOn(uint8_t x)
{
    switch(x)
    {
        case 0:
            hss0->enable();
            break;

        case 1:
            hss1->enable();
            break;
        
        case 2:
            hss2->enable();
            break;

        case 3:
            hss3->enable();
            break;
        
        case 4:
            hss4->enable();
            break;
    }
    return OK;
}

/**
 * @brief   Switch off the selected High-Side-Switch
 * 
 * This function turns off the desired High-Side-Switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned on (0-2). Possible values:
 *                  Switch 0    -   Profet 0 (BTT6030 - 2 channel)
 *                  Switch 1    -   Profet 1 (BTT6030 - 2 channel)
 *                  Switch 2    -   Profet 2 (Single channel)
 * @param[in]   ch  Channel no. in the switch. Possible values:
 *                  CHANNEL0    -   Channel 0
 *                  CHANNEL1    -   Channel 1
 * 
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchHxOff(uint8_t x)
{
    switch(x)
    {
        case 0:
            hss0->disable();
            break;

        case 1:
            hss1->disable();
            break;
        
        case 2:
            hss2->disable();
            break;

        case 3:
            hss3->disable();
            break;
        
        case 4:
            hss4->disable();
            break;
    }
    return OK;
}

/**
 * @brief Turn on the selected High-Side-Switches
 * 
 * This function is used to enable multiple switches at once.
 * 
 * @param[in] h0_0    Enable the Switch 0 - channel 0 if h0_0 = true
 * @param[in] h1_0    Enable the Switch 0 - channel 1 if h1_0 = true   
 * @param[in] h0_1    Enable the Switch 1 - channel 0 if h0_1 = true
 * @param[in] h1_1    Enable the Switch 1 - channel 1 if h1_1 = true
 * @param[in] h2      Enable the Switch 2 - channel 0 if h2   = true
 * 
 * @return            Error_t 
 */
Error_t Profet24VBTTShield::switchesHxOn(bool h0_0 = NULL, bool h1_0 = NULL, bool h0_1 = NULL, bool h1_1 = NULL, bool h2 = NULL)
{
    if(h0_0 == true){
        hss0->enable();
    }

    if(h1_0 == true){
        hss1->enable();
    }

    if(h0_1 == true){
        hss2->enable();
    }

    if(h1_1 == true){
        hss3->enable();
    }

    if(h2 == true){
        hss4->enable();
    }
    return OK;
}

/**
 * @brief Turn off the selected High-Side-Switches
 * 
 * This function is used to disable multiple switches at once.
 * 
 * @param[in] h0_0    Disable the Switch 0 - channel 0 if h0_0 = true
 * @param[in] h1_0    Disable the Switch 0 - channel 1 if h1_0 = true   
 * @param[in] h0_1    Disable the Switch 1 - channel 0 if h0_1 = true
 * @param[in] h1_1    Disable the Switch 1 - channel 1 if h1_1 = true
 * @param[in] h2      Disable the Switch 2 - channel 0 if h2   = true
 * 
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchesHxOff(bool h0_0 = NULL, bool h1_0 = NULL, bool h0_1 = NULL, bool h1_1 = NULL, bool h2 = NULL)
{
    if(h0_0 == true){
        hss0->disable();
    }

    if(h1_0 == true){
        hss1->disable();
    }

    if(h0_1 == true){
        hss2->disable();
    }

    if(h1_1 == true){
        hss3->disable();
    }

    if(h2 == true){
        hss4->disable();
    }
    return OK;
}

/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function:
 *      - Enables diagnosis for the channel
 *      - Selects the channel through dsel
 *      - Calls function to get the calibrated sensed current value on chosen channel
 *      - Disables diagnosis pin post operation completion
 * 
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 * @return          The calibrated value of the current in [A]      
 */
float Profet24VBTTShield::readIsx(uint8_t x)
{
    float iisCalib;

    switch (x)
    {
        case 0:
            hss0->enableDiag();
            iisCalib = getIs(x);
            hss0->disableDiag();
            break;
        
        case 1:
            hss1->enableDiag();
            iisCalib = getIs(x);
            hss1->disableDiag();
            break;

        case 2:
            hss2->enableDiag();
            iisCalib = getIs(x);
            hss2->disableDiag();
            break;

        case 3:
            hss3->enableDiag();
            iisCalib = getIs(x);
            hss3->disableDiag();
            break;

        case 4:
            hss4->enableDiag();
            iisCalib = getIs(x);
            hss4->disableDiag();
            break;
    }

    return iisCalib;
}

/**
 * @brief   Get Is value
 * 
 * This function:
 *  - Reads the IS pin of the chosen High-Side-Switch to get ADC stored value
 *  - Converts raw ADC value to voltage and in-turn to sensed current
 *  - Performs current calibration
 * 
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 * 
 * @param[out]  iisCalib    Calibrated sensed current value
 * 
 * @return          Error_t     
 */
float  Profet24VBTTShield::getIs(uint8_t x)
{
    uint16_t adcResult;
    float iis_A, vis_V, iisCalib;

    switch(x)
    {
        case 0:
            adcResult = hss0->readIs(CHANNEL0);
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss0->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            break;

        case 1:
            adcResult = hss1->readIs(CHANNEL1);
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss1->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            break;
  
        case 2:
            adcResult = hss2->readIs(CHANNEL0);
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss2->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            break;

        case 3:
            adcResult = hss3->readIs(CHANNEL1);
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss3->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            break;
            
        case 4:
            adcResult = hss2->readIs();
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss4->calibrateIs(iis_A,BTT6020.kilis,BTT6020.ampsOffset, BTT6020.ampsGain);
            break;
    }
    return OK;
}

/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose perform diagnosis.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x           Number of the Switch the should be turned on (0-4). Possible values:
 *                          Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                          Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                          Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                          Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                          Switch 4    -   Profet 2 (Single channel)
 *   
 * @return      DiagStatus_t
 * 
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load     
 */
DiagStatus_t Profet24VBTTShield::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;
    float iisFault = 0.006;
    float iisOl_btt6030 =  0.000005;
    float iisOl_btt6020 =  0.000004;

    switch(x)
    {
        case 0:
            if(hss0->getSwitchStatus() == POWER_ON){
                diagStatus = hss0->diagRead(getIs(0), iisFault, iisOl_btt6030, BTT6030.kilis, CHANNEL0);
            }
            hss0->disableDiag();
            break;

        case 1:
            if(hss1->getSwitchStatus() == POWER_ON){
                diagStatus = hss1->diagRead(getIs(1), iisFault, iisOl_btt6030, BTT6030.kilis, CHANNEL1);
            }
            hss1->disableDiag();
            break;

        case 2:
            if(hss2->getSwitchStatus() == POWER_ON){
                diagStatus = hss2->diagRead(getIs(2), iisFault, iisOl_btt6030, BTT6030.kilis, CHANNEL0);
            }
            hss2->disableDiag();
            break;

        case 3:
            if(hss3->getSwitchStatus() == POWER_ON){
                diagStatus = hss3->diagRead(getIs(3), iisFault, iisOl_btt6030, BTT6030.kilis, CHANNEL1);
            }
            hss3->disableDiag();
            break;

        case 4:
            if(hss4->getSwitchStatus() == POWER_ON){
                diagStatus = hss4->diagRead(getIs(4), iisFault, iisOl_btt6020, BTT6020.kilis);
            }
            hss4->disableDiag();
            break;
    }
    return diagStatus;
}

