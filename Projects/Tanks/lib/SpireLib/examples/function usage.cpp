#include "Arduino.h"
#include "SpireLib.h"
#include "Servo.h"    // not actually required for using the library, just to demonstrate the servo function

#define LEDPIN 11     // a led connected to digital pin 11

Pot servoPot(0);      // The pin used is an analog input pin, so you can use A0-5 or just 0-5
Pot pwmPot(1);        // The pin used is an analog input pin, so you can use A0-5 or just 0-5
Temp myTemp(2);       // The pin used is an analog input pin, so you can use A0-5 or just 0-5

Servo myServo;        // just used to demonstrate the servo function

void setup()  {
  Serial.begin(9600); // for logging the temperature
  myServo.attach(3);  // connected on digital pin 3
  pinMode(LEDPIN, OUTPUT);
}

void loop()   {
  //  This reads the value from the potentiometer,
  //  transforms it to a range usable by the servo (0 - 180)
  //  then writes the value to the servo
  myServo.write(servoPot.readServo());
  Serial.print("Servo: ");
  Serial.print(servoPot.readServo());
  Serial.print("  ");

  //  This writes a PWM signal to the led
  //  using the value read from the potentiometer
  //  like the example above, the value has been
  //  transformed into a range, this time the PWM range (0 - 255)
  analogWrite(LEDPIN, pwmPot.readPWM());
  Serial.print("PWM: ");
  Serial.print(pwmPot.readPWM());
  Serial.print("  ");

  //  This reads the temperature from the temperature sensor
  //  and logs it to the serial monitor
  Serial.print("The temperature is ");
  Serial.print(myTemp.readC());
  Serial.print(" ");
  Serial.print("degrees celsius!");

Serial.println(" ");
}
