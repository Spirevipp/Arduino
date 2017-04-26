/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  Blink
  Basic example to test that HoodLoader2 works.

  You may also want to use:
  LED_BUILTIN
  LED_BUILTIN_RX
  LED_BUILTIN_TX
*/

const uint32_t blinkDelay = 300;
const uint8_t pinLed1 = LED_BUILTIN_RX;
const uint8_t pinLed2 = LED_BUILTIN_TX;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize led as an output.
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  delay(blinkDelay);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed1, LOW);
  delay(blinkDelay);
}
