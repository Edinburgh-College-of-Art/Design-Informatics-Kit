
//---------------------------------------------------------------------------------------------------------------------------------------
void connectToWifi(const char* ssid, const char* pass)
{
  int status = WiFi.status();
  if (status == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");
    haltFirmware();
  }

  Serial.println("Starting...");
  Serial.println("Connecting to WiFi.");

  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(3000);
  }
  delay(1000);
  Serial.println("------------ WiFi Details ------------");
  Serial.println("You're connected to the network");
  printCurrentNet();
  printWifiData();
  Serial.println("--------------------------------------");

}
//---------------------------------------------------------------------------------------------------------------------------------------
void printWifiData()
{
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);

  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printMacAddress(mac);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printCurrentNet()
{
  Serial.print(" SSID: ");
  Serial.println(WiFi.SSID());

  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  printMacAddress(bssid);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printMacAddress(byte mac[])
{
  for (int i = 5; i >= 0; i--)
  {
    if (mac[i] < 16)
    {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0)
    {
      Serial.print(":");
    }
  }
  Serial.println();
}
//---------------------------------------------------------------------------------------------------------------------------------------
void haltFirmware()
{
//  WiFi.disconnect();
  WiFi.end();
  Serial.println("\n\nSTOPPING THE PROGRAM!");
  while (true) {}
}
//---------------------------------------------------------------------------------------------------------------------------------------
