# Day 3 — Servo Motion + Button Control

## Goal
1. Sweep a servo through several angles.
2. Then combine the Day 2 button with the servo: press -> 90°, release -> 0°.

## Servo wire colors used
- Orange -> signal
- Red -> power
- Brown -> ground

## Historical wiring
Servo was connected directly to ESP32 pins using jumper wires, not via fixed breadboard coordinates:
- Brown -> ESP32 GND
- Red -> ESP32 VIN
- Orange -> ESP32 D18 / GPIO18

Because exact breadboard coordinates were not used in the session, the canonical redo is simply the same direct 3-wire connection.

## Button + servo combination
Button reused Day 2 wiring:
- GPIO22 -> D26 / button contact
- opposite button contact -> G28 -> GND

Servo:
- signal -> GPIO18
- power -> VIN
- ground -> GND
