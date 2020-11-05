#include <Arduino.h>

#define right_x_axis A0
#define right_y_axis A1
#define left_x_axis A2
#define left_y_axis A3

#define right_switch 2
#define left_switch 3

#define BT_out 0
#define BT_in 1

void setup()  
{
  //set digital pins as input and output for HS-06 (bluetooth module).
  pinMode(BT_out, OUTPUT);
  pinMode(BT_in, INPUT);

  //set analog pins as input from joystick.
  pinMode(right_x_axis, INPUT);
  pinMode(right_y_axis, INPUT);
  pinMode(left_x_axis, INPUT);
  pinMode(left_y_axis, INPUT);

  //set digital pins as input from joystick switchs.
  pinMode(right_switch, INPUT);
  pinMode(left_switch, INPUT);

  // set the data rate for the serial monitor.
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(analogRead(right_x_axis));
  delay(1000);
}