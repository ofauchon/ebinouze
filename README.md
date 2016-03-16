# e-binouze

e-binouze is a personnal brewery control module. 

Basicaly, this code will drive the Arduino board to control:

- Up/Down/Left/Right/Ok/Cancel Button on debounced GPIO
- DS18S20 for temperature sensor
- Solid State Relay (through PWM output) for heating control (PID Regulation) 
- Some other ouputs and leds ... if required
- Serial port for debugging


## Build 

arduino --verify  ebinouze.ino


