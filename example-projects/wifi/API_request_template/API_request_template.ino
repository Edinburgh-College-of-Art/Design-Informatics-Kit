/*
   What is this called?

   What does it do?

   Who wrote it? and when?

   What equipment do I need?

   What pins are connected to what?

 | Arduino Pin | Device pin |
 | ----------- | ---------- |
 | 0           |            |
 | 1           |            |
 | 2           |            |
 | 3           |            |
 | 5V          |            |
 | GND         |            |

   Do you need to add any certificates?

   Do you need to add any Libraries?
 */

//---------------------------------------------------------------------------------------------------------------------------------------
// Libraries
#include <WiFiNINA.h>
#include <ArduinoJson.h>
//---------------------------------------------------------------------------------------------------------------------------------------
const unsigned int CHARACTER_LIMIT= 10000; // Limit of characters in HTTP response
//---------------------------------------------------------------------------------------------------------------------------------------
// WiFi Connection
const char* ssid = "YOUR_SSID";          // replace these with the name and password for your local wi-fi network
const char* password = "YOUR_WIFI_PASSWORD";
//---------------------------------------------------------------------------------------------------------------------------------------
// API
String host = "raw.githubusercontent.com";
String url = "/Edinburgh-College-of-Art/Connected-Things/master/example-code/json/example-data.json";
//---------------------------------------------------------------------------------------------------------------------------------------
// WiFi Client
//WiFiSSLClient sslClient;  // HTTPS
//WiFiClient client;        // HTTP
//char httpResponse[CHARACTER_LIMIT]; // If you are getting responses larger that 10kB, use another request.
//---------------------------------------------------------------------------------------------------------------------------------------
// Timer
//unsigned long updateTimer = 300000;
//---------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {} // This line is blocking, remove it when you are finished

  connectToWifi(ssid, password);

//  JsonObject json = makeAPIcall(host, url, client, 443);
//
//  String someData = json["say"]["hello"][2]["json"]; // This will change depending on the API of course
//
//  Serial.println("\n\nSome Data: ");
//  Serial.println(someData);
  Serial.println("Now Get to Work!");
  haltFirmware();
}
//---------------------------------------------------------------------------------------------------------------------------------------

void loop()
{}
