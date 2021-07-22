#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "BITS_FastIO.h"
#include "clock.h"
#include "gpio.h"
#include "timer.h"
#include "gic.h"
#include "display.h"

void SystemInit(){	
	
}

void watchdog_ISR_Function(void *data){
	PORTG_1 ^= 1;
	WDG_CTRL |= 1;
}

void delay_us(uint32_t count);
void delay_ms(uint32_t count);

//_irq_handler watchdog_callback;

void main(){
	PLL_Init(PLL_CPU, (PLL_PARAM_TypeDef){.P = 1, .N = 25, .K = 2, .M = 1});
	
  GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
	GPIO_InitStruct.Pull = GPIO_PULL_NONE;
	GPIO_InitStruct.MultiDriving = GPIO_DRV_3;
	GPIO_Init(GPIOG, &GPIO_InitStruct);
		
	PORTG_0 = PORTG_1 = PORTG_2 = 1;	
	
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Pull = GPIO_PULL_NONE;
	GPIO_InitStruct.MultiDriving = GPIO_DRV_3;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	PORTB_4 = 1;
	display_Init();
	while(1){
		PORTG_0 = 0;
		delay_ms(2000);
		PORTG_0 = 1;
		delay_ms(2000);
	}
}

void delay_us(uint32_t count){
	count = count * 130;
	while(count--){
	}
}

void delay_ms(uint32_t count){
	while(count--){
		delay_us(1000);
	}
}
