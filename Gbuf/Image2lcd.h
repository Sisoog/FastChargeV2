/*
 * Image2lcd.h
 *
 *  Created on: Feb 3, 2017
 *      Author: mohammad
 */

#ifndef IMAGE2LCD_H_
#define IMAGE2LCD_H_
#include <stdint-gcc.h>


typedef struct _HEADGRAY
{
   uint8_t scan;
   uint8_t gray;
   uint16_t w;
   uint16_t h;
}HEADGRAY;


extern const unsigned char gImage_USB[436];
extern const unsigned char gImage_rfid[366];

void Load_Image(uint8_t X,uint8_t Y,const unsigned char *picture);

#endif /* IMAGE2LCD_H_ */
