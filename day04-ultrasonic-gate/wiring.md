# Wiring — Day 4

| HC-SR04 | Connection |
|---|---|
| VCC | ESP32 VIN |
| GND | ESP32 GND |
| TRIG | ESP32 GPIO5 |
| ECHO | 1kΩ -> midpoint -> GPIO19; midpoint -> 2kΩ -> GND |

## Historical coordinate bridge
- GND: sensor -> A10, ESP32 GND -> D10
- VCC: sensor -> A12, ESP32 VIN -> D12
- TRIG: sensor -> A14, ESP32 GPIO5 -> D14
- ECHO: B26 -> 1kΩ C26-C24 -> midpoint row 24 -> GPIO19 at B24; 2kΩ from D24 to GND

## Servo
- Red -> VIN
- Brown -> GND
- Orange -> GPIO18
