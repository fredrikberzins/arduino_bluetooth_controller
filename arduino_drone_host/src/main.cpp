#include <Arduino.h>

#include <SoftwareSerial.h> // libery for Bluetooth module(HC-05)

SoftwareSerial BT(0, 1); 
// creates a "virtual" serial port/UART
// connect BT module RX to Digital TX0
// connect BT module TX to Digital RX1
// connect BT GND to GND
// connect BT Vcc to 5V

#define chnage_factor_for_input 8.8; // Used to change the input of 0-880 to 0-100

int throttle = 0;
int yaw = 0;
int pitch = 0;
int roll = 0;

#define throttle_input analogRead(A0)
#define yaw_input analogRead(A1)
#define pitch_input analogRead(A2)
#define roll_input analogRead(A3)
#define right_stick_switch 14
#define left_stick_switch 15

void setup() {
  pinMode(throttle_input,INPUT);
  pinMode(yaw_input,INPUT);
  pinMode(pitch_input,INPUT);
  pinMode(roll_input,INPUT);
  
  pinMode(right_stick_switch,INPUT);
  pinMode(left_stick_switch,INPUT);

  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  throttle = throttle_input/chnage_factor_for_input;
  yaw = yaw_input/chnage_factor_for_input;
  pitch = pitch_input/chnage_factor_for_input;
  roll = roll_input/chnage_factor_for_input;
  
  Serial.print("\n\n");
  Serial.println((String)"throttle: "+ throttle +" input:"+ throttle_input);
  Serial.println((String)"yaw: "+ yaw +" input:"+ yaw_input);
  Serial.println((String)"pitch: "+ pitch +" input:"+ pitch_input);
  Serial.println((String)"roll: "+ roll +" input:"+ roll_input);
  delay(5000);
}