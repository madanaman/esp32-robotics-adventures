# Day 1 — LED Blink

## Goal
Make an external LED blink from ESP32 GPIO23.

## Concepts
- GPIO output
- LED polarity
- Current-limiting resistor
- Ground as return path
- `setup()` vs `loop()`

## Exact historical breadboard coordinates
Blue LED straddled the center trench at row 20:
- LED long leg (anode): **E20**
- LED short leg (cathode): **F20**

220Ω resistor:
- one leg: **D20**
- other leg: **D15**

Jumpers:
- ESP32 **D23 / GPIO23** -> **C15**
- ESP32 **GND** -> **G20**

Because C15/D15 are connected and D20/E20 are connected, the path is:

`GPIO23 -> C15/D15 -> 220Ω -> D20/E20 -> LED -> F20/G20 -> GND`

## Expected behavior
LED ON 1 second, OFF 1 second, repeating.

## Files
- `wiring.md` — connection table
- `diagram.mmd` — Mermaid circuit diagram
- `day01_led_blink.ino` — Arduino code
