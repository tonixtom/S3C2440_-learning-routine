/******************************************************************************

 Filename:	camif.h

 Descriptions		
 - header file of camif.c

 ******************************************************************************/

 
#ifndef __CAMIF_H__
#define __CAMIF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "camdef.h"

void CalculateBurstSize(uint32_t dstHSize,uint32_t *mainBurstSize,uint32_t *RemainedBurstSize);
void CalculatePrescalerRatioShift(uint32_t srcWidth, uint32_t dstWidth, uint32_t *ratio,uint32_t *shift);

void __irq CamPviewIsr(void);
void __irq CamCodecIsr(void);
void __irq CamIsr(void);


void CamPortSet(void);
void CamPortReturn(void);
void CamPreviewIntUnmask(void);
void CamCodecIntUnmask(void);
void CamPreviewIntMask(void);
void CamCodecIntMask(void);
void CamReset(void);
void CamModuleReset(void);
void SetCAMClockDivider(int divn);

void CamCaptureStart(uint32_t mode);
void CamCaptureStop(void);
void _CamPviewStopHw(void);
void _CamCodecStopHw(void);


void Test_CamPreview(void);
void Test_CamCodec(void);
void Test_YCbCr_to_RGB(void);
void Camera_Test(void);


#ifdef __cplusplus
}
#endif

#endif /*__CAMIF_H__*/
