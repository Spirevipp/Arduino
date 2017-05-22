#include <Arduino.h>
#include <PS2X_lib.h> //for v1.6
#include <Servo.h>

int verdi1 = 30;
int verdi2 = 105;
int verdi3 = 30;
int verdi4 = 45;
int verdi5 = 60;
int klo = 30;

PS2X ps2x; // create PS2 Controller Class

// right now, the library does NOT support hot pluggable controllers, meaning
// you must always either restart your Arduino after you conect the controller,
// or call config_gamepad(pins) again after connecting the controller.
int error = 0;
byte type = 0;
byte vibrate = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
  Serial.begin(115200);
  servo1.attach(22);
  servo2.attach(23);
  servo3.attach(24);
  servo4.attach(25);
  servo5.attach(26);
  servo6.attach(27);

  // CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************

  error = ps2x.config_gamepad(5, 4, 3, 2, true,
                              true); // setup pins and settings:  GamePad(clock,
                                     // command, attention, data, Pressures?,
                                     // Rumble?) check for error

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, "
                   "faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to "
                   "enable debug. visit www.billporter.info for "
                   "troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see "
                   "readme.txt to enable debug. Visit www.billporter.info for "
                   "troubleshooting tips");

  else if (error == 3)
    Serial.println(
        "Controller refusing to enter Pressures mode, may not support it. ");

  // Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
  case 0:
    Serial.println("Unknown Controller type");
    break;
  case 1:
    Serial.println("DualShock Controller Found");
    break;
  case 2:
    Serial.println("GuitarHero Controller Found");
    break;
  }
}

void loop() {
  /* You must Read Gamepad to get new values
     Read GamePad and set vibration values
     ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
     if you don't enable the rumble, use ps2x.read_gamepad(); with no values

     you should call this at least once a second
   */

  if (error == 1) // skip loop if no controller found
    return;

  else { // DualShock Controller

    ps2x.read_gamepad(false, vibrate); // read controller and set large motor to
                                       // spin at 'vibrate' speed

    if (ps2x.Button(PSB_L2)) {
      // servo6 mot 0
      Serial.println("L2");
      klo -= 5;
      klo = constrain(klo, 30, 120);
      Serial.println(klo);
      servo6.write(klo);
    } else if (ps2x.Button(PSB_R2)) {
      // servo6 mot 180
      Serial.println("R2");
      klo += 5;
      klo = constrain(klo, 30, 120);
      Serial.println(klo);
      servo6.write(klo);
    }

    if (ps2x.Button(PSB_L1)) {
      Serial.println("L1  ");
      verdi5 -= 5;
      verdi5 = constrain(verdi5, 0, 180);
      Serial.println(verdi5);
      servo5.write(verdi5);
    } else if (ps2x.Button(PSB_R1)) {
      Serial.println("R1  ");
      verdi5 += 5;
      verdi5 = constrain(verdi5, 0, 180);
      Serial.println(verdi5);
      servo5.write(verdi5);
    }

    if (ps2x.Button(PSB_PAD_LEFT)) {
      // servo1 mot 0
      Serial.println("LEFT");
      verdi1 -= 5;
      verdi1 = constrain(verdi1, 0, 180);
      Serial.println(verdi1);
      servo1.write(verdi1);
    } else if (ps2x.Button(PSB_PAD_RIGHT)) {
      // servo1 mot 180
      Serial.println("RIGHT");
      verdi1 += 5;
      verdi1 = constrain(verdi1, 0, 180);
      Serial.println(verdi1);
      servo1.write(verdi1);
    }
    if (ps2x.Button(PSB_PAD_UP)) {
      Serial.println("UP");
      verdi2 += 5;
      verdi2 = constrain(verdi2, 0, 180);
      Serial.println(verdi2);
      servo2.write(verdi2);
    } else if (ps2x.Button(PSB_PAD_DOWN)) {
      Serial.println("DOWN");
      verdi2 -= 5;
      verdi2 = constrain(verdi2, 0, 180);
      Serial.println(verdi2);
      servo2.write(verdi2);
    }

    if (ps2x.Analog(PSS_LY) > 200) {
      Serial.println("LY  ");
      // Serial.println(ps2x.Analog(PSS_LY));
      verdi3 -= 5;
      verdi3 = constrain(verdi3, 0, 180);
      Serial.println(verdi3);
      servo3.write(verdi3);
    } else if (ps2x.Analog(PSS_LY) < 55) {
      Serial.println("LY  ");
      // Serial.println(ps2x.Analog(PSS_LY));
      verdi3 += 5;
      verdi3 = constrain(verdi3, 0, 180);
      Serial.println(verdi3);
      servo3.write(verdi3);
    }

    // gjør om til L1 og L2
    if (ps2x.Analog(PSS_RY) > 200) {
      Serial.println("RY  ");
      // Serial.println(ps2x.Analog(PSS_RY));
      verdi4 += 5;
      verdi4 = constrain(verdi4, 0, 180);
      Serial.println(verdi4);
      servo4.write(verdi4);
    } else if (ps2x.Analog(PSS_RY) < 55) {
      Serial.println("RY  ");
      // Serial.println(ps2x.Analog(PSS_RY));
      verdi4 -= 5;
      verdi4 = constrain(verdi4, 0, 180);
      Serial.println(verdi4);
      servo4.write(verdi4);
    }
  }

  delay(150);
}
