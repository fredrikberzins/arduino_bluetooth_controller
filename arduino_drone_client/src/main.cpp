#include <Arduino.h>

#include <Wire.h> // Libery for gyro and acelerometer
//# #include <SoftwareSerial.h> // libery for Bluetooth module(HC-06)

//# SoftwareSerial BT(0, 1); 
// creates a "virtual" serial port/UART
// connect BT module RX to Digital TX0
// connect BT module TX to Digital RX1
// connect BT GND to GND
// connect BT Vcc to 5V

#define Motor1 4 // Motor 1 Digital pin 4
#define Motor2 5 // Motor 2 Digital pin 5
#define Motor3 6 // Motor 3 Digital pin 6
#define Motor4 7 // Motor 4 Digital pin 7
#define Motor5 8 // Motor 3 Digital pin 8
#define Motor6 9 // Motor 4 Digital pin 9
#define MotorArm 2 // Motor Arming Digital pin 2

//# long accelX, accelY, accelZ;
//# float gForceX, gForceY, gForceZ;

//# long gyroX, gyroY, gyroZ;
//# float rotX, rotY, rotZ;

//# char Rx_input[4]; //Initializ variable for Serial transfer (over wire)

//# char mode[5] = "TAER";

//# int throttle = 0;
//# int roll = 0;
//# int pitch = 0;
//# int yaw = 0;

int brightness = 0;
int fadeAmount = 5;

void setup()  
{
  // set digital pin to control as an output for motors
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(Motor5, OUTPUT);
  pinMode(Motor6, OUTPUT);
  pinMode(MotorArm, OUTPUT);

  // set the data rate for the serial port/UART, for accelerometer and gyro module.
  Serial.begin(9600);
  //# Wire.begin();
  //# setup_MPU_6050();
  digitalWrite(MotorArm, HIGH);
}

void loop() 
{
  //# Serial.readBytes(Rx_input, 4); //Read the serial data and store in var
  //# Serial.println(Rx_input); //Print data on Serial Monitor
  analogWrite(Motor1, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}