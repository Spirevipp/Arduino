#include <Arduino.h>
#include <NewPing.h>


//Define analog pins
#define IR_SENSOR A0
#define LIGHT_SENSOR_ANALOG A1
#define TEMP_SENSOR A2
#define SOUND_SENSOR_ANALOG A3

//Define digital pins
#define LIGHT_SENSOR_DIGITAL 6
#define SOUND_SENSOR_DIGITAL 7
#define RANGE_SENSOR_ECHO 8
#define RANGE_SENSOR_TRIG 9

#define MAX_DISTANCE 420 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(RANGE_SENSOR_TRIG, RANGE_SENSOR_ECHO, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



void setup()  {

        pinMode(LIGHT_SENSOR_DIGITAL, INPUT);
        pinMode(SOUND_SENSOR_DIGITAL, INPUT);

        Serial.begin(115200);
}

void loop() {
  delay(70);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print("cm");

  Serial.print("    LIGHT: ");
  Serial.print(analogRead(LIGHT_SENSOR_ANALOG));

  Serial.print("    TEMP: ");
  Serial.print(analogRead(TEMP_SENSOR));

  Serial.print("    SOUND: ");
  Serial.print(analogRead(SOUND_SENSOR_ANALOG));

  Serial.print("    IR: ");
  Serial.println(analogRead(IR_SENSOR));

}
