const int IN1 = 5;
const int IN2 = 18;
const int IN3 = 19;
const int IN4 = 21;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setStep(int a, int b, int c, int d) {
  digitalWrite(IN1, a);
  digitalWrite(IN2, b);
  digitalWrite(IN3, c);
  digitalWrite(IN4, d);
}

void loop() {
  setStep(HIGH, LOW, HIGH, LOW);   // 1010
  delay(20);

  setStep(LOW, HIGH, HIGH, LOW);   // 0110
  delay(20);

  setStep(LOW, HIGH, LOW, HIGH);   // 0101
  delay(20);

  setStep(HIGH, LOW, LOW, HIGH);   // 1001
  delay(20);
}
