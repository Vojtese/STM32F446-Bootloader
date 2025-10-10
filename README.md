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
```

## 🔗 Linked Repositories

This bootloader is designed to work with the following application slots:

- [STM32F446-APP1](https://github.com/Vojtese/STM32F446-APP1): Primary application slot
- [STM32F446-APP2](https://github.com/Vojtese/STM32F446-APP2): Secondary/fallback application slot

## 🧪 How to Use

1. **Flash the bootloader**  
   Use STM32CubeProgrammer or JTAG/SWD to flash `bootloader.bin` to the MCU.

2. **Upload firmware via UART**  
   Use a Python CLI tool or custom uploader to send a compiled `.bin` firmware image over UART.

3. **Bootloader verifies and writes firmware**  
   The bootloader checks CRC integrity and writes the firmware to either App1 or App2 slot.

4. **Automatic jump to valid application**  
   On next reset, the bootloader checks both slots and jumps to the valid application.

## 🛠️ Tools Used

- STM32CubeIDE
- STM32CubeMX
- STM32CubeProgrammer
- JTAG/SWD debugger
- Python (for CLI uploader)

## ⚠️ Known Issues / TODO

- Add GUI interface for firmware upload
- Improve error handling and fallback logic
- Document memory map and slot layout

## 📜 License

This project is licensed under the Public GPT License.
