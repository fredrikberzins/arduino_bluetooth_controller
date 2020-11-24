#include <Arduino.h>

#define right_x_axis_pin A0
#define right_y_axis_pin A1
#define left_x_axis_pin A2
#define left_y_axis_pin A3

#define right_switch_pin 2
#define left_switch_pin 3

#define right_x_axis analogRead(right_x_axis_pin)
#define right_y_axis analogRead(right_y_axis_pin)
#define left_x_axis analogRead(left_x_axis_pin)
#define left_y_axis analogRead(left_y_axis_pin)

#define right_switch digitalRead(right_switch_pin)
#define left_switch digitalRead(left_switch_pin)

//create max an min varibles
int min_right_x_axis = 512;
int max_right_x_axis = 512;

int min_right_y_axis = 512;
int max_right_y_axis = 512;

int min_left_x_axis = 512;
int max_left_x_axis = 512;

int min_left_y_axis = 512;
int max_left_y_axis = 512;

void print_values()
{
  //a first print to se if Serial.print works (if it all works all values will be 0).
  Serial.print("right joystick x-axis min: ");
  Serial.print(min_right_x_axis);
  Serial.print(" max: ");
  Serial.println(max_right_x_axis);

  Serial.print("right joystick y-axis min: ");
  Serial.print(min_right_y_axis);
  Serial.print(" max: ");
  Serial.println(max_right_y_axis);

  Serial.print("left joystick x-axis min: ");
  Serial.print(min_left_x_axis);
  Serial.print(" max: ");
  Serial.println(max_left_x_axis);

  Serial.print("left joystick y-axis min: ");
  Serial.print(min_left_y_axis);
  Serial.print(" max: ");
  Serial.println(max_left_y_axis);
}

void setup()  
{
  //set analog pins as input from joystick.
  pinMode(right_x_axis_pin, INPUT);
  pinMode(right_y_axis_pin, INPUT);
  pinMode(left_x_axis_pin, INPUT);
  pinMode(left_y_axis_pin, INPUT);

  //set digital pins as input from buttons.
  pinMode(right_switch_pin, INPUT);
  pinMode(left_switch_pin, INPUT);

  //set the data rate for the serial monitor.
  Serial.begin(9600);

  print_values();
  delay(1000);
}



void loop() 
{
  //right joystick x-axis
  if (right_x_axis < min_right_x_axis)
  {
    min_right_x_axis = right_x_axis;
  }
  
  if (right_x_axis > max_right_x_axis)
  {
    max_right_x_axis = right_x_axis;
  }

  //right joystick y-axis
  if (right_y_axis < min_right_y_axis)
  {
    min_right_y_axis = right_y_axis;
  }

  if (right_y_axis > max_right_y_axis)
  {
    max_right_y_axis = right_y_axis;
  }

  //left joystick x-axis
  if (left_x_axis < min_left_x_axis)
  {
    min_left_x_axis = left_x_axis;
  }
  
  if (left_x_axis > max_left_x_axis)
  {
    max_left_x_axis = left_x_axis;
  }

  //left joystick y-axis
  if (left_y_axis < min_left_y_axis)
  {
    min_left_y_axis = left_y_axis;
  }
  
  if (left_y_axis > max_left_y_axis)
  {
    max_left_y_axis = left_y_axis;
  }

  print_values();

  delay(500);
}