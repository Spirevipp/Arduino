#include <Arduino.h>
/*
**********AtTiny85 INFO**********
6 pins
all 6 pins are digital I/O
Pin 0 → I2C SDA, PWM (LED on Model B)
Pin 1 → PWM (LED on Model A)
Pin 2 → I2C SCK, Analog In
Pin 3 → Analog In (also used for USB+ when USB is in use)
Pin 4 → PWM, Analog (also used for USB- when USB is in use)
Pin 5 → Analog In

When uploading the code, leave the module unplugged
start the upload process, then plug it in

***Drivers***
https://github.com/digistump/DigistumpArduino/releases

*/
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); // LED on Model B
  pinMode(1, OUTPUT); // LED on Model A
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(0, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, HIGH);
  delay(1000);          // wait for a second
  digitalWrite(0, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW);
  delay(1000); // wait for a second
}
