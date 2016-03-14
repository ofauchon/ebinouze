# e-binouze

e-binouze is a personnal brewery control module. 

Basicaly, this code will drive the Arduino board to control:

- Keyboard and LCD for configuration and visualization
- DS18S20 for temperature sensor
- Solid State Relay (through PWM output) for heating control (PID Regulation) 
- Some other ouputs and leds ... if required



## Build 

arduino --verify  ebinouze.ino


