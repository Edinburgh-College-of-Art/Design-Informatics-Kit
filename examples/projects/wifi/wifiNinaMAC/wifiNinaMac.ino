#include <WiFiNINA.h>

byte mac[6];
const char* ssid = "Major Crimes";          // replace these with the name and password for your local wi-fi network
const char* password = "The Bunk";

void setup()
{
  Serial.begin(9600);

  while (!Serial) {}

  WiFi.macAddress(mac);
  for (int i = 5; i >= 0; i--)
  {
    if (mac[i] < 16)
      Serial.print(0);

    Serial.print(mac[i], HEX);
    Serial.print((i == 0) ? "" : ":");
  }
}

void loop ()
{
  while (!Serial) {}
  connectToWifi(ssid, password);
  Serial.println("Now Get to Work!");
  haltFirmware();
}
