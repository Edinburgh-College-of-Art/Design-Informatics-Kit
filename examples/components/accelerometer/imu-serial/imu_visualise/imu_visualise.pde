import processing.serial.*;
import java.nio.*;
Serial arduino;

float pitch, roll, lastRoll, lastPitch;
float ax, ay, az, gx, gy, gz;
PImage img;
float data[];
void setup()
{
  size(400, 400, P3D);
  printArray(Serial.list());
  arduino = new Serial(this, Serial.list()[3], 9600);
  img = loadImage("di_logo2.png");
  data = new float[6];
}

void draw()
{
  // Get new reading from serial port
  updateImuData();
  // get pitch and roll
  pitch = getPitch();
  roll = getRoll();
  //println(pitch, roll);
  background(0);
  noStroke() ;

  // Put view in the middle of the screen
  // and far enough away to see properly
  translate(width/2, height/2, -100);

  // Rotate view
  rotateX(-pitch);
  rotateZ(roll);

  // Zoom
  scale(190);

  // Draw the box
  drawBox(0.6, 0.1, 1);
}

float getPitch()
{
  if (ay * sin(roll) + az * cos(roll) == 0)
  {
    pitch = (ax > 0) ? (PI / 2) : (-PI / 2);
  } else
  {
    pitch = atan(-ax / (ay * sin(roll) + (az * cos(roll))));
  }
  return pitch;
}

float getRoll()
{
  return atan2(ay, az);
}

void drawBox(float w, float h, float d)
{
  // Front
  beginShape(QUADS) ;
  fill(255, 0, 0) ;
  vertex(-w, -h, d) ;
  vertex( w, -h, d) ;
  vertex( w, h, d);
  vertex(-w, h, d) ;
  endShape() ;

  // Back
  beginShape(QUADS) ;
  fill(255, 255, 0) ;
  vertex( w, -h, -d) ;
  ;
  vertex(-w, -h, -d);
  vertex(-w, h, -d) ;
  vertex( w, h, -d);
  endShape() ;

  // Bottom
  beginShape(QUADS);
  fill( 255, 0, 255);
  vertex(-w, h, d);
  vertex( w, h, d);
  vertex( w, h, -d);
  vertex(-w, h, -d);
  endShape();

  // Top

  blendMode(REPLACE);
  textureMode(NORMAL);
  textureWrap(CLAMP);
  beginShape(QUADS);
  texture(img);
  tint(255, 255, 255);
  vertex(-w, -h, -d, -1, -0.2);
  vertex( w, -h, -d, 2, -0.2);
  vertex( w, -h, d, 2, 1.2);
  vertex(-w, -h, d, -1, 1.2);
  endShape();

  // Right
  beginShape(QUADS);
  fill(0, 0, 255);
  vertex( w, -h, d);
  vertex( w, -h, -d);
  vertex( w, h, -d);
  vertex( w, h, d);
  endShape();

  // Left
  beginShape(QUADS);
  fill(0, 255, 0) ;
  vertex(-w, -h, -d) ;
  vertex(-w, -h, d) ;
  vertex(-w, h, d) ;
  vertex(-w, h, -d);
  endShape();
}

void updateImuData()
{

  if (arduino.available() == 24)
  {
    for (int i = 0; i < 6; i++)
    {
      data[i] =  ByteBuffer.wrap(arduino.readBytes(4)).order(ByteOrder.LITTLE_ENDIAN).getFloat();
    }
    ax = data[0];
    ay = data[1];
    az = data[2];
    gx = data[3];
    gy = data[4];
    gz = data[5];
    arduino.write(1);
  }
}
