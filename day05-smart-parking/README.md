# Day 5 — Smart Parking Sensor

## Goal
Build a three-zone parking system:
- > 30 cm -> LED OFF, servo closed
- 15–30 cm -> LED blinks, servo closed
- < 15 cm -> LED ON, servo opens

## Day 5 pin assignment chosen by the learner
- TRIG -> GPIO18
- ECHO -> GPIO19
- LED -> GPIO21
- Servo signal -> GPIO22

## Exact historical ECHO breadboard coordinates
- HC-SR04 ECHO -> **A20**
- Same row: **B20** -> one end of 1kΩ resistor
- 1kΩ resistor other end -> **B24**
- 2kΩ resistor one end -> **C24**
- ESP32 GPIO19 -> **D24**
- 2kΩ resistor other end -> **C27**
- ESP32 GND -> **D27**

Thus row 24 is the divider midpoint:
`B24/C24/D24`.

## Exact historical LED breadboard coordinates
This LED was on the **right-side breadboard** of the joined pair.
- ESP32 GPIO21 -> **B28**
- same row to resistor via **C28**
- 220Ω resistor: **D28 -> D24**
- LED long leg -> **E24**
- LED short leg -> **F24**
- GND jumper -> **G24**

Electrical path:
`GPIO21 -> row 28 -> 220Ω -> row 24 left-half -> LED across trench -> row 24 right-half -> GND`.

## Servo
- Orange -> GPIO22
- Brown -> GND
- Red -> VIN

## HC-SR04 power / trigger
- VCC -> VIN
- GND -> GND
- TRIG -> GPIO18

### Debugging note
An early run returned `duration = 0` because VCC was accidentally connected to the wrong board pin (`VN` rather than `VIN`). The minimal duration test helped isolate the sensor before restoring full logic.
