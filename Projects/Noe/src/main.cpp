#include <Arduino.h>

#include <Servo.h>
#include <LiquidCrystal.h>

#define POTPIN A0
#define TEMP A1

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
Servo servo;

int valTemp;
int valPot;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  servo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  valPot = analogRead(POTPIN);            // reads the value of the potentiometer (value between 0 and 1023)
  valPot = map(valPot, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo.write(valPot);                  // sets the servo position according to the scaled value
  valTemp = analogRead(TEMP);
  // convert the ADC reading to voltage
  float voltage = (valTemp / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;

  lcd.print("Servo pos: ");
  lcd.print(valPot);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  delay(100);
}
