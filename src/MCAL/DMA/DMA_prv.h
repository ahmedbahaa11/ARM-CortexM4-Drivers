/*
 * DMA_prv.h
 *
 *  Created on: Oct 11, 2022
 *      Author: ABahaa
 */

#ifndef MCAL_DMA_DMA_PRV_H_
#define MCAL_DMA_DMA_PRV_H_


#define DMA2_BASE_ADDR		0x40026400

typedef struct
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_Stream_t;

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_Stream_t S[8]; 
}DMA_MemMap_t;

#define DMA2    ((volatile DMA_MemMap_t*)(DMA2_BASE_ADDR))


#endif /* MCAL_DMA_DMA_PRV_H_ */
