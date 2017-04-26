#include <Arduino.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int servo5val, servo3val, servo2val;
int servo1val = 1;
int servo6val = 1;
int servo4val = 1;
int x = 0;
int y = 0;
int z = 90;

void setup()  {

  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  servo5.attach(8);
  servo6.attach(9);

}

void loop() {
  servo2.write(90);
  servo3.write(90);
  servo5.write(120);

  if (servo1val == 1) {
    servo1.write(x);
    x = x + 1;
    if (x == 180) {
      servo1val = 0;
    }
  } else {
    servo1.write(x);
    x = x - 1;
    if (x == 0) {
      servo1val = 1;
    }
  }
  if (servo4val == 1) {
    servo4.write(z);
    z = z + 1;
    if (z == 180) {
      servo4val = 0;
    }
  } else {
    servo4.write(z);
    z = z - 1;
    if (z == 0) {
      servo4val = 1;
    }
  }
  if (servo6val == 1) {
    servo6.write(y);
    y = y + 1;
    if (y == 180) {
      servo6val = 0;
    }
  } else {
    servo6.write(y);
    y = y - 1;
    if (y == 0) {
      servo6val = 1;
    }
  }


delay(30);
}
