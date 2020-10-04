#include <Arduino.h>

#include <Wire.h> // Libery for gyro and acelerometer
#include <SoftwareSerial.h> // libery for Bluetooth module(HC-06)

SoftwareSerial BT(0, 1); 
// creates a "virtual" serial port/UART
// connect BT module RX to Digital TX0
// connect BT module TX to Digital RX1
// connect BT GND to GND
// connect BT Vcc to 5V

#define Motor1 6 // Motor 1 Digital pin 6
#define Motor2 7 // Motor 2 Digital pin 7
#define Motor3 8 // Motor 3 Digital pin 8
#define Motor4 9 // Motor 4 Digital pin 9
#define MotorArm 2 // Motor Arming Digital pin 2

long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;


void setup()  
{
  // set digital pin to control as an output for motors
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(MotorArm, OUTPUT);

  // set the data rate for the serial port/UART, for Bluetooth module.
  BT.begin(9600);

  // set the data rate for the serial port/UART, for accelerometer and gyro module.
  Serial.begin(9600);
  Wire.begin();
  setupMPU();

  // Send test message to other device
  BT.println("Reciver: Setup done");
}

void setupMPU(){
  Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();  
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1B); //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4) 
  Wire.write(0x00000000); //Setting the gyro to full scale +/- 250deg./s 
  Wire.endTransmission(); 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1C); //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5) 
  Wire.write(0b00000000); //Setting the accel to +/- 2g
  Wire.endTransmission(); 
}


char a; // stores incoming character from other device

void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='1')
    {
      digitalWrite(SW, LOW);// Turn LIGH ON
      BT.println("Light on");
    }
    if (a=='2')
    {
      digitalWrite(SW, HIGH);// Turn LIGHT OFF
      BT.println("Light off");
    }
    if (a=='?')
    {
      BT.println("Send '1' to turn LIGHT on");
      BT.println("Send '2' to turn LIGHT OFF");
    }   
    if (a=='3')
    {
      digitalWrite(SW, HIGH);// Turn LIGHT OFF
      BT.println("Light off");
      delay(500);
      digitalWrite(SW, LOW);// Turn LIGHT OFF
      delay(500);
      digitalWrite(SW, HIGH);// Turn LIGHT OFF
      delay(500);
      digitalWrite(SW, LOW);// Turn LIGHT OFF
    }
    
  }
}
  
