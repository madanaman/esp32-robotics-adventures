# Wiring — Day 2

## LED
Same as Day 1.

## Button
| From | To | Notes |
|---|---|---|
| ESP32 GPIO22 (D22) | D26 | Same row as one button contact |
| Button contact 1 | E26 | Input side |
| Button contact 2 | F28 | Opposite switched side |
| ESP32 GND | G28 | Same row as button contact 2 |

Do not use two pins that belong to the same permanently-connected pair on the tactile switch.
