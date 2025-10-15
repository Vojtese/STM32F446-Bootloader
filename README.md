# STM32F446 Bootloader

This repository contains a custom bootloader for the STM32F446 microcontroller, designed for dual-slot firmware management and in-application programming (IAP) via UART. It is part of a signal acquisition unit for rainwater management, enabling robust firmware updates and fallback logic.

## 🚀 Features

- Dual-slot architecture (App1 and App2)
- CRC-based firmware integrity verification
- UART-based firmware update interface
- Vector table relocation via `SCB->VTOR`
- CMSIS LL drivers for low-level control
- Compatible with GUI uploader and RS485 test firmware

## 📁 Project Structure

- `Core/`: Bootloader source code
- `Drivers/`: STM32 LL drivers
- `.ioc`: STM32CubeMX configuration
- `STM32F446RETX_FLASH.ld`: Custom linker script

## 🔗 Related Projects

- [STM32F446-APP1](https://github.com/Vojtese/STM32F446-APP1)
- [STM32F446-APP2](https://github.com/Vojtese/STM32F446-APP2)
- [serial_BIN_file_transfer](https://github.com/Vojtese/serial_BIN_file_transfer)
- [STM32F446-uploadRS485Test](https://github.com/Vojtese/STM32F446-uploadRS485Test)

## 📜 License

This project is licensed under the GNU General Public License v3.0.
