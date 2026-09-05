# Wiring — Day 1

| From | To | Notes |
|---|---|---|
| ESP32 GPIO23 (D23) | C15 | Same row as resistor D15 |
| 220Ω resistor | D15 -> D20 | Limits LED current |
| LED long leg | E20 | Same row as resistor D20 |
| LED short leg | F20 | Opposite side of trench |
| ESP32 GND | G20 | Same row as LED short leg |
