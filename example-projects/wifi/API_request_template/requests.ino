//---------------------------------------------------------------------------------------------------------------------------------------
unsigned int makeGetRequest(String &host, String &url, WiFiClient &client, int port)
{
  Serial.println(((port == 443) ? ("https://") : ("http://")) + host + url);

  if (client.connect(host.c_str(), port))
  {
    delay(1000);
    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: " + host);
    client.println("Connection: close");
    client.println();
  }
  else
  {
    Serial.println("Connection Failed; check:\n\t- did WiFi Connect?\n\t- is the site HTTPS?\n\t- have you used the correct client? (WiFiClient or WiFiSSLClient)\n\t- have you selected the correct port? (80 or 443)n\t- Do you need to upload any certificates?");
    haltFirmware();
  }
  delay(3000);

  unsigned int contentLength = 0;

  Serial.println("------------ Http Header  ------------");
  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.startsWith("Content-Length: "))
    {
      contentLength = getContentLength(line);
    }
    else if (line.startsWith("Transfer-Encoding: chunked"))
    {
      Serial.println("WARNING CHUNKED ENCODING: Email the lecturer");
      chunked = true;
    }
    else if (line == "\r")
    {
      break;
    }
  }

  return contentLength;
}
//---------------------------------------------------------------------------------------------------------------------------------------
JsonObject makeAPIcall(String & host, String & url, WiFiSSLClient &httpClient, int port)
{
  int contentLength = makeGetRequest(host, url, httpClient, port);
  unsigned int charCount;
  if (chunked)
  {
    //    charCount = parseChunked(httpClient);
    haltFirmware();
  }
  else if (contentLength > CHARACTER_LIMIT)
  {
    Serial.print("Your Content Length is: ");
    Serial.println(contentLength);
    Serial.println("Maybe use another request or API");
    haltFirmware();
  }
  else
  {
    charCount = parseContent(contentLength, httpClient);
  }
  Serial.println("------------ HttpResponse ------------");
  printHttpResponse(charCount);
  Serial.println("--------------------------------------");
  DynamicJsonDocument buffer(charCount + 100);
  deserializeJson(buffer, httpResponse);  
  return buffer.as < JsonObject > ();
}
//---------------------------------------------------------------------------------------------------------------------------------------
//
unsigned int getContentLength(String line)
{
  return line.substring(16).toInt();
}
//---------------------------------------------------------------------------------------------------------------------------------------

unsigned int parseChunked(Client &httpClient)
{
  char p = 0;
  unsigned int charCounter = 0;

  String firstNumber = "";

  while (firstNumber == "")
  {
    firstNumber = httpClient.readStringUntil('\n');
  }

  while (true)
  {
    char t = httpClient.read();
    Serial.print(t);
    if (t != 255)
    {
      if (p == '0')
      {
        if (t == 13)
        {
          charCounter--; // PARSE OUT last "0" from result
          break;
        }
      }
      else
      {
        if (t != ' ' && t != '\r' && t != '\n')
        {
          httpResponse[charCounter] = t;
          charCounter++;
          if (charCounter == CHARACTER_LIMIT)
          {
            Serial.println("response is too large to parse");
            haltFirmware();
          }
        }
      }
      p = t;
    }

  }
  return charCounter;
}
//---------------------------------------------------------------------------------------------------------------------------------------

unsigned int parseContent(unsigned int contentLength, Client &httpClient)
{
  unsigned int byteCounter = 0;
  unsigned int charCounter = 0;
  char p = '\0';
  while (true)
  {
    char t = httpClient.read();

    if (t != 255)
    {
      if (t != ' ' && t != '\r' && t != '\n')
      {
        httpResponse[charCounter] = t;
        charCounter++;
      }

      byteCounter++;
      if (byteCounter == contentLength)
      {
        Serial.println(byteCounter);
        break;
      }
    }
    p = t;
  }
  return charCounter;
}
//---------------------------------------------------------------------------------------------------------------------------------------

void printHttpResponse(unsigned int charCount)
{
  for (int i = 0; i < charCount; i++)
  {
    Serial.print(httpResponse[i]);
  }
  Serial.println();
}
