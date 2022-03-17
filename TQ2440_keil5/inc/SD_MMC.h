#ifndef __SD_H__
#define __SD_H__

#define	INICLK		300000
#define	SDCLK		24000000	//PCLK=49.392MHz
#define	MMCCLK		15000000	//PCLK=49.392MHz



/********************************************************
	宏定义
********************************************************/
#define INVALID_CARD	0
#define MMC_CARD		1
#define SD_V1X_CARD		2
#define SDHC_V20_CARD	3

/* SD卡信息结构体定义 */  
/* the information structure variable of SD Card*/ 
typedef struct SD_STRUCT 
{	 
	uint8_t cCardType;				/* 卡类型 */ 
	uint8_t cBlockSize;				// 卡的块长度，以为2的2次方表示，如512字节为2的9次方，则该值为9
	uint8_t cCardCID[16];			// 卡的CID信息
	uint16_t iCardRCA;				/* 卡逻辑地址 */ 
	uint32_t lCardCSD[4];			// 卡的CSD信息
	uint32_t lBlockNum;				/* 卡中块的数量 */ 
	uint32_t lBlockLen;				/* 卡的块长度(单位:字节) */ 
	uint32_t lSectorSize;			/* 一次可擦除的块个数 */ 
	uint32_t lCardSize;				//卡容量(单位:字节)
	
	 
	uint32_t timeout_read;			/* 读块超时时间(单位: 8 SPI clock) */ 
	uint32_t timeout_write;			/* 写块超时时间(单位: 8 SPI clock) */ 
	uint32_t timeout_erase;			/* 擦块超时时间(单位: 8 SPI clock) */ 
}sSD_struct; 








int Chk_CMD_End(int cmd, int be_resp);
void CMD0(void);
uint8_t CMD1(void);
uint8_t CMD8(void);
uint8_t CMD55(uint16_t iRCA);
uint8_t ACMD41(uint16_t iRCA)	;
uint8_t CMD2(uint8_t *cCID_Info);
uint8_t CMD3(uint16_t iCardType,uint16_t *iRCA);
uint8_t CMD7(uint8_t cSorD,uint16_t iRCA);
uint16_t CMD13(uint16_t iRCA)	;
uint8_t ACMD6(uint8_t BusWidth,uint16_t iRCA);
uint8_t CMD9(uint16_t iRCA,uint32_t *lCSD)	;
uint8_t CMD17(uint32_t Addr);
uint8_t CMD18(uint32_t Addr);
uint8_t CMD12(void);
uint8_t CMD24(uint32_t Addr);
uint8_t CMD25(uint32_t Addr);
uint8_t CMD32(uint32_t Addr);
uint8_t CMD33(uint32_t Addr);
uint8_t CMD38(void);

uint8_t Card_sel_desel(uint8_t cSelDesel,uint16_t iCardRCA);
uint8_t Set_bus_Width(uint8_t cCardType,uint8_t cBusWidth,uint16_t iRCA);
uint8_t SDinit(void);
uint8_t Read_One_Block(uint32_t Addr,uint32_t* RxBuffer);
uint8_t Write_One_Block(uint32_t Addr,uint32_t* TxBuffer);
uint8_t Read_Mult_Block(uint32_t Addr,uint32_t DatSize,uint32_t* RxBuffer);
uint8_t Write_Mult_Block(uint32_t Addr,uint32_t DatSize,uint32_t* TxBuffer);
uint8_t Erase_Block(uint32_t StartAddr,uint32_t EndAddr);
#endif

