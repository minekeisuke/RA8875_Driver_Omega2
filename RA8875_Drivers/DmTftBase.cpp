/**********************************************************************************************
 Copyright (c) 2014 DisplayModule. All rights reserved.

 Redistribution and use of this source code, part of this source code or any compiled binary
 based on this source code is permitted as long as the above copyright notice and following
 disclaimer is retained.

 DISCLAIMER:
 THIS SOFTWARE IS SUPPLIED "AS IS" WITHOUT ANY WARRANTIES AND SUPPORT. DISPLAYMODULE ASSUMES
 NO RESPONSIBILITY OR LIABILITY FOR THE USE OF THE SOFTWARE.
 ********************************************************************************************/

#include "DmTftBase.h"
#include <cstring>

#define FONT_CHAR_WIDTH    8
#define FONT_CHAR_HEIGHT  16
const unsigned char font[1520] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x48,0x6C,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x24,0x24,0x24,0x7F,0x12,0x12,0x12,0x7F,0x12,0x12,0x12,0x00,0x00,
0x00,0x00,0x08,0x1C,0x2A,0x2A,0x0A,0x0C,0x18,0x28,0x28,0x2A,0x2A,0x1C,0x08,0x08,
0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x15,0x2A,0x58,0x54,0x54,0x54,0x22,0x00,0x00,
0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x11,0x91,0x6E,0x00,0x00,
0x00,0x06,0x06,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,
0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x7F,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x04,0x03,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,
0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00,
0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x04,
0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x40,0x20,0x10,0x10,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x2D,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F,
0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00,
0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00,
0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x4D,0x53,0x32,0x1C,0x60,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x6B,0x49,0x49,0x49,0x49,0x55,0x55,0x36,0x22,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00,
0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,
0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40,
0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,
0x00,0x38,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x78,0x44,0x42,0x42,0xFC,0x00,0x00,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00,
0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x78,0x44,0x42,0x42,0x42,0x64,0xD8,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x02,0x02,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xF0,0x88,0x08,0x08,0x7E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x72,0x12,0x0A,0x16,0x12,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEB,0x49,0x49,0x55,0x55,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x24,0x18,0x18,0x18,0x24,0x6E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x18,0x08,0x08,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00,
0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
0x00,0x06,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x06,0x00,
0x0C,0x32,0xC2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

/*
 * Macro to read the 8 bits representing one line of a character.
 * The macro is needed as the reading is handled differently on
 * Arduino and Mbed platforms.
 */

#define read_font_line(__char, __line) \
	font[((uint16_t)(__char))*FONT_CHAR_HEIGHT+(__line)]


void DmTftBase::setPixel(uint16_t x, uint16_t y, uint16_t color) {
  cbi(_pinCS, _bitmaskCS);

  if ((x >= _width) || (y >= _height)) {
    return;
  }

  setAddress(x, y, x, y);

  sendData(color);
  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::clearScreen(uint16_t color) {
  cbi(_pinCS, _bitmaskCS);

  setAddress(0,0,_width-1, _height-1);

  for(uint16_t i=0; i<_height; i++) {
    for(uint16_t j=0; j<_width; j++) {
        sendData(color);
    }
  }

  sbi(_pinCS, _bitmaskCS);
}

void  DmTftBase::drawHorizontalLine(uint16_t x, uint16_t y, uint16_t length, uint16_t color) {
  cbi(_pinCS, _bitmaskCS);

  setAddress(x, y, x + length, y);

  for (int i = 0; i <= length; i++) {
    sendData(color);
  }

  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::drawVerticalLine(uint16_t x, uint16_t y, uint16_t length, uint16_t color) {
  cbi(_pinCS, _bitmaskCS);

  setAddress(x, y, x, y + length);

  for (int i = 0; i <= length; i++) {
    sendData(color);
  }

  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) {
  int x = x1-x0;
  int y = y1-y0;
  int dx = abs(x), sx = x0<x1 ? 1 : -1;
  int dy = -abs(y), sy = y0<y1 ? 1 : -1;
  int err = dx+dy, e2;  /* error value e_xy             */
  for (;;) {
    setPixel(x0,y0,color);
    e2 = 2*err;
    if (e2 >= dy) {      /* e_xy+e_x > 0                 */
      if (x0 == x1) {
        break;
      }
      err += dy; x0 += sx;
    }
    if (e2 <= dx) { /* e_xy+e_y < 0   */
      if (y0 == y1) {
        break;
      }
      err += dx; y0 += sy;
    }
  }
}

void DmTftBase::drawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) {
  // Make sure x0,y0 are in the top left corner
  if(x0 > x1) {
    x0 = x0^x1;
    x1 = x0^x1;
    x0 = x0^x1;
  }
  if(y0 > y1) {
    y0 = y0^y1;
    y1 = y0^y1;
    y0 = y0^y1;
  }

  drawHorizontalLine(x0, y0, x1-x0, color);
  drawHorizontalLine(x0, y1, x1-x0, color);
  drawVerticalLine(x0, y0, y1-y0, color);
  drawVerticalLine(x1, y0, y1-y0, color);
}

void DmTftBase::fillRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) {
  unsigned long numPixels=0;
  unsigned long i=0;

  // Make sure x0,y0 are in the top left corner
  if(x0 > x1) {
    x0 = x0^x1;
    x1 = x0^x1;
    x0 = x0^x1;
  }
  if(y0 > y1) {
    y0 = y0^y1;
    y1 = y0^y1;
    y0 = y0^y1;
  }

  x0 = constrain(x0, 0, _width-1);
  x1 = constrain(x1, 0, _width-1);
  y0 = constrain(y0, 0, _height-1);
  y1 = constrain(y1, 0, _height-1);

  numPixels = (x1-x0+1);
  numPixels = numPixels*(y1-y0+1);

  cbi(_pinCS, _bitmaskCS);
  setAddress(x0,y0,x1,y1);/* start to write to display ra */

  for(i=0; i < numPixels; i++) {
    sendData(color);
  }

  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color) {
  int x = -r, y = 0, err = 2-2*r, e2;
  do {
    setPixel(x0-x, y0+y, color);
    setPixel(x0+x, y0+y, color);
    setPixel(x0+x, y0-y, color);
    setPixel(x0-x, y0-y, color);
    e2 = err;
    if (e2 <= y) {
      err += ++y*2+1;
      if (-x == y && e2 <= x) {
        e2 = 0;
      }
    }
    if (e2 > x) {
      err += ++x * 2 + 1;
    }
  } while (x <= 0);
}

void DmTftBase::fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color) {
  int x = -r, y = 0, err = 2-2*r, e2;
  do {
    drawVerticalLine(x0-x, y0-y, 2*y, color);
    drawVerticalLine(x0+x, y0-y, 2*y, color);

    e2 = err;
    if (e2 <= y) {
      err += ++y * 2 + 1;
      if (-x == y && e2 <= x) {
        e2 = 0;
      }
    }
    if (e2 > x) {
      err += ++x*2+1;
    }
  } while (x <= 0);
}

void DmTftBase::drawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {
  drawLine(x0, y0, x1, y1, color);
  drawLine(x0, y0, x2, y2, color);
  drawLine(x1, y1, x2, y2, color);
}

void DmTftBase::drawPoint(uint16_t x, uint16_t y, uint16_t radius) {
  if (radius == 0) {
    cbi(_pinCS, _bitmaskCS);

    setAddress(x,y,x,y);
    sendData(_fgColor);

    sbi(_pinCS, _bitmaskCS);
  } else {
    fillRectangle(x-radius,y-radius,x+radius,y+radius, _fgColor);
  }
}

void DmTftBase::drawChar(uint16_t x, uint16_t y, char ch, bool transparent) {
  cbi(_pinCS, _bitmaskCS);

  uint8_t temp;
  uint8_t pos,t;

  if ((x > (_width - FONT_CHAR_WIDTH)) || (y > (_height - FONT_CHAR_HEIGHT))) {
    return;
  }

  ch=ch-' ';
  if (!transparent) { // Clear background
    setAddress(x,y,x+FONT_CHAR_WIDTH-1,y+FONT_CHAR_HEIGHT-1);
    for(pos=0;pos<FONT_CHAR_HEIGHT;pos++) {
      temp = read_font_line(ch, pos);
      for(t=0;t<FONT_CHAR_WIDTH;t++) {
        if (temp & 0x01) {
          sendData(_fgColor);
        }
        else {
          sendData(_bgColor);
        }
        temp>>=1;
      }
      y++;
    }
  }
  else { //Draw directly without clearing background
    for(pos=0;pos<FONT_CHAR_HEIGHT;pos++) {
      temp = read_font_line(ch, pos);
      for(t=0;t<FONT_CHAR_WIDTH;t++) {
        if (temp & 0x01) {
          setAddress(x + t, y + pos, x + t, y + pos);
          sendData(_fgColor);
          //drawPoint(x + t, y + pos);
        }
        temp>>=1;
      }
    }
  }

  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::drawNumber(uint16_t x, uint16_t y, int num, int digitsToShow, bool leadingZeros) {
  bool minus = false;
  if (num < 0) {
    num = -num;
    minus = true;
  }
  for (int i = 0; i < digitsToShow; i++) {
    char c = ' ';
    if ((num == 0) && (i > 0)) {
      if (leadingZeros) {
        c = '0';
        if (minus && (i == (digitsToShow-1))) {
          c = '-';
        }
      } else if (minus) {
        c = '-';
        minus = false;
      }
    } else {
      c = '0' + (num % 10);
    }
    drawChar(x + FONT_CHAR_WIDTH*(digitsToShow - i - 1), y, c, false);
    num = num / 10;
  }
}

void DmTftBase::drawString(uint16_t x, uint16_t y, const char *p) {
  while(*p!='\0')
  {
    if(x > (_width - FONT_CHAR_WIDTH)) {
      x = 0;
      y += FONT_CHAR_HEIGHT;
    }
    if(y > (_height - FONT_CHAR_HEIGHT)) {
      y = x = 0;
    }
    drawChar(x, y, *p, false);
    x += FONT_CHAR_WIDTH;
    p++;
  }
}

void DmTftBase::drawStringCentered(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const char *p) {
  int len = strlen(p);
  uint16_t tmp = len * FONT_CHAR_WIDTH;
  if (tmp <= width) {
    x += (width - tmp)/2;
  }
  if (FONT_CHAR_HEIGHT <= height) {
    y += (height - FONT_CHAR_HEIGHT)/2;
  }
  drawString(x, y, p);
}

void DmTftBase::drawImage(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t* data) {
  const uint16_t* p = data;

  cbi(_pinCS, _bitmaskCS);

  setAddress(x,y,x+width-1,y+height-1);
  for (int i = width*height; i > 0; i--) {
    sendData(*p);
    p++;
  }

  sbi(_pinCS, _bitmaskCS);
}

void DmTftBase::select(){
  cbi(_pinCS, _bitmaskCS);
}

void DmTftBase::unSelect() {
  sbi(_pinCS, _bitmaskCS);
}


