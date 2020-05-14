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
* File Name    : r_cg_sau_user.c
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for SAU module.
* Creation Date: 2020/04/01
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_sau.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_uart0_interrupt_send(vect=INTST0)
#pragma interrupt r_uart0_interrupt_receive(vect=INTSR0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_uart0_tx_address;         /* uart0 send buffer address */
extern volatile uint16_t  g_uart0_tx_count;            /* uart0 send data number */
extern volatile uint8_t * gp_uart0_rx_address;         /* uart0 receive buffer address */
extern volatile uint16_t  g_uart0_rx_count;            /* uart0 receive data number */
extern volatile uint16_t  g_uart0_rx_length;           /* uart0 receive data length */
/* Start user code for global. Do not edit comment generated here */
volatile uint8_t	g_flg_rxfin = 0;
volatile uint8_t	g_flg_txfin = 0;

#if 0 /* Replacement of Code Generating codes */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_uart0_interrupt_receive
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_uart0_interrupt_receive(void)
{
    volatile uint8_t rx_data;
    volatile uint8_t err_type;
    
    err_type = (uint8_t)(SSR01 & 0x07U);
    SIR01 = (uint8_t)err_type;
    rx_data = RXD0;

    if (g_uart0_rx_length > g_uart0_rx_count)
    {
        *gp_uart0_rx_address = rx_data;
        gp_uart0_rx_address++;
        g_uart0_rx_count++;

        if (g_uart0_rx_length == g_uart0_rx_count)
        {
            r_uart0_callback_receiveend();
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_uart0_interrupt_send
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_uart0_interrupt_send(void)
{
    if (g_uart0_tx_count > 0U)
    {
        TXD0 = *gp_uart0_tx_address;
        gp_uart0_tx_address++;
        g_uart0_tx_count--;
    }
    else
    {
        r_uart0_callback_sendend();
    }
}
/***********************************************************************************************************************
* Function Name: r_uart0_callback_receiveend
* Description  : This function is a callback function when UART0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_uart0_callback_sendend
* Description  : This function is a callback function when UART0 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart0_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
	g_flg_txfin++;

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
#endif

/***********************************************************************************************************************
 * Function Name: r_uart0_interrupt_send
 * Description  : None
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
static void __near	r_uart0_interrupt_send(void)
{
	if(0U < g_uart0_tx_count)
	{
		TXD0 = *gp_uart0_tx_address;
		gp_uart0_tx_address++;
		g_uart0_tx_count--;
	}
	else
	{
		SMR00L &= (uint8_t)~_01_SAU_BUFFER_EMPTY;
//		if(0U == (SSR00 & _40_SAU_UNDER_EXECUTE))
		{
			g_flg_txfin++;
		}
	}
}

/***********************************************************************************************************************
 * Function Name: r_uart0_interrupt_receive
 * Description  : None
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
static void __near	r_uart0_interrupt_receive(void)
{
	static uint8_t	s_ptr_read = 0;
	uint8_t		rx_data;

	{
		volatile uint8_t	err_type;
		err_type = (uint8_t)(SSR01 & 0x07U);
		SIR01 = (uint8_t)err_type;
	}
	rx_data = RXD0;
	switch(s_ptr_read)
	{
	default:
		s_ptr_read = 0;
	case 0:
		if((D_ISC35_WCMD | D_ToF_ID) == rx_data)
		{
			s_ptr_read++;
		}
		break;
	case 1:
		if(D_ISC35_SC == rx_data)
		{
			s_ptr_read++;
		}
		else
		{
			s_ptr_read = 0;
		}
		break;
	case 2:
		if(0 == rx_data)
		{
			s_ptr_read++;
		}
		else
		{
			s_ptr_read = 0;
		}
		break;
	case 3:
		if(2 == rx_data)
		{
			g_flg_rxfin++;
	//		SRMK0	= 1U;						/* disable INTSR0 interrupt */
	//		ST0		|= _02_SAU_CH1_STOP_TRG_ON;	/* disable UART0 receive */
	//		SRIF0	= 0U;						/* clear INTSR0 interrupt flag */
		}
		s_ptr_read = 0;
		break;
	}
}

/* End user code. Do not edit comment generated here */
