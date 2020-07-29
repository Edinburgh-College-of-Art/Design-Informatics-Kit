//------------------------------------------------------------------------------
const unsigned int getWidth()
{
  return 128;
}
//------------------------------------------------------------------------------
const unsigned int getHeight()
{
  return 128;
}
//------------------------------------------------------------------------------
void supermario()
{
  const uint16_t b = 0x0000;
  const uint16_t r = rgb24to16(0xF00000);
  const uint16_t s = rgb24to16(0xE0A040);
  const uint16_t h = rgb24to16(0x80701A);

  const int c[16][16] = {
    {b, b, b, b, b, r, r, r, r, r, r, b, b, b, b, b},
    {b, b, b, b, r, r, r, r, r, r, r, r, r, r, b, b},
    {b, b, b, b, h, h, h, h, s, s, h, s, b, b, b, b},
    {b, b, b, h, h, s, h, s, s, s, h, s, s, s, b, b},
    {b, b, b, h, h, s, h, h, s, s, s, h, s, s, s, b},
    {b, b, b, h, h, h, s, s, s, s, h, h, h, h, b, b},
    {b, b, b, b, b, s, s, s, s, s, s, s, s, b, b, b},
    {b, b, b, b, h, h, h, r, h, h, h, b, b, b, b, b},
    {b, b, b, h, h, h, h, r, h, h, r, h, h, h, b, b},
    {b, b, h, h, h, h, h, r, r, r, r, h, h, h, h, b},
    {b, b, s, s, s, h, r, s, r, r, s, r, h, s, s, b},
    {b, b, s, s, s, s, r, r, r, r, r, r, s, s, s, b},
    {b, b, s, s, s, r, r, r, r, r, r, r, r, s, s, b},
    {b, b, b, b, r, r, r, r, b, r, r, r, r, b, b, b},
    {b, b, b, h, h, h, h, b, b, b, h, h, h, h, b, b},
    {b, b, h, h, h, h, h, b, b, b, h, h, h, h, h, b}
  };

  const int blockSize = getHeight() / 16;
  for (int y = 0; y < 16; y++)
  {
    for (int x = 0; x < 16; x++)
    {
      tft.fillRect(x * blockSize, y * blockSize,
                   blockSize,     blockSize,
                   c[y][x]);
    }
  }
}
//------------------------------------------------------------------------------
/*!
 * Convert Colours from 24-bit hex to 16-bit 565 colours
 */
uint16_t rgb24to16(uint32_t c)
{
  uint8_t red   = (c >> 16) & 0xFF;
  uint8_t green = (c >> 8) & 0xFF;;
  uint8_t blue  = (c >> 0) & 0xFF;;
  return (((red & 0xf8) << 8) + ((green & 0xfc) << 3) + (blue >> 3));
}
