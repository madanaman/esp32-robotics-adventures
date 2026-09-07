const int IN1 = 5;
const int IN2 = 18;
const int IN3 = 19;
const int IN4 = 21;

// IN1-IN4 control four channels on the ULN2003 driver.
// Each setStep(...) call energizes a particular combination of motor coils.
// Changing the sequence moves the magnetic field around the motor.
// Repeating the sequence makes the shaft rotate.
//
// Incorrect phase ordering can cause vibration without rotation.
// The working sequence for our exact 28BYJ-48 + ULN2003 setup is:
//
// IN1 IN2 IN3 IN4
//  1   0   1   0
//  0   1   1   0
//  0   1   0   1
//  1   0   0   1

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start with all coils off.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Apply one coil pattern to the ULN2003 driver.
void setStep(int a, int b, int c, int d) {
  digitalWrite(IN1, a);
  digitalWrite(IN2, b);
  digitalWrite(IN3, c);
  digitalWrite(IN4, d);
}

void loop() {
  // Working full-step sequence for our motor.
  //
  // IN1 IN2 IN3 IN4
  //  1   0   1   0
  setStep(HIGH, LOW, HIGH, LOW);
  delay(20);

  //  0   1   1   0
  setStep(LOW, HIGH, HIGH, LOW);
  delay(20);

  //  0   1   0   1
  setStep(LOW, HIGH, LOW, HIGH);
  delay(20);

  //  1   0   0   1
  setStep(HIGH, LOW, LOW, HIGH);
  delay(20);
}
