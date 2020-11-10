#include <Arduino.h>

//================
//    Settings
//================

Joystick_chanle_maping = "TAER";
Joystick_stick_mode = 1;
Joystick_output_mode = "RC";

#define right_x_axis_pin A0
#define right_y_axis_pin A1
#define left_x_axis_pin A2
#define left_y_axis_pin A3

#define right_switch_pin 2
#define left_switch_pin 3

#define BT_out 0
#define BT_in 1

void setup()  
{
  //set digital pins as input and output for HS-06 (bluetooth module).
  pinMode(BT_out, OUTPUT);
  pinMode(BT_in, INPUT);

  //set analog pins as input from joystick.
  pinMode(right_x_axis_pin, INPUT);
  pinMode(right_y_axis_pin, INPUT);
  pinMode(left_x_axis_pin, INPUT);
  pinMode(left_y_axis_pin, INPUT);

  //set digital pins as input from buttons.
  pinMode(right_switch_pin, INPUT);
  pinMode(left_switch_pin, INPUT);

  //set joysticks values as varibles.
  int right_x_axis = analogRead(A0);
  int right_y_axis = analogRead(A1);
  int left_x_axis = analogRead(A2);
  int left_y_axis = analogRead(A3);

  //set button values as varibles.
  int right_switch = digitalRead(2);
  int left_switch = digitalRead(3);

  // set the data rate for the serial monitor.
  Serial.begin(9600);
}

void Format_signal(Joystick_chanle_maping, Joystick_stick_mode, Joystick_output_mode, right_x_axis, right_y_axis, left_x_axis, left_y_axis)
{

}

void loop() 
{
  Format_signal()
  delay(100);
}