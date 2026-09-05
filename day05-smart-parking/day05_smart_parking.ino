#include <ESP32Servo.h>

const int TRIG_PIN = 18;
const int ECHO_PIN = 19;
const int LED_PIN = 21;
const int SERVO_PIN = 22;

unsigned long lastBlinkTime = 0;
bool ledState = false;

Servo myServo;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration, max wait = 30 ms
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("No echo");
    delay(200);
    return;
  }

  float distanceCm = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  if (distanceCm > 30) {
    myServo.write(0);
    ledState = false;
    digitalWrite(LED_PIN, LOW);
  }
  else if (distanceCm >= 15 && distanceCm <= 30) {
    myServo.write(0);

    if (millis() - lastBlinkTime >= 500) {
      lastBlinkTime = millis();
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }
  else if (distanceCm < 15) {
    myServo.write(90);
    ledState = true;
    digitalWrite(LED_PIN, HIGH);
  }

  delay(200);
}
