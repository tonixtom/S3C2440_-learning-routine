//===================================================================
// File Name : 2440slib.h
// Function  : TQ2440 
// Version   : 1.0
//===================================================================

#ifndef __2440slib_h__
#define __2440slib_h__

#ifdef __cplusplus
extern "C" {
#endif

int SET_IF(void);
void WR_IF(int cpsrValue);
void CLR_IF(void);
void EnterCritical(uint32_t *pSave);
void ExitCritical(uint32_t *pSave);
void MMU_EnableICache(void);
void MMU_DisableICache(void);
void MMU_EnableDCache(void);
void MMU_DisableDCache(void);
void MMU_EnableAlignFault(void);
void MMU_DisableAlignFault(void);
void MMU_EnableMMU(void);
void MMU_DisableMMU(void);
void MMU_SetTTBase(uint32_t base);
void MMU_SetDomain(uint32_t domain);

void MMU_SetFastBusMode(void);  //GCLK=HCLK
void MMU_SetAsyncBusMode(void); //GCLK=FCLK @(FCLK>=HCLK)

void MMU_InvalidateIDCache(void);
void MMU_InvalidateICache(void);
void MMU_InvalidateICacheMVA(uint32_t mva);
void MMU_PrefetchICacheMVA(uint32_t mva);
void MMU_InvalidateDCache(void);
void MMU_InvalidateDCacheMVA(uint32_t mva);
void MMU_CleanDCacheMVA(uint32_t mva);
void MMU_CleanInvalidateDCacheMVA(uint32_t mva);
void MMU_CleanDCacheIndex(uint32_t index);
void MMU_CleanInvalidateDCacheIndex(uint32_t index);	
void MMU_WaitForInterrupt(void);
	
void MMU_InvalidateTLB(void);
void MMU_InvalidateITLB(void);
void MMU_InvalidateITLBMVA(uint32_t mva);
void MMU_InvalidateDTLB(void);
void MMU_InvalidateDTLBMVA(uint32_t mva);

void MMU_SetDCacheLockdownBase(uint32_t base);
void MMU_SetICacheLockdownBase(uint32_t base);

void MMU_SetDTLBLockdown(uint32_t baseVictim);
void MMU_SetITLBLockdown(uint32_t baseVictim);

void MMU_SetProcessId(uint32_t pid);

#ifdef __cplusplus
}
#endif

#endif   //__2440slib_h__
