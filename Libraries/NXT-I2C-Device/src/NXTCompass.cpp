// NXTCompass.cpp

// Initial version: mrShu, 2013

/*
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
*/


#include "NXTCompass.h"


NXTCompass::NXTCompass(uint8_t i2c_address)
: NXTI2CDevice(i2c_address)
{
}

uint8_t NXTCompass::read()
{
    byte r[2];
    r[0] = readByte(0x44);
    r[1] = readByte(0x45);
    delay(10);

    Serial.print(r[0]);
    Serial.print(' ');
    Serial.println(r[1]);

    int c = (r[1] * 256) + (uint8_t) r[0];
    return c;
}


