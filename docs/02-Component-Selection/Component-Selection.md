---
title: Component Selection 
---



**Options 

**External Clock Module**

1. PDV-P8103 CDS PHOTORESISTOR 16-33KOHM


  <img width="251" height="136" alt="image" src="https://github.com/user-attachments/assets/62fbd04a-39f2-44e9-9d67-134f88270aad" />

* $0.70/each  
* [link to product](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610)

| Pros                  | Cons               |
|------------------------|--------------------|
| Inexpensive            | Slow shipping      |
| Compatible with PSoC   |       shipping fee |
| Easy install           |                    |


2. VEMD2023X01 SENSOR PHOTODIODE 940NM 2SMD


    <img width="313" height="313" alt="image" src="https://github.com/user-attachments/assets/6389eb30-d382-4122-9df2-ca588d574e19" />


    * $0.90/each
    * [Link to product](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/VEMD2023X01/4075873)

    | Pros                                                              | Cons                |
    | ----------------------------------------------------------------- | ------------------- |
    | Small and compact                                              | More expensive      |
    | High Reverse Voltage                                           | Slow shipping speed |
    |                                                                | Sensitive to high temperatures    |
    |                                                                | Amplifier needed   |
    |                                                                | Surface Mount    |



3. BPW34 SENSOR PHOTODIODE 850NM 2DIP



    <img width="313" height="313" alt="image" src="https://github.com/user-attachments/assets/eb2f617b-c7af-4ef2-a1fd-09d9c7d412a3" />



    * $1.14/each
    * [Link to product](https://www.digikey.com/en/products/detail/ams-osram-usa-inc/BPW34/607274)

    | Pros                                                              | Cons                |
    | ----------------------------------------------------------------- | ------------------- |
    | High Temperature                                               | 	Low Reverse voltage    |
    | Accurate readings                                              | Slow shipping speed    |  
    |                                                                | 	Tariff for shipping to US    |
    



   
**Choice:** Option 1: PDV-P8103 CDS PHOTORESISTOR 16-33KOHM


**Rationale:** Light sensor or Photodetector, which converts light energy into an electrical signa. This is important because we need to send a signal corresponding to the level of light present, in relation to lowering the blinds. An amplifier might be needed to send a stonger message to compenstate for the secondary motor when adjusting the level of blinds.




1. MCP6004-I/P IC OPAMP GP 4 CIRCUIT 14DIP



 <img width="221" height="221" alt="image" src="https://github.com/user-attachments/assets/fe37bf87-7fa8-4837-b103-025e68c92c05" />

* $0.59/each  
* [Link to product](https://www.digikey.com/en/products/detail/microchip-technology/MCP6004-I-P/523060)

| Pros          | Cons          |
|----------------|----------------|
| Experienced    | Shipping       |
| Easy install   | Burnout        |
| Cheap          | Fragile pins   |
| 4 Circuits     |                |
   




2. MCP6004-E/P IC OPAMP GP 4 CIRCUIT 14DIP



    <img width="313" height="313" alt="image" src="https://github.com/user-attachments/assets/35ca0cb8-7a3a-4ecb-9cbe-5bd8432063ee" />



    * $0.65/each
    * [Link to product](https://www.digikey.com/en/products/detail/microchip-technology/MCP6004-E-P/683200)

    | Pros                                                              | Cons                |
    | ----------------------------------------------------------------- | ------------------- |
    | 	Identical to Previous                                              | 	Shipping      |
    | 	Experienced                                | 	Burnout |
    |   Easy install                                | 	Sensitive to high temperatures    |
     |   	Cheap                                  | 	Fragile Pins  |







3. LMC6484IN/NOPB IC CMOS 4 CIRCUIT 14DIP



   <img width="255" height="255" alt="image" src="https://github.com/user-attachments/assets/02fe99d8-6997-441f-b7da-69f2c3fa6668" />

* $3.64/each  
* [Link to product](https://www.digikey.com/en/products/detail/texas-instruments/LMC6484IN-NOPB/164521)

| Pros              | Cons               |
|--------------------|--------------------|
| Small and compact  | More expensive     |
| Less circuits      | Slow shipping speed|
| Battery systems    |                    |
    





   
**Choice:** 1. MCP6004-I/P IC OPAMP GP 4 CIRCUIT 14DIP

**Rationale:** A clock oscillator is easier to work with because it requires no external circuitry in order 
to interface with the PSoC. This allows for amplifying the difference of input voltage created by the PDV-
P8103 CDS PHOTORESISTOR 16-33KOHM. By amplifying the difference the pic can read the levels and once 
surpassing a threshold or certain levels it sets the blind to pre determined positions 

# **Final Component Selection Summary**

| Component Category | Selected Part | Manufacturer | Key Specifications | Unit Price | Justification |
|-------------------|---------------|--------------|-------------------|------------|---------------|
| **Light Sensor** | PDV-P8103 CDS Photoresistor | Advanced Photonix | 16–33 kΩ range, through-hole | $0.70 | Inexpensive, class-proven, compatible with PSoC, easy installation |
| **Operational Amplifier** | MCP6004-I/P | Microchip Technology | Quad op-amp, rail-to-rail, 14-DIP | $0.59 | Low-cost, familiar from lab use, four circuits, simple interface |
| **Microcontroller** | PIC18F57Q43 | Microchip Technology | 8-bit, integrated ADC, 64-pin TQFP | — | Provided in-class, capable ADC for sensor input, familiar development environment |

---

## **Selection Rationale Summary**

### **Photoresistor (PDV-P8103)**
- Provides reliable ambient light sensing with variable resistance output
- Already used in coursework, reducing learning curve and validation time
- Cost-effective at $0.70 per unit with straightforward through-hole mounting

### **Op-Amp (MCP6004-I/P)**
- Amplifies small photoresistor signals for robust ADC conversion
- Rail-to-rail operation ensures full signal swing at low voltages
- Quad configuration allows unused sections to be properly terminated
- Prior classroom experience enables a strong foundation for implementation

### **Microcontroller (PIC18F57Q43)**
- Integrated 12-bit ADC directly reads amplified sensor signals
- Sufficient I/O for sensor interface, debug controls, and external communication
- Supported by in-class development tools and libraries

---

## **System Benefits**
1. **Reduced Risk**: All major active components have been validated in previous lab sessions
2. **Cost Efficiency**: Total active component cost under $2.00 per unit (excluding microcontroller)
3. **Design Continuity**: Familiar components accelerate prototyping and debugging
4. **Performance**: Adequate signal chain from sensing to processing to output control

**Pin Configuration with Custom Names:**

| Location | Pin Name | Function        | Direction | Custom Name        | Analog | Pull-Up |
|----------|----------|----------------|-----------|------------------|--------|---------|
| RA0      | ADC      | Analog Input   | input     | PHOTORESISTOR_IN | yes    | no      |
| RA2      | GPIO     | Digital Output | output    | DIGITAL_TO_KEITH | no     | no      |
| RD1      | GPIO     | LED Output     | output    | DEBUG_LED        | no     | no      |
| RD2      | GPIO     | Button Input   | input     | DEBUG_BUTTON     | no     | yes     |


