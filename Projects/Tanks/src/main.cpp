#include "Arduino.h"
#include "SpireLib.h"

#define LEFT_MOTOR 9
#define RIGHT_MOTOR 10

Pot leftPot(1);
Pot rightPot(0);

void setup()  {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
}

void loop() {
  analogWrite(LEFT_MOTOR, leftPot.readPWM());
  analogWrite(RIGHT_MOTOR, rightPot.readPWM());
}
