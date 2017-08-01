
// RelativeNXTCompass.cpp

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


#include "RelativeNXTCompass.h"


RelativeNXTCompass::RelativeNXTCompass(uint8_t i2c_address)
: NXTI2CDevice(i2c_address)
{
    _north = 0;
}

uint16_t RelativeNXTCompass::read_raw()
{
    uint16_t r0, r1;
    r0 = readByte(0x44);
    r1 = readByte(0x45);

    r1 = r1 * 256;
    delay(10);

    return r1 + r0;
}


void RelativeNXTCompass::set_north()
{
    _north = read_raw();
}

uint16_t RelativeNXTCompass::angle()
{
    uint16_t relative_angle = (read_raw() - _north + 360) % 360;

    if (relative_angle < 0)
        relative_angle += 360;

    return relative_angle;
}

uint16_t RelativeNXTCompass::real_north()
{
    return _north;
}

