---
title: Individal Block Diagram
tags:
- tag1
- tag2
---
# System Overview

This system provides a structured approach to sensing ambient light, conditioning the resulting analog signal, and processing it through an embedded microcontroller platform. The following sections (1–5) summarize each major subsystem, outlining the progression from power regulation to signal detection, conditioning, and final data output.


1. **Power Regulation**  
   * A voltage regulator produces a stable 5 V power supply that runs all components in the system.

2. **Light Detection**  
   * A CDS photoresistor changes its resistance (through the use of a potentiometer) based on how much light is present. This creates an analog voltage that represents light intensity.

3. **Signal Conditioning**  
   * An operational amplifier (op-amp) takes this analog signal and adjusts it so it can be accurately read by the microcontroller.

4. **Microcontroller Processing**  
   A PIC18F57Q43 Curiosity Nano board:
   * Reads the analog light signal through its ADC (Analog-to-Digital Converter)  
   * Uses digital pins to control a debug LED  
   * Reads a debug button for testing or mode changes  
   * Sends the processed signals out through an 8-pin connector for use by other systems




<img width="701" height="691" alt="ID" src="https://github.com/user-attachments/assets/12879113-0c55-40bf-84af-07524462bc81" />


