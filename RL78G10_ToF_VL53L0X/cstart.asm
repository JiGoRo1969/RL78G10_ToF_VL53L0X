; Copyright (C) 2014 Renesas Electronics Corporation
; RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
; This program must be used solely for the purpose for which
; it was furnished by Renesas Electronics Corporation. No part of this
; program may be reproduced or disclosed to others, in any
; form, without the prior written permission of Renesas Electronics
; Corporation.

;   NOTE       : THIS IS A TYPICAL EXAMPLE.

$IFNDEF __RENESAS_VERSION__
__RENESAS_VERSION__	.EQU	0x01000000
$ENDIF

	.public	_start
	.public _exit

;-----------------------------------------------------------------------------
;	RAM section
;-----------------------------------------------------------------------------
.SECTION .dataR, DATA
.SECTION .sdataR, DATA

$IF (__RENESAS_VERSION__ < 0x01010000)	; for CC-RL V1.00
; !!! [CAUTION] !!!
; The start address of RAM depend on the device in use.
; See the user's manual of the device.
;   ex. R5F10Y14ASP -> 0x0FFE60
RAM_ADDR_START	.EQU	0x0FFE60	; Start address of RAM (SAMPLE)
RAM_ADDR_END	.EQU	0x0FFEE0	; End address of RAM +1

;-----------------------------------------------------------------------------
;	stack area
;-----------------------------------------------------------------------------
; !!! [CAUTION] !!!
; Set up stack size suitable for a project.
.SECTION .stack_bss, BSS
_stackend:
	.DS     0x40
_stacktop:
$ENDIF

;-----------------------------------------------------------------------------
;	RESET vector
;-----------------------------------------------------------------------------
_start	.VECTOR	0

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
.SECTION .text, TEXT
_start:
	;--------------------------------------------------
	; setting the stack pointer
	;--------------------------------------------------
$IF (__RENESAS_VERSION__ >= 0x01010000)
	MOVW	SP,#LOWW(__STACK_ADDR_START)
$ELSE	; for CC-RL V1.00
	MOVW	SP,#LOWW(_stacktop)
$ENDIF

	;--------------------------------------------------
	; hardware initialization
	;--------------------------------------------------
	CALL	!!_hdwinit

	;--------------------------------------------------
	; initializing RAM
	;--------------------------------------------------
$IF (__RENESAS_VERSION__ >= 0x01010000)
	MOVW	HL,#LOWW(__RAM_ADDR_START)
	MOVW	AX,#LOWW(__RAM_ADDR_END)
$ELSE	; for CC-RL V1.00
	MOVW	HL,#LOWW(RAM_ADDR_START)
	MOVW	AX,#LOWW(RAM_ADDR_END)
$ENDIF
	BR	$.L2_RAM
.L1_RAM:
	MOV	[HL+0],#0
	INCW	HL
.L2_RAM:
	CMPW	AX,HL
	BNZ	$.L1_RAM

	;--------------------------------------------------
	; ROM data copy
	;--------------------------------------------------
	; copy external variables having initial value (near)
	MOV	ES,#HIGHW(STARTOF(.data))
	MOVW	BC,#LOWW(SIZEOF(.data))
	BR	$.L2_DATA
.L1_DATA:
	DECW	BC
	MOV	A,ES:LOWW(STARTOF(.data))[BC]
	MOV	LOWW(STARTOF(.dataR))[BC],A
.L2_DATA:
	CLRW	AX
	CMPW	AX,BC
	BNZ	$.L1_DATA

	; copy saddr variables having initial value
	MOV	ES,#HIGHW(STARTOF(.sdata))
	MOVW	BC,#LOWW(SIZEOF(.sdata))
	BR	$.L2_SDATA
.L1_SDATA:
	DECW	BC
	MOV	A,ES:LOWW(STARTOF(.sdata))[BC]
	MOV	LOWW(STARTOF(.sdataR))[BC],A
.L2_SDATA:
	CLRW	AX
	CMPW	AX,BC
	BNZ	$.L1_SDATA

	;--------------------------------------------------
	; call main function
	;--------------------------------------------------
	CALL	!_main		; main();

	;--------------------------------------------------
	; call exit function
	;--------------------------------------------------
	CLRW	AX		; exit(0);
_exit:
	BR	$_exit

;-----------------------------------------------------------------------------
;	section
;-----------------------------------------------------------------------------
$IF (__RENESAS_VERSION__ >= 0x01010000)
.SECTION .RLIB, TEXTF
.L_section_RLIB:
.SECTION .SLIB, TEXTF
.L_section_SLIB:
$ENDIF
.SECTION .textf, TEXTF
.L_section_textf:
.SECTION .const, CONST
.L_section_const:
.SECTION .constf, CONSTF
.L_section_constf:
.SECTION .data, DATA
.L_section_data:
.SECTION .sdata, SDATA
.L_section_sdata:
.SECTION .bss, BSS
.L_section_bss:
.SECTION .sbss, SBSS
.L_section_sbss:
