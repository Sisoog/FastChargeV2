/*
 * Board.c
 *
 *  Created on: Mar 21, 2016
 *      Author: mohammad
 */

#ifndef BOARD_C_
#define BOARD_C_
#include <stm32f0xx.h>

#define IS_NewBoard		1


#define IS_LernRemote	0
#define Flash_Lock		0

#if(IS_NewBoard==0)
#define LED_GPIO		GPIOA
#define LED1_Pin		GPIO_Pin_6
#else
#define LED_GPIO		GPIOF
#define LED1_Pin		GPIO_Pin_0
#endif

#define LED1_ON()		LED_GPIO->BSRR = LED1_Pin
#define LED1_OFF()		LED_GPIO->BRR = LED1_Pin
#define LED1_Tog()		LED_GPIO->ODR ^= LED1_Pin


#if(IS_NewBoard==0)
#define SWITCH_Pin		GPIO_Pin_5
#define SWITCH_GPIO		GPIOA
#else
#define SWITCH_Pin		GPIO_Pin_1
#define SWITCH_GPIO		GPIOF
#endif
#define PressSW()		((SWITCH_GPIO->IDR & SWITCH_Pin) == 0)

#if(IS_NewBoard==0)
#define OUT_CH1			GPIO_Pin_0
#define OUT_GPIO		GPIOA
#else
#define OUT_CH1			GPIO_Pin_10
#define OUT_GPIO		GPIOA
#endif


#define CH1_ON()		OUT_GPIO->BSRR = OUT_CH1
#define CH1_OFF()		OUT_GPIO->BRR = OUT_CH1
#define CH1_Tog()		OUT_GPIO->ODR ^= OUT_CH1
#define CH1_ISON()		(OUT_GPIO->ODR & OUT_CH1)



#endif /* BOARD_C_ */
