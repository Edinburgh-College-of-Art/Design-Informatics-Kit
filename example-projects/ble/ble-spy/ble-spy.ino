/*
  Ble-Spy:

  List all BLE devices nearby and try anmd print what they are
*/
//------------------------------------------------------------------------------
#include <ArduinoBLE.h>
//------------------------------------------------------------------------------
const int maxDevices = 50;
int numDevices = 0;
String foundDevices[maxDevices];
//------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin())
  {
    halt("starting BLE failed!");
  }
  delay(3000);
  Serial.println("BLE Central - Peripheral Explorer");
  BLE.scan();
  printHeader();
}
//------------------------------------------------------------------------------
void loop()
{
  BLEDevice peripheral = BLE.available();

  if (peripheral)
  {
    if (deviceIsNew(peripheral) && numDevices < maxDevices)
    {
      printPreripheralInfo(peripheral);
      explorerPeripheral(peripheral);
      numDevices++;
      foundDevices[numDevices] = peripheral.address();
    }
  }
}
//------------------------------------------------------------------------------
