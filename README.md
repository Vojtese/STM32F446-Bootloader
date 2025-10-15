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
- Compatible with [serial_BIN_file_transfer](https://github.com/Vojtese/serial_BIN_file_transfer) GUI

### 🧱 CMSIS LL Driver Integration
- LL_USART for UART/RS485 communication
- LL_FLASH for Flash programming
- LL_CRC for checksum validation
- LL_GPIO for boot pin logic (optional)

---

## 🧠 Memory Layout

| Region        | Address Range       | Purpose              |
|---------------|---------------------|----------------------|
| Bootloader    | 0x08000000–0x08007FFF | 32 KB bootloader     |
| App1          | 0x08008000–0x0803FFFF | Primary application  |
| App2          | 0x08040000–0x0807FFFF | Fallback application |

Custom linker scripts are used for each region to ensure proper placement and isolation.

---

## 📁 Project Structure

- `Core/`: Bootloader source code
- `Drivers/`: STM32 LL drivers
- `.ioc`: STM32CubeMX configuration
- `STM32F446RETX_FLASH.ld`: Custom linker script for bootloader region

---

## 🔗 Related Projects

- [STM32F446-APP1](https://github.com/Vojtese/STM32F446-APP1) – Primary application
- [STM32F446-APP2](https://github.com/Vojtese/STM32F446-APP2) – Fallback application
- [STM32F446-SensorTestAndHW](https://github.com/Vojtese/STM32F446-SensorTestAndHW) – Hardware and sensor validation firmware
- [STM32F446-uploadRS485Test](https://github.com/Vojtese/STM32F446-uploadRS485Test) – RS485-based firmware upload test
- [serial_BIN_file_transfer](https://github.com/Vojtese/serial_BIN_file_transfer) – Python GUI for firmware upload

---

## 🧪 Testing and Validation

- Verified UART and RS485 firmware upload using GUI and terminal
- CRC validation tested with corrupted and valid firmware images
- Bootloader fallback tested by erasing App1 and confirming App2 execution
- Flash write/verify tested with oscilloscope and debug logs

---

## 🛠️ TODO & Improvements

This section outlines planned enhancements and refinements for the bootloader based on the development experience, thesis goals, and integration feedback.

### 🔄 1. RS485 Upload Integration
- [ ] Finalize RS485 support for firmware upload using DMA and direction control
- [ ] Implement automatic baud rate detection for RS485
- [ ] Add timeout and retry logic for noisy environments

### 🧠 2. Boot Decision Logic
- [ ] Add boot pin override to force fallback or stay in bootloader
- [ ] Implement watchdog-based recovery if application hangs after jump
- [ ] Log boot decisions and CRC results via UART for diagnostics

### 🧪 3. Flash Write Robustness
- [ ] Add double-buffering for packet reception to avoid timing issues
- [ ] Verify Flash erase/write success with read-back and CRC
- [ ] Add support for partial firmware updates (sector-level targeting)

### 🧰 4. Protocol Enhancements
- [ ] Extend packet format to include versioning and metadata
- [ ] Add acknowledgment and error codes for GUI feedback
- [ ] Support encrypted or signed firmware packets (future-proofing)

### 📊 5. Debug and Diagnostics
- [ ] Add LED blink patterns for bootloader status (e.g. CRC fail, waiting for upload)
- [ ] Add UART debug output for packet parsing and Flash status
- [ ] Integrate with CLI from SensorTest project for manual control

### 🧩 6. Memory and Linker Improvements
- [ ] Add linker script validation to prevent overlap between bootloader and apps
- [ ] Reserve space for bootloader configuration and persistent flags
- [ ] Document memory map in README and code comments

### 📦 7. Packaging and Deployment
- [ ] Add script to generate `.bin` with appended CRC automatically
- [ ] Add GUI-side support for selecting App1 vs App2 target
- [ ] Create unified flashing tool for UART and RS485 modes

---

## 📜 License

This project is licensed under the GNU General Public License v3.0.
