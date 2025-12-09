---
title: Individal Block Diagram
tags:
- tag1
- tag2
---
# System Overview
This document describes a structured embedded system for ambient light sensing, signal conditioning, and digital processing. The architecture progresses from regulated power input through analog detection to microcontroller-based data 
output, as detailed in the following subsystem breakdown (Sections 1–5).

## Design Specifications
Following the system design suggestions, the  block diagram includes annotations for the signal gain at each stage. These gain values are calculated based on a 5V input, with the calibration potentiometer set to a resistance of 9.45 kΩ.

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


