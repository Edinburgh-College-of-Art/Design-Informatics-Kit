import processing.serial.*;
import java.nio.*;
Serial arduino;

void setup()
{
  
  printArray(Serial.list());
  arduino = new Serial(this, Serial.list()[3], 9600);
  //arduino.buffer(24);
  byte[] pi = {0x40, 0x49, 0x15, byte(0xDA)};
  println(ByteBuffer.wrap(pi).getFloat());
}

void draw()
{  
  updateImuData();
  delay(1000);
}

void updateImuData()
{
  if (arduino.available() == 24)
  { 
    for (int i = 0; i < 6; i++)
    {
      print( ByteBuffer.wrap(arduino.readBytes(4)).order(ByteOrder.LITTLE_ENDIAN).getFloat());
      print("\t\t");
    }
    println();
    arduino.write(1);
  }
}
