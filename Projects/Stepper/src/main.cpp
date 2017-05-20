#include <Arduino.h>
#include <Stepper.h>

#define STEPS 32

int dir = HIGH;

Stepper motor(STEPS, 11, 9, 10, 8);

void setup() {}

void loop() {
  motor.direction();
  motor.setSpeed(1000);
  motor.step(2048);
  delay(3000);
}
