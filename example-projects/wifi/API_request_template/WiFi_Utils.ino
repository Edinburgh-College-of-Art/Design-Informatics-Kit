//Setting up a WiFi connection - COMPLETE

void connectToWifi(const char ssidName[], const char pass[])
{
  Serial.println("Starting...");
  Serial.println("Connecting to WiFi.");

  int conn = WiFi.begin(ssidName, pass);

  switch (conn)
  {
    case WL_CONNECTED:
      Serial.println("OK!");
      break;
    case WL_IDLE_STATUS:
      Serial.println("Idle");
      break;
    default:
      Serial.println("WiFi Connection Failed!");

  }
}

void haltFirmware()
{
  Serial.println("\n\nSTOPPING THE PROGRAM!");
  while(true) {}
}
