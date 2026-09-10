#include <ESP32Servo.h>

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int SERVO_PIN = 22;

const int OPEN_ANGLE = 90;
const int CLOSED_ANGLE = 0;

// Remember the door state and when a continuously-far reading began.
bool doorOpen = false;
unsigned long farSince = 0;

Servo doorServo;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  doorServo.attach(SERVO_PIN);
  doorServo.write(CLOSED_ANGLE);
}

void loop() {
  // Send the HC-SR04 trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Stop waiting after 30 ms so a missing echo cannot block forever.
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("No echo");
    delay(100);
    return;
  }

  float distanceCm = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Open immediately when a person is close.
  if (distanceCm < 20) {
    if (!doorOpen) {
      Serial.println("Opening door");

      doorServo.write(OPEN_ANGLE);
      doorOpen = true;
    }

    // A close reading cancels any pending close timer.
    farSince = 0;
  }

  // Start closing only after the person remains clearly far away.
  else if (distanceCm > 30) {
    if (doorOpen) {
      if (farSince == 0) {
        farSince = millis();
        Serial.println("Person moved away - starting close timer");
      }

      else if (millis() - farSince >= 2000) {
        Serial.println("Closing door");

        doorServo.write(CLOSED_ANGLE);
        doorOpen = false;
        farSince = 0;
      }
    }
  }

  // Hold the current state inside the 20-30 cm hysteresis zone.
  else {
    farSince = 0;
  }

  delay(100);
}
