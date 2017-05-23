#include "Arduino.h"
#include "SpireLib.h"

Pot::Pot(int pin) { _pin = pin; }

int Pot::readServo() {
  _val = analogRead(_pin);
  _val = map(_val, 0, 1023, 0, 180);

  return _val;
}

int Pot::readPWM() {
  _val = analogRead(_pin);
  _val = map(_val, 0, 1023, 0, 255);

  return _val;
}

int Pot::readHighPWM() {
  _val = analogRead(_pin);
  _val = map(_val, 0, 1023, 120, 255);

  return _val;
}

Temp::Temp(int pin) { _pin = pin; }

float Temp::readC() {
  _read = analogRead(_pin);
  _val = (_read / 1024.0) * 5.0;
  _val = (_val - .5) * 100;

  return _val;
}

MillisTimer::clock() {_pMillis = 0;}

bool clock::check(unsigned long intervall) {
  _intervall = intervall;
  if(_pMillis + _intervall >= millis()){
    _pMillis = millis();
    return true;
  } else {
    return false;
  }
}
