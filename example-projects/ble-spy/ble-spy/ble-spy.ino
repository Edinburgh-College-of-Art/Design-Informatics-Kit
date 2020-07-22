/*
  Ble-Spy:

  List all BLE devices nearby and try anmd print what they are
*/
//------------------------------------------------------------------------------
#include <ArduinoBLE.h>
//------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin())
  {
    halt("starting BLE failed!");
  }

  Serial.println("BLE Central - Peripheral Explorer");
  BLE.scan();
}
//------------------------------------------------------------------------------
void loop() 
{
  BLEDevice peripheral = BLE.available();

  if (peripheral) 
  {
    printPreripheralInfo(peripheral);
  }
}
//------------------------------------------------------------------------------
