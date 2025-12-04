 
//Donovan Calderon
//Code For Light Sensor
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc.h"
#include <stdint.h>
#include <stdbool.h>


#define VREF 5.0f
#define PHOTORESISTOR_THRESHOLD_V 2.5f
#define ADC_MAX_COUNTS 4095

#define ADC_THRESHOLD   (uint16_t)((PHOTORESISTOR_THRESHOLD_V / VREF) * ADC_MAX_COUNTS)

volatile uint16_t adcValue = 0;
volatile bool lightDetected = false;
volatile bool debugMode = false;


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

// OUTPUT TO KEITH 
void SignalKeith(bool active) {
    if(active) {
        DIGITAL_TO_KEITH_SetHigh();
        SetDebugLED(true);
    } else {
        DIGITAL_TO_KEITH_SetLow();
        SetDebugLED(false);
    }
}

//  BUTTON DEBUG MODE 
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

//
void UpdateSystemStatus(void) {
    bool lightNow = (adcValue > ADC_THRESHOLD);

    if(!debugMode && lightNow != lightDetected) {
        lightDetected = lightNow;
        SignalKeith(lightDetected);
        IndicateStateChange(lightDetected);
    }
}


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
