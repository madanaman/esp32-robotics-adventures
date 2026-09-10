# Wiring - Day 8

Disconnect USB power before changing any wiring.

| Component | Pin | Connection |
|---|---|---|
| HC-SR04 | VCC | ESP32 VIN |
| HC-SR04 | GND | ESP32 GND |
| HC-SR04 | TRIG | ESP32 GPIO18 |
| HC-SR04 | ECHO | 1kΩ resistor -> divider midpoint |
| Divider midpoint | - | ESP32 GPIO19 |
| Divider midpoint | - | 2kΩ resistor -> GND |
| Servo | Orange / signal | ESP32 GPIO22 |
| Servo | Red / power | ESP32 VIN |
| Servo | Brown / ground | ESP32 GND |

## ECHO voltage divider

```text
HC-SR04 ECHO -> 1kΩ -> midpoint -> ESP32 GPIO19
                           |
                          2kΩ
                           |
                          GND
```

When ECHO is approximately 5V, the midpoint is approximately 3.3V. Connect GPIO19 to the midpoint, not directly to the HC-SR04 ECHO pin.

## Shared power
The breadboard power rails can distribute ESP32 VIN and GND to the sensor and servo:

- ESP32 VIN -> positive rail -> HC-SR04 VCC and servo red.
- ESP32 GND -> ground rail -> HC-SR04 GND, servo brown, and the bottom of the 2kΩ resistor.

All grounds must be common. This also applies if a suitable external servo power source is used later.
