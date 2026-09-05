# Wiring — Day 5

## HC-SR04
| Pin | Connection |
|---|---|
| VCC | ESP32 VIN |
| GND | ESP32 GND |
| TRIG | ESP32 GPIO18 |
| ECHO | A20 -> B20 -> 1kΩ -> B24 midpoint -> D24 GPIO19; C24 -> 2kΩ -> C27/D27 GND |

## LED — right-side breadboard
| Element | Coordinates |
|---|---|
| GPIO21 jumper | B28 |
| 220Ω resistor | D28 -> D24 |
| LED long leg | E24 |
| LED short leg | F24 |
| GND jumper | G24 |

## Servo
| Wire | ESP32 |
|---|---|
| Orange | GPIO22 |
| Brown | GND |
| Red | VIN |
