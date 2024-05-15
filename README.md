# AUTODIAG (On-Board-Diagnostic-System-for-Vehicles)
# Project Overview:
The On-Board Diagnostic System for Vehicles is designed to identify vehicle malfunctions by analyzing sensory data from various vehicle subsystems. It employs a Python script to stream sensory data from Kaggle through the PL2303 via UART to the STM32f103, which serves as the core of the system. The system utilizes a layered static design architecture with APIs for managing data reception, Real-Time Operating System (RTOS), interrupt handling, memory management, and General Purpose Input/Output (GPIO). Data transmission is achieved through SPI to the ESP8266, which acts as the data gateway, organizing and wirelessly transmitting vehicle data and Diagnostic Trouble Codes (DTCs) to the system’s database via the MQTT protocol periodically.
# Our Services:
Aiming to reduce costs, improve customer satisfaction, and enhance vehicle safety
and performance standards, Our System provided Four Services:
1- REAL-TIME MONITORING
2- REMAINING USEFUL LIFE
3- ON-BOARD DIAGNOSIS CAPABILITY
4- ROAD-SIDE ASSISTANCE
📝 You can view more Details from here. <a href="https://drive.google.com/file/d/12X-7KyyK5NAQu-tFUbDE7he6bxcZAbdy/view?usp=sharing" target="blank">presentation</a>

# Components:
1. PL2303 USB to Serial/UART Bridge Controller:
   # HARDWARE :
      • The PL2303TA facilitates the connection of an RS232-like full-duplex asynchronous serial device to a USB capable host.
      • Highly compatible drivers allow existing COM port-based applications to operate over USB without significant modifications.
      • Supports USB bulk transfer mode for higher throughput and flexible baud rates ranging from 75 bps to 6M bps.
      • Compliant with USB2.0 full-speed devices and includes integrated transceiver.
   # SOFTWARE :
      • PL2303 Windows Driver: Allows the PL2303 USB to Serial/UART Bridge Controller to interface with Windows operating systems, simulating a traditional COM port.
      • PuTTY: Free and open-source terminal emulator and serial console for connecting to serial ports.
      • Visual Studio Code: Free and open-source code editor for building and debugging applications, with support for various programming languages.
   # PROTOCOL :
      • Universal Asynchronous Receiver-Transmitter (UART):
      • Protocol for asynchronous serial communication with configurable data format and transmission speeds.
      • Supports simplex, full duplex, and half duplex communication modes.
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/assets/87882944/66ff7298-aeb4-4e81-bc90-6c827dd3d795)

