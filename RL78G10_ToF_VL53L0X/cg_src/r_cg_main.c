/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_main.c
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2020/04/01
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_sau.h"
#include "r_cg_iica.h"
/* Start user code for include. Do not edit comment generated here */
#include "vl53l0x.h"
#include <string.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
//#define 	D_USE_TESTCODE

#ifdef	D_USE_TESTCODE

const uint8_t	dex2hex[]	= "0123456789ABCDEF";
const uint8_t	txbuf_t[]	= "DIST=0x0000\n";
uint8_t			txbuf[sizeof(txbuf_t) + 1];

#else	// !D_USE_TESTCODE

uint8_t			txbuf[8];

#endif	// D_USE_TESTCODE

/* End user code. Do not edit comment generated here */

static void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
	if(1 != STCEN0)					/* Case of bus non-liberating. */
	{
		SPT0	= 1U;				/* set stop condition flag */
		while(!SPD0);				/* Detection waiting of stop condition. */
	}
	init(true);
#ifndef	D_USE_ToF_SINGLE_MODE
	startContinuous();
#endif	// !D_USE_ToF_SINGLE_MODE
	//
#ifdef	D_USE_TESTCODE
	memcpy(txbuf, txbuf_t, sizeof(txbuf_t));
	g_flg_txfin = 1;
	while(1)
	{
		uint16_t	dist;   //センサの出力[mm]を保存する変数

#ifdef	D_USE_ToF_SINGLE_MODE
		dist = readRangeSingleMillimeters();
#else	// !D_USE_ToF_SINGLE_MODE
		dist = readRangeContinuousMillimeters();
#endif	// D_USE_ToF_SINGLE_MODE
		//
		txbuf[ 7] = dex2hex[(dist >> 12) & 15];
		txbuf[ 8] = dex2hex[(dist >>  8) & 15];
		txbuf[ 9] = dex2hex[(dist >>  4) & 15];
		txbuf[10] = dex2hex[(dist      ) & 15];
		//
		while(0 == g_flg_txfin);
		g_flg_txfin = 0;
		R_UART0_Send(txbuf, sizeof(txbuf_t));
	}
#else	// !D_USE_TESTCODE
	txbuf[0]	= D_ISC35_RCMD | D_ToF_ID;
	txbuf[1]	= D_ISC35_SC;
	txbuf[2]	= 0;
	txbuf[3]	= 2;
	while(1)
	{
		uint16_t	dist;   //センサの出力[mm]を保存する変数

#ifdef	D_USE_ToF_SINGLE_MODE
		dist = readRangeSingleMillimeters();
#else	// !D_USE_ToF_SINGLE_MODE
		dist = readRangeContinuousMillimeters();
#endif	// D_USE_ToF_SINGLE_MODE
		//
		txbuf[ 4]	= (dist      ) & 15;	// dex2hex[(dist      ) & 15];
		txbuf[ 5]	= (dist >>  4) & 15;	// dex2hex[(dist >>  4) & 15];
		txbuf[ 6]	= (dist >>  8) & 15;	// dex2hex[(dist >>  8) & 15];
		txbuf[ 7]	= (dist >> 12) & 15;	// dex2hex[(dist >> 12) & 15];
		//
		if(0 == g_flg_rxfin)
		{
			continue;
		}
		g_flg_rxfin = 0;
		//
	//	SS0		|= _02_SAU_CH1_START_TRG_ON;	/* enable UART0 receive and transmit */
	//	SRIF0	= 0U;							/* clear INTSR0 interrupt flag */
	//	SRMK0	= 0U;							/* enable INTSR0 interrupt */
		//
		R_UART0_Send(txbuf, 8);
		while(0 == g_flg_txfin);
		g_flg_txfin = 0;
	}
#endif	// D_USE_TESTCODE

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
	EI();
	R_UART0_Start();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
