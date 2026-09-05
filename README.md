# ESP32 Robotics Adventures — Days 1–5

A reproducible record of the first five ESP32 learning sessions.

## Hardware
- ELEGOO ESP32 USB-C Super Starter Kit (ESP32-WROOM-32 style dev board)
- Breadboards
- LEDs
- 220Ω, 1kΩ, 2kΩ resistors
- Tactile pushbutton
- SG90-style micro servo
- HC-SR04 ultrasonic sensor
- Jumper wires
- USB data cable (the OnePlus cable worked reliably)

## Important safety / wiring rules
- Unplug USB before changing physical wiring.
- ESP32 GPIO is 3.3V logic.
- Do **not** feed the HC-SR04 ECHO 5V signal directly into an ESP32 GPIO.
- Use a 1kΩ / 2kΩ voltage divider on ECHO.
- GPIO pins are for signals, not for powering motors/servos.
- Servo red -> VIN, brown -> GND, orange -> signal GPIO.

## Breadboard notation
- On one half of a standard breadboard, holes A–E in the same numbered row are electrically connected.
- On the other half, holes F–J in the same numbered row are electrically connected.
- The center trench separates the two halves.
- When two breadboards are joined, coordinates repeat. Each day notes which board/side is meant.

## Historical vs canonical coordinates
Some sessions were done with the ESP32 off-board and some were rebuilt while debugging. Where exact historical coordinates were stated, they are preserved. Where they were not, a **canonical redo layout** is provided so the project can be rebuilt consistently.

## Days
1. [Day 1 — LED blink](day01-led-blink/README.md)
2. [Day 2 — Button controls LED](day02-button-led/README.md)
3. [Day 3 — Servo motion + button control](day03-servo/README.md)
4. [Day 4 — Ultrasonic automatic gate](day04-ultrasonic-gate/README.md)
5. [Day 5 — Smart parking sensor](day05-smart-parking/README.md)
