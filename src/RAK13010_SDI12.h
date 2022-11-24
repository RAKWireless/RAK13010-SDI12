 /**
   @file RAK13010_SDI12.h
   @author rakwireless.com
   @brief  This is part of RAK13010 SDI12 is based on EnviroDIY Arduino-SDI-12 library for the Arduino platform.
           We have added support for RAK4631 and RAK11300.
   @version 0.1
   @date  2022-03-14
   @copyright Copyright (c) 2022
**/

#ifndef __RAK13010_SDI12_H__
#define __RAK13010_SDI12_H__

#include "SDI12.h"

#if defined(RAK4630)
	#include "Adafruit_TinyUSB.h"
#endif 

class RAK_SDI12 : public SDI12
{
  public:
  RAK_SDI12(int8_t dataPinRX  , int8_t dataPinTX , int8_t OE) : SDI12(dataPinRX,dataPinTX,OE){};
  RAK_SDI12(void) : SDI12(){};
  ~RAK_SDI12(){};
};

#endif 