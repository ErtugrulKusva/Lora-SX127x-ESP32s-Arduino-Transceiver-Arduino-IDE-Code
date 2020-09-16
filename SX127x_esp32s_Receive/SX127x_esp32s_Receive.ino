//SX 1272 RECEIVER EXAMPLE
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
SX1272 radio = new Module(9, 4, 5, 6); //arduino uno
//SX1272 radio = new Module(15, 2, 22, 4); // esp32s

void setup() {
  Serial.begin(9600);

  // initialize SX1272 with default settings
  Serial.print(F("[SX1272] Initializing ... "));
  int state = radio.begin(867.0,125.0,9,7,0x34,20,8,0); // 868 -1020
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  Serial.print(F("[SX1272] Waiting for incoming transmission ... "));

  // you can receive data as an Arduino String
  // NOTE: receive() is a blocking method!
  //       See example ReceiveInterrupt for details
  //       on non-blocking reception method.
  String str;
  int state = radio.receive(str);

  // you can also receive data as byte array
  /*
    byte byteArr[8];
    int state = radio.receive(byteArr, 8);
  */

  if (state == ERR_NONE) {
    // packet was successfully received
    Serial.println(F("success!"));

    // print the data of the packet
    Serial.print(F("[SX1272] Data:\t\t\t"));
    Serial.println(str);

    // print the RSSI (Received Signal Strength Indicator)
    // of the last received packet
    Serial.print(F("[SX1278] RSSI:\t\t\t"));
    Serial.print(radio.getRSSI());
    Serial.println(F(" dBm"));

    // print the SNR (Signal-to-Noise Ratio)
    // of the last received packet
    Serial.print(F("[SX1272] SNR:\t\t\t"));
    Serial.print(radio.getSNR());
    Serial.println(F(" dB"));

    // print frequency error
    // of the last received packet
    Serial.print(F("[SX1272] Frequency error:\t"));
    Serial.print(radio.getFrequencyError());
    Serial.println(F(" Hz"));

  } else if (state == ERR_RX_TIMEOUT) {
    // timeout occurred while waiting for a packet
    Serial.println(F("timeout!"));

  } else if (state == ERR_CRC_MISMATCH) {
    // packet was received, but is malformed
    Serial.println(F("CRC error!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }
}
