# Day 4 — Ultrasonic Automatic Gate

## Goal
Measure distance with HC-SR04, then open a servo when an object is closer than ~15 cm.

## Concepts
- Ultrasonic time-of-flight
- `pulseIn()`
- Speed-of-sound distance calculation
- 5V vs 3.3V logic
- Voltage divider
- Sensor -> decision -> actuator

## Historical GPIO choices
- TRIG -> GPIO5
- ECHO -> GPIO19 through 1kΩ / 2kΩ divider
- Servo signal -> GPIO18

## Exact historical ECHO divider coordinates
- HC-SR04 ECHO -> **B26**
- 1kΩ resistor: **C26 -> C24**
- ESP32 GPIO19 -> **B24**
- 2kΩ resistor: one end -> **D24**
- other end -> GND (historically described as a GND row; a later exact Day 5 layout uses C27/D27)

Because B24/C24/D24 are the same breadboard row, row 24 is the divider midpoint.

Electrical path:
`ECHO -> 1kΩ -> midpoint -> GPIO19`, with `midpoint -> 2kΩ -> GND`.

## Power / trigger wiring
Historical bridge-style setup before mounting ESP32 across two breadboards:
- HC-SR04 GND -> A10, ESP32 GND -> D10
- HC-SR04 VCC -> A12, ESP32 VIN -> D12
- HC-SR04 TRIG -> A14, ESP32 GPIO5 -> D14

After two breadboards were joined, ESP32 was mounted across them, but the same electrical connections were retained.
