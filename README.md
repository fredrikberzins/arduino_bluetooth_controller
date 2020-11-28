# Arduiono bluetooth controller

A bluetooth controller made with 2 joyticks with built in buttons, it has no telemtry.

## Parts
- HS-05(Bluetooth module)
- Arduino pro micro(Almost every ardouno works with 4 digitla pins and 4 analog. May need change to platformio.ini file.)
- Power source/Battery (5V or higher)
- Tiny Buck converter(If power source voltage is higher then 5V)
- 2x 2 axis Joysticks with built in buttoons.

## Signal output
- 4 letter char (depending on what joystick chanle maping)
- 4 numbers betwine 0-100, 0-1000 or 1000-2000 (depending on what joystick output mode)
- 2 numbers betwine 0-1 (depending on )

## Settings
### Output signal settings
#### Joystick output mode
- joystick output mode changes what number is low and high, the output is sent as RC-signal(0, 1000-2000), low_RC-signal(1, 0-1000) or Procent(2, 0 - 100).
- (id/code setting nummber, output betwine x-y)

### Button inversion
- Inverts the normal and pressed output state of the buttons
- Button_inversion = 0 means that buttons will regester 0 normaly and 1 when pressed

### Buttons activation
- Activating or deactivating the buttons so they don't output the button signal.
- The right and left button can be deactivated and activated induvidualy.
- If the buttons are not conneted they can be turned off to lower the latency of the signal.
  
### Settings in code
- All settings are writhen with the id of the option.


### Standard settings
- Joystick_output_mode = 0
- Button_inversion = 0
- Button_active_right = 0
- Button_active_left = 0

## Body/Chassi to the conttroller
The controller is made up of a few pecex ment to be put together with dubbel sided tape. It is amde up of 2 mane parts that are connected with a cable with 5 wires in.
The controllers are mad like 2 nintendo Wii nunchuk, one side has a joystick, battery and step down buck converter. The other side has the HC-05, arduino and joystick.

Link to the stl and f3d files to print the controllers or customize: https://www.thingiverse.com/thing:4665958

## Config for the bluetooth module
To get the bluetooth module you will have to config it to binded to the right bluetooth module/reciver.
