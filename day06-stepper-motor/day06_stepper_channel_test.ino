const int IN1 = 5;
const int IN2 = 18;
const int IN3 = 19;
const int IN4 = 21;

const int channels[] = {IN1, IN2, IN3, IN4};
const int channelCount = 4;

void setup() {
  for (int i = 0; i < channelCount; i++) {
    pinMode(channels[i], OUTPUT);
    digitalWrite(channels[i], LOW);
  }
}

void allOff() {
  for (int i = 0; i < channelCount; i++) {
    digitalWrite(channels[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < channelCount; i++) {
    allOff();
    digitalWrite(channels[i], HIGH);
    delay(1500);
  }

  allOff();
  delay(1500);
}
