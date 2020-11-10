# Arduiono bluetooth controller

A bluetooth controler made with 2 joyticks and 2 buttons. 

## Parts
- 2x HS-05(Bluetooth module)
- Arduino pro micro(Almost every ardouno works with 4 digitla pins and 4 analog. May need change to platformio.ini file.)
- Power source/Battery (5V or higher)
- Tiny Buck converter(If power source voltage is higher then 5V)

## Signal output
- 4 letter char (depending on what joystick chanle maping)
- 4 numbers betwine 0-100, 0-1000 or 1000-2000 (depending on what joystick output mode)
- 2 numbers betwine 0-1 (depending on )

## Settings
### Output signal settings
#### Joystick chanle maping
- joystick chanle maping changes what order the signals are sent and is whriten as a four letter code made of A, E, R and T(Aileron, Elevator, Rudder and Throttle).
- The channle maping changes the order of the chanle siganls
#### Joystick stick mode
- joystick stick mode changes witch joystick the trottle is on,  the output is sent as mode 1(1, throttle on right x-axis) or mode 2(2, throttle on left x-axis).
- mode 1 has throttle on rigth x-axis, eileron on left x-axis.
- mode 2 has throttle on left x-axis, eileron on right x-axis.
#### Joystick output mode
- joystick output mode changes what number is low and high, the output is sent as RC-signal(RC, 1000-2000), low_RC-signal(lowRC, 0-1000) or Procent(procent, 0 - 100). 

### Standard settings
- Joystick_chanle_maping = "TAER"
- Joystick_stick_mode = 1
- Joystick_output_mode = "RC"
