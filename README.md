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

![IMG_6276](https://github.com/user-attachments/assets/8c16e335-a20f-4902-a334-c371edee69b2)

