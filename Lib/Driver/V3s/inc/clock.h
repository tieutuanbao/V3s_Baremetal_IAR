#ifndef __V3S_CLOCK_H__
#define __V3S_CLOCK_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "memmap.h"

#define	CCU_PLL_CPU_CTRL 							*(volatile uint32_t *)(CCU_BASE + 0x000)
#define	CCU_PLL_AUDIO_CTRL 						*(volatile uint32_t *)(CCU_BASE + 0x008)
#define	CCU_PLL_VIDEO_CTRL 						*(volatile uint32_t *)(CCU_BASE + 0x010)
#define	CCU_PLL_VE_CTRL 							*(volatile uint32_t *)(CCU_BASE + 0x018)
#define	CCU_PLL_DDR0_CTRL 						*(volatile uint32_t *)(CCU_BASE + 0x020)
#define	CCU_PLL_PERIPH0_CTRL 					*(volatile uint32_t *)(CCU_BASE + 0x028)
#define	CCU_PLL_ISP_CTRL 							*(volatile uint32_t *)(CCU_BASE + 0x02C)
#define	CCU_PLL_PERIPH1_CTRL 					*(volatile uint32_t *)(CCU_BASE + 0x044)
#define	CCU_PLL_DDR1_CTRL 						*(volatile uint32_t *)(CCU_BASE + 0x04C)
	
#define	CCU_CPU_AXI_CFG 							*(volatile uint32_t *)(CCU_BASE + 0x050)
#define	CCU_AHB_APB0_CFG 							*(volatile uint32_t *)(CCU_BASE + 0x054)
#define	CCU_APB1_CFG 									*(volatile uint32_t *)(CCU_BASE + 0x058)
#define	CCU_AHB2_CFG 									*(volatile uint32_t *)(CCU_BASE + 0x05C)

#define	CCU_BUS_CLK_GATE0 						*(volatile uint32_t *)(CCU_BASE + 0x060)
#define	CCU_BUS_CLK_GATE1 						*(volatile uint32_t *)(CCU_BASE + 0x064)
#define	CCU_BUS_CLK_GATE2 						*(volatile uint32_t *)(CCU_BASE + 0x068)
#define	CCU_BUS_CLK_GATE3 						*(volatile uint32_t *)(CCU_BASE + 0x06C)
#define	CCU_BUS_CLK_GATE4 						*(volatile uint32_t *)(CCU_BASE + 0x070)

#define	CCU_SDMMC0_CLK 								*(volatile uint32_t *)(CCU_BASE + 0x088)
#define	CCU_SDMMC1_CLK 								*(volatile uint32_t *)(CCU_BASE + 0x08C)
#define	CCU_SDMMC2_CLK 								*(volatile uint32_t *)(CCU_BASE + 0x090)
#define	CCU_CE_CLK 										*(volatile uint32_t *)(CCU_BASE + 0x09C)
#define	CCU_SPI0_CLK 									*(volatile uint32_t *)(CCU_BASE + 0x0A0)
#define	CCU_USBPHY_CFG								*(volatile uint32_t *)(CCU_BASE + 0x0CC)
#define	CCU_DRAM_CFG									*(volatile uint32_t *)(CCU_BASE + 0x0F4)
#define	CCU_DDR1_CFG									*(volatile uint32_t *)(CCU_BASE + 0x0F8)
#define	CCU_MBUS_RST									*(volatile uint32_t *)(CCU_BASE + 0x0FC)
#define	CCU_DRAM_CLK_GATE 						*(volatile uint32_t *)(CCU_BASE + 0x100)
#define	CCU_DE_CLK										*(volatile uint32_t *)(CCU_BASE + 0x104)
#define	CCU_TCON_CLK 									*(volatile uint32_t *)(CCU_BASE + 0x118)
#define	CCU_CSI_CLK 									*(volatile uint32_t *)(CCU_BASE + 0x134)
#define	CCU_VE_CLK 										*(volatile uint32_t *)(CCU_BASE + 0x13C)
#define	CCU_AC_DIG_CLK 								*(volatile uint32_t *)(CCU_BASE + 0x140)
#define	CCU_AVS_CLK 									*(volatile uint32_t *)(CCU_BASE + 0x144)
#define	CCU_MBUS_CLK									*(volatile uint32_t *)(CCU_BASE + 0x15C)
#define	CCU_MIPI_CSI									*(volatile uint32_t *)(CCU_BASE + 0x16C)
#define	CCU_PLL_STABLE_TIME0 					*(volatile uint32_t *)(CCU_BASE + 0x200)
#define	CCU_PLL_STABLE_TIME1 					*(volatile uint32_t *)(CCU_BASE + 0x204)
#define	CCU_PLL_CPU_BIAS 							*(volatile uint32_t *)(CCU_BASE + 0x220)
#define	CCU_PLL_AUDIO_BIAS 						*(volatile uint32_t *)(CCU_BASE + 0x224)
#define	CCU_PLL_VIDEO_BIAS 						*(volatile uint32_t *)(CCU_BASE + 0x228)
#define	CCU_PLL_VE_BIAS 							*(volatile uint32_t *)(CCU_BASE + 0x22C)
#define	CCU_PLL_DDR0_BIAS 						*(volatile uint32_t *)(CCU_BASE + 0x230)
#define	CCU_PLL_PERIPH0_BIAS 					*(volatile uint32_t *)(CCU_BASE + 0x234)
#define	CCU_PLL_ISP_BIAS 							*(volatile uint32_t *)(CCU_BASE + 0x238)
#define	CCU_PLL_PERIPH1_BIAS					*(volatile uint32_t *)(CCU_BASE + 0x244)
#define	CCU_PLL_DDR1_BIAS							*(volatile uint32_t *)(CCU_BASE + 0x24C)
#define	CCU_PLL_CPU_TUN 							*(volatile uint32_t *)(CCU_BASE + 0x250)
#define	CCU_PLL_DDR0_TUN							*(volatile uint32_t *)(CCU_BASE + 0x260)
#define	CCU_PLL_CPU_PAT_CTRL					*(volatile uint32_t *)(CCU_BASE + 0x280)
#define	CCU_PLL_AUDIO_PAT_CTRL				*(volatile uint32_t *)(CCU_BASE + 0x284)
#define	CCU_PLL_VIDEO_PAT_CTRL				*(volatile uint32_t *)(CCU_BASE + 0x288)
#define	CCU_PLL_VE_PAT_CTRL						*(volatile uint32_t *)(CCU_BASE + 0x28C)
#define	CCU_PLL_DDR0_PAT_CTRL 				*(volatile uint32_t *)(CCU_BASE + 0x290)
#define	CCU_PLL_ISP_PAT_CTRL 					*(volatile uint32_t *)(CCU_BASE + 0x298)
#define	CCU_PLL_PERIPH1_PAT_CTRL 			*(volatile uint32_t *)(CCU_BASE + 0x2A4)
#define	CCU_PLL_DDR1_PAT_CTRL0 				*(volatile uint32_t *)(CCU_BASE + 0x2AC)
#define	CCU_PLL_DDR1_PAT_CTRL1 				*(volatile uint32_t *)(CCU_BASE + 0x2B0)
#define	CCU_BUS_SOFT_RST0 						*(volatile uint32_t *)(CCU_BASE + 0x2C0)
#define	CCU_BUS_SOFT_RST1 						*(volatile uint32_t *)(CCU_BASE + 0x2C4)
#define	CCU_BUS_SOFT_RST2 						*(volatile uint32_t *)(CCU_BASE + 0x2C8)
#define	CCU_BUS_SOFT_RST3 						*(volatile uint32_t *)(CCU_BASE + 0x2D0)
#define	CCU_BUS_SOFT_RST4 						*(volatile uint32_t *)(CCU_BASE + 0x2D8)
#define	CCU_PS_CTRL				 						*(volatile uint32_t *)(CCU_BASE + 0x300)
#define	CCU_PS_CNT				 						*(volatile uint32_t *)(CCU_BASE + 0x304)

#define CCU_PLL_LOCKED_MASK		(1U << 28)

typedef struct{
	uint32_t P;
	uint32_t N;
	uint32_t K;
	uint32_t M;
} PLL_PARAM_TypeDef;
	
typedef enum{
	PLL_CPU 						= 1,
	PLL_AUDIO 					= 2,
	PLL_VIDEO 					= 3,
	PLL_VE 							= 4,
	PLL_DDR0 						= 5,
	PLL_PERIPH0 				= 6,
	PLL_ISP			 				= 7,
	PLL_PERIPH1 				= 8,
	PLL_DDR1 						= 9
} PLL_CTRL_Enum;

typedef enum
{
	CLK_CPU_SRC_LOSC 					= 0,
	CLK_CPU_SRC_OSC24M 				= 1,
	CLK_CPU_SRC_PLL_CPU 			= 2,
} CLK_CPU_SRC_Enum;

typedef enum
{
	CLK_AHB_SRC_LOSC 									= 0,
	CLK_AHB_SRC_OSC24M 								= 1,
	CLK_AHB_SRC_CPUCLK 								= 2,
	CLK_AHB_SRC_PLL_PERIPH_PREDIV 		= 3,
} CLK_AHB_SRC_Enum;

typedef enum
{
	CLK_APB_DIV_2 						= 1,
	CLK_APB_DIV_4 						= 2,
	CLK_APB_DIV_8 						= 3,
} CLK_APB_DIV_Enum;

typedef enum
{
	CLK_DE_SRC_PLL_VIDEO 			= 0,
	CLK_DE_SRC_PLL_PERIPH 		= 2,
} CLK_DE_SRC_Enum;

typedef enum
{
	CLK_VID_SRC_PLL_VIDEO_1X 			= 0,
	CLK_VID_SRC_OSC24M 						= 1, // TVD only
	CLK_VID_SRC_PLL_VIDEO_2X 			= 2,
} CLK_VID_SRC_Enum;
	
void PLL_Init(PLL_CTRL_Enum pll, PLL_PARAM_TypeDef pllParam);

#ifdef __cplusplus
}
#endif

#endif /* __V3S_CLOCK_H__ */
