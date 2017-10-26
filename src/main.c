//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include <stm32f0xx.h>
#include <stm32f0xx_iwdg.h>
#include <ss1306.h>
#include <Image2lcd.h>
#include <gbuf.h>
// ----- main() ---------------------------------------------------------------

#define LsiFreq 	 40000
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"


void HW_Init(void);
void SetRDP(void);

int main(int argc, char* argv[])
{
	SystemInit();
	SystemCoreClockUpdate();
	HW_Init();

#if(Flash_Lock)
	SetRDP();

	/* Enable write access to IWDG_PR and IWDG_RLR registers */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	/* IWDG counter clock: LSI/32 */
    IWDG_SetPrescaler(IWDG_Prescaler_64);
    IWDG_SetReload(LsiFreq/16); /*1000 ms*/
    IWDG_ReloadCounter();
	IWDG_Enable();
#endif


	oled_init();
	oled_clear();
	GBcls();
	Load_Image(10,10,gImage_USB);
	GBupdate();
  while (1)
    {

    }

}

#if(Flash_Lock)
void SetRDP(void)
{
  FLASH_Status FLASHStatus = FLASH_COMPLETE;

  /* Unlock the Flash Program Erase controller */
  FLASH_Unlock();

  FLASH_OB_Unlock();

//  /* Clear all FLASH flags */
//  FLASH_ClearFlag( FLASH_FLAG_WRPERR | FLASH_FLAG_PGERR | FLASH_FLAG_BSY);
//  FLASH_ClearFlag(FLASH_FLAG_EOP);

  if (!FLASH_OB_GetRDP())
  {
    FLASHStatus = FLASH_OB_RDPConfig(OB_RDP_Level_1); // Locks Chip (Lvl 2 Toasts)

    if (FLASHStatus == FLASH_COMPLETE)
    {
      /* Generate System Reset to load the new option byte values */
      FLASH_OB_Launch();
    }
  }
}
#endif


void HW_Init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA , ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;


	/* SPI pin mappings */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_0);


	// Configure pin in output push/pull mode
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);



	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 /* LCD D/C*/ | GPIO_Pin_6 /*LCD Reset*/;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* SPI configuration -------------------------------------------------------*/
	SPI_I2S_DeInit(SPI1);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_Init(SPI1, &SPI_InitStructure);

	/* Enable the SPI peripheral */
	SPI_Cmd(SPI1, ENABLE);
}





#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
