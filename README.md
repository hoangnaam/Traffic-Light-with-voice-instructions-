## What is it?
This project is a simple traffic light controller with pedestrian crossing. When the button is pressed, the system checks if enough time has passed since the last light change (to avoid interrupting traffic too soon). If allowed, the car lights cycle from green → yellow → red, and the pedestrian light turns green and the speaker announces. After a set crossing time, the pedestrian light starts flashing to warn that it’s about to change back to red with another announcement. Finally, the car lights return from red → yellow → green, and normal traffic flow continues.

## Videos (Please turns on the sound):

https://github.com/user-attachments/assets/c37eb1e0-0d36-4e11-9700-490b101f74fb


## Schematic (Image of KiCad):

![interactive_traffic_lights](https://github.com/user-attachments/assets/df1f1299-2126-493a-8c6e-88ca59a32397)

### Schematic's labels explanation
- CLRed: car light's red.
- CLGreen: car light's green.
- CLYellow: car light's yellow.
- PDgreen: pedestrian light's green.
- PDRed: pedestrian light's red.

## Build instructions**

  ***Required components:***
  - 1 Arduino UNO R3.
  - 1 MP3-TF-16P module (Reading SD cards)
  - 1 Speaker.
  - 1 Button.
  - 1 Buzzer.
  - 5 `220Ohm resistors`.
  - 1 `1kOhm resistor`.
  - 5 LEDs (2 reds, 2 greens, 1 yellow).
  - Jumper wires.
  - Bredboards.
  - 1 SD Card.
  ***Wiring:***
  
  Looks at the schematic.
  
  ***Code:***
  
  Download the `traffic_light.ino` in the project repo.
  Upload 2 sound files (found in repo) into the SD Card and insert it into the MP3-TF-16P module.
  
  *Notes:* Before running the code, you must have a DFRobotDFPlayeMini (by DFRobot) library
