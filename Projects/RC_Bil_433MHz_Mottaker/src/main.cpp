#include <Arduino.h>

#include <VirtualWire.h>

/*
 #ifndef cbi
 #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
 #endif
 #ifndef sbi
 #define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
 #endif
   sbi(TCCR2A, WGM21);  // Change from Phase-Correct PWM to Fast PWM
 */

int pspd = 0;
int spd = 0;
int motorBs = 3;
int motorBd = 4;



void setup() {
        pinMode(motorBs, OUTPUT); //speed
        pinMode(motorBd, OUTPUT); //direction
        digitalWrite(motorBd, LOW);
        digitalWrite(motorBs, LOW);


        Serial.begin(115200);           // origanlt 9600. 115200 for testing
        Serial.println("setup"); // Prints "Setup" to the serial monitor
        vw_set_rx_pin(12);    // Sets pin D12 as the RX Pin
        //vw_set_ptt_inverted(true);  // Required for DR3100
        vw_setup(2000);                   // Bits per sec 4000 orginalt, 2000 for test
        vw_rx_start();        // Start the receiver PLL running
}

void loop() {
        uint8_t recieveBuffer[VW_MAX_MESSAGE_LEN];
        uint8_t bufferMax = VW_MAX_MESSAGE_LEN; // no need to make it global


        if (vw_get_message(recieveBuffer, &bufferMax)) { // Non-blocking
                int i;
                digitalWrite(13, true); // Flash a light to show received good message

                // Message with a good checksum received, dump it.
                Serial.print("Got: ");

                for (i = 0; i < bufferMax - 2; i += 3) {
                        char chanID = recieveBuffer[i]; // Extract channel ID
                        int c = (recieveBuffer[i + 2] << 8) | recieveBuffer[i + 1]; // Reconstruct 16-bit joystick reading
                        spd = map(c, 0, 1023, 150, 255);

                        Serial.print(chanID);
                        Serial.print(" ");
                        Serial.print(c);
                }
                Serial.println("");
                digitalWrite(13, false);
        }

        if (spd != pspd) {
                pspd = spd;
                Serial.println(spd);
                analogWrite(motorBs, spd);
        }
}
