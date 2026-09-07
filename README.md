# ESP32 Robotics Adventures — Days 1–6

A reproducible record of the first six ESP32 learning sessions.

## Hardware
- ELEGOO ESP32 USB-C Super Starter Kit (ESP32-WROOM-32 style dev board)
- Breadboards
- LEDs
- 220Ω, 1kΩ, 2kΩ resistors
- Tactile pushbutton
- SG90-style micro servo
- HC-SR04 ultrasonic sensor
- 28BYJ-48 5V stepper motor
- ULN2003 stepper motor driver board
- Jumper wires
- USB data cable (the OnePlus cable worked reliably)
- USB power bank

## Important safety / wiring rules
- Unplug USB before changing physical wiring.
- ESP32 GPIO is 3.3V logic.
- Do **not** feed the HC-SR04 ECHO 5V signal directly into an ESP32 GPIO.
- Use a 1kΩ / 2kΩ voltage divider on ECHO.
- GPIO pins are for signals, not for powering motors/servos.
- Servo red -> VIN, brown -> GND, orange -> signal GPIO.
- Stepper motors should be powered through a driver board such as the ULN2003.

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
6. [Day 6 — Stepper motor with ULN2003 driver](day06-stepper-motor/README.md) — Stepper motor + ULN2003 driver, coil sequencing, power/current debugging.

## Diagram files

Each day includes three diagram formats:

- `diagram.mmd` — Mermaid source.
- `diagram.drawio` — native editable draw.io / diagrams.net source.
- `diagram.drawio.png` — PNG preview with the draw.io diagram data embedded, so it can be reopened and edited in draw.io.

For Git, prefer keeping the `.drawio` source. The editable PNG is convenient when you want a diagram that is both immediately viewable and still recoverable in draw.io.
