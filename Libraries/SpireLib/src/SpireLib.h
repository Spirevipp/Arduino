#ifndef SpireLib_h
#define SpireLib_h

#include "Arduino.h"

class Pot
{
  public:
    Pot(int pin);
    int readServo();
    int readPWM();
    int readHighPWM();
  private:
    int _pin;
    int _val;
};

class Temp
{
  public:
    Temp(int pin);
    float readC();
  private:
    int _pin;
    int _read;
    float _val;
};

// todo fiks dette

class Clock
{
public:
  Clock();
  bool check();

private:
  unsigned long _pMillis;
  unsigned long _intervall;
  bool _time;
}

#endif
