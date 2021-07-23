/**
	******************************************************************************
	* @file display.c
	*
	* @brief Display Config for V3s
	*
	*
	* @author Tieu Tuan Bao
	* Contact: tieutuanbao@gmail.com
	* P-Number: +84979755670
	******************************************************************************
	*/

#include "display.h"
#include "gpio.h"
#include "clock.h"
#include "de.h"


void display_Init(){
	/* ------------------ GPIO Init ------------------ */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_AF3;
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|
												GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_16|GPIO_PIN_17|GPIO_PIN_18|GPIO_PIN_19|GPIO_PIN_23|GPIO_PIN_24;
	
	GPIO_InitStruct.Pull = GPIO_PULL_NONE;
	GPIO_InitStruct.MultiDriving = GPIO_DRV_3;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
		
	/* ------------------ CLOCK Init ------------------ */
	PLL_Init(PLL_VIDEO, (PLL_PARAM_TypeDef){.P = 1, .N = 100, .K = 1, .M = 4});		//PLL_Video = (24 * N) / M        N=[1,128] M=[1,16]
	PLL_Init(PLL_VE, (PLL_PARAM_TypeDef){.P = 1, .N = 100, .K = 1, .M = 4});		//PLL_VE = (24 * N) / M        N=[1,128] M=[1,16]
	
	write32(CCU_DE_CLK, read32(CCU_DE_CLK)|(1U<<31));					// Enable Gating Clock
	write32(CCU_TCON_CLK, read32(CCU_TCON_CLK)|(1U<<31));			// Enable Gating Clock
	
	/* ------------------ TCON Disable ------------------ */
	write32(TCON_BASE, read32(TCON_BASE)|(1U<<31));
	/* ------------------ DE set mode ------------------ */
//	write32();
}