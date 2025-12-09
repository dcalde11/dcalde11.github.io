# MPLab Project Documentation - LIGHTSENSOR

## 1. Project Overview & Objectives - LIGHTSENSOR

**Objective:**  
This document details the implementation of the **Light Sensor Subsystem (LIGHTSENSOR)** using a PIC18F57Q43 microcontroller. This subsystem detects ambient light and communicates with Keith Payne's subsystem via a digital output.

**Software Concept:**
- **Light ON** → Send HIGH signal to Keith
- **Light OFF** → Send LOW signal to Keith

## 2. MCC Configuration Summary - LIGHTSENSOR

**Drivers Configuration:**  
- **ADC Driver:** Enabled (only driver used in this project)

**Pin Configuration with Custom Names:**

| Location | Pin Name | Function        | Direction | Custom Name        | Analog | Pull-Up |
|----------|----------|----------------|-----------|------------------|--------|---------|
| RA0      | ADC      | Analog Input   | input     | PHOTORESISTOR_IN | yes    | no      |
| RA2      | GPIO     | Digital Output | output    | DIGITAL_TO_KEITH | no     | no      |
| RD1      | GPIO     | LED Output     | output    | DEBUG_LED        | no     | no      |
| RD2      | GPIO     | Button Input   | input     | DEBUG_BUTTON     | no     | yes     |

### 3. Software Architecture – LIGHTSENSOR
 #### 3.1 Control Logic
 - **Read PHOTORESISTOR_IN (RA0)**
 - **Compare ADC value to Threshold**
 -  If **ADC > Threshold**
 - `DIGITAL_TO_KEITH = HIGH`
 - `DEBUG_LED = ON`
 -  Else- `DIGITAL_TO_KEITH = LOW`
 - `DEBUG_LED = OFF`
 - **Check DEBUG_BUTTON (RD2)**
 - Toggle `debugMode`
 - Force state updates when presse

## 4. Complete Code Implementation - LIGHTSENSOR

*The full code for LIGHTSENSOR is included in `LightSensor.c`. It initializes the ADC, reads the photoresistor, manages debug mode, and toggles outputs.*



## 5. Testing & Validation - LIGHTSENSOR

**5.1 Sensor Testing:**  
- Cover/uncover photoresistor to trigger state changes  
- Confirm DIGITAL_TO_KEITH output reflects light detection  
- DEBUG_LED shows correct state

**5.2 Debug Testing:**  
- Press DEBUG_BUTTON to toggle manual mode  
- LED flashes indicate debug toggle  
- Forced state changes reflected in output



## 6. System Specifications - LIGHTSENSOR

- **Operating Voltage:** 5V DC  
- **ADC Resolution:** 12-bit (0–4095)  
- **Light Threshold:** 2.5V  
- **Input:** PHOTORESISTOR_IN (RA0)  
- **Output:** DIGITAL_TO_KEITH (RA2)  
- **Status LED:** DEBUG_LED (RD1)  
- **Control Button:** DEBUG_BUTTON (RD2)  



**DOCUMENT VERSION: LIGHTSENSOR - FINAL**  
**STATUS: PRODUCTION READY**


Below is the file for the main code that was used in programming the system [*Light-Subsystem*](https://github.com/dcalde11/dcalde11.github.io/blob/2a0318d0db4d65a3e27d15a51a7affd6935ff5d5/docs/08-Resources/mcc_files.zip)
