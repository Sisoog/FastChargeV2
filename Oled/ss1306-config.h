/*
 * ssd1306_config.h
 *
 * Created: 4/29/2013 7:11:39 PM
 *  Author: kmm
 */ 


#ifndef SS1306_CONFIG_H_
#define SS1306_CONFIG_H_

#define SS1306_OLED_GEOM_W 128
#define SS1306_OLED_GEOM_H 64


#define SS1306_OLED_DC    GPIO_Pin_4
#define SS1306_OLED_CS    PB2
#define SS1306_OLED_PORT  GPIOA


#define SS1306_OLED_PORTC_MASK _BV(SS1306_OLED_DC) | _BV(SS1306_OLED_CS);


#endif
