# STM32F446 Bootloader

This repository contains a custom bootloader for the STM32F446 microcontroller, developed as part of a signal acquisition unit for a rainwater retention system. The bootloader enables robust firmware management, including dual-slot fallback, CRC integrity checks, and in-application programming (IAP) via UART or RS485.

It is a core component of a distributed embedded system designed for diagnostics, monitoring, and control in harsh environments. The bootloader is tightly integrated with the application firmware, GUI uploader, and hardware test routines.

---

## 🚀 Features

### 🔁 Dual-Slot Architecture
- Supports two application slots (APP1 and APP2)
- Bootloader verifies CRC of APP1 on startup
- If APP1 fails or is missing, it falls back to APP2
- Ensures system reliability during firmware updates or corruption

### 🔐 CRC Integrity Verification
- Uses STM32 hardware CRC peripheral
- Each application image includes a CRC appended at the end
- Bootloader calculates CRC before jumping to application

### 🔧 Vector Table Relocation
- Uses `SCB->VTOR` to remap the interrupt vector table to the application base address
- Ensures correct interrupt handling after bootloader jump

### 🔄 In-Application Programming (IAP)
- Receives `.bin` firmware files over UART or RS485
- Parses 240-byte packets with headers and CRC
- Writes to Flash using `LL_FLASH_Program()` and verifies each block
- Compatible with GUI uploader and RS485 upload test firmware

### 🧱 CMSIS LL Driver Integration
- LL_USART for UART/RS485 communication
- LL_FLASH for Flash programming
- LL_CRC for checksum validation
- LL_GPIO for boot pin logic (optional)

---

## 📁 Project Structure

- `Core/` – Bootloader source code
- `Drivers/` – STM32 LL drivers
- `.ioc` – STM32CubeMX configuration
- `STM32F446RETX_FLASH.ld` – Custom linker script for bootloader region
- `docs/` – Diagrams and hardware images

---

## 📊 Firmware Architecture

### 🧭 Bootloader Flow

The bootloader supports dual-slot firmware management with CRC validation and UART/RS485-based in-application programming. It verifies the integrity of App1 and App2 and jumps accordingly.

![Bootloader Flow](docs/SWdesignv2.pdf)

---

### 🧠 Application Flow with IAP (APP1/APP2)

In this version, the application itself can receive and flash new firmware using DMA and UART/RS485, without rebooting into the bootloader. This is ideal for remote updates in distributed systems.

![APP IAP Flow](docs/SWdesignv1.pdf)

---

## 🧪 Electronics Overview

The bootloader is part of a complete embedded system for rainwater diagnostics. Below are top and bottom views of the final PCB design.

![Top View](docs/top.png)

![Bottom View](docs/bottom.png)

---

## 🔗 Related Projects

- [STM32F446-APP1](https://github.com/Vojtese/STM32F446-APP1) – Primary application
- [STM32F446-APP2](https://github.com/Vojtese/STM32F446-APP2) – Fallback application
- [STM32F446-SensorTestAndHW](https://github.com/Vojtese/STM32F446-SensorTestAndHW) – Hardware and sensor validation firmware
- [STM32F446-uploadRS485Test](https://github.com/Vojtese/STM32F446-uploadRS485Test) – RS485-based firmware upload test
- [serial_BIN_file_transfer](https://github.com/Vojtese/serial_BIN_file_transfer) – Python GUI for firmware upload

---

## 🛠️ TODO & Improvements

### RS485 Upload Integration
- [ ] Finalize RS485 support for firmware upload using DMA and direction control
- [ ] Implement automatic baud rate detection
- [ ] Add timeout and retry logic

### Boot Decision Logic
- [ ] Add boot pin override to force fallback or stay in bootloader
- [ ] Implement watchdog-based recovery
- [ ] Log boot decisions via UART

### Flash Write Robustness
- [ ] Add double-buffering for packet reception
- [ ] Verify Flash erase/write success with read-back
- [ ] Support partial firmware updates

### Protocol Enhancements
- [ ] Extend packet format with versioning and metadata
- [ ] Add acknowledgment and error codes
- [ ] Support encrypted or signed firmware packets

### Debug and Diagnostics
- [ ] Add LED blink patterns for bootloader status
- [ ] Add UART debug output
- [ ] Integrate CLI from SensorTest project

### Memory and Linker Improvements
- [ ] Validate linker script boundaries
- [ ] Reserve space for persistent bootloader flags
- [ ] Document memory map in code and README

### Packaging and Deployment
- [ ] Add script to generate `.bin` with CRC
- [ ] Add GUI-side support for selecting App1 vs App2
- [ ] Create unified flashing tool for UART and RS485

---

## 📜 License

This project is licensed under the GNU General Public License v3.0.
