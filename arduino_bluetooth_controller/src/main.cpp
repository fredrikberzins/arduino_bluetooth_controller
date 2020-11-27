#include <Arduino.h>
#include <SoftwareSerial.h>

//================
//    Settings
//================

Joystick_chanle_maping = "TAER";
Joystick_stick_mode = 1;
Joystick_output_mode = "RC";

//Joy stick offset
//The format is as folowing
// max/min_right/left_x/y_axis = "int"
// "int" = offset from what the number is supose to be. can be tested with te testing program.
//Example: testing program prints 1019 instead of 1023  on the right y axis. 
int max_right_x_axis = 0;
int min_right_x_axis = 0;
int max_right_y_axis = 0;
int min_right_y_axis = 0;
int max_left_x_axis = 0;
int min_left_x_axis = 0;
int max_left_y_axis = 0;
int min_left_y_axis = 0;

#define right_x_axis_pin A0
#define right_y_axis_pin A1
#define left_x_axis_pin A2
#define left_y_axis_pin A3

#define right_switch_pin 2
#define left_switch_pin 3

//Rx and Tx for bluetooth
//Recive on pin 0
//Transmitt on pin 1
SoftwareSerial Bluetooth (0, 1);

//Defining all input pins for joysticks and buttons
#define 

#define right_switch_pin 2
#define left_switch_pin 3

#define right_x_axis analogRead(right_x_axis_pin)
#define right_y_axis analogRead(right_y_axis_pin)
#define left_x_axis analogRead(left_x_axis_pin)
#define left_y_axis analogRead(left_y_axis_pin)

#define right_switch digitalRead(right_switch_pin)
#define left_switch digitalRead(left_switch_pin)

void send_values()
{
  
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
  //set the data rate for the bluetooth module conection.
  Bluetooth.begin(9600);

  Serial.println("Ready to use")
  delay(500);
}



void loop() 
{

  send_values();

  delay(500);
}