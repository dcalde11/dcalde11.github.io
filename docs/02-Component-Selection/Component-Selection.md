---
title: Component Selection
---

# Component Selection Overview
On this page, I outline my decision-making process for selecting the core hardware in my light-sensing blinds controller.
I chose three main components:

* PDV‑P8103 Photoresistor – to sense ambient light levels

* MCP6004‑I/P Op‑Amp – to amplify the sensor’s weak signal

* PIC18F57Q43 Microcontroller – to process readings and control the blinds

I evaluated each part based on cost, ease of use, and my prior hands‑on experience from classroom labs. For 
every option, I included product specs, images, purchase links, and pros/cons tables. My final selections 
prioritize reliability, affordability, and seamless integration—helping me stay on budget while building a 
system I know how to troubleshoot.

This page also shows the final pin mappings and explains how each component fits into the overall signal 
chain.



## 1. Light Sensor Selection

### **Options Considered:**

**Option 1: PDV-P8103 CDS Photoresistor (16-33KΩ)**
<img width="251" height="136" alt="PDV-P8103" src="https://github.com/user-attachments/assets/62fbd04a-39f2-44e9-9d67-134f88270aad" />

* **Price:** $0.70/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610)

| Pros | Cons |
|------|------|
| Inexpensive | Slow shipping |
| Compatible with PSoC | Shipping fee |
| Easy to install | |

**Option 2: VEMD2023X01 Photodiode**
<img width="313" height="313" alt="VEMD2023X01" src="https://github.com/user-attachments/assets/6389eb30-d382-4122-9df2-ca588d574e19" />

* **Price:** $0.90/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/VEMD2023X01/4075873)

| Pros | Cons |
|------|------|
| Small and compact | More expensive |
| High reverse voltage | Slow shipping |
| | Sensitive to high temperatures |
| | Requires amplifier |
| | Surface mount (SMD) |

**Option 3: BPW34 Photodiode**
<img width="313" height="313" alt="BPW34" src="https://github.com/user-attachments/assets/eb2f617b-c7af-4ef2-a1fd-09d9c7d412a3" />

* **Price:** $1.14/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/ams-osram-usa-inc/BPW34/607274)

| Pros | Cons |
|------|------|
| High temperature tolerance | Low reverse voltage |
| Accurate readings | Slow shipping |
| | Tariff for US shipping |

### **Selected: PDV-P8103 CDS Photoresistor**
**Rationale:** Provides reliable light-to-electrical signal conversion needed for detecting ambient light levels. Its output signal corresponds directly to light intensity, enabling the system to adjust blinds based on environmental conditions. The photoresistor's simplicity and compatibility with our existing PSoC architecture make it ideal for this application, and an amplifier can be added if needed to strengthen the signal for motor control.

---

## 2. Operational Amplifier Selection

### **Options Considered:**

**Option 1: MCP6004-I/P (14-DIP)**
<img width="221" height="221" alt="MCP6004-I/P" src="https://github.com/user-attachments/assets/fe37bf87-7fa8-4837-b103-025e68c92c05" />

* **Price:** $0.59/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/microchip-technology/MCP6004-I-P/523060)

| Pros | Cons |
|------|------|
| Prior experience | Shipping delays |
| Easy installation | Risk of burnout |
| Low cost | Fragile pins |
| Four independent circuits | |

**Option 2: MCP6004-E/P (14-DIP)**
<img width="313" height="313" alt="MCP6004-E/P" src="https://github.com/user-attachments/assets/35ca0cb8-7a3a-4ecb-9cbe-5bd8432063ee" />

* **Price:** $0.65/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/microchip-technology/MCP6004-E-P/683200)

| Pros | Cons |
|------|------|
| Identical to MCP6004-I/P | Shipping delays |
| Prior experience | Risk of burnout |
| Easy installation | Heat sensitivity |
| Low cost | Fragile pins |

**Option 3: LMC6484IN/NOPB (14-DIP)**
<img width="255" height="255" alt="LMC6484IN/NOPB" src="https://github.com/user-attachments/assets/02fe99d8-6997-441f-b7da-69f2c3fa6668" />

* **Price:** $3.64/unit
* **Link:** [DigiKey Product Page](https://www.digikey.com/en/products/detail/texas-instruments/LMC6484IN-NOPB/164521)

| Pros | Cons |
|------|------|
| Compact design | Higher cost |
| Fewer circuits needed | Slow shipping |
| Battery system compatible | |

### **Selected: MCP6004-I/P**
**Rationale:** This op-amp provides straightforward amplification of the photoresistor's output voltage 
without requiring complex external circuitry. By amplifying the signal difference, the microcontroller can 
accurately detect light level changes and trigger appropriate blind positioning. Our prior classroom 
experience with this component reduces implementation risk and accelerates development.



---

## Final Component Selection Summary

| Component Category | Selected Part | Manufacturer | Key Specifications | Unit Price | Justification |
|-------------------|---------------|--------------|-------------------|------------|---------------|
| **Light Sensor** | PDV-P8103 CDS Photoresistor | Advanced Photonix | 16–33 kΩ range, through-hole | $0.70 | Inexpensive, class-proven, PSoC compatible, easy installation |
| **Operational Amplifier** | MCP6004-I/P | Microchip Technology | Quad op-amp, rail-to-rail, 14-DIP | $0.59 | Low-cost, familiar from labs, four circuits, simple interface |
| **Microcontroller** | PIC18F57Q43 | Microchip Technology | 8-bit, integrated ADC, 64-pin TQFP | — | Provided in-class, capable ADC, familiar development tools |

---

## Selection Rationale Summary

### Photoresistor (PDV-P8103)
- Reliable light sensing with variable resistance output
- Coursework experience reduces learning curve and build time
- Cost-effectivem $0.70 per unit with through-hole mounting
- Direct light-to-voltage conversion 

### Op-Amp (MCP6004-I/P)
- Amplifies small photoresistor signals for robust ADC conversion
- Rail-to-rail operation ensures full signal swing at low voltages
- Classroom experience provides confidence in using op-amp

### Microcontroller (PIC18F57Q43)
- Integrated 12-bit ADC directly reads amplified sensor signals
- Sufficient I/O for sensor interface, debug controls, and external communication
- Supported by in-class use.

---

## Pin Configuration

| Location | Pin Name | Function | Direction | Custom Name | Analog | Pull-Up |
|----------|----------|----------|-----------|-------------|--------|---------|
| RA0 | ADC | Analog Input | input | PHOTORESISTOR_IN | yes | no |
| RA2 | GPIO | Digital Output | output | DIGITAL_TO_KEITH | no | no |
| RD1 | GPIO | LED Output | output | DEBUG_LED | no | no |
| RD2 | GPIO | Button Input | input | DEBUG_BUTTON | no | yes |

---

## System Benefits
1. **Reduced Development Risk**: Components validated in previous lab sessions
2. **Cost Efficiency**: Active component cost under $2.00 per unit (excluding microcontroller)
3. **Design Continuity**: Familiar components accelerate prototyping and debugging
