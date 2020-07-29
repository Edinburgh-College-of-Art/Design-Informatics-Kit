/*
   Helper Functions for working worth BLE
*/

void explorerPeripheral(BLEDevice peripheral)
{
  BLE.stopScan();
  Serial.print("\t");
  int attempts = 0;
  while (!peripheral.connected() && attempts < 5)
  {
    peripheral.connect();
    delay(1000);
    attempts++;
    Serial.print(".");
  }
  Serial.println();
  if (!peripheral.connected())
  {
    BLE.scan();
    return;
  }
  if (!peripheral.discoverAttributes())
  {
    Serial.println("\tAttribute discovery failed!");
    peripheral.disconnect();
    BLE.scan();
    return;
  }
  Serial.print("\tDevice name: ");
  Serial.println(peripheral.deviceName());
  for (int i = 0; i < peripheral.serviceCount(); i++)
  {
    BLEService service = peripheral.service(i);
    if (service.uuid()[0] == '1' && service.uuid()[1] == '8')
      exploreService(service);
  }
  peripheral.disconnect();
  BLE.scan();
}
//------------------------------------------------------------------------------
void exploreService(BLEService service)
{
  Serial.print("\tService ");
  Serial.println(service.uuid());
  if (String(service.uuid()).equals("180f"))
  {
    Serial.print("\tBattery ");
    for (int i = 0; i < service.characteristicCount(); i++)
    {
      BLECharacteristic characteristic = service.characteristic(i);
      if (String(characteristic.uuid()).equals("2a19"))
      {
        Serial.print("\tBattery ");
        printBatteryLevel(characteristic);
      }
    }
  }
  else
  {
    for (int i = 0; i < service.characteristicCount(); i++)
    {
      BLECharacteristic characteristic = service.characteristic(i);
      exploreCharacteristic(characteristic);
    }
  }
}
//------------------------------------------------------------------------------
void printBatteryLevel(BLECharacteristic characteristic)
{
  if (characteristic.canRead())
  {
    Serial.print("\tBattery ");
    characteristic.read();

    if (characteristic.valueLength() > 0)
    {
      Serial.print(", value 0x");
      Serial.print(characteristic.valueLength());

      Serial.println((*(uint16_t*)characteristic.value()));
      
      for (int i = 0; i < characteristic.valueLength(); i++)
      {
        unsigned char b = characteristic.value()[i];
        Serial.print(b);
      }
    }
  }
  Serial.println();
}

void exploreCharacteristic(BLECharacteristic characteristic)
{
  Serial.print("\t\tCharacteristic ");
  Serial.print(characteristic.uuid());
  Serial.print(", properties 0x");
  Serial.print(characteristic.properties(), HEX);

  if (characteristic.canRead())
  {
    characteristic.read();

    if (characteristic.valueLength() > 0)
    {
      Serial.print(", value 0x");
      printData(characteristic.value(), characteristic.valueLength());
    }
  }
  Serial.println();

  for (int i = 0; i < characteristic.descriptorCount(); i++)
  {
    BLEDescriptor descriptor = characteristic.descriptor(i);
    exploreDescriptor(descriptor);
  }
}
//------------------------------------------------------------------------------
void exploreDescriptor(BLEDescriptor descriptor)
{
  Serial.print("\t\tDescriptor ");
  Serial.print(descriptor.uuid());
  descriptor.read();
  Serial.print(", value 0x");
  printData(descriptor.value(), descriptor.valueLength());

  Serial.println();
}
//------------------------------------------------------------------------------
void printData(const unsigned char data[], int length)
{
  for (int i = 0; i < length; i++)
  {
    unsigned char b = data[i];
    Serial.print(char(b));
  }
}
//------------------------------------------------------------------------------
void printPreripheralInfo(BLEDevice &peripheral)
{
  Serial.print(peripheral.address());
  Serial.print("\t'");
  Serial.print(peripheral.localName());
  Serial.print("'");
  Serial.print((peripheral.localName().length() < 4) ? "\t\t" : "\t");
  Serial.print(peripheral.rssi());
  Serial.println();
}
//------------------------------------------------------------------------------
bool deviceIsNew(BLEDevice &peripheral)
{
  bool newDev = true;
  for (int i = 0 ; i < numDevices; i++)
  {
    if (peripheral == foundDevices[i])
    {
      newDev = false;
      break;
    }
  }
  return newDev;
}
//------------------------------------------------------------------------------

void printHeader()
{
  Serial.print("Address\t\t\t");
  Serial.print("Local Name\t");
  Serial.print("Service UUID\t");
  Serial.print("RSSI\n");
  Serial.println();
}
