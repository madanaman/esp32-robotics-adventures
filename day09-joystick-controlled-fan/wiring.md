# Wiring - Day 9

Disconnect USB power before changing the circuit. Install the L293D across the breadboard center gap before adding jumper wires.

## Joystick to ESP32

| Joystick pin | ESP32 connection | Purpose |
|---|---|---|
| VCC / `+5V` label | 3V3 | Safe supply for 3.3V-range analog outputs |
| GND | GND | Common ground |
| VRx | GPIO34 | Left/right direction command |
| VRy | GPIO35 | Up/down speed command |
| SW | Not connected | Push switch is unused |

Although the joystick board may label its supply pin `+5V`, this build intentionally powers it from ESP32 3V3. VRx and VRy are derived from that supply voltage, so this keeps both analog signals within the ESP32 ADC input range.

## L293D pin orientation
Hold the IC with its notch facing upward. Pin 1 is at the upper left. Number down the left side to pin 8, then continue from pin 9 at the lower right up to pin 16.

```text
                    notch
                  ┌───∪───┐
 Enable 1,2   1   │       │  16  Logic VCC
 Input 1      2   │       │  15  Unused
 Output 1     3   │ L293D │  14  Unused
 GND          4   │       │  13  GND
 GND          5   │       │  12  GND
 Output 2     6   │       │  11  Unused
 Input 2      7   │       │  10  Unused
 Motor VCC    8   │       │   9  Unused
                  └───────┘
```

Do not rotate this numbering diagram to match the breadboard. First find the physical notch, point it upward, and then identify pin 1.

## ESP32, L293D, and motor

| L293D pin | Function | Connection |
|---|---|---|
| 1 | Enable 1,2 | ESP32 GPIO23 (PWM speed) |
| 2 | Input 1 | ESP32 GPIO18 (direction) |
| 3 | Output 1 | DC motor red wire |
| 4 | GND | Common GND |
| 5 | GND | Common GND |
| 6 | Output 2 | DC motor black wire |
| 7 | Input 2 | ESP32 GPIO19 (direction) |
| 8 | Motor VCC | ESP32 VIN |
| 12 | GND | Common GND |
| 13 | GND | Common GND |
| 16 | Logic VCC | ESP32 VIN |

The unused half of the L293D can remain unconnected.

## Common ground
ESP32 GND, joystick GND, and L293D pins 4, 5, 12, and 13 must all share the same common ground.

## Connection checklist
- Joystick VCC is connected to `3V3`, not VIN.
- Joystick VRx goes to GPIO34 and VRy goes to GPIO35.
- L293D notch faces upward before pins are counted.
- L293D pin 1 goes to GPIO23 for PWM.
- L293D pins 2 and 7 go to GPIO18 and GPIO19 for direction.
- The motor connects only to L293D output pins 3 and 6.
- L293D motor and logic supplies, pins 8 and 16, go to VIN.
- All four used L293D ground pins share ESP32 GND.
