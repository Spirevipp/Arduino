// RelativeRelativeNXTCompass.h
//

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


#ifndef RelativeNXTCompass_H
#define RelativeNXTCompass_H
#include "NXTI2CDevice.h"

class RelativeNXTCompass : public NXTI2CDevice
{
public:
	RelativeNXTCompass(uint8_t i2c_address = 0x02);

	uint16_t		read_raw();
	uint16_t		angle();
	uint16_t		real_north();
	void            set_north();
private:
    uint16_t        _north;
};

#endif

