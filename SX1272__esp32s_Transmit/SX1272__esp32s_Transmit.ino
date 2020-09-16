/*
 * SX1272 TRANSMITTER EXAMPLE
  
 */

// include the library
#include <RadioLib.h>

// SX1272 has the following connections:
//esp32s
// NSS pin:   15
// DIO0 pin:  2
// RESET pin: 22
// DIO1 pin:  4
//arduino uno
// NSS pin:   9
// DIO0 pin:  4
// RESET pin: 5
// DIO1 pin:  6
//SX1272 radio = new Module(9, 4, 5, 6); //arduino uno
SX1272 radio = new Module(15, 2, 22, 4); // esp32s


void setup() {
  Serial.begin(9600);

  // initialize SX1272
  Serial.print(F("[SX1272] Initializing ... "));
  int state = radio.begin(867.0,125.0,9,7,0x34,20,8,0); 
  //radio.begin(frequency(860.0-1020.0 MHz), bandwidth(125,250,500 kHz), spreading factor(6-12), coding rate denominater(5-8), sync word, output power(1-20 dBm),preamble length(6-65535), gain(0-6 , 0 automatic,  6 the lowest, max:1))
  
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  Serial.print(F("[SX1272] Transmitting packet ... "));

  // you can transmit C-string or Arduino string up to
  // 256 characters long
  // NOTE: transmit() is a blocking method!
  //       See example SX127x_Transmit_Interrupt for details
  //       on non-blocking transmission method.
  int state = radio.transmit("Test message!");

  // you can also transmit byte array up to 256 bytes long
  /*
    byte byteArr[] = {0x01, 0x23, 0x45, 0x67, 0x89, 200, 0x15, 0x77};
    int state = radio.transmit(byteArr, 8);
 */ 

  if (state == ERR_NONE) {
    // the packet was successfully transmitted
    Serial.println(F(" success!"));

    // print measured data rate
    Serial.print(F("[SX1272] Datarate:\t"));
    Serial.print(radio.getDataRate());
    Serial.println(F(" bps"));

  } else if (state == ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 256 bytes
    Serial.println(F("too long!"));

  } else if (state == ERR_TX_TIMEOUT) {
    // timeout occurred while transmitting packet
    Serial.println(F("timeout!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }

  // wait for a second before transmitting again
  delay(1000);
}
