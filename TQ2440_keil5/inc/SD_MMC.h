#ifndef __SD_H__
#define __SD_H__

#define	INICLK		300000
#define	SDCLK		24000000	//PCLK=49.392MHz
#define	MMCCLK		15000000	//PCLK=49.392MHz



/********************************************************
	�궨��
********************************************************/
#define INVALID_CARD	0
#define MMC_CARD		1
#define SD_V1X_CARD		2
#define SDHC_V20_CARD	3

/* SD����Ϣ�ṹ�嶨�� */  
/* the information structure variable of SD Card*/ 
typedef struct SD_STRUCT 
{	 
	uint8_t cCardType;				/* ������ */ 
	uint8_t cBlockSize;				// ���Ŀ鳤�ȣ���Ϊ2��2�η���ʾ����512�ֽ�Ϊ2��9�η������ֵΪ9
	uint8_t cCardCID[16];			// ����CID��Ϣ
	uint16_t iCardRCA;				/* ���߼���ַ */ 
	uint32_t lCardCSD[4];			// ����CSD��Ϣ
	uint32_t lBlockNum;				/* ���п������ */ 
	uint32_t lBlockLen;				/* ���Ŀ鳤��(��λ:�ֽ�) */ 
	uint32_t lSectorSize;			/* һ�οɲ����Ŀ���� */ 
	uint32_t lCardSize;				//������(��λ:�ֽ�)
	
	 
	uint32_t timeout_read;			/* ���鳬ʱʱ��(��λ: 8 SPI clock) */ 
	uint32_t timeout_write;			/* д�鳬ʱʱ��(��λ: 8 SPI clock) */ 
	uint32_t timeout_erase;			/* ���鳬ʱʱ��(��λ: 8 SPI clock) */ 
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

