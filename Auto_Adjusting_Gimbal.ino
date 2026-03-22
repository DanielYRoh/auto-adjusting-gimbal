#include "Wire.h"

const int address = 0x68;

int16_t accelerometer_x;
int16_t accelerometer_y;

const int ACCEL_XOUT_H = 0x3B;
const int PWR_MGMT_1 = 0x6B;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin(); //Initiates the wire library.


  Wire.beginTransmission(address);
  Wire.write(PWR_MGMT_1);
  Wire.write(0); //Set the register to 0. Wakes up the MPU6050.
  Wire.endTransmission(true); //sends a stop condition
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(address);
  Wire.write(ACCEL_XOUT_H); //Starting with register 0x3B.
  Wire.endTransmission(false); //sends a restart condition
  Wire.requestFrom(address, 4, true); //Registers 0x3B-0x3E - Accelerometer Measurements (x,y)
  
  accelerometer_x = (Wire.read()<<8) | Wire.read(); //Shift upper half 8 bits left, then use OR operator with lower half to combine them.
  accelerometer_y =  (Wire.read()<<8) | Wire.read();

  Serial.print("x = ");
  Serial.print(accelerometer_x);

  Serial.print("|  y = ");
  Serial.println(accelerometer_y);

  delay(1000);


}
