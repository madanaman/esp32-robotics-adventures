# Day 6 — Stepper Motor with ULN2003 Driver

## Goal
Control a 28BYJ-48 5V stepper motor from an ESP32 using a ULN2003 driver board, then debug the coil sequence and power arrangement until the shaft rotates reliably.

## What a stepper motor is
A stepper motor moves in small fixed steps instead of spinning freely like a DC motor. Inside the motor are multiple coils. By energizing those coils in the right order, the magnetic field moves around the motor and pulls the rotor from one position to the next.

This makes steppers useful when position matters, such as gauges, small robot mechanisms, turntables, and simple automated doors.

## What the ULN2003 does
The ULN2003 board is a driver between the ESP32 and the stepper motor. The ESP32 sends low-current logic signals to IN1, IN2, IN3, and IN4. The ULN2003 uses those signals to switch the motor coils on and off.

The board also has indicator LEDs, which are useful for checking whether each input channel is being commanded.

## Why GPIO controls the driver instead of powering the motor
ESP32 GPIO pins are for control signals, not motor power. A GPIO pin cannot safely provide the current a stepper motor coil needs. Trying to power a motor directly from GPIO can cause unreliable behavior or damage the ESP32.

Instead:
- ESP32 GPIO pins control the ULN2003 inputs.
- The ULN2003 switches current through the motor coils.
- Motor power comes from VIN/GND, not from GPIO.

## GPIO assignments
| ULN2003 input | ESP32 pin |
|---|---|
| IN1 | GPIO5 |
| IN2 | GPIO18 |
| IN3 | GPIO19 |
| IN4 | GPIO21 |

## Power arrangement
Final working setup:
- ESP32 powered over USB/power bank.
- ULN2003 `+` -> ESP32 VIN.
- ULN2003 `-` -> ESP32 GND.
- 28BYJ-48 5-wire motor plug -> ULN2003 white motor socket.

## Working full-step sequence
The naive sequence using IN1 -> IN2 -> IN3 -> IN4 did not rotate the motor correctly.

The working full-step sequence was:

```text
1010
0110
0101
1001
```

The bits correspond to:

```text
IN1 IN2 IN3 IN4
```

Equivalent effective coil order:

```text
IN1 -> IN3 -> IN2 -> IN4
```

## Debugging journey
- The ULN2003 LEDs sequenced, but the motor shaft only vibrated.
- Simple stepping sequences were tested first.
- A half-step sequence was also tested.
- All four ULN2003 LEDs were verified.
- All four channels produced motor vibration, proving each driver path had some effect.
- A separate breadboard power module fed by a 6F22 9V battery was tested, but it caused vibration without reliable rotation.
- The setup was changed to a power bank powering the ESP32, with ULN2003 power taken from ESP32 VIN/GND.
- The correct coil stepping order was discovered: IN1 -> IN3 -> IN2 -> IN4.

## Key lessons
- Voltage alone is not enough; current capability matters.
- Driver LED activity proves input control but not necessarily correct motor rotation.
- Stepper motors depend on correct phase order.
- Debugging works best when control, power, and motor behavior are isolated one at a time.
