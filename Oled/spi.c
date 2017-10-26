/*
 * SSD1306.c
 *
 *  Created on: Oct 26, 2017
 *      Author: Mazarei
 */
#include <stm32f0xx.h>



void SPI_Send(uint8_t Data)
{
	while (!(SPI1->SR & SPI_SR_TXE)); // Wait until TX buffer is empty
	SPI_SendData8(SPI1,Data);
	while (SPI1->SR & SPI_SR_BSY); // Wait until the transmission is complete
}

