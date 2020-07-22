/*
   PN532 Test Memory Dump

    Pin Map
    -------

    | Nano | PN532           |
    | ---- | --------------- |
    | VIN  | 3.3v            |
    | 13   | SCK             |
    | 12   | MISO            |
    | 11   | MOSI / SDA / TX |
    | 10   | SSEL / SCL / RX |
    | GND  | GND             |
*/
//==============================================================================
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
//==============================================================================
const uint8_t sselPin = 10;
Adafruit_PN532 nfc(sselPin);
//==============================================================================
void setup(void)
{
  //----------------------------------------------------------------------------
  Serial.begin(9600);  // has to be fast to dump the entire memory contents!
  waitForSerial();
  //----------------------------------------------------------------------------
  setupReader();
  //----------------------------------------------------------------------------  
  Serial.println("Waiting for an ISO14443A Card ...");
  //----------------------------------------------------------------------------
}
//==============================================================================

void loop(void)
{
  //----------------------------------------------------------------------------
  memoryDumpCard();
  //----------------------------------------------------------------------------  
//  waitForSerialInput();
  //----------------------------------------------------------------------------
}
