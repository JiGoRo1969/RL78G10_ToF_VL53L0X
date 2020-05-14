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
* File Name    : r_cg_port.h
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for Port module.
* Creation Date: 2020/04/01
***********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Mode Register (PMm)
*/
/* Pmn pin I/O mode selection (PMm7 - PMm0) */
#define _01_PMn0_NOT_USE        (0x01U) /* not use Pn0 as digital I/O */
#define _01_PMn0_MODE_INPUT     (0x01U) /* use Pn0 as input mode */
#define _00_PMn0_MODE_OUTPUT    (0x00U) /* use Pn0 as output mode */
#define _02_PMn1_NOT_USE        (0x02U) /* not use Pn1 as digital I/O */
#define _02_PMn1_MODE_INPUT     (0x02U) /* use Pn1 as input mode */
#define _00_PMn1_MODE_OUTPUT    (0x00U) /* use Pn1 as output mode */
#define _04_PMn2_NOT_USE        (0x04U) /* not use Pn2 as digital I/O */
#define _04_PMn2_MODE_INPUT     (0x04U) /* use Pn2 as input mode */
#define _00_PMn2_MODE_OUTPUT    (0x00U) /* use Pn2 as output mode */
#define _08_PMn3_NOT_USE        (0x08U) /* not use Pn3 as digital I/O */
#define _08_PMn3_MODE_INPUT     (0x08U) /* use Pn3 as input mode */
#define _00_PMn3_MODE_OUTPUT    (0x00U) /* use Pn3 as output mode */
#define _10_PMn4_NOT_USE        (0x10U) /* not use Pn4 as digital I/O */
#define _10_PMn4_MODE_INPUT     (0x10U) /* use Pn4 as input mode */
#define _00_PMn4_MODE_OUTPUT    (0x00U) /* use Pn4 as output mode */
#define _20_PMn5_NOT_USE        (0x20U) /* not use Pn5 as digital I/O */
#define _20_PMn5_MODE_INPUT     (0x20U) /* use Pn5 as input mode */
#define _00_PMn5_MODE_OUTPUT    (0x00U) /* use Pn5 as output mode */
#define _40_PMn6_NOT_USE        (0x40U) /* not use Pn6 as digital I/O */
#define _40_PMn6_MODE_INPUT     (0x40U) /* use Pn6 as input mode */
#define _00_PMn6_MODE_OUTPUT    (0x00U) /* use Pn6 as output mode */
#define _80_PMn7_NOT_USE        (0x80U) /* not use Pn7 as digital I/O */
#define _80_PMn7_MODE_INPUT     (0x80U) /* use Pn7 as input mode */
#define _00_PMn7_MODE_OUTPUT    (0x00U) /* use Pn7 as output mode */

/*
    Port Register (Pm)
*/
/* Pmn pin data (Pm7 - Pm0) */
#define _00_Pn0_OUTPUT_0        (0x00U) /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1        (0x01U) /* Pn0 output 1 */
#define _00_Pn1_OUTPUT_0        (0x00U) /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1        (0x02U) /* Pn1 output 1 */
#define _00_Pn2_OUTPUT_0        (0x00U) /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1        (0x04U) /* Pn2 output 1 */
#define _00_Pn3_OUTPUT_0        (0x00U) /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1        (0x08U) /* Pn3 output 1 */
#define _00_Pn4_OUTPUT_0        (0x00U) /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1        (0x10U) /* Pn4 output 1 */
#define _00_Pn5_OUTPUT_0        (0x00U) /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1        (0x20U) /* Pn5 output 1 */
#define _00_Pn6_OUTPUT_0        (0x00U) /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1        (0x40U) /* Pn6 output 1 */
#define _00_Pn7_OUTPUT_0        (0x00U) /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1        (0x80U) /* Pn7 output 1 */

/*
    Pull-up Resistor Option Register (PUm)
*/
/* Pmn pin on-chip pull-up resistor selection (PUmn) */
#define _00_PUn0_PULLUP_OFF     (0x00U) /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON      (0x01U) /* Pn0 pull-up resistor connected */
#define _00_PUn1_PULLUP_OFF     (0x00U) /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON      (0x02U) /* Pn1 pull-up resistor connected */
#define _00_PUn2_PULLUP_OFF     (0x00U) /* Pn2 Pull-up resistor not connected */
#define _04_PUn2_PULLUP_ON      (0x04U) /* Pn2 pull-up resistor connected */
#define _00_PUn3_PULLUP_OFF     (0x00U) /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON      (0x08U) /* Pn3 pull-up resistor connected */
#define _00_PUn4_PULLUP_OFF     (0x00U) /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON      (0x10U) /* Pn4 pull-up resistor connected */
#define _00_PUn5_PULLUP_OFF     (0x00U) /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON      (0x20U) /* Pn5 pull-up resistor connected */
#define _00_PUn6_PULLUP_OFF     (0x00U) /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON      (0x40U) /* Pn6 pull-up resistor connected */
#define _00_PUn7_PULLUP_OFF     (0x00U) /* Pn7 pull-up resistor not connected */
#define _80_PUn7_PULLUP_ON      (0x80U) /* Pn7 pull-up resistor connected */

/*
    Port Output Mode Register (POMm)
*/
/* Pmn pin output mode selection (POMmn) */
#define _00_POMn0_NCH_OFF       (0x00U) /* set Pn0 output normal mode */
#define _01_POMn0_NCH_ON        (0x01U) /* set Pn0 output N-ch open-drain mode */
#define _00_POMn1_NCH_OFF       (0x00U) /* set Pn1 output normal mode */
#define _02_POMn1_NCH_ON        (0x02U) /* set Pn1 output N-ch open-drain mode */
#define _00_POMn6_NCH_OFF       (0x00U) /* set Pn6 output normal mode */
#define _40_POMn6_NCH_ON        (0x40U) /* set Pn6 output N-ch open-drain mode */
#define _00_POMn7_NCH_OFF       (0x00U) /* set Pn7 output normal mode */
#define _80_POMn7_NCH_ON        (0x80U) /* set Pn7 output N-ch open-drain mode */

/*
    Port Operation Mode Register (PMCm)
*/
/* Pmn pin digital input buffer selection (PMCmn) */
#define _02_PMCn1_NOT_USE       (0x02U) /* not use Pn1 digital input */
#define _00_PMCn1_DI_ON         (0x00U) /* enable Pn1 digital input */
#define _04_PMCn2_NOT_USE       (0x04U) /* not use Pn2 digital input */
#define _00_PMCn2_DI_ON         (0x00U) /* enable Pn2 digital input */
#define _08_PMCn3_NOT_USE       (0x08U) /* not use Pn3 digital input */
#define _00_PMCn3_DI_ON         (0x00U) /* enable Pn3 digital input */
#define _10_PMCn4_NOT_USE       (0x10U) /* not use Pn4 digital input */
#define _00_PMCn4_DI_ON         (0x00U) /* enable Pn4 digital input */
#define _20_PMCn5_NOT_USE       (0x20U) /* not use Pn5 digital input */
#define _00_PMCn5_DI_ON         (0x00U) /* enable Pn5 digital input */
#define _40_PMCn6_NOT_USE       (0x40U) /* not use Pn6 digital input */
#define _00_PMCn6_DI_ON         (0x00U) /* enable Pn6 digital input */
#define _80_PMCn7_NOT_USE       (0x80U) /* not use Pn7 digital input */
#define _00_PMCn7_DI_ON         (0x00U) /* enable Pn7 digital input */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _FC_PM4_DEFAULT         (0xFCU) /* PM4 default value */
#define _01_PMC0_DEFAULT        (0x01U) /* PMC0 default value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_PORT_Create(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
