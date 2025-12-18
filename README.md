# Industrial Grease System Timer

Embedded timer controller for industrial grease lubrication systems,
designed to manage timed lubrication cycles for 28 grease systems
along production lines in the Rolling Mill 300, Esfahan Steel Company.

This system stabilizes and filters industrial power fluctuations using
recycled computer power supplies, ensuring minimal noise and reliable operation
in harsh industrial environments.

---

## Features

- Control of 28 independent grease delivery motors (3-phase)  
- Configurable start times from 10 minutes up to 48 hours  
- Simple and intuitive UI with only 3 buttons for all settings  
- Display: 16x2 character LCD for real-time status and configuration  
- Cost-effective design prior to full PLC implementation  
- High timing accuracy compared to legacy analog systems  
- Significant reduction in grease consumption and energy savings  
- Easy maintenance and debugging via Proteus simulation for AVR  

---

## Hardware Design

- Microcontroller: AVR-based system  
- Motor Control: 5V relays isolating microcontroller from 220V motors  
- Full isolation between relay section and MCU to prevent noise and unintended resets  
- Input: 3 control buttons for full configuration  
- Output: Relays driving 3-phase grease delivery motors  
- Power: Stabilized industrial power using modified computer PSUs  

---

## Software

- Language: Embedded C  
- Architecture: Bare-metal programming on AVR  
- Debugging: Full simulation and testing in Proteus  
- Timer management: Accurate industrial-grade scheduling for lubrication cycles  

---

## Use Case

This system is designed to automate lubrication in heavy machinery environments,
providing precise timing control before PLC-based panel installations.  
It is engineered for easy operation by personnel with minimal technical experience,  
ensuring reliable and energy-efficient lubrication across production lines.

---

## Benefits

- Minimal cost for maximum industrial performance  
- Simple user interface (3 buttons) for easy operation  
- High reliability and minimal interference from industrial noise  
- Improved efficiency in grease usage and energy consumption  
- Fully debugged and tested in simulation environment  

---

## GitHub Media / LinkedIn Display

**Title:**  
Industrial Grease Lubrication Timer – Embedded C

**Description:**  
Embedded timer system for industrial grease lubrication. Manages
28 independent motors with configurable timing, stable operation
under industrial noise, and user-friendly interface using 3 buttons.
Project implemented in Embedded C on AVR, fully debugged in Proteus.
