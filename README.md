# PIC16F1719 Examples

This repository contains code examples for the **PIC16F1719** microcontroller. 
These examples are designed to be **teachable**, **modular**, and **practical**—ideal for learning, experimenting, and building real embedded projects.

## Overview

The **PIC16F1719** is a feature‑rich 8‑bit microcontroller from Microchip, offering a powerful blend of **Intelligent Analog**, **Core Independent Peripherals**, and **low‑power operation**. Key specifications include:

- 28 KB Flash program memory  
- 2 KB SRAM  
- 128 bytes High-Endurance Flash (HEF)  
- 40‑pin package with up to 35 I/O pins  
- Internal oscillator up to 32 MHz  
- 16‑level hardware stack  
- Interrupt capability  
- Peripheral Pin Select (PPS) for flexible pin mapping  

### Notable Peripherals

- **Intelligent Analog**
  - 10‑bit ADC with multiple channels  
  - 2 × rail‑to‑rail op‑amps  
  - 2 × high‑speed comparators  
- **Core Independent Peripherals (CIPs)**
  - Configurable Logic Cell (CLC)  
  - Numerically Controlled Oscillator (NCO)  
  - Complementary Output Generator (COG)  
- **Timers**
  - Four 8‑bit timers  
  - One 16‑bit timer  
- **Communication**
  - I²C, SPI, EUSART (with auto‑baud detect)  

This makes the PIC16F1719 a great platform for **signal processing**, **motor control**, **sensor interfacing**, **logic generation**, and **general embedded experimentation**.

## Software Implementations

This repository includes examples in:

- **XC8 C**
- **pic-as Assembly**
- **MCC‑generated starter projects** (optional)

Each example is structured to be clear, annotated, and beginner‑friendly—perfect for teaching or rapid prototyping.

## Prerequisites

To build and program the examples, you will need:

- **MPLAB X IDE** (v5.0 or later recommended)  
- **XC8 Compiler**  
- **pic-as Assembler** (for Assembly examples)  
- **PICkit 4/5**, SNAP, or other compatible programmer/debugger  
- (Optional) **MPLAB Code Configurator (MCC)** for auto‑generated peripheral setup  

## Notes

- The PIC16F1719 supports **interrupts**, **multiple timers**, and **CIPs**, so examples may rely on hardware features beyond simple polling loops.  
- **Peripheral Pin Select (PPS)** allows flexible routing of digital peripherals—be sure to configure it correctly in each project.  
- The internal oscillator is accurate enough for many applications but can be fine‑tuned using OSCTUNE if needed.  
- High‑Endurance Flash (HEF) provides a small area for nonvolatile data storage without external EEPROM.  
- Some peripherals (e.g., op‑amps, CLC, NCO) require careful configuration—examples in this repo demonstrate recommended initialization sequences.  


## Breadboard Example for the Music project
![Setup_1](https://github.com/user-attachments/assets/da03ee22-ea75-45e6-ac17-d1976d00ce70)
![Setup_CloseUp](https://github.com/user-attachments/assets/9919d8db-0992-4724-8689-aea0ebabed56)
