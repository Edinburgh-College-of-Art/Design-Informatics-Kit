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

      Yes: ArduinoJson
*/

//---------------------------------------------------------------------------------------------------------------------------------------
// Libraries
#include <WiFiNINA.h>
#include <ArduinoJson.h>
//---------------------------------------------------------------------------------------------------------------------------------------
const unsigned int CHARACTER_LIMIT = 5000; // Limit of characters in HTTP response
char httpResponse[CHARACTER_LIMIT]; // If you are getting responses larger that 10kB, use another request.
//---------------------------------------------------------------------------------------------------------------------------------------
// WiFi Connection
const char* ssid = "YOUR_SSID"; // replace these with the name and password for your local wi-fi network
const char* password = "YOUR_WIFI_PASSWORD";
//---------------------------------------------------------------------------------------------------------------------------------------
// API
String host = "raw.githubusercontent.com";
String url = "/Edinburgh-College-of-Art/Connected-Things/master/example-code/json/example-data.json";
//---------------------------------------------------------------------------------------------------------------------------------------
// WiFi Client
WiFiSSLClient client;  // HTTPS
//WiFiClient client;     // HTTP
//---------------------------------------------------------------------------------------------------------------------------------------
// HTTP details
bool chunked = false;
//---------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  while (!Serial) {} // This line is blocking, remove it when you are finished

  connectToWifi(ssid, password);
  JsonObject json = makeAPIcall(host, url, client, 443);

  String someData = json["say"]["hello"][2]["json"].as<String>();
  Serial.println("\n\nSome Data: ");
  Serial.println(someData);
  haltFirmware();
}
//---------------------------------------------------------------------------------------------------------------------------------------

void loop()
{}
