/*********************************************
  NAME: memtest.c
  DESC: test SDRAM of TQ2440
 *********************************************/

#include "def.h"
#include "option.h"
#include "2440addr.h"
#include "2440lib.h"
#include "2440slib.h"
#include "mmu.h"


void MemoryTest(void)
{
	int i;
	uint32_t data;
	int memError=0;
	uint32_t *pt;
    
	//
	// memory test
	//
	//Uart_Printf("Memory Test(%xh-%xh):WR",_RAM_STARTADDRESS,(_ISR_STARTADDRESS&0xfff0000));
	//test sdram from _RAM_STARTADDRESS+2M, hzh
	Uart_Printf("Memory Test(%xh-%xh):WR",_RAM_STARTADDRESS+0x00200000,(_ISR_STARTADDRESS&0xffff0000));

	//pt=(uint32_t *)_RAM_STARTADDRESS;
	pt=(uint32_t *)(_RAM_STARTADDRESS+0x00200000);	//hzh
	while((uint32_t)pt<(_ISR_STARTADDRESS&0xffff0000))
	{
		*pt=(uint32_t)pt;
		pt++;
	}

	Uart_Printf("\b\bRD");
	//pt=(uint32_t *)_RAM_STARTADDRESS;
	pt=(uint32_t *)(_RAM_STARTADDRESS+0x00200000);	//hzh
	
	while((uint32_t)pt<(_ISR_STARTADDRESS&0xffff0000))
	{
		data=*pt;
		if(data!=(uint32_t)pt)
		{
			memError=1;
		Uart_Printf("\b\bFAIL:0x%x=0x%x\n",i,data);
		break;
		}
		pt++;
	}

	if(memError==0)Uart_Printf("\b\bO.K.\n");
}

