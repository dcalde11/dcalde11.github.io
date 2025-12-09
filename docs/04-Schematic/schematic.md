---
title: Schematic
---

## Overview

This schematic supports overall system functionality by integrating power regulation, light sensing, and control operations. Ambient light intensity is detected by a photoresistor, with the resulting small analog voltage amplified by a non‑inverting op‑amp stage using the MCP6004. Any unused op‑amp pins are properly terminated—pulled to power through a resistor or grounded—to ensure stable operation.
The amplified signal is conditioned by an ADC driver and then enters the PIC18F57Q43 microcontroller on pin RA0 for analog-to-digital conversion. After processing the light data, the microcontroller outputs the control signal from pin RA2. This output is sent to an external subsystem via an 8‑pin shared connector, where pin 7 provides power and pin 8 serves as ground.A debug section with an LED and tactile button enables manual state changes for functional testing. The power regulation section supplies clean, stable voltage rails for reliable operation of all analog and digital circuitry.



<img width="1227" height="870" alt="image" src="https://github.com/user-attachments/assets/37354cc9-f6b0-4a3b-a444-f60b4e7b6c24" />





**Figure 1: Shows Schematic


## Resouces

The schematic as a PDF download is available [*here*](https://github.com/dcalde11/dcalde11.github.io/blob/4c5b0d906c9cb7297b95a6b4c42ddb51027e799b/docs/04-Schematic/voltage_regulator.pdf),  and the Zip folder of the project [*here*](https://github.com/dcalde11/dcalde11.github.io/blob/d0d5d5c220cbf1b354f782d8bdd138bd6da8f46e/docs/04-Schematic/LightSensorV1.zip)


