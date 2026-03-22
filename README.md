# Single-Axis Auto-Adjusting Gimbal

## Overview
This project was developed for the SJSU Robotics Firmware Trial. The goal was to create a self-leveling gimbal using an Arduino Uno, an MPU6050 accelerometer, and a servo motor. 
The system maintains a vertical orientation regardless of the base's tilt and allows for dynamic offsets
through the Serial Monitor.

## Technologies
1. Microcontroller:Arduino Uno
2. Sensor:GY-521 MPU6050 (Accelerometer)
3. Servo: SG90

## Details
The firmware was written in C++ using the standard Wire.h and Servo.h libraries.
The MPU6050 was initialized using the I2C Protocol, by writing to and reading from its registers.
Tilt is detected using trigonometry (the atan2 function) and raw x,y,z accelerometer data is printed
alongisde the offset, base angle, and final servo angle.

<img src="https://mail.google.com/mail/u/1?ui=2&ik=e60e2a3b5b&attid=0.1&permmsgid=msg-a:r4939076501611912157&th=19d14521ef514e31&view=fimg&fur=ip&permmsgid=msg-a:r4939076501611912157&sz=s0-l75-ft&attbid=ANGjdJ_gxQWVU8_rwQyaS2pSELjPKeH9jUUEErxn4WUSEKn8GVReIYi3ZZFoWam0A172weO4CAwfvisIxmamyrnQM4kuRf6vRVXy5HPCYBA5DBlFwwZbzuP30dYDrMg&disp=emb&realattid=842A31ED-C903-4440-B6B8-C6C00816E4FC&zw" width="600">
