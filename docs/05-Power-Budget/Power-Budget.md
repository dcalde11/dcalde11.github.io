---
title: Power Budget
---

## Overview
For our Electric Blinds project, we created a power budget to understand and manage how much electrical power our system requires. The power budget helps ensure that all components, including the microcontroller, light sensor, and operational amplifier, receive adequate power without exceeding the system’s supply limits.

By listing each component’s voltage and current requirements, we were able to calculate the total power needed for the system and confirm that our chosen power source and voltage regulators can handle the load safely. This step is essential for preventing power shortages, overheating, or component damage.

Creating a detailed power budget also helps improve the efficiency and reliability of our design. It ensures the automatic blinds system operates smoothly as it detects light levels and adjusts to maintain indoor comfort—without wasting energy or overloading the circuit.



<img width="613" height="1539" alt="Screenshot 2025-12-08 162148" src="https://github.com/user-attachments/assets/ee77e5a0-5082-4ae8-8994-0065240288ad" />









## Conclusions

The power budget verifies that the light-detection subsystem that includes the 5 V regulator, CDS photoresistor with potentiometer, op-amp conditioning stage, and the Curiosity Nano microcontroller—operates well within the system’s power limits as shown in the image of the BOM. By reviewing each component’s voltage and current requirements, we confirmed the circuit can reliably sense ambient light, condition the signal for accurate ADC readings, and process it without risking overload or instability. This ensures the subsystem remains efficient, stable, and ready for integration into the larger project.

## Resouces

The power budget as a PDF download is available [*here*](http://digil.ink/l/36146ZBstB), and a Microsoft Excel Sheet [*here*](https://github.com/dcalde11/dcalde11.github.io/blob/main/Power%20Budget%202.xlsx).
