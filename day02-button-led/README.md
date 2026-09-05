# Day 2 — Button Controls LED

## Goal
Use a tactile pushbutton as input and turn the LED on only while the button is pressed.

## Concepts
- GPIO input
- `INPUT_PULLUP`
- Active-low button logic
- 4-leg tactile switch internal pairing
- Sense -> decide -> act

## LED wiring
Same as Day 1.

## Exact historical button coordinates
Button straddled the center trench around rows 26–28.

Working configuration:
- ESP32 **D22 / GPIO22** -> **D26**
- Button left contact: approximately **E26**
- Button opposite switched contact: approximately **F28**
- ESP32 **GND** -> **G28**

The original GND connection at G26 caused the input to stay LOW because it landed on the same internally-connected switch pair. Moving GND to G28 fixed it. Rotating the switch 90° would also have solved the orientation issue.

## Expected behavior
- Released -> GPIO22 reads HIGH -> LED OFF
- Pressed -> button connects GPIO22 to GND -> LOW -> LED ON
