# Micro-Controller Code: LIGHTSENSOR

## Overview
This embedded C program implements the core logic for a light-sensitive blinds control system on a PIC18F57Q43 microcontroller. It continuously reads analog voltage from a photoresistor, compares the value against a preset threshold, and sends a corresponding digital signal to an external motor controller. The firmware supports both automatic light-based operation and a manual debug mode—toggled by a tactile button—with visual feedback provided through an LED. Designed for reliability and real-time responsiveness, the code integrates ADC readings, state management, and heartbeat monitoring within a simple, maintainable loop. For futher details refer to the [Resources](https://dcalde11.github.io/08-Resources/resources/) page.
```c
/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc.h"
#include <stdint.h>
#include <stdbool.h>

// ===================== CONSTANTS =====================
#define VREF 5.0f
#define PHOTORESISTOR_THRESHOLD_V 2.5f
#define ADC_MAX_COUNTS 4095

#define ADC_THRESHOLD   (uint16_t)((PHOTORESISTOR_THRESHOLD_V / VREF) * ADC_MAX_COUNTS)

// ===================== GLOBALS =====================
volatile uint16_t adcValue = 0;
volatile bool lightDetected = false;
volatile bool debugMode = false;

// ===================== LED CONTROL =====================
void SetDebugLED(bool on) {
    if(on) DEBUG_LED_SetHigh();
    else   DEBUG_LED_SetLow();
}

void FlashLEDPattern(uint8_t count) {
    for(uint8_t i = 0; i < count; i++) {
        SetDebugLED(true);
        __delay_ms(150);
        SetDebugLED(false);
        __delay_ms(150);
    }
}

void IndicateStateChange(bool state) {
    FlashLEDPattern(state ? 1 : 2);
    SetDebugLED(state);
}

// ===================== OUTPUT TO KEITH =====================
void SignalKeith(bool active) {
    if(active) {
        DIGITAL_TO_KEITH_SetHigh();
        SetDebugLED(true);
    } else {
        DIGITAL_TO_KEITH_SetLow();
        SetDebugLED(false);
    }
}

// ===================== BUTTON DEBUG MODE =====================
void HandleDebugButton(void) {
    static bool last = false;
    bool current = DEBUG_BUTTON_GetValue();

    if(current && !last) {
        debugMode = !debugMode;

        FlashLEDPattern(3);   // Indicate debug toggle

        lightDetected = !lightDetected;
        SignalKeith(lightDetected);
        IndicateStateChange(lightDetected);
    }

    last = current;
}

// ===================== AUTO LOGIC =====================
void UpdateSystemStatus(void) {
    bool lightNow = (adcValue > ADC_THRESHOLD);

    if(!debugMode && lightNow != lightDetected) {
        lightDetected = lightNow;
        SignalKeith(lightDetected);
        IndicateStateChange(lightDetected);
    }
}

// ===================== MAIN =====================
int main(void) {

    SYSTEM_Initialize();
    ADC_Initialize();

    FlashLEDPattern(5);   // Boot indicator

    lightDetected = false;
    SignalKeith(false);

    while(1) {

        HandleDebugButton();

        // Read the photoresistor from RA0
        ADC_ChannelSelect(PHOTORESISTOR_IN);
        ADC_ConversionStart();
        while(!ADC_IsConversionDone());
        adcValue = ADC_ConversionResultGet();     // ? correct API

        UpdateSystemStatus();

        // Heartbeat
        static uint32_t hb = 0;
        if(hb++ >= 5000) {
            bool cur = DEBUG_LED_GetValue();
            SetDebugLED(!cur);
            __delay_ms(50);
            SetDebugLED(cur);
            hb = 0;
        }

        __delay_ms(1);
    }

    return 0;
}
```
