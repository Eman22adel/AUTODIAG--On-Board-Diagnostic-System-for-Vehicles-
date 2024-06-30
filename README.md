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
# 1. PL2303 USB to Serial/UART Bridge Controller:
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Picture1.jpg)
# HARDWARE :
-  The PL2303TA facilitates the connection of an RS232-like full-duplex asynchronous serial device to a USB capable host.
-  Highly compatible drivers allow existing COM port-based applications to operate over USB without significant modifications.
-  Supports USB bulk transfer mode for higher throughput and flexible baud rates ranging from 75 bps to 6M bps.
-  Compliant with USB2.0 full-speed devices and includes integrated transceiver.


# SOFTWARE :
- PL2303 Windows Driver: Allows the PL2303 USB to Serial/UART Bridge Controller to interface with Windows operating systems, simulating a traditional COM
        port.
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20141613.png)
      
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20141221.png)
   
- PuTTY: Free and open-source terminal emulator and serial console for connecting to serial ports.
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20141234.png)
   
- Visual Studio Code: Free and open-source code editor for building and debugging applications, with support for various programming languages.
   
# PROTOCOL :
- Universal Asynchronous Receiver-Transmitter (UART).
   
- Protocol for asynchronous serial communication with configurable data format and transmission speeds.
   
- Supports simplex, full duplex, and half duplex communication modes.
   
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Picture7.jpg)
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Picture6.png)

# 2. STM32F103C8T6 MICROCONTROLLER:
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/STM.png)
# HARDWARE :
- Scalability: The microcontrollers offer a range of package options from 36 to 100 pins, providing flexibility in system design and upgrades.

- Power Efficiency: They operate within a 2.0 to 3.6 V power supply range and offer power-saving modes, making them suitable for energy-conscious 
  applications.
  
- Robust I/O Capabilities: With a wide range of enhanced I/Os and peripherals, these microcontrollers provide extensive connectivity options, ideal for 
  interfacing with various devices.
  
- Real-Time Performance: The high-performance ARM Cortex-M3 32-bit RISC core operating at 72 MHz ensures efficient data handling and real-time performance.

- Versatility: Features like two 12-bit ADCs and multiple timers make these microcontrollers versatile for various applications, from motor control to data 
   acquisition systems.
         
# SOFTWARE :
1- STM32CubeIDE:
      
- Integration with STM32CubeMX: STM32CubeIDE integrates STM32 configuration and project creation functionalities from STM32CubeMX to offer an all-in-one 
  tool experience.
  
- Build and Stack Analyzers: These provide useful information about project status and memory requirements.

- Debugging Features: It includes standard and advanced debugging features including views of CPU core registers, memories, and peripheral registers, as 
  well as live variable watch, Serial Wire Viewer interface, or fault analyzer.
  
- Support for ST-LINK and J-Link Debug Probes: STM32CubeIDE supports ST-LINK (STMicroelectronics) and J-Link (SEGGER) debug probes.

- Multi-OS Support: It supports Windows, Linux, and macOS (64-bit versions only).
         
# PROTOCOL :
1- UART:
- CONFIGRATION :
  
 ![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/PL2303%20USB%20to%20Serial_page9_image.png)
      
- DATA :
  
 ![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20141319.png)

2- SPI : 
- CONFIGRATION :
  
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20150810.png)
          
- DATA :
  
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20151221.png)
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20151301.png)
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20151308.png)
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20151335.png)


# 3. STM32 ST-LINK Utility:    
# HARDWARE :
 The STM32 ST-LINK Utility is a full-featured software interface for programming STM32 microcontrollers1. Here’s a summary of its key features:

- Ease of Use: It provides an easy-to-use and efficient environment for reading, writing, and verifying a memory device.

- Versatility: The tool offers a wide range of features to program STM32 internal memories (Flash, RAM, OTP, and others), external memories, to verify 
  the programming content (checksum, verify during and after programming, compare with file) and to automate STM32 programming.
  
- GUI and CLI: STM32 ST-LINK Utility is delivered as a graphical user interface (GUI) with a command line interface (CLI), making it accessible for 
  different types of users.
  
- Support for Various Formats: It supports Motorola S19, Intel HEX, and binary formats.
         
# SOFTWARE :
  
 ![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/Screenshot%202024-05-15%20143440.png)

# 3. ESP8266:   
![image](https://github.com/Eman22adel/AUTODIAG--On-Board-Diagnostic-System-for-Vehicles-/blob/main/esp.png)
# HARDWARE:
NodeMCU ESP8266 is an open-source firmware and development kit that allows developers to create IOT projects using the ESP8266 Wi-Fi module. The ESP8266 is a low-cost Wi-Fi module that can connect to a Wi-Fi network and communicate with other devices over the internet.
NodeMCU ESP8266 can be used with MQTT Broker. It offers a wide range of features such as real time database, authentication, cloud storage, hosting, and many more. By integrating MQTT Broker with NodeMCU, developers can create IOT projects that can be controlled and monitored remotely.
In our project, the NodeMCU acts as a communication gateway between the STM32 and the HiveMQ Broker. ESP8266 is connected to the vehicle's ECU and transmits data wirelessly through Wi-Fi. This data is then stored in the MQTT Broker database, which can be accessed remotely. 

# SOFTWARE :
Arduino  IDE  is  an  Integrated  Development  Environment  (IDE)  is  a  software application that provides a user-friendly platform for writing, compiling, and uploading code to Arduino microcontrollers. 

# PROTOCOL :
MQTT
MQTT (Message Queuing Telemetry Transport) is a lightweight, publish-subscribe- based  messaging  protocol  designed  for  resource-constrained  devices  and  low- bandwidth, high-latency, or unreliable networks. It plays a crucial role on the Internet of  Things  (IoT)  ecosystem,  enabling  efficient  communication  between  sensors, actuators, and other devices.
In our project, MQTT is used to do communication between ESP8266 as a Client and Hive MQ as MQTT Broker.




