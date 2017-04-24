#ifndef SpireLib_h
#define SpireLib_h

#include "Arduino.h"

class Pot
{
  public:
    Pot(int pin);
    void readServo();
    void readPWM();
    void readHighPWM();
  private:
    int _pin;
    int _val;
};

class Temp
{
  public:
    Temp(int pin);
    void readC();
  private:
    int _pin;
    int _read;
    float _val;
};

#endif
