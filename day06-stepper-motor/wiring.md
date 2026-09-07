# Wiring — Day 6

## ULN2003 driver
| ULN2003 pin | ESP32 connection |
|---|---|
| IN1 | GPIO5 |
| IN2 | GPIO18 |
| IN3 | GPIO19 |
| IN4 | GPIO21 |
| + | VIN |
| - | GND |

## Stepper motor
| Motor | Connection |
|---|---|
| 28BYJ-48 5-wire connector | ULN2003 white motor socket |

## Power
| Source | Connection |
|---|---|
| USB/power bank | ESP32 USB |
| ESP32 VIN | ULN2003 + |
| ESP32 GND | ULN2003 - |

If an external motor power source is used later, all grounds must be common: external supply ground, ULN2003 `-`, and ESP32 GND must be connected together.
