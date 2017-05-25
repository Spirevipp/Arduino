#include <Arduino.h>
/*
**********AtTiny85 INFO**********
6 pins
all 6 pins are digital I/O
Pin 0 → I2C SDA, PWM (LED on Model B)
Pin 1 → PWM (LED on Model A) ****den jeg har****
Pin 2 → I2C SCK, Analog In
Pin 3 → Analog In (also used for USB+ when USB is in use)
Pin 4 → PWM, Analog (also used for USB- when USB is in use)
Pin 5 → Analog In (3V istedenfor 5V på HIGH)

The internal pull-up resistor (turned on by calling digitalWrite(0) after
setting the pin to output, where 0 is the pin number) are much weaker (about 25
kohm) on an ATtiny than on an Arduino, so the onboard LED interferes with them.
If you need them, you can use a different port. Change your circuit to not need
the internal pull-up, or cut the LED trace.

Pin 3 and Pin 4 (P3 and P4) are used for USB communication and programming,
while you can use them in your circuit if you are not using USB communication,
you may have to unplug your circuit during programming if the circuit would
impede the pin states or dramatically affect the voltage levels on these pins.

Pin 3 (P3) has a 1.5 kΩ pull-up resistor attached to it which is required for
when P3 and P4 are used for USB communication (including programming). Your
design may need to take into account that you'd have to overpower this to pull
this pin low.

The Digispark does not have a hardware serial port nor a hardware serial to USB
converter. An example library (DigiUSB) is provided, as well as some example
code and a serial monitor like program, but communication with the computer will
not always be plug and play, especially when other libraries are involved.


THIS IS P5, P5 is analog input 0, so when you are using analog read, you refer
to it as 0.
same goes for the others
analog 0 → Pin 5
analog 1 → Pin 2
analog 2 → Pin 4
analog 3 → Pin 3

When uploading the code, leave the module unplugged
start the upload process, then plug it in

***Drivers***
https://github.com/digistump/DigistumpArduino/releases
*/

#include <SimpleServo.h>

#define BUTTON 0
#define BUTTON2 3
#define LED_PIN 1
#define DISTANCE 80
#define DEFAULT_POS 100

int buttonState = LOW;
int buttonState2 = LOW;
SimpleServo servo;

void click();

void setup() {
  servo.attach(2);
  servo.setPulseMillis(20);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON, INPUT);
  servo.write(DEFAULT_POS);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  buttonState2 = digitalRead(BUTTON2);
  if (buttonState == HIGH || buttonState2 == HIGH) {
    click();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}

void click() {
  int pos = DEFAULT_POS - DISTANCE;
  servo.write(pos);
  delay(50);
  servo.write(DEFAULT_POS);
}
