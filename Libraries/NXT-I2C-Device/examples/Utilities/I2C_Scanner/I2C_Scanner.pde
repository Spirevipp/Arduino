/************************************************************************/
/*
	Copyright (c) 2010 by mindsensors.com, 2013 XLC Team
	Email: info (<at>) mindsensors (<dot>) com
         xlc.team@gmail.com

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

************************************************************************/

/*  History
* When        Who                 Comments
* 05/28/10    Deepak Patil        Initial authoring.
* 06/08/10    Andrew Sylvester    Modification of I2C Scanner for NXTI2CDevice Class
* 06/07/13    mrShu               Easier I2C check
*/

#include <Wire.h>
#include <NXTI2CDevice.h>       // Needs to be included here for //
                           // the NXTI2CDevice to work //

void i2c_check (int end_addr)
{
    char            str[35];
    char            s[35];
    int             i;
    int             start_addr;
    bool            status;
    char           *str2;

    start_addr = 1;
    end_addr = 20;              // End adress may be modified to any
                                // number up to 127

    // Print showing the scan has begun
    sprintf(str, "Scanning %d to %d ...", start_addr * 2, end_addr * 2);
    Serial.println(str);
    str[0] = '\0';
    NXTI2CDevice    mid(start_addr * 2);
    // Start Scanning from start adress adding 1 after each scan till end
    // adress
    for (i = start_addr * 2; i <= end_addr * 2; i += 2) {
        sprintf(str, "Checking Address %d .... ", i);   // Print which
        // adress is being
        // checked
        mid.setAddress(i);
        Serial.print(str);
        str[0] = '\0';

        if (mid.checkAddress()) {
            sprintf(str, "found.");
            Serial.println(str);    // Print if a device is found at
            // this adress
            str[0] = '\0';
            Serial.print("Name: ");
            str2 = mid.getDeviceID();
            strcpy(s, str2);
            Serial.println(s);
            Serial.print("Version: ");
            str2 = mid.getFirmwareVersion();
            Serial.println(str2);
            Serial.print("Vendor: ");
            str2 = mid.getVendorID();
            Serial.println(str2);
            Serial.println("------------------");
        } else {
            Serial.println("no device found.");
        }
    }
    Serial.println("I2C Scan Complete.");



}

int END_ADDRESS = 20;

void
setup()
{
    Serial.begin(9600);         // Start Communication with the Aurduio at
    i2c_check(END_ADDRESS);
    Serial.println("=> Press any key to start the scan again.");

}

void
loop()                          // After the setup the LED blinks to show
                                // the program is complete
{
    if (Serial.available()) {
      i2c_check(END_ADDRESS);
      Serial.read();
      Serial.println("=> Press any key to start the scan again.");
    }
}
