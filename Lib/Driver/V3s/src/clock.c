/**
	******************************************************************************
	* @file clock.c
	*
	* @brief CCU Config for V3s
	*
	*
	* @author Tieu Tuan Bao
	* Contact: tieutuanbao@gmail.com
	* P-Number: +84979755670
	******************************************************************************
	*/

#include "clock.h"

/**
 *	Function: void PLL_Init(PLL_CTRL_enum pll, PLL_PARAM_TypeDef pllParam);
 *	----------------------------
 *		Configuration PLL
 *
 *		pll: any member in PLL_CTRL_enum
 *		pllParam: PLL parameter [M,N,P,K]
 *		
 *		returns: void
 */
void PLL_Init(PLL_CTRL_Enum pll, PLL_PARAM_TypeDef pllParam)
{
	uint32_t temp = 0;
		
	switch(pll){
		case PLL_CPU:{
			if((pllParam.N == 0) || (pllParam.K == 0) || (pllParam.M == 0) || (pllParam.P == 0)) return;
			if((pllParam.P != 1) && (pllParam.P != 2) && (pllParam.P != 4)) return;
			if((pllParam.N > 32) || (pllParam.K > 4) || (pllParam.M > 4)) return;
			
			temp = read32(CCU_PLL_CPU_CTRL);			
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.P >> 1) << 16) | ((pllParam.N - 1) << 8) | ((pllParam.K - 1) << 4) | (pllParam.M - 1);
			write32(CCU_PLL_CPU_CTRL, temp);
			while((CCU_PLL_CPU_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_AUDIO:{
			if((pllParam.N == 0) || (pllParam.M == 0) || (pllParam.P == 0)) return;
			if((pllParam.N > 128) || (pllParam.M > 32) || (pllParam.P > 16)) return;
			
			temp = read32(CCU_PLL_AUDIO_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.P - 1) << 16) | ((pllParam.N - 1) << 8) | (pllParam.M - 1);
			write32(CCU_PLL_AUDIO_CTRL, temp);
			while((CCU_PLL_AUDIO_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_VIDEO:{
			if((pllParam.N == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 128) || (pllParam.M > 16)) return;
			
			temp = read32(CCU_PLL_VIDEO_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | (pllParam.M - 1);
			write32(CCU_PLL_VIDEO_CTRL, temp);
			while((CCU_PLL_VIDEO_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_VE:{
			if((pllParam.N == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 128) || (pllParam.M > 16)) return;
			
			temp = read32(CCU_PLL_VE_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | (pllParam.M - 1);
			write32(CCU_PLL_VE_CTRL, temp);
			while((CCU_PLL_VE_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_DDR0:{
			if((pllParam.N == 0) || (pllParam.K == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 32) || (pllParam.K > 4) || (pllParam.M > 4)) return;
			
			temp = read32(CCU_PLL_DDR0_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | ((pllParam.K - 1) << 4) | (pllParam.M - 1);
			write32(CCU_PLL_DDR0_CTRL, temp);
			while((CCU_PLL_DDR0_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_PERIPH0:{
			if((pllParam.N == 0) || (pllParam.K == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 32) || (pllParam.K > 4) || (pllParam.M > 4)) return;
			
			temp = read32(CCU_PLL_PERIPH0_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | ((pllParam.K - 1) << 4) | (pllParam.M - 1);
			write32(CCU_PLL_PERIPH0_CTRL, temp);
			while((CCU_PLL_PERIPH0_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_ISP:{
			if((pllParam.N == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 128) || (pllParam.M > 16)) return;
			
			temp = read32(CCU_PLL_ISP_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | (pllParam.M - 1);
			write32(CCU_PLL_ISP_CTRL, temp);
			while((CCU_PLL_ISP_CTRL & CCU_PLL_LOCKED_MASK) == 0);			
			break;
		}
		case PLL_PERIPH1:{
			if((pllParam.N == 0) || (pllParam.K == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 32) || (pllParam.K > 4) || (pllParam.M > 4)) return;
			
			temp = read32(CCU_PLL_PERIPH1_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | ((pllParam.K - 1) << 4) | (pllParam.M - 1);
			write32(CCU_PLL_PERIPH1_CTRL, temp);
			while((CCU_PLL_PERIPH1_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
		case PLL_DDR1:{
			if((pllParam.N == 0) || (pllParam.M == 0)) return;
			if((pllParam.N > 128) || (pllParam.M > 4)) return;
			
			temp = read32(CCU_PLL_DDR1_CTRL);
			temp |= (1U << 31);					// Enable PLL
			temp |= ((pllParam.N - 1) << 8) | (pllParam.M - 1);
			write32(CCU_PLL_DDR1_CTRL, temp);
			while((CCU_PLL_DDR1_CTRL & CCU_PLL_LOCKED_MASK) == 0);
			break;
		}
	}
	temp = read32(CCU_CPU_AXI_CFG);
	temp &= ~(0x03 << 16);
	temp |=  (0x02 << 16);
	write32(CCU_CPU_AXI_CFG, temp);	
}

