// HTIRSeekerV2.h
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


#ifndef HTIRSeekerV2_H
#define HTIRSeekerV2_H
#include "NXTI2CDevice.h"

class HTIRSeekerV2 : public NXTI2CDevice
{
public:
    HTIRSeekerV2(uint8_t i2c_address = 0x10);
    void        read(uint8_t *dir, uint8_t *s1, uint8_t *s2, uint8_t *s3, uint8_t *s4,
                    uint8_t *s5);

};

#endif


