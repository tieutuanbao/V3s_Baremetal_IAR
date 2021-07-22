#ifndef __BITS_FASTIO_H
#define __BITS_FASTIO_H

typedef struct{
	uint32_t Bit0			:	1;
	uint32_t Bit1			:	1;
	uint32_t Bit2			:	1;
	uint32_t Bit3			:	1;
	uint32_t Bit4			:	1;
	uint32_t Bit5			:	1;
	uint32_t Bit6			:	1;
	uint32_t Bit7			:	1;
	uint32_t Bit8			:	1;
	uint32_t Bit9			:	1;
	uint32_t Bit10		:	1;
	uint32_t Bit11		:	1;
	uint32_t Bit12		:	1;
	uint32_t Bit13		:	1;
	uint32_t Bit14		:	1;
	uint32_t Bit15		:	1;
	uint32_t Bit16		:	1;
	uint32_t Bit17		:	1;
	uint32_t Bit18		:	1;
	uint32_t Bit19		:	1;
	uint32_t Bit20		:	1;
	uint32_t Bit21		:	1;
	uint32_t Bit22		:	1;
	uint32_t Bit23		:	1;
	uint32_t Bit24		:	1;
	uint32_t Bit25		:	1;
	uint32_t Bit26		:	1;
	uint32_t Bit27		:	1;
	uint32_t Bit28		:	1;
	uint32_t Bit29		:	1;
	uint32_t Bit30		:	1;
	uint32_t Bit31		:	1;
} _bit;

#ifdef V3S
	/* ~~~~~~~~~~~~~~~~~~~~ PORT Define ~~~~~~~~~~~~~~~~~~~~ */
	#define PORTB	GPIOB->DATA
	#define PORTC	GPIOC->DATA
	#define PORTD	GPIOD->DATA
	#define PORTE	GPIOE->DATA
	#define PORTF	GPIOF->DATA
	#define PORTG	GPIOG->DATA

	/* ~~~~~~~~~~~~~~~~~~~~ Bit Define ~~~~~~~~~~~~~~~~~~~~ */
	#define PORTB_0		((_bit *)&(GPIOB->DATA))->Bit0
	#define PORTB_1		((_bit *)&(GPIOB->DATA))->Bit1
	#define PORTB_2		((_bit *)&(GPIOB->DATA))->Bit2
	#define PORTB_3		((_bit *)&(GPIOB->DATA))->Bit3
	#define PORTB_4		((_bit *)&(GPIOB->DATA))->Bit4
	#define PORTB_5		((_bit *)&(GPIOB->DATA))->Bit5
	#define PORTB_6		((_bit *)&(GPIOB->DATA))->Bit6
	#define PORTB_7		((_bit *)&(GPIOB->DATA))->Bit7
	#define PORTB_8		((_bit *)&(GPIOB->DATA))->Bit8
	#define PORTB_9		((_bit *)&(GPIOB->DATA))->Bit9

	#define PORTC_0		((_bit *)&(GPIOC->DATA))->Bit0
	#define PORTC_1		((_bit *)&(GPIOC->DATA))->Bit1
	#define PORTC_2		((_bit *)&(GPIOC->DATA))->Bit2
	#define PORTC_3		((_bit *)&(GPIOC->DATA))->Bit3

	#define PORTE_0		((_bit *)&(GPIOE->DATA))->Bit0
	#define PORTE_1		((_bit *)&(GPIOE->DATA))->Bit1
	#define PORTE_2		((_bit *)&(GPIOE->DATA))->Bit2
	#define PORTE_3		((_bit *)&(GPIOE->DATA))->Bit3
	#define PORTE_4		((_bit *)&(GPIOE->DATA))->Bit4
	#define PORTE_5		((_bit *)&(GPIOE->DATA))->Bit5
	#define PORTE_6		((_bit *)&(GPIOE->DATA))->Bit6
	#define PORTE_7		((_bit *)&(GPIOE->DATA))->Bit7
	#define PORTE_8		((_bit *)&(GPIOE->DATA))->Bit8
	#define PORTE_9		((_bit *)&(GPIOE->DATA))->Bit9
	#define PORTE_10		((_bit *)&(GPIOE->DATA))->Bit10
	#define PORTE_11		((_bit *)&(GPIOE->DATA))->Bit11
	#define PORTE_12		((_bit *)&(GPIOE->DATA))->Bit12
	#define PORTE_13		((_bit *)&(GPIOE->DATA))->Bit13
	#define PORTE_14		((_bit *)&(GPIOE->DATA))->Bit14
	#define PORTE_15		((_bit *)&(GPIOE->DATA))->Bit15
	#define PORTE_16		((_bit *)&(GPIOE->DATA))->Bit16
	#define PORTE_17		((_bit *)&(GPIOE->DATA))->Bit17
	#define PORTE_18		((_bit *)&(GPIOE->DATA))->Bit18
	#define PORTE_19		((_bit *)&(GPIOE->DATA))->Bit19
	#define PORTE_20		((_bit *)&(GPIOE->DATA))->Bit20
	#define PORTE_21		((_bit *)&(GPIOE->DATA))->Bit21
	#define PORTE_22		((_bit *)&(GPIOE->DATA))->Bit22
	#define PORTE_23		((_bit *)&(GPIOE->DATA))->Bit23
	#define PORTE_24		((_bit *)&(GPIOE->DATA))->Bit24
	#define PORTE_25		((_bit *)&(GPIOE->DATA))->Bit25
	#define PORTE_26		((_bit *)&(GPIOE->DATA))->Bit26
	#define PORTE_27		((_bit *)&(GPIOE->DATA))->Bit27
	#define PORTE_28		((_bit *)&(GPIOE->DATA))->Bit28
	#define PORTE_29		((_bit *)&(GPIOE->DATA))->Bit29

	#define PORTF_0		((_bit *)&(GPIOF->DATA))->Bit0
	#define PORTF_1		((_bit *)&(GPIOF->DATA))->Bit1
	#define PORTF_2		((_bit *)&(GPIOF->DATA))->Bit2
	#define PORTF_3		((_bit *)&(GPIOF->DATA))->Bit3
	#define PORTF_4		((_bit *)&(GPIOF->DATA))->Bit4
	#define PORTF_5		((_bit *)&(GPIOF->DATA))->Bit5
	#define PORTF_6		((_bit *)&(GPIOF->DATA))->Bit6

	#define PORTG_0		((_bit *)&(GPIOG->DATA))->Bit0
	#define PORTG_1		((_bit *)&(GPIOG->DATA))->Bit1
	#define PORTG_2		((_bit *)&(GPIOG->DATA))->Bit2
	#define PORTG_3		((_bit *)&(GPIOG->DATA))->Bit3
	#define PORTG_4		((_bit *)&(GPIOG->DATA))->Bit4
	#define PORTG_5		((_bit *)&(GPIOG->DATA))->Bit5

#endif

#endif