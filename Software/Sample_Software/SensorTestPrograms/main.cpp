#include <Arduino.h>
// Basic demo for accelerometer readings from Adafruit MPU6050

/** Sample Orientation Program with calibration.
 * NOTE/BUG: the decimal value is getting trimmed somewhere.
 *  -Dylan
 * 
 * Other 'main copy.txt' was the original test program that
 * just recorded angular velocity, not position.
 */

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;
double baseX;
double baseY;
double baseZ;

uint8_t Tp = 50; //Ms
uint8_t tdc = 25;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);

  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);
  baseX = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  baseY = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  baseZ = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
}
int angyX(double baseAng, double ang) {
  double zing = (baseAng - ang);
  if (zing>180) zing = zing-360;
  return zing;
}

int angyY(double baseAng, double ang) {
  double zing = abs((baseAng - ang));
  if (zing>180) zing = zing-360;
  //Serial.printf("B:A %i %i", baseAng, ang);
  return zing;
}

void loop()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
/*
  Serial.print("AngleX= ");
  Serial.println(angyX(baseX,x));

  Serial.print("AngleY= ");
  Serial.println(angyY(baseY,y));

  Serial.println("-----------------------------------------"); */
  
  //Calculate duty cycle with respect to error. 
  //Set high
  delay(tdc);
  //Set low
  delay(Tp-tdc)

}