#include <Stepper.h>

const int STEPS_PER_REV = 2048;

// Constructor order is intentionally:
// IN1, IN3, IN2, IN4
Stepper motor(STEPS_PER_REV, 5, 19, 18, 21);

void rotateDegrees(float degrees) {
  int steps = degrees * STEPS_PER_REV / 360.0;
  motor.step(steps);
}

void setup() {
  // Speed is in RPM.
  motor.setSpeed(8);

  // Demonstrate degree-based positioning.
  rotateDegrees(90);
  delay(3000);

  rotateDegrees(-90);
  delay(3000);

  rotateDegrees(180);
  delay(3000);

  rotateDegrees(-180);
  delay(3000);

  rotateDegrees(360);
}

void loop() {
  // Nothing here.
  // Run the demonstration once from setup().
}
