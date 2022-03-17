/****************************************************************
 NAME: MAIN.h
 DESC: 
 ****************************************************************/
 
#ifndef __MAIN_H__
#define __MAIN_H__

extern volatile unsigned char *downPt;
extern volatile uint32_t totalDmaCount;
extern volatile uint32_t downloadFileSize;
extern volatile uint32_t downloadAddress;
extern volatile uint16_t checkSum;

extern int download_run;
extern uint32_t tempDownloadAddress;

#endif /*__MAIN_H__*/
