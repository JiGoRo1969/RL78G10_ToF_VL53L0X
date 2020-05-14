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
* File Name    : r_cg_sau.h
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for SAU module.
* Creation Date: 2020/04/01
***********************************************************************************************************************/
#ifndef SAU_H
#define SAU_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Serial Clock Select Register m (SPSm)
*/
/* Operating mode and clear mode selection (PRS003 - PRS000) */
#define _00_SAU_CK00_FCLK_0              (0x00U)    /* ck00 - fCLK */
#define _01_SAU_CK00_FCLK_1              (0x01U)    /* ck00 - fCLK/2^1 */
#define _02_SAU_CK00_FCLK_2              (0x02U)    /* ck00 - fCLK/2^2 */
#define _03_SAU_CK00_FCLK_3              (0x03U)    /* ck00 - fCLK/2^3 */
#define _04_SAU_CK00_FCLK_4              (0x04U)    /* ck00 - fCLK/2^4 */
#define _05_SAU_CK00_FCLK_5              (0x05U)    /* ck00 - fCLK/2^5 */
#define _06_SAU_CK00_FCLK_6              (0x06U)    /* ck00 - fCLK/2^6 */
#define _07_SAU_CK00_FCLK_7              (0x07U)    /* ck00 - fCLK/2^7 */
#define _08_SAU_CK00_FCLK_8              (0x08U)    /* ck00 - fCLK/2^8 */
#define _09_SAU_CK00_FCLK_9              (0x09U)    /* ck00 - fCLK/2^9 */
#define _0A_SAU_CK00_FCLK_10             (0x0AU)    /* ck00 - fCLK/2^10 */
#define _0B_SAU_CK00_FCLK_11             (0x0BU)    /* ck00 - fCLK/2^11 */
#define _0C_SAU_CK00_FCLK_12             (0x0CU)    /* ck00 - fCLK/2^12 */
#define _0D_SAU_CK00_FCLK_13             (0x0DU)    /* ck00 - fCLK/2^13 */
#define _0E_SAU_CK00_FCLK_14             (0x0EU)    /* ck00 - fCLK/2^14 */
#define _0F_SAU_CK00_FCLK_15             (0x0FU)    /* ck00 - fCLK/2^15 */
/* Operating mode and clear mode selection (PRS013 - PRS010) */
#define _00_SAU_CK01_FCLK_0              (0x00U)    /* ck01 - fCLK */
#define _10_SAU_CK01_FCLK_1              (0x10U)    /* ck01 - fCLK/2^1 */
#define _20_SAU_CK01_FCLK_2              (0x20U)    /* ck01 - fCLK/2^2 */
#define _30_SAU_CK01_FCLK_3              (0x30U)    /* ck01 - fCLK/2^3 */
#define _40_SAU_CK01_FCLK_4              (0x40U)    /* ck01 - fCLK/2^4 */
#define _50_SAU_CK01_FCLK_5              (0x50U)    /* ck01 - fCLK/2^5 */
#define _60_SAU_CK01_FCLK_6              (0x60U)    /* ck01 - fCLK/2^6 */
#define _70_SAU_CK01_FCLK_7              (0x70U)    /* ck01 - fCLK/2^7 */
#define _80_SAU_CK01_FCLK_8              (0x80U)    /* ck01 - fCLK/2^8 */
#define _90_SAU_CK01_FCLK_9              (0x90U)    /* ck01 - fCLK/2^9 */
#define _A0_SAU_CK01_FCLK_10             (0xA0U)    /* ck01 - fCLK/2^10 */
#define _B0_SAU_CK01_FCLK_11             (0xB0U)    /* ck01 - fCLK/2^11 */
#define _C0_SAU_CK01_FCLK_12             (0xC0U)    /* ck01 - fCLK/2^12 */
#define _D0_SAU_CK01_FCLK_13             (0xD0U)    /* ck01 - fCLK/2^13 */
#define _E0_SAU_CK01_FCLK_14             (0xE0U)    /* ck01 - fCLK/2^14 */
#define _F0_SAU_CK01_FCLK_15             (0xF0U)    /* ck01 - fCLK/2^15 */

/*
    Serial Mode Register mn H (SMRmnH)
*/
/* Selection of macro clock (MCK) of channel n (CKSmn) */
#define _00_SAU_CLOCK_SELECT_CK00        (0x00U)    /* operation clock CK0 set by PRS register */ 
#define _80_SAU_CLOCK_SELECT_CK01        (0x80U)    /* operation clock CK1 set by PRS register */
/* Selection of transfer clock (TCLK) of channel n (CCSmn) */
#define _00_SAU_CLOCK_MODE_CKS           (0x00U)    /* divided operation clock MCK specified by CKSmn bit */  
#define _40_SAU_CLOCK_MODE_TI0N          (0x40U)    /* clock input from SCK pin (slave transfer in CSI mode) */
/* Selection of start trigger source (STSmn) */
#define _00_SAU_TRIGGER_SOFTWARE         (0x00U)    /* only software trigger is valid */
#define _01_SAU_TRIGGER_RXD              (0x01U)    /* valid edge of RXD pin */

/*
    Serial Mode Register mn L (SMRmnL)
*/
#define _20_SAU_SMRMN_INITIALVALUE       (0x20U)
/* Controls inversion of level of receive data of channel n in UART mode (SISmn0) */
#define _00_SAU_EDGE_FALL                (0x00U)    /* falling edge is detected as the start bit */
#define _40_SAU_EDGE_RISING              (0x40U)    /* rising edge is detected as the start bit */
/* Setting of operation mode of channel n (MDmn2, MDmn1) */
#define _00_SAU_MODE_CSI                 (0x00U)    /* CSI mode */
#define _02_SAU_MODE_UART                (0x02U)    /* UART mode */
#define _04_SAU_MODE_IIC                 (0x04U)    /* simplified IIC mode */
/* Selection of interrupt source of channel n (MDmn0) */
#define _00_SAU_TRANSFER_END             (0x00U)    /* transfer end interrupt */
#define _01_SAU_BUFFER_EMPTY             (0x01U)    /* buffer empty interrupt */

/*
    Serial Communication Operation Setting Register mn H (SCRmnH)
*/
/* Setting of operation mode of channel n (TXEmn, RXEmn) */
#define _00_SAU_NOT_COMMUNICATION        (0x00U)    /* does not start communication */
#define _40_SAU_RECEPTION                (0x40U)    /* reception only */
#define _80_SAU_TRANSMISSION             (0x80U)    /* transmission only */
#define _C0_SAU_RECEPTION_TRANSMISSION   (0xC0U)    /* reception and transmission */
/* Selection of data and clock phase in CSI mode (DAPmn, CKPmn) */
#define _00_SAU_TIMING_1                 (0x00U)    /* type 1 */
#define _10_SAU_TIMING_2                 (0x10U)    /* type 2 */
#define _20_SAU_TIMING_3                 (0x20U)    /* type 3 */
#define _30_SAU_TIMING_4                 (0x30U)    /* type 4 */
/* Selection of masking of error interrupt signal (EOCmn) */
#define _00_SAU_INTSRE_MASK              (0x00U)    /* masks error interrupt INTSREx */
#define _04_SAU_INTSRE_ENABLE            (0x04U)    /* enables generation of error interrupt INTSREx */
/* Setting of parity bit in UART mode (PTCmn1 - PTCmn0) */
#define _00_SAU_PARITY_NONE              (0x00U)    /* none parity */
#define _01_SAU_PARITY_ZERO              (0x01U)    /* zero parity */
#define _02_SAU_PARITY_EVEN              (0x02U)    /* even parity */
#define _03_SAU_PARITY_ODD               (0x03U)    /* odd parity */

/*
    Serial Communication Operation Setting Register mn L (SCRmnL)
*/
/* Selection of data transfer sequence in CSI and UART modes (DIRmn) */
#define _00_SAU_MSB                      (0x00U)    /* MSB */
#define _80_SAU_LSB                      (0x80U)    /* LSB */
/* Setting of stop bit in UART mode (SLCmn1, SLCmn0) */
#define _00_SAU_STOP_NONE                (0x00U)    /* none stop bit */
#define _10_SAU_STOP_1                   (0x10U)    /* 1 stop bit */
#define _20_SAU_STOP_2                   (0x20U)    /* 2 stop bits */
/* Setting of data length in CSI and UART modes (DLSmn2 - DLSmn0) */
#define _06_SAU_LENGTH_7                 (0x06U)    /* 7-bit data length */
#define _07_SAU_LENGTH_8                 (0x07U)    /* 8-bit data length */

/*
    Serial Output Level Register m (SOLm)
*/
/* Selects inversion of the level of the transmit data of channel n in UART mode */
#define _00_SAU_CHANNEL0_NORMAL          (0x00U)    /* normal bit level */
#define _01_SAU_CHANNEL0_INVERTED        (0x01U)    /* inverted bit level */

/*
    Noise Filter Enable Register 0 (NFEN0)
*/
/* Use of noise filter of RXD0 pin (SNFEN00)*/
#define _00_SAU_RXD0_FILTER_OFF          (0x00U)     /* noise filter off */
#define _01_SAU_RXD0_FILTER_ON           (0x01U)     /* noise filter on */

/*
    Format of Serial Status Register mn (SSRmn)
*/
/* Communication status indication flag of channel n (TSFmn) */
#define _40_SAU_UNDER_EXECUTE            (0x40U)    /* communication is under execution */
/* Buffer register status indication flag of channel n (BFFmn) */
#define _20_SAU_VALID_STORED             (0x20U)    /* valid data is stored in the SDRmn register */
/* Framing error detection flag of channel n (FEFmn) */
#define _04_SAU_FRAM_ERROR               (0x04U)    /* a framing error occurs during UART reception */
/* Parity error detection flag of channel n (PEFmn) */
#define _02_SAU_PARITY_ERROR             (0x02U)    /* a parity error occurs or ACK is not detected */
/* Overrun error detection flag of channel n (OVFmn) */
#define _01_SAU_OVERRUN_ERROR            (0x01U)    /* an overrun error occurs */

/*
    Serial Channel Start Register m (SSm)
*/
/* Operation start trigger of channel 0 (SSm0) */
#define _00_SAU_CH0_START_TRG_OFF        (0x00U)    /* no trigger operation */
#define _01_SAU_CH0_START_TRG_ON         (0x01U)    /* sets SEm0 to 1 and enters the communication wait status */
/* Operation start trigger of channel 1 (SSm1) */
#define _00_SAU_CH1_START_TRG_OFF        (0x00U)    /* no trigger operation */
#define _02_SAU_CH1_START_TRG_ON         (0x02U)    /* sets SEm1 to 1 and enters the communication wait status */

/*
    Serial Channel Stop Register m (STm)
*/
/* Operation stop trigger of channel 0 (STm0) */
#define _00_SAU_CH0_STOP_TRG_OFF         (0x00U)    /* no trigger operation */
#define _01_SAU_CH0_STOP_TRG_ON          (0x01U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (STm1) */
#define _00_SAU_CH1_STOP_TRG_OFF         (0x00U)    /* no trigger operation */
#define _02_SAU_CH1_STOP_TRG_ON          (0x02U)    /* operation is stopped (stop trigger is generated) */

/*
    Format of Serial Flag Clear Trigger Register mn (SIRmn)
*/
/* Clear trigger of overrun error flag of channel n (OVCTmn) */
#define _01_SAU_SIRMN_OVCTMN             (0x01U)
/* Clear trigger of parity error flag of channel n (PECTmn) */
#define _02_SAU_SIRMN_PECTMN             (0x02U)
/* Clear trigger of framing error of channel n (FECTMN) */
#define _04_SAU_SIRMN_FECTMN             (0x04U)

/*
    Serial Output Enable Register m (SOEm)
*/
/* Serial output enable/disable of channel 0 (SOEm0) */
#define _01_SAU_CH0_OUTPUT_ENABLE        (0x01U)    /* stops output by serial communication operation */
#define _00_SAU_CH0_OUTPUT_DISABLE       (0x00U)    /* enables output by serial communication operation */
/* Serial output enable/disable of channel 1 (SOEm1) */
#define _02_SAU_CH1_OUTPUT_ENABLE        (0x02U)    /* stops output by serial communication operation */
#define _00_SAU_CH1_OUTPUT_DISABLE       (0x00U)    /* enables output by serial communication operation */

/*
    Serial Data Output Register m (SOm)
*/
/* Serial data output of channel 0 (SOm0) */
#define _00_SAU_CH0_DATA_OUTPUT_0        (0x00U)    /* serial data output value is "0" */
#define _01_SAU_CH0_DATA_OUTPUT_1        (0x01U)    /* serial data output value is "1" */
/* Serial data output of channel 1 (SOm1) */
#define _00_SAU_CH1_DATA_OUTPUT_0        (0x00U)    /* serial data output value is "0" */
#define _02_SAU_CH1_DATA_OUTPUT_1        (0x02U)    /* serial data output value is "1" */

/*
    Serial Clock Output Register m (CKOm)
*/
/* Serial clock output of channel 0 (CKOm0) */
#define _00_SAU_CH0_CLOCK_OUTPUT_0       (0x00U)    /* serial clock output value is "0" */
#define _01_SAU_CH0_CLOCK_OUTPUT_1       (0x01U)    /* serial clock output value is "1" */
/* Serial clock output of channel 1 (CKOm1) */
#define _00_SAU_CH1_CLOCK_OUTPUT_0       (0x00U)    /* serial clock output value is "0" */
#define _02_SAU_CH1_CLOCK_OUTPUT_1       (0x02U)    /* serial clock output value is "1" */

/* SAU used flag */
#define _00_SAU_IIC_MASTER_FLAG_CLEAR    (0x00U)
#define _01_SAU_IIC_SEND_FLAG            (0x01U)
#define _02_SAU_IIC_RECEIVE_FLAG         (0x02U)
#define _04_SAU_IIC_SENDED_ADDRESS_FLAG  (0x04U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _06_UART0_RECEIVE_DIVISOR        (0x06U)
#define _4E_UART0_TRANSMIT_DIVISOR       (0x4EU)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_SAU0_Create(void);
void R_UART0_Create(void);
void R_UART0_Start(void);
void R_UART0_Stop(void);
MD_STATUS R_UART0_Send(uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_UART0_Receive(uint8_t * const rx_buf, uint16_t rx_num);
static void r_uart0_callback_receiveend(void);
static void r_uart0_callback_sendend(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
