/*
 * ssd1306_bitbang.h
 *
 * Created: 4/21/2013 2:16:29 PM
 *  Author: kmm
 */ 
#include <stdint-gcc.h>


#define BOX_TL 0x10
#define BOX_TR 0x0E
#define BOX_HL 0x40
#define BOX_VL 0x5D
#define BOX_BL 0x0D
#define BOX_BR 0x1D

#ifndef SS1306_H_
#define SS1306_H_

void oled_write(uint8_t dc, uint8_t data);
void oled_init();
void oled_display_en(uint8_t state);
void oled_set_clock(uint8_t val);
void oled_set_addr_mode(uint8_t mode);
void oled_clear();
void oled_Fill();
void oled_home();


void oled_display_off(void);
void oled_display_on(void);

#endif
