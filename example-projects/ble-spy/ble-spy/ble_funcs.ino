/*
 * Helper Functions for working worth BLE
 */

void explorerPeripheral(BLEDevice peripheral) 
{
  Serial.println("Connecting ...");

  if (peripheral.connect()) 
  {
    Serial.println("Connected");
  } 
  else 
  {
    Serial.println("Failed to connect!");
    return;
  }

  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) 
  {
    Serial.println("Attributes discovered");
  } 
  else 
  {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }
  Serial.println();
  Serial.print("Device name: ");
  Serial.println(peripheral.deviceName());
  Serial.print("Appearance: 0x");
  Serial.println(peripheral.appearance(), HEX);
  Serial.println();

  for (int i = 0; i < peripheral.serviceCount(); i++) 
  {
    BLEService service = peripheral.service(i);
    exploreService(service);
  }

  Serial.println();
  Serial.println("Disconnecting ...");
  peripheral.disconnect();
  Serial.println("Disconnected");
}
//------------------------------------------------------------------------------
void exploreService(BLEService service) 
{
  Serial.print("Service ");
  Serial.println(service.uuid());

  for (int i = 0; i < service.characteristicCount(); i++) 
  {
    BLECharacteristic characteristic = service.characteristic(i);
    exploreCharacteristic(characteristic);
  }
}
//------------------------------------------------------------------------------
void exploreCharacteristic(BLECharacteristic characteristic) 
{
  Serial.print("\tCharacteristic ");
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
  for (int i = 0; i < length; i++) {
    unsigned char b = data[i];

    if (b < 16) {
      Serial.print("0");
    }

    Serial.print(b, HEX);
  }
}
//------------------------------------------------------------------------------
void printPreripheralInfo(BLEDevice &peripheral)
{
  Serial.print("Found ");
  Serial.print(peripheral.address());
  Serial.print(" '");
  Serial.print(peripheral.localName());
  Serial.print("' ");
  Serial.print(peripheral.advertisedServiceUuid());
  Serial.println();
}
