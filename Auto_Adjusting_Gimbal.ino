#include "Wire.h"
#include "Servo.h"

const int address = 0x68;
const int servoPin = 9;

int16_t accelerometer_x;
int16_t accelerometer_y;
int16_t accelerometer_z;

const int ACCEL_XOUT_H = 0x3B;
const int PWR_MGMT_1 = 0x6B;

int baseAngle=90;
int angle;
int offset=0;

Servo myServo;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);

  Wire.begin(); //Initiates the wire library.


  Wire.beginTransmission(address);
  Wire.write(PWR_MGMT_1);
  Wire.write(0); //Set the register to 0. Wakes up the MPU6050.
  Wire.endTransmission(true); //sends a stop condition
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() >0){ //Checks if there are bytes to read in the serial monitor.
    int newAngle = Serial.parseInt();
    if (newAngle>0 && newAngle <180){
      baseAngle= newAngle;
    }
  }

  Wire.beginTransmission(address);
  Wire.write(ACCEL_XOUT_H); //Starting with register 0x3B.
  Wire.endTransmission(false); //sends a restart condition
  Wire.requestFrom(address, 6, true); //Registers 0x3B-0x40 - Accelerometer Measurements (x,y,z)
  
  accelerometer_x = (Wire.read()<<8) | Wire.read(); //Shift upper half 8 bits left, then use OR operator with lower half to combine them.
  accelerometer_y =  (Wire.read()<<8) | Wire.read();
  accelerometer_z =  (Wire.read()<<8) | Wire.read();

  Serial.print("x = ");
  Serial.print(accelerometer_x); //printing the raw values

  Serial.print(" |  y = ");
  Serial.print(accelerometer_y);

  Serial.print(" |  z = ");
  Serial.print(accelerometer_z);


  offset = atan2(accelerometer_y, accelerometer_z)*(180)/PI; //atan2 returns angle in radians. Takes care of the sign and divide by zero problem.
  
  angle = baseAngle+offset;
  angle = constrain(angle, 0,180); //preventing offset from going beyond 180/

  
  myServo.write(angle);

  Serial.print(" | baseAngle = ");
  Serial.print(baseAngle);

  Serial.print(" | angle = ");
  Serial.print(angle);

  Serial.print(" | offset = ");
  Serial.println(offset);

  delay(100);


}