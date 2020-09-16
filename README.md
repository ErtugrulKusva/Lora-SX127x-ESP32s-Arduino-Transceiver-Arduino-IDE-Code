# Lora-SX127x-ESP32s-Arduino-Transceiver-Arduino-IDE-Code
*In this project, I communicate two Arduino or  two ESP32s with using SX1272MB2DAS semtech shield Transceivers. Modules and modules's pinouts have been given in this repo.
*You can use this library not only sx1272 but also SX1261, SX1262, SX1268, SX1273, SX1276, SX1277, SX1278, SX1279, SX1280, SX1281, SX1282, RF69, RFM22, RFM23, RFM95, RFM96, RFM97, RFM98 and many other wireless modules. However, you have to rearrange pin connections.

*Also, you can use these codes for many other microcontrollers such as Teensy, STM32.

*I wrote these arduino codes with using universal wireless communication library for Arduino You can download from this link:(https://github.com/jgromes/RadioLib) . Plus, I added the library as a zip file in this project.


SPI interface Pinout Connections

Lora SX1272 Semtech <---> ESP32s

3.3 V <---> 3.3 V 

GND <---> GND

NSS <---> D15

DIO0 <---> D2

DIO1 <---> D4

SCK <---> D18

MISO <---> D19

RESET <---> D22

MOSI <---> D23

Lora SX1272 Semtech <---> Arduino

3.3 V <---> 3.3 V 

GND <---> GND

SCK <---> 13

MISO <---> 12

MOSI <---> 11

NSS <---> 9

RESET <---> 5

DIO0 <---> 4

DIO1 <---> 6






