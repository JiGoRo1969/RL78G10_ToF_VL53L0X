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
* File Name    : r_cg_intp.h
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for INTP module.
* Creation Date: 2020/03/27
***********************************************************************************************************************/
#ifndef INTP_H
#define INTP_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    External Interrupt Rising Edge Enable Register 0 (EGP0)
*/
/* INTPn pin valid edge selection (EGPn) */
#define _01_INTP0_EDGE_RISING_SEL       (0x01U) /* rising edge selected for INTP0 pin */
#define _00_INTP0_EDGE_RISING_UNSEL     (0x00U) /* rising edge not selected for INTP0 pin */
#define _02_INTP1_EDGE_RISING_SEL       (0x02U) /* rising edge selected for INTP1 pin */
#define _00_INTP1_EDGE_RISING_UNSEL     (0x00U) /* rising edge not selected for INTP1 pin*/
#define _04_INTP2_EDGE_RISING_SEL       (0x04U) /* rising edge selected for INTP2 pin */
#define _00_INTP2_EDGE_RISING_UNSEL     (0x00U) /* rising edge not selected for INTP2 pin */
#define _08_INTP3_EDGE_RISING_SEL       (0x08U) /* rising edge selected for INTP3 pin */
#define _00_INTP3_EDGE_RISING_UNSEL     (0x00U) /* rising edge not selected for INTP3 pin */

/*
    External Interrupt Falling Edge Enable Register 0 (EGN0)
*/
/* INTPn pin valid edge selection (EGNn) */
#define _01_INTP0_EDGE_FALLING_SEL      (0x01U) /* falling edge selected for INTP0 pin */
#define _00_INTP0_EDGE_FALLING_UNSEL    (0x00U) /* falling edge not selected for INTP0 pin */
#define _02_INTP1_EDGE_FALLING_SEL      (0x02U) /* falling edge selected for INTP1 pin */
#define _00_INTP1_EDGE_FALLING_UNSEL    (0x00U) /* falling edge not selected for INTP1 pin */
#define _04_INTP2_EDGE_FALLING_SEL      (0x04U) /* falling edge selected for INTP2 pin */
#define _00_INTP2_EDGE_FALLING_UNSEL    (0x00U) /* falling edge not selected for INTP2 pin */
#define _08_INTP3_EDGE_FALLING_SEL      (0x08U) /* falling edge selected for INTP3 pin */
#define _00_INTP3_EDGE_FALLING_UNSEL    (0x00U) /* falling edge not selected for INTP3 pin */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_INTC_Create(void);
void R_INTC1_Start(void);
void R_INTC1_Stop(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
