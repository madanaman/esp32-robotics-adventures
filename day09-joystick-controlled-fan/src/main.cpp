#include <Arduino.h>

// -------------------------
// Joystick
// -------------------------

const int VRX_PIN = 34;
const int VRY_PIN = 35;

const int LOW_THRESHOLD = 1000;
const int HIGH_THRESHOLD = 3000;


// -------------------------
// L293D / Motor
// -------------------------

const int ENABLE_PIN = 23;
const int IN1_PIN = 18;
const int IN2_PIN = 19;


// -------------------------
// Motor state
// -------------------------

int targetSpeed = 0;
int currentSpeed = 0;

bool requestedClockwise = true;
bool actualClockwise = true;


// -------------------------
// Timing
// -------------------------

unsigned long lastSpeedCommand = 0;
unsigned long lastRampUpdate = 0;
unsigned long reversePauseStarted = 0;

bool waitingToReverse = false;

const int SPEED_CHANGE_AMOUNT = 20;

const int RAMP_STEP = 10;

const unsigned long SPEED_COMMAND_INTERVAL = 150;
const unsigned long RAMP_INTERVAL = 40;
const unsigned long REVERSE_PAUSE = 150;


// -------------------------
// Set physical motor direction
// -------------------------

void setMotorDirection(bool clockwise) {

    if (clockwise) {
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
    }
    else {
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, HIGH);
    }
}


void setup() {

    Serial.begin(115200);

    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);

    setMotorDirection(actualClockwise);

    analogWrite(ENABLE_PIN, 0);
}


void loop() {

    int xValue = analogRead(VRX_PIN);
    int yValue = analogRead(VRY_PIN);


    // =====================================================
    // 1. JOYSTICK LEFT / RIGHT
    //    Only change the REQUESTED direction
    // =====================================================

    if (xValue < LOW_THRESHOLD) {
        requestedClockwise = false;
    }
    else if (xValue > HIGH_THRESHOLD) {
        requestedClockwise = true;
    }


    // =====================================================
    // 2. JOYSTICK UP / DOWN
    //    Change TARGET speed
    // =====================================================

    if (millis() - lastSpeedCommand >= SPEED_COMMAND_INTERVAL) {

        // UP -> increase target speed
        if (yValue < LOW_THRESHOLD) {

            targetSpeed += SPEED_CHANGE_AMOUNT;

            if (targetSpeed > 255) {
                targetSpeed = 255;
            }

            lastSpeedCommand = millis();
        }

        // DOWN -> decrease target speed
        else if (yValue > HIGH_THRESHOLD) {

            targetSpeed -= SPEED_CHANGE_AMOUNT;

            if (targetSpeed < 0) {
                targetSpeed = 0;
            }

            lastSpeedCommand = millis();
        }
    }


    // =====================================================
    // 3. MOTOR CONTROL / RAMPING
    // =====================================================

    if (millis() - lastRampUpdate >= RAMP_INTERVAL) {

        lastRampUpdate = millis();


        // -------------------------------------------------
        // Direction change requested
        // -------------------------------------------------

        if (requestedClockwise != actualClockwise) {

            // First slow motor down
            if (currentSpeed > 0) {

                currentSpeed -= RAMP_STEP;

                if (currentSpeed < 0) {
                    currentSpeed = 0;
                }

                analogWrite(ENABLE_PIN, currentSpeed);
            }

            // Motor has reached zero
            else {

                // Start short pause before reversing
                if (!waitingToReverse) {

                    analogWrite(ENABLE_PIN, 0);

                    reversePauseStarted = millis();
                    waitingToReverse = true;
                }

                // After pause, switch direction
                else if (millis() - reversePauseStarted >= REVERSE_PAUSE) {

                    actualClockwise = requestedClockwise;

                    setMotorDirection(actualClockwise);

                    waitingToReverse = false;
                }
            }
        }


        // -------------------------------------------------
        // Direction is already correct
        // Ramp toward requested speed
        // -------------------------------------------------

        else {

            waitingToReverse = false;

            if (currentSpeed < targetSpeed) {

                currentSpeed += RAMP_STEP;

                if (currentSpeed > targetSpeed) {
                    currentSpeed = targetSpeed;
                }
            }

            else if (currentSpeed > targetSpeed) {

                currentSpeed -= RAMP_STEP;

                if (currentSpeed < targetSpeed) {
                    currentSpeed = targetSpeed;
                }
            }

            analogWrite(ENABLE_PIN, currentSpeed);
        }
    }


    // =====================================================
    // Debug output
    // =====================================================

    Serial.print("Target: ");
    Serial.print(targetSpeed);

    Serial.print("  Actual: ");
    Serial.print(currentSpeed);

    Serial.print("  Requested: ");
    Serial.print(requestedClockwise ? "CW" : "CCW");

    Serial.print("  Actual Direction: ");
    Serial.println(actualClockwise ? "CW" : "CCW");


    delay(50);
}
