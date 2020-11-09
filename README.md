# Arduiono bluetooth controller

A bluetooth controler made with 2 joyticks and 2 buttons. 

## Parts
- 2x HS-05(Bluetooth module)
- Arduino pro micro(Almost every ardouno works with 4 digitla pins and 4 analog. May need change to platformio.ini file.)
- Power source/Battery (5V or higher)
- Tiny Buck converter(If power source voltage is higher then 5V)

## Output signal
The output is codeed as folowing
-joystick chanle maping
  - writhetn as a combination of A, E, R and T. (Aileron, Elevator, Rudder and Throttle)(Standart combination is "TAER".)
  - The channle maping changes the order of the chanle siganls
- joystick stick mode
  - joystick stick mode changes witch joystick the trottle is on,  the output is sent as mode 1(1, throttle on right x-axis) or mode 2(2, throttle on left x-axis).
    - mode 1 has throttle on rigth x-axis, eileron on left x-axis.
    - mode 2 has throttle on left x-axis, eileron on right x-axis.
- joystick output mode
  - joystick output mode changes what number is low and high, the output is sent as RC-signal(RC, 1000-2000), low_RC-signal(lowRC, 0-1000) or Procent(procent, 0 - 100). 
