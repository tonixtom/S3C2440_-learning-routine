#ifndef	__NORFLASH_H
#define	__NORFLASH_H

int UnlockAllBlks(void);
int ChkNorFlash(void);
void ProgNorFlash(uint32_t addr, uint32_t src, uint32_t len);


#endif