#include <Arduino.h>

/** IMU-Controlled Servo Orientation.
 * Rocket is placed upright vertically. 
 * Orientation is calibrated at 0 degrees for two axis.
 * 
 * Required duty cycle is then calculated to drive the servos.
 * 
 * Other 'main copy.txt' was the original test program that
 * just recorded angular velocity, not position.
 */

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ; //int16_t

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;
double baseX;
double baseY;
double baseZ;

float Tp = 50; //Duty cycle period (20 Hz), is later converted to 60 Hz.
float tdc = 25; //uint_8

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
  pinMode(5, OUTPUT);
}
float angyX(double baseAng, double ang) {
  double zing = (baseAng - ang);
  if (zing>180) zing = zing-360;
  return zing;
}

float angyY(double baseAng, double ang) {
  double zing = (double)abs((baseAng - ang));
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
  double xAng = map(AcX, minVal, maxVal, -90, 90);
  double yAng = map(AcY, minVal, maxVal, -90, 90);
  double zAng = map(AcZ, minVal, maxVal, -90, 90);

  //delay(700);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);



  /*Serial.print("AngleX= ");
  Serial.println(angyX(baseX,x));

  Serial.print("AngleY= ");
  Serial.println(angyY(baseY,y));

  Serial.println("-----------------------------------------"); 
  delay(300);*/
  
  
  /*
    Duty-cycle of 6% positions the servo at midpoint, 90 degrees. 
    0% is 0 degrees, 12% is 180 degrees. 

    The current code is a proof of functionality expirement. 
    It is currently implemented with a polling approach. 
    For greater responsivness upon integration with the wider avionics system,
     It is strongly advised to call this module via timer-based interrupts. 
  */
  double xxAng = (angyX(baseX,x));
  if(xxAng>0) {
    if (xxAng > 10) xxAng = 10;
    tdc = 3 + (Tp*xxAng/180) * 0.12; //Where the '3' constant is 6%. (3/50).
    //Serial.println(tdc);
  }
  else if(xxAng<0) {
    if (xxAng < -10) xxAng = -10;
    tdc = 3 + (Tp*xxAng/180) * 0.12;
    //Serial.println(tdc);
  }

  digitalWrite(5, HIGH);
  delay(tdc/3);
  digitalWrite(5, LOW);
  delay((Tp-tdc)/3);
}
