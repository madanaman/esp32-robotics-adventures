#include <ESP32Servo.h>

const int SERVO_PIN = 18;
const int BUTTON_PIN = 22;

Servo myServo;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }
}
