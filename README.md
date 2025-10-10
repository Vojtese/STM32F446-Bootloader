# STM32F446 Bootloader

This repository contains a custom bootloader for the STM32F446 microcontroller (Cortex-M4), designed to support In-Application Programming (IAP) with dual-slot firmware architecture. It enables safe firmware updates over UART and ensures robust fallback mechanisms in case of corruption or failure.

## 🚀 Features

- Dual-slot firmware architecture (App1 and App2)
- Flash memory management with write protection
- CRC-based firmware integrity verification
- UART-based firmware update interface
- Vector table relocation and SCB->VTOR setup
- STM32CubeIDE project structure with LL drivers

## 📁 Project Structure

- `Core/`: Bootloader source files
- `Drivers/`: STM32 LL drivers
- `STM32F446RETX_FLASH.ld`: Custom linker script defining memory layout
- `.ioc`: STM32CubeMX configuration file
- `bootloader.bin`: Precompiled bootloader binary (optional)

## 🧠 Bootloader Flow

```plaintext
+------------------+
| Bootloader Start |
+------------------+
         |
         v
+------------------+
| Check App1 Slot  |
| CRC & Valid Flag |
+------------------+
         |
         v
+------------------+
| Jump to App1     |
| or fallback to   |
| App2 if needed   |
+------------------+
         |
         v
+------------------+
| Application Runs |
+------------------+
