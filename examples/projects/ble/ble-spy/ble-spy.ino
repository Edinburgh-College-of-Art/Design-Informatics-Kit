/*
  Ble-Spy:

  List all BLE devices nearby and try and print what they are
*/
//------------------------------------------------------------------------------
#include <ArduinoBLE.h>
//------------------------------------------------------------------------------
const int maxDevices = 50;
int numDevices = 0;
BLEDevice foundDevices[maxDevices];
unsigned long lastTime = 0;
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
      foundDevices[numDevices] = peripheral;
    }
  }

  //  if (millis() - lastTime > 5000u)
  //  {
  //    lastTime = millis();
  //    for (int i = 0 ; i < numDevices; i++)
  //    {
  //      getPeripheralInfo(foundDevices[i]);
  //      explorerPeripheral(foundDevices[i]);
  //    }
}

//------------------------------------------------------------------------------
