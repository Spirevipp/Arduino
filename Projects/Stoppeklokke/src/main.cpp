#include <Arduino.h>
#include <LiquidCrystal.h>

#define BUTTON 2

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

unsigned long klokke = 0;
unsigned long sek = 0;
unsigned long min = 0;
unsigned long mil = 0;
unsigned long hr = 0;
unsigned long psek = 0;
unsigned long pmin = 0;
unsigned long pmil = 0;
unsigned long phr = 0;

bool start = false;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON)) {
    if (!start) {
      klokke = millis();
      sek = 0;
      min = 0;
      mil = 0;
      hr = 0;
      start = true;
      delay(100);
    } else {
      start = false;
      delay(100);
    }
  }
  if (millis() > klokke + 100) {
    mil++;
    if (mil == 10) {
      mil = 0;
    }
  }
  if (millis() > klokke + 1000) {
    klokke = millis();
    sek++;
  }
  if (sek == 60) {
    sek = 0;
    min++;
  }
  if (min == 60) {
    min = 0;
    hr++;
  }
  if (start && (min != pmin || mil != pmil || sek != psek || hr != phr)) {
    pmin = min;
    psek = sek;
    pmil = mil;
    phr = hr;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(hr);
    lcd.print(":");
    lcd.print(min);
    lcd.print(":");
    lcd.print(sek);
    lcd.print(".");
    lcd.print(mil);
  }
  delay(50);
}
