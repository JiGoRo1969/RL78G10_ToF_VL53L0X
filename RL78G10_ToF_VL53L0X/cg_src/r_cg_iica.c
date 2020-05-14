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
* File Name    : r_cg_iica.c
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IICA module.
* Creation Date: 2020/04/01
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_iica.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
#if 0
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t   g_iica0_master_status_flag; /* iica0 master flag */
volatile uint8_t   g_iica0_slave_status_flag;  /* iica0 slave flag */
volatile uint8_t * gp_iica0_rx_address;        /* iica0 receive buffer address */
volatile uint16_t  g_iica0_rx_len;             /* iica0 receive data length */
volatile uint16_t  g_iica0_rx_cnt;             /* iica0 receive data count */
volatile uint8_t * gp_iica0_tx_address;        /* iica0 send buffer address */
volatile uint16_t  g_iica0_tx_cnt;             /* iica0 send data count */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IICA0_Create
* Description  : This function initializes the IICA0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Create(void)
{
    IICA0EN = 1U; /* supply IICA0 clock */
    IICE0 = 0U; /* disable IICA0 operation */
    IICAMK0 = 1U; /* disable INTIICA0 interrupt */
    IICAIF0 = 0U; /* clear INTIICA0 interrupt flag */
    /* Set INTIICA0 low priority */
    IICAPR10 = 1U;
    IICAPR00 = 1U; 
    /* Set SCLA0, SDAA0 pin */
    POM0 |= 0xC0U;
    PMC0 &= 0x3FU;
    PM0 |= 0xC0U;
    P0 &= 0x3FU;
    SMC0 = 1U;
    IICWL0 = _1A_IICA0_IICWL_VALUE;
    IICWH0 = _18_IICA0_IICWH_VALUE;
    DFC0 = 1U; /* digital filter on */
    SVA0 = _10_IICA0_MASTERADDRESS;
    STCEN0 = 1U;
    IICRSV0 = 1U;
    SPIE0 = 0U;
    WTIM0 = 1U;
    ACKE0 = 1U;
    IICAMK0 = 0U;
    IICE0 = 1U;
    LREL0 = 1U;
    /* Set SCLA0, SDAA0 pin */
    PM0 &= 0x3FU;
}
/***********************************************************************************************************************
* Function Name: R_IICA0_Stop
* Description  : This function stops IICA0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Stop(void)
{
    IICE0 = 0U;    /* disable IICA0 operation */
}
/***********************************************************************************************************************
* Function Name: R_IICA0_StopCondition
* Description  : This function sets IICA0 stop condition flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_StopCondition(void)
{
    SPT0 = 1U;     /* set stop condition flag */
}
/***********************************************************************************************************************
* Function Name: R_IICA0_Master_Send
* Description  : This function starts to send data as master mode.
* Arguments    : adr -
*                    send address
*                tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                wait -
*                    wait for start condition
* Return Value : status -
*                    MD_OK or MD_ERROR1 or MD_ERROR2
***********************************************************************************************************************/
MD_STATUS R_IICA0_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num, uint8_t wait)
{
    MD_STATUS status = MD_OK;

    IICAMK0 = 1U;  /* disable INTIICA0 interrupt */

    if (1U == IICBSY0)
    {
        /* Check bus busy */
        IICAMK0 = 0U;  /* enable INTIICA0 interrupt */
        status = MD_ERROR1;
    }
    else
    {
        STT0 = 1U; /* send IICA0 start condition */
        IICAMK0 = 0U;  /* enable INTIICA0 interrupt */
        
        /* Wait */
        while (wait--)
        {
            ;
        }
        
        if (0U == STD0)
        {
            status = MD_ERROR2;
        }
		
        /* Set parameter */
        g_iica0_tx_cnt = tx_num;
        gp_iica0_tx_address = tx_buf;
        g_iica0_master_status_flag = _00_IICA_MASTER_FLAG_CLEAR;
        adr &= (uint8_t)~0x01U; /* set send mode */
        IICA0 = adr; /* send address */
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: R_IICA0_Master_Receive
* Description  : This function starts to receive IICA0 data as master mode.
* Arguments    : adr -
*                    receive address
*                rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
*                wait -
*                    wait for start condition
* Return Value : status -
*                    MD_OK or MD_ERROR1 or MD_ERROR2
***********************************************************************************************************************/
MD_STATUS R_IICA0_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num, uint8_t wait)
{
    MD_STATUS status = MD_OK;

    IICAMK0 = 1U;  /* disable INTIIA0 interrupt */

    if (1U == IICBSY0)
    {
        /* Check bus busy */
        IICAMK0 = 0U;  /* enable INTIIA0 interrupt */
        status = MD_ERROR1;
    }
    else
    {
        STT0 = 1U; /* set IICA0 start condition */
        IICAMK0 = 0U;  /* enable INTIIA0 interrupt */
        
        /* Wait */
        while (wait--)
        {
            ;
        }
        
        if (0U == STD0)
        {
            status = MD_ERROR2;
        }
		
        /* Set parameter */
        g_iica0_rx_len = rx_num;
        g_iica0_rx_cnt = 0U;
        gp_iica0_rx_address = rx_buf;
        g_iica0_master_status_flag  = _00_IICA_MASTER_FLAG_CLEAR;
        adr |= 0x01U; /* set receive mode */
        IICA0 = adr; /* receive address */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
#else

/***********************************************************************************************************************
 * Function Name: R_IICA0_Create
 * Description  : This function initializes the IICA0 module.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
void	R_IICA0_Create(void)
{
	IICA0EN		= 1U;			/* supply IICA0 clock */
	IICE0		= 0U;			/* disable IICA0 operation */
	IICAMK0		= 1U;			/* disable INTIICA0 interrupt */
	IICAIF0		= 0U;			/* clear INTIICA0 interrupt flag */
	/* Set INTIICA0 low priority */
	IICAPR10	= 1U;
	IICAPR00	= 1U; 
	/* Set SCLA0, SDAA0 pin */
	POM0		|= 0xC0U;
	PMC0		&= 0x3FU;
	PM0			|= 0xC0U;
	P0			&= 0x3FU;
	/* Set IIC CLKS */
	IICWL0		= 26;
	IICWH0		= 24;
	/* Set IICA0 address */
	SVA0		= 0x10;
	/* Set Start Conditions with IICF0 */
	STCEN0		= 1U;
	IICRSV0		= 0U;
	/* IICCTL01 */
	DFC0		= 1U;			/* Set digital filter on */
	SMC0		= 1U;			/* 400kbps */
	/* IICCTL00 0b0XX111XX */
	ACKE0		= 1U;
	WTIM0		= 1U;
	SPIE0		= 1U;
	/* IICCTL00 1b0XX111XX */
	IICAMK0		= 0U;			/* enable INTIICA0 interrupt */
	IICE0		= 1U;
	//
	LREL0		= 1U;
	/* Set SCLA0, SDAA0 pin */
	PM0			&= 0x3FU;
}

/***********************************************************************************************************************
 * Function Name: r_iic_master_send
 * Description  : This function starts to send data as master mode.
 * Arguments    : adr -
 *                    send address
 *                tx_buf -
 *                    transfer buffer pointer
 *                tx_num -
 *                    buffer size
 * Return Value : status -
 *                    MD_OK or MD_ERROR1 or MD_ERROR2
 ***********************************************************************************************************************/
void	r_iic_master_send(uint8_t adr, uint8_t *tx_buf, uint16_t tx_num)
{
	IICAMK0	= 1U;				/* disable INTIICA0 interrupt */
	ACKE0	= 1U;
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	STT0	= 1U;				/* send IICA0 start condition */
	while(MSTS0 == 0);
	IICA0	= adr << 1;			/* send address */
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	while(0U < tx_num)
	{
		IICA0	= *tx_buf++;
		tx_num--;
		while(0U == IICAIF0);
		IICAIF0	= 0U;			/* clear INTIICA0 interrupt flag */
	}
	SPT0	= 1U;				/* set stop condition flag */
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
}

/***********************************************************************************************************************
 * Function Name: r_iic_master_receive
 * Description  : This function starts to receive IICA0 data as master mode.
 * Arguments    : adr -
 *                    receive address
 *                rx_buf -
 *                    receive buffer pointer
 *                rx_num -
 *                    buffer size
 * Return Value : status -
 *                    MD_OK or MD_ERROR1 or MD_ERROR2
 ***********************************************************************************************************************/
void	r_iic_master_receive(uint8_t adr, uint8_t reg, uint8_t *rx_buf, uint16_t rx_num)
{
	IICAMK0	= 1U;				/* disable INTIIA0 interrupt */
	ACKE0	= 1U;
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	STT0	= 1U;				/* set IICA0 start condition */
	while(MSTS0 == 0);
	IICA0	= (adr << 1);		/* receive address */
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	IICA0	= reg;
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	//
	STT0	= 1U;				/* set IICA0 start condition */
	IICA0	= (adr << 1) | 1;	/* receive address */
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
	//
	do {
		if(1U == rx_num)
		{
			ACKE0	= 0U;		/* disable ACK responce */
			WTIM0	= 1U;
			WREL0	= 1U;
		}
		else
		{
			ACKE0	= 1U;		/* automatically ACK responce */
			WTIM0	= 1U;
			WREL0	= 1U;
		}
		while(0U == IICAIF0);
		IICAIF0	= 0U;			/* clear INTIICA0 interrupt flag */
		*rx_buf = IICA0;
		rx_buf++;
		rx_num--;
	} while(0U < rx_num);
	SPT0	= 1U;				/* set stop condition flag */
	while(0U == IICAIF0);
	IICAIF0	= 0U;				/* clear INTIICA0 interrupt flag */
}

#endif

/* End user code. Do not edit comment generated here */
