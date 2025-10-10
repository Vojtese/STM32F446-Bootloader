/*
 * iap.h
 *
 *  Created on: 31. 3. 2022
 *      Author: slabv
 */

#ifndef INC_IAP_H_
#define INC_IAP_H_

#include "stm32f4xx_hal.h"

/* FLASH STRUCTURE */

/* 0-255 pages of 2kB per page -> 2048 */
/* 512/0x200 - quarter page */
/* 512/0x400 - half page */
/* 512/0x800 - one page */

////////////////////////////////////	-- 0x0800 0000	-- page 0
//                                //
//       	Bootloader			  //
//                                //	-- 0x0800 FFFF  -- end of page 32
////////////////////////////////////	-- 0x0801 0000	-- start of page 33 ...
//                                //
//       	Config:  			  //
//       	iapStruct			  //
//                                //	-- 0x0801 7FFF	-- page 47
////////////////////////////////////	-- 0x0801 8000
//                                //
//       	APP 1    			  //
//                                //	-- 0x0804 7FFF	-- page 143
////////////////////////////////////	-- 0x0804 8000
//                                //
//       	APP 2                 //
//                                //	-- 0x0807 7FFF	-- page 239
////////////////////////////////////	-- 0x0807 8000
//       	Reserved			  //
////////////////////////////////////	-- 0x0807 FFFF  -- page 255

/* Declarations  */
void flash_jump_to_app(uint32_t ADDRESS_TO_JUMP);

#endif /* INC_IAP_H_ */
