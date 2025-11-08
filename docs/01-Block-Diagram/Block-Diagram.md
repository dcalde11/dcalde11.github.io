---
title: Individal Block Diagram
tags:
- tag1
- tag2
---

## Overview
The block diagram provides an overview of the system’s key components—in this case, the light sensor—and how they interact. The sensor connects to pin RA0, which receives the light data from the photoresistor. The microcontroller then sends an inverting signal as confirmation that the system should activate, which is output through pin RA2 to control the rest of the system. A shared ground connection on pin 8 ensures all boards operate at the same reference point. The diagram also highlights how each subsystem integrates to maintain efficient communication and coordinated operation across the project.




<img width="701" height="691" alt="Lightsensor drawio" src="https://github.com/user-attachments/assets/b725143e-94de-4ccb-862d-4bedadaef3e6" />
