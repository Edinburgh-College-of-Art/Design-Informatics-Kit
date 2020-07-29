/*
  Draw the original 16 x 16 pixel Super Mario sprite

  Demonstrating drawing technique and converting colours to 565 colour space.

  The 1.44" TFT breakout https://www.adafruit.com/product/2088

  Wiring:

        | Nano | 1.44" TFT |
        | ---- | --------- |
        | 3.3v | Vin       |
        | GND  | GND       |
        | D13  | SCK       |
        | D12  | SO        |
        | D11  | SI        |
        | D10  | TCS       |
        | D9   | RST       |
        | D8   | D/C       |

*/

//------------------------------------------------------------------------------
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
//------------------------------------------------------------------------------
#define TFT_CS        10
#define TFT_RST        9
#define TFT_DC         8
//------------------------------------------------------------------------------
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
//------------------------------------------------------------------------------
void setup(void)
{
  //----------------------------------------------------------------------------
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  //----------------------------------------------------------------------------
  supermario();
  //----------------------------------------------------------------------------
}
void loop()
{

}
