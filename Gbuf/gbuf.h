/*****************************************************
© Copyright 2000-2010 
http://www.elecom.agape.ir

Name 	: GBUF
Version : 3.0
Date    : 2010/08/10
Author  : Mohammad mazarei
Email	: mohammad.mazarei@gmail.com
LICENSE	: GNU GPL version 3
****************************************************/
#ifndef GB_CLASS_h
#define GB_CLASS_h
#define GBVERSION       3
#include <stdint-gcc.h>

/*
 BeFor Include This Lib,shuld be Define 'Show_Buf' Function.
        This Function Drow a Buffer To Display Screen;
        Scale of Function:    
                void Show_Buf(char *Buf)
        Sample:
        void Show_Buf(char *Buf){
            int i;
            ks0108_SetAddress(0,0);
            for(i=0;i<1024;i++)
                ks0108_Write(*Buf++);
        }
*/

#define MAX_X 128
#define MAX_Y 64

#define MAX_BUF MAX_X*MAX_Y/8
#ifndef black
#define black 1
#endif
#define white 0

    

    char GBRead(char x, char y);
    void GBWrite(char x, char y, char data);
    void GBGWrite(char x, char y,char _bit ,char data);
    void GBGWriteXOR(char x, char y,char _bit ,char data);
    void GBcls(void);
    void GBinvert(void);
    void GBupdate(void);
    
    void GBpset(char x,char y);
    void GBReset(char x,char y);
    void GBpoint(int x,int y,char color);
    char GBread_point(char x,char y);
    
    void GBline(int startx,int starty,int endx,int endy,char color);
    void GBCircle(unsigned char xcenter,unsigned char ycenter,unsigned char radius);
    void GBbox(int startx,int starty,int endx,int endy,char color);
    void GBfill_box(int startx,int starty,int endx,int endy,char color);
    
    void GBcopy_screen(int startx, int starty,int endx,int endy, int x, int y);
    void GBmove_screen(int startx, int starty,int endx,int endy, int x, int y);

    void GBprintBigNumber(char Num, int X, int Y);
    void GBwriteCharBig (unsigned char x,unsigned char y,unsigned char ch);
#endif



