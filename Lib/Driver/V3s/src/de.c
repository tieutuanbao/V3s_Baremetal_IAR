/**
	******************************************************************************
	* @file de.c
	*
	* @brief DE Config for V3s
	*
	*
	* @author Tieu Tuan Bao
	* Contact: tieutuanbao@gmail.com
	* P-Number: +84979755670
	******************************************************************************
	*/

#include "de.h"
#include "io.h"
#include <stdlib.h>
#include <string.h>

uint8_t *vram;

void de_set_mode(uint32_t width, uint32_t height){
	uint32_t temp = 0;
	uint32_t size = (((height - 1) << 16) | (width - 1));
	uint32_t pixlen = (width * height * 4);
	
	if(vram == 0){
		vram = (uint8_t *)malloc(pixlen);
	}else if(sizeof(vram) < pixlen){
		vram = (uint8_t *)realloc(vram, pixlen);
	}

	/* set Reset off */
	temp = read32(DE_DISP_SYS_AHB_RESET);
	temp |= 1 << 0;
	write32(DE_DISP_SYS_AHB_RESET, temp);

	/* set Clock pass */
	temp = read32(DE_DISP_SYS_SCLK_GATE);
	temp |= 1 << 0;
	write32(DE_DISP_SYS_SCLK_GATE, temp);

	/* set Clock pass */
	temp = read32(DE_DISP_SYS_HCLK_GATE);
	temp |= 1 << 0;
	write32(DE_DISP_SYS_HCLK_GATE, temp);
	
	/* Mixer0 => TCON0 */
	temp = read32(DE_DISP_SYS_D2TCON_MUX);
	temp &= ~(1 << 0);
	write32(DE_DISP_SYS_D2TCON_MUX, temp);

	write32(&DE_RTM0_GLB->ctl, (1 << 0));
	write32(&DE_RTM0_GLB->status, 0);
	write32(&DE_RTM0_GLB->dbuff, 1);
	write32(&DE_RTM0_GLB->size, size);

	for(uint8_t i = 0; i < 4; i++)
	{
		void * chan = (void *)(DE_RTM0_CHAN + 0x1000 * i);
		memset(chan, 0, i == 0 ? sizeof(DE_V_TypeDef) : sizeof(DE_UI_TypeDef));
	}

	write32(&DE_RTM0_BLD->fcolor_ctl, 0x00000101);
	write32(&DE_RTM0_BLD->route, 2);
	write32(&DE_RTM0_BLD->premultiply, 0);
	write32(&DE_RTM0_BLD->bkcolor, 0xff000000);
	write32(&DE_RTM0_BLD->bld_mode[0], 0x03010301);
	write32(&DE_RTM0_BLD->bld_mode[1], 0x03010301);
	write32(&DE_RTM0_BLD->output_size, size);
	write32(&DE_RTM0_BLD->out_ctl, 0);
	write32(&DE_RTM0_BLD->ck_ctl, 0);
	for(uint8_t i = 0; i < 4; i++)
	{
		write32(&DE_RTM0_BLD->attr[i].fcolor, 0xff000000);
		write32(&DE_RTM0_BLD->attr[i].insize, size);
	}

	write32(DE_RTM0_VSU, 0);
	write32(DE_RTM0_GSU1, 0);
	write32(DE_RTM0_GSU2, 0);
	write32(DE_RTM0_GSU3, 0);
	write32(DE_RTM0_FCE, 0);
	write32(DE_RTM0_BWS, 0);
	write32(DE_RTM0_LTI, 0);
	write32(DE_RTM0_PEAK, 0);
	write32(DE_RTM0_ASE, 0);
	write32(DE_RTM0_FCC, 0);
	write32(DE_RTM0_DCSC, 0);

	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->cfg[0].attr), (1 << 0) | (4 << 8) | (1 << 1) | (0xff << 24));
	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->cfg[0].size), size);
	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->cfg[0].coord), 0);
	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->cfg[0].pitch), 4 * width);
	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->cfg[0].top_laddr), (uint32_t)vram);
	write32((uint32_t)&(((DE_UI_TypeDef *)(DE_RTM0_CHAN + 0x1000 * 2))->ovl_size), size);
}