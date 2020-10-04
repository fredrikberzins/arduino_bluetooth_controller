#include <Arduino.h>

int throttle = 0;
int yaw = 0;
int pitch = 0;
int roll = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("start");
}

void loop() {
  throttle = analogRead(A0);
  yaw = analogRead(A1);
  pitch = analogRead(A2);
  roll = analogRead(A3);

  if (throttle == 0);
    
}