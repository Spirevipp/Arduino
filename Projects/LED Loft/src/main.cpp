#include <Arduino.h>
// No display ATM
//#include <LiquidCrystal.h>

// Defines
#define firstPin 2
#define lastPin 13

#define buttonR 5
#define buttonG 6
#define buttonB 7
#define buttonW 8

//#define displayPower 2

// Function initializers
// void showDisplay();

// Variables
// unsigned long displayTimer = 0;
// bool buttonPressed = false;

// LiquidCrystal lcd();

void setup() {

  for (int i = 0; i < 14; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  for (int i = firstPin; i <= lastPin; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  /*
  if (digitalRead(buttonR) == LOW || digitalRead(buttonG) == LOW ||
      digitalRead(buttonB) == LOW || digitalRead(buttonW) == LOW) {
    buttonPressed = true;
  }
  showDisplay();
  */
}

// Functions
/*
void showDisplay() {
  bool isActive;
  if (buttonPressed) {
    displayTimer = millis();
  }
  if (millis() - displayTimer < 10000) {
    digitalWrite(displayPower, HIGH);
    isActive = true;

  } else {
    digitalWrite(displayPower, LOW);
    isActive = false;
  }
  if (isActive) {
    // Display Stuff

    // Show ip
    // current color
    // Current brightness
  }
}
*/
