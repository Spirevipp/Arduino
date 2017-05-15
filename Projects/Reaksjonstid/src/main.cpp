#include <Arduino.h>
#include <LiquidCrystal.h>

#define BUTTON 2
#define LED 7

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

unsigned long klokke = 0;
unsigned long randomTime = 0;

unsigned long sek = 0;
unsigned long min = 0;
unsigned long mil = 0;
unsigned long hr = 0;
unsigned long psek = 0;
unsigned long pmin = 0;
unsigned long pmil = 0;
unsigned long phr = 0;

bool start = false;
bool react = false;
bool buttonToggle = false;

int buttonState;

void updateTime();

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  updateTime();

  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    buttonToggle = !buttonToggle;
  }
  if (buttonState == HIGH && buttonToggle) {
    randomTime = random(1, 10) * 1000;
  }
  if (buttonState == HIGH && !buttonToggle) {
    start = false;
  }
  if (millis() > klokke + randomTime && !start) {
    start = true;
  }

  if (!buttonToggle) {
    pmin = 0;
    psek = 0;
    pmil = 0;
    phr = 0;
    min = 0;
    sek = 0;
    hr = 0;
    mil = 0;
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
  klokke = millis();
}

void updateTime() {
  if (millis() > klokke + 100) {
    mil++;
  }
  if (mil == 10) {
    mil = 0;
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
}
