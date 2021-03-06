/*
 * Image2lcd.c
 *
 *  Created on: Feb 3, 2017
 *      Author: mohammad
 */
#include <Image2lcd.h>
#include <gbuf.h>
#include <string.h>

const unsigned char gImage_USB[436] =
{ 0X22,0X01,0X56,0X00,0X28,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X80,0XC0,0XC0,0XC0,0XE0,0XE0,0XE0,0XF0,
0XF0,0XF0,0XF8,0XF8,0XF8,0XFC,0XFC,0XFC,0XFC,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,
0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,
0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0XFE,0X00,0X00,0X00,0X00,0X00,
0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X80,
0X80,0X80,0X80,0X80,0X80,0X80,0XF8,0XFC,0XFE,0XFE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X3F,0XBF,0X9F,0X9F,0X9F,0X0F,0X0F,0X0F,0X0F,
0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,
0X1F,0X1F,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC7,0X83,0X01,0X01,0X83,0X83,0XC7,
0XEF,0XEF,0XCF,0XCF,0X8F,0X0F,0X6F,0XE7,0XE7,0XE3,0XE1,0XEC,0XEE,0XEF,0XEF,0XEF,
0XEF,0XEF,0XEF,0XEF,0XEF,0XEF,0XEF,0XEF,0XEF,0XEF,0X83,0X83,0XC7,0XCF,0XEF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X7E,0X7E,0X7E,0X7E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X1F,0X3F,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0XFC,0XF9,0XF9,
0XF3,0XF3,0XF3,0XF3,0XF3,0XF3,0XE1,0XE1,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,
0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0XF8,0XF8,0XF8,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,
0X01,0X03,0X03,0X03,0X07,0X07,0X0F,0X0F,0X0F,0X1F,0X1F,0X1F,0X3F,0X3F,0X3F,0X3F,
0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,
0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,0X7F,
0X7F,0X7F,0X7F,0X00,0X00,0X00,0X00,0X00,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,
0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,0X01,};


const unsigned char gImage_rfid[366] = { 0X22,0X01,0X3C,0X00,0X30,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X80,0XC0,0XC0,0XC0,0XE0,0XE0,0XF0,0XF0,0XF0,0XF8,
0X78,0X7C,0X3C,0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3F,0X3F,0X1F,0X1F,0X1F,0X1F,0X3F,
0X3E,0X3E,0X3E,0X3E,0X3E,0X3E,0X3C,0X3C,0X7C,0X78,0XF8,0XF0,0XF0,0XE0,0XE0,0XE0,
0XC0,0XC0,0XC0,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0XF8,0XFC,0XFC,
0X7E,0X3F,0X1F,0X0F,0X0F,0X07,0X03,0X03,0X81,0XC0,0XC0,0XE0,0XE0,0XF0,0XF0,0XF8,
0XF8,0XF8,0XFC,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0XFC,
0XF8,0XF8,0XF8,0XF0,0XF0,0XF0,0XE0,0XC0,0XC1,0XC1,0XC3,0XC3,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0XFC,0XF8,0XF0,0XF0,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1C,
0X3C,0XFE,0XFE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0XF1,0XF0,0XF8,0XF8,0XFC,
0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0X7C,0XFC,0XFC,0XF8,0XF8,0XF1,0XF1,0XF1,
0XE3,0XC3,0X83,0X87,0X0F,0X0F,0X1F,0X3F,0X7F,0XFF,0XFF,0X7F,0X7F,0X3F,0X0F,0X07,
0X03,0X03,0X03,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X03,
0X07,0X0F,0X0F,0X1F,0X0F,0X0F,0X83,0XC3,0XC1,0XE1,0XE0,0XF0,0XF0,0XF0,0XF8,0X78,
0X78,0X78,0X78,0XF8,0XF0,0XF0,0XF0,0XF0,0XF1,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X3F,
0X3E,0X1C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X03,0X07,0X0F,0X9F,0XFF,0XFF,0XFF,0XFC,0XFC,0X7C,0X7C,0XFC,0XFC,
0XF8,0XF1,0XE1,0X83,0X07,0X07,0X07,0X07,0X03,0X01,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X03,0X0F,0X1F,0X7F,0X7F,0X7C,0XFC,0XFC,0X7C,0X7F,0X3F,0X1F,0X1F,0X07,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};




void Load_Image(uint8_t X,uint8_t Y,const unsigned char *picture)
{
	const uint8_t *Pic = picture;
	HEADGRAY  Head;
	memcpy(&Head,Pic,sizeof(HEADGRAY));
	Pic += sizeof(HEADGRAY);

	for(int y=0;y<Head.h/8;y++)
		for(int x=0;x<Head.w;x++)
			GBGWrite(X + x,Y + (y*8),8,*Pic++);
			//GBGWrite(x,y*8,8,0xFF);
}



