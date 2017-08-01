// HTIRSeekerV2.cpp

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


#include "HTIRSeekerV2.h"


HTIRSeekerV2::HTIRSeekerV2(uint8_t i2c_address)
: NXTI2CDevice(i2c_address)
{

}

void HTIRSeekerV2::read(uint8_t *dir, uint8_t *s1, uint8_t *s2, uint8_t *s3, uint8_t *s4,
                    uint8_t *s5)
{

    *dir  = readByte(0x49);
    *s1 = readByte(0x4A);
    *s2 = readByte(0x4B);
    *s3 = readByte(0x4C);
    *s4 = readByte(0x4D);
    *s5 = readByte(0x4E);
    delay(10);
}


