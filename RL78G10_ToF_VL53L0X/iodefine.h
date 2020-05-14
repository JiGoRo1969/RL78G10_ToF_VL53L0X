/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* http://www.renesas.com/disclaimer                                          */
/*                                                                            */
/* Device     : RL78/R5F10Y46                                                 */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of Special Function Register (SFR)                 */
/* History    : V1.03  [Device File version]                                  */
/* Options    : -df=C:\Program Files (x86)\Renesas Electronics\CS+\CC\Device\ */
/*              RL78\Devicefile\DR5F10Y46.DVF -o=D:\Renesas\RL78\robo\TOF_G10 */
/*              _B1\iodefine.h -f                                             */
/* Date       : 2020/03/22                                                    */
/* Version    : V1.12.00.01  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R5F10Y46IODEFINE_HEADER__
#define __R5F10Y46IODEFINE_HEADER__

typedef struct
{
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
} __bitf_T;

typedef struct
{
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
    unsigned char no8:1;
    unsigned char no9:1;
    unsigned char no10:1;
    unsigned char no11:1;
    unsigned char no12:1;
    unsigned char no13:1;
    unsigned char no14:1;
    unsigned char no15:1;
} __bitf_T2;



#define ADM2         (*(volatile __near unsigned char  *)0x10)
#define ADM2_bit     (*(volatile __near __bitf_T *)0x10)
#define ADTYP        (((volatile __near __bitf_T *)0x10)->no0)
#define ADTES        (*(volatile __near unsigned char  *)0x13)
#define PU0          (*(volatile __near unsigned char  *)0x30)
#define PU0_bit      (*(volatile __near __bitf_T *)0x30)
#define PU4          (*(volatile __near unsigned char  *)0x34)
#define PU4_bit      (*(volatile __near __bitf_T *)0x34)
#define PU12         (*(volatile __near unsigned char  *)0x3C)
#define PU12_bit     (*(volatile __near __bitf_T *)0x3C)
#define POM0         (*(volatile __near unsigned char  *)0x50)
#define POM0_bit     (*(volatile __near __bitf_T *)0x50)
#define PMC0         (*(volatile __near unsigned char  *)0x60)
#define PMC0_bit     (*(volatile __near __bitf_T *)0x60)
#define NFEN0        (*(volatile __near unsigned char  *)0x70)
#define NFEN0_bit    (*(volatile __near __bitf_T *)0x70)
#define NFEN1        (*(volatile __near unsigned char  *)0x71)
#define NFEN1_bit    (*(volatile __near __bitf_T *)0x71)
#define ISC          (*(volatile __near unsigned char  *)0x73)
#define ISC_bit      (*(volatile __near __bitf_T *)0x73)
#define PIOR         (*(volatile __near unsigned char  *)0x77)
#define HOCODIV      (*(volatile __near unsigned char  *)0xA8)
#define PER0         (*(volatile __near unsigned char  *)0xF0)
#define PER0_bit     (*(volatile __near __bitf_T *)0xF0)
#define TAU0EN       (((volatile __near __bitf_T *)0xF0)->no0)
#define SAU0EN       (((volatile __near __bitf_T *)0xF0)->no2)
#define IICA0EN      (((volatile __near __bitf_T *)0xF0)->no4)
#define ADCEN        (((volatile __near __bitf_T *)0xF0)->no5)
#define CMPEN        (((volatile __near __bitf_T *)0xF0)->no6)
#define TMKAEN       (((volatile __near __bitf_T *)0xF0)->no7)
#define OSMC         (*(volatile __near unsigned char  *)0xF3)
#define BCDADJ       (*(volatile __near unsigned char  *)0xFE)
#define SSR00        (*(volatile __near unsigned char  *)0x100)
#define SSR01        (*(volatile __near unsigned char  *)0x102)
#define SIR00        (*(volatile __near unsigned char  *)0x108)
#define SIR01        (*(volatile __near unsigned char  *)0x10A)
#define SMR00L       (*(volatile __near unsigned char  *)0x110)
#define SMR00H       (*(volatile __near unsigned char  *)0x111)
#define SMR01L       (*(volatile __near unsigned char  *)0x112)
#define SMR01H       (*(volatile __near unsigned char  *)0x113)
#define SCR00L       (*(volatile __near unsigned char  *)0x118)
#define SCR00H       (*(volatile __near unsigned char  *)0x119)
#define SCR01L       (*(volatile __near unsigned char  *)0x11A)
#define SCR01H       (*(volatile __near unsigned char  *)0x11B)
#define SE0          (*(volatile __near unsigned char  *)0x120)
#define SE0_bit      (*(volatile __near __bitf_T *)0x120)
#define SS0          (*(volatile __near unsigned char  *)0x122)
#define SS0_bit      (*(volatile __near __bitf_T *)0x122)
#define ST0          (*(volatile __near unsigned char  *)0x124)
#define ST0_bit      (*(volatile __near __bitf_T *)0x124)
#define SPS0         (*(volatile __near unsigned char  *)0x126)
#define SO0          (*(volatile __near unsigned char  *)0x128)
#define CKO0         (*(volatile __near unsigned char  *)0x129)
#define SOE0         (*(volatile __near unsigned char  *)0x12A)
#define SOE0_bit     (*(volatile __near __bitf_T *)0x12A)
#define SOL0         (*(volatile __near unsigned char  *)0x134)
#define TCR00L       (*(volatile __near unsigned char  *)0x180)
#define TCR00H       (*(volatile __near unsigned char  *)0x181)
#define TCR01L       (*(volatile __near unsigned char  *)0x182)
#define TCR01H       (*(volatile __near unsigned char  *)0x183)
#define TCR02L       (*(volatile __near unsigned char  *)0x184)
#define TCR02H       (*(volatile __near unsigned char  *)0x185)
#define TCR03L       (*(volatile __near unsigned char  *)0x186)
#define TCR03H       (*(volatile __near unsigned char  *)0x187)
#define TMR00L       (*(volatile __near unsigned char  *)0x190)
#define TMR00H       (*(volatile __near unsigned char  *)0x191)
#define TMR01L       (*(volatile __near unsigned char  *)0x192)
#define TMR01H       (*(volatile __near unsigned char  *)0x193)
#define TMR02L       (*(volatile __near unsigned char  *)0x194)
#define TMR02H       (*(volatile __near unsigned char  *)0x195)
#define TMR03L       (*(volatile __near unsigned char  *)0x196)
#define TMR03H       (*(volatile __near unsigned char  *)0x197)
#define TSR00        (*(volatile __near unsigned char  *)0x1A0)
#define TSR01        (*(volatile __near unsigned char  *)0x1A2)
#define TSR02        (*(volatile __near unsigned char  *)0x1A4)
#define TSR03        (*(volatile __near unsigned char  *)0x1A6)
#define TE0          (*(volatile __near unsigned char  *)0x1B0)
#define TE0_bit      (*(volatile __near __bitf_T *)0x1B0)
#define TEH0         (*(volatile __near unsigned char  *)0x1B1)
#define TEH0_bit     (*(volatile __near __bitf_T *)0x1B1)
#define TS0          (*(volatile __near unsigned char  *)0x1B2)
#define TS0_bit      (*(volatile __near __bitf_T *)0x1B2)
#define TSH0         (*(volatile __near unsigned char  *)0x1B3)
#define TSH0_bit     (*(volatile __near __bitf_T *)0x1B3)
#define TT0          (*(volatile __near unsigned char  *)0x1B4)
#define TT0_bit      (*(volatile __near __bitf_T *)0x1B4)
#define TTH0         (*(volatile __near unsigned char  *)0x1B5)
#define TTH0_bit     (*(volatile __near __bitf_T *)0x1B5)
#define TPS0         (*(volatile __near unsigned char  *)0x1B6)
#define TO0          (*(volatile __near unsigned char  *)0x1B8)
#define TOE0         (*(volatile __near unsigned char  *)0x1BA)
#define TOE0_bit     (*(volatile __near __bitf_T *)0x1BA)
#define TOL0         (*(volatile __near unsigned char  *)0x1BC)
#define TOM0         (*(volatile __near unsigned char  *)0x1BE)
#define IICCTL00     (*(volatile __near unsigned char  *)0x230)
#define IICCTL00_bit (*(volatile __near __bitf_T *)0x230)
#define SPT0         (((volatile __near __bitf_T *)0x230)->no0)
#define STT0         (((volatile __near __bitf_T *)0x230)->no1)
#define ACKE0        (((volatile __near __bitf_T *)0x230)->no2)
#define WTIM0        (((volatile __near __bitf_T *)0x230)->no3)
#define SPIE0        (((volatile __near __bitf_T *)0x230)->no4)
#define WREL0        (((volatile __near __bitf_T *)0x230)->no5)
#define LREL0        (((volatile __near __bitf_T *)0x230)->no6)
#define IICE0        (((volatile __near __bitf_T *)0x230)->no7)
#define IICCTL01     (*(volatile __near unsigned char  *)0x231)
#define IICCTL01_bit (*(volatile __near __bitf_T *)0x231)
#define DFC0         (((volatile __near __bitf_T *)0x231)->no2)
#define SMC0         (((volatile __near __bitf_T *)0x231)->no3)
#define DAD0         (((volatile __near __bitf_T *)0x231)->no4)
#define CLD0         (((volatile __near __bitf_T *)0x231)->no5)
#define WUP0         (((volatile __near __bitf_T *)0x231)->no7)
#define IICWL0       (*(volatile __near unsigned char  *)0x232)
#define IICWH0       (*(volatile __near unsigned char  *)0x233)
#define SVA0         (*(volatile __near unsigned char  *)0x234)
#define P0           (*(volatile __near unsigned char  *)0xFF00)
#define P0_bit       (*(volatile __near __bitf_T *)0xFF00)
#define P4           (*(volatile __near unsigned char  *)0xFF04)
#define P4_bit       (*(volatile __near __bitf_T *)0xFF04)
#define P12          (*(volatile __near unsigned char  *)0xFF0C)
#define P12_bit      (*(volatile __near __bitf_T *)0xFF0C)
#define P13          (*(volatile __near unsigned char  *)0xFF0D)
#define P13_bit      (*(volatile __near __bitf_T *)0xFF0D)
#define SDR00L       (*(volatile __near unsigned char  *)0xFF10)
#define SIO00        (*(volatile __near unsigned char  *)0xFF10)
#define TXD0         (*(volatile __near unsigned char  *)0xFF10)
#define SDR00H       (*(volatile __near unsigned char  *)0xFF11)
#define RXD0         (*(volatile __near unsigned char  *)0xFF12)
#define SDR01L       (*(volatile __near unsigned char  *)0xFF12)
#define SIO01        (*(volatile __near unsigned char  *)0xFF12)
#define SDR01H       (*(volatile __near unsigned char  *)0xFF13)
#define TDR00L       (*(volatile __near unsigned char  *)0xFF18)
#define TDR00H       (*(volatile __near unsigned char  *)0xFF19)
#define TDR01L       (*(volatile __near unsigned char  *)0xFF1A)
#define TDR01H       (*(volatile __near unsigned char  *)0xFF1B)
#define ADCRL        (*(volatile __near unsigned char  *)0xFF1E)
#define ADCRH        (*(volatile __near unsigned char  *)0xFF1F)
#define PM0          (*(volatile __near unsigned char  *)0xFF20)
#define PM0_bit      (*(volatile __near __bitf_T *)0xFF20)
#define PM4          (*(volatile __near unsigned char  *)0xFF24)
#define PM4_bit      (*(volatile __near __bitf_T *)0xFF24)
#define ADM0         (*(volatile __near unsigned char  *)0xFF30)
#define ADM0_bit     (*(volatile __near __bitf_T *)0xFF30)
#define ADCE         (((volatile __near __bitf_T *)0xFF30)->no0)
#define ADCS         (((volatile __near __bitf_T *)0xFF30)->no7)
#define ADS          (*(volatile __near unsigned char  *)0xFF31)
#define ADS_bit      (*(volatile __near __bitf_T *)0xFF31)
#define KRCTL        (*(volatile __near unsigned char  *)0xFF34)
#define KRCTL_bit    (*(volatile __near __bitf_T *)0xFF34)
#define KRF          (*(volatile __near unsigned char  *)0xFF35)
#define KRM0         (*(volatile __near unsigned char  *)0xFF37)
#define KRM0_bit     (*(volatile __near __bitf_T *)0xFF37)
#define EGP0         (*(volatile __near unsigned char  *)0xFF38)
#define EGP0_bit     (*(volatile __near __bitf_T *)0xFF38)
#define EGN0         (*(volatile __near unsigned char  *)0xFF39)
#define EGN0_bit     (*(volatile __near __bitf_T *)0xFF39)
#define IICA0        (*(volatile __near unsigned char  *)0xFF50)
#define IICS0        (*(volatile __near unsigned char  *)0xFF51)
#define IICS0_bit    (*(volatile __near __bitf_T *)0xFF51)
#define SPD0         (((volatile __near __bitf_T *)0xFF51)->no0)
#define STD0         (((volatile __near __bitf_T *)0xFF51)->no1)
#define ACKD0        (((volatile __near __bitf_T *)0xFF51)->no2)
#define TRC0         (((volatile __near __bitf_T *)0xFF51)->no3)
#define COI0         (((volatile __near __bitf_T *)0xFF51)->no4)
#define EXC0         (((volatile __near __bitf_T *)0xFF51)->no5)
#define ALD0         (((volatile __near __bitf_T *)0xFF51)->no6)
#define MSTS0        (((volatile __near __bitf_T *)0xFF51)->no7)
#define IICF0        (*(volatile __near unsigned char  *)0xFF52)
#define IICF0_bit    (*(volatile __near __bitf_T *)0xFF52)
#define IICRSV0      (((volatile __near __bitf_T *)0xFF52)->no0)
#define STCEN0       (((volatile __near __bitf_T *)0xFF52)->no1)
#define IICBSY0      (((volatile __near __bitf_T *)0xFF52)->no6)
#define STCF0        (((volatile __near __bitf_T *)0xFF52)->no7)
#define COMPMDR      (*(volatile __near unsigned char  *)0xFF60)
#define COMPMDR_bit  (*(volatile __near __bitf_T *)0xFF60)
#define C0ENB        (((volatile __near __bitf_T *)0xFF60)->no0)
#define C0MON        (((volatile __near __bitf_T *)0xFF60)->no3)
#define COMPFIR      (*(volatile __near unsigned char  *)0xFF61)
#define COMPFIR_bit  (*(volatile __near __bitf_T *)0xFF61)
#define COMPOCR      (*(volatile __near unsigned char  *)0xFF62)
#define COMPOCR_bit  (*(volatile __near __bitf_T *)0xFF62)
#define C0IE         (((volatile __near __bitf_T *)0xFF62)->no0)
#define C0OE         (((volatile __near __bitf_T *)0xFF62)->no1)
#define C0OP         (((volatile __near __bitf_T *)0xFF62)->no2)
#define SPDMD        (((volatile __near __bitf_T *)0xFF62)->no7)
#define TDR02L       (*(volatile __near unsigned char  *)0xFF64)
#define TDR02H       (*(volatile __near unsigned char  *)0xFF65)
#define TDR03L       (*(volatile __near unsigned char  *)0xFF66)
#define TDR03H       (*(volatile __near unsigned char  *)0xFF67)
#define ITMCL        (*(volatile __near unsigned char  *)0xFF90)
#define ITMCH        (*(volatile __near unsigned char  *)0xFF91)
#define CMC          (*(volatile __near unsigned char  *)0xFFA0)
#define CSC          (*(volatile __near unsigned char  *)0xFFA1)
#define CSC_bit      (*(volatile __near __bitf_T *)0xFFA1)
#define HIOSTOP      (((volatile __near __bitf_T *)0xFFA1)->no0)
#define MSTOP        (((volatile __near __bitf_T *)0xFFA1)->no7)
#define OSTC         (*(volatile __near unsigned char  *)0xFFA2)
#define OSTC_bit     (*(volatile __near __bitf_T *)0xFFA2)
#define OSTS         (*(volatile __near unsigned char  *)0xFFA3)
#define CKC          (*(volatile __near unsigned char  *)0xFFA4)
#define CKC_bit      (*(volatile __near __bitf_T *)0xFFA4)
#define MCM0         (((volatile __near __bitf_T *)0xFFA4)->no4)
#define MCS          (((volatile __near __bitf_T *)0xFFA4)->no5)
#define CKS0         (*(volatile __near unsigned char  *)0xFFA5)
#define CKS0_bit     (*(volatile __near __bitf_T *)0xFFA5)
#define PCLOE0       (((volatile __near __bitf_T *)0xFFA5)->no7)
#define RESF         (*(volatile __near unsigned char  *)0xFFA8)
#define WDTE         (*(volatile __near unsigned char  *)0xFFAB)
#define IF0L         (*(volatile __near unsigned char  *)0xFFE0)
#define IF0L_bit     (*(volatile __near __bitf_T *)0xFFE0)
#define WDTIIF       (((volatile __near __bitf_T *)0xFFE0)->no0)
#define PIF0         (((volatile __near __bitf_T *)0xFFE0)->no1)
#define PIF1         (((volatile __near __bitf_T *)0xFFE0)->no2)
#define CSIIF00      (((volatile __near __bitf_T *)0xFFE0)->no3)
#define IICIF00      (((volatile __near __bitf_T *)0xFFE0)->no3)
#define STIF0        (((volatile __near __bitf_T *)0xFFE0)->no3)
#define CSIIF01      (((volatile __near __bitf_T *)0xFFE0)->no4)
#define SRIF0        (((volatile __near __bitf_T *)0xFFE0)->no4)
#define SREIF0       (((volatile __near __bitf_T *)0xFFE0)->no5)
#define TMIF01H      (((volatile __near __bitf_T *)0xFFE0)->no6)
#define TMIF00       (((volatile __near __bitf_T *)0xFFE0)->no7)
#define IF0H         (*(volatile __near unsigned char  *)0xFFE1)
#define IF0H_bit     (*(volatile __near __bitf_T *)0xFFE1)
#define TMIF01       (((volatile __near __bitf_T *)0xFFE1)->no0)
#define ADIF         (((volatile __near __bitf_T *)0xFFE1)->no1)
#define KRIF         (((volatile __near __bitf_T *)0xFFE1)->no2)
#define PIF2         (((volatile __near __bitf_T *)0xFFE1)->no3)
#define PIF3         (((volatile __near __bitf_T *)0xFFE1)->no4)
#define TMIF03H      (((volatile __near __bitf_T *)0xFFE1)->no5)
#define IICAIF0      (((volatile __near __bitf_T *)0xFFE1)->no6)
#define TMIF02       (((volatile __near __bitf_T *)0xFFE1)->no7)
#define IF1L         (*(volatile __near unsigned char  *)0xFFE2)
#define IF1L_bit     (*(volatile __near __bitf_T *)0xFFE2)
#define TMIF03       (((volatile __near __bitf_T *)0xFFE2)->no0)
#define ITIF         (((volatile __near __bitf_T *)0xFFE2)->no1)
#define CMPIF0       (((volatile __near __bitf_T *)0xFFE2)->no2)
#define MK0L         (*(volatile __near unsigned char  *)0xFFE4)
#define MK0L_bit     (*(volatile __near __bitf_T *)0xFFE4)
#define WDTIMK       (((volatile __near __bitf_T *)0xFFE4)->no0)
#define PMK0         (((volatile __near __bitf_T *)0xFFE4)->no1)
#define PMK1         (((volatile __near __bitf_T *)0xFFE4)->no2)
#define CSIMK00      (((volatile __near __bitf_T *)0xFFE4)->no3)
#define IICMK00      (((volatile __near __bitf_T *)0xFFE4)->no3)
#define STMK0        (((volatile __near __bitf_T *)0xFFE4)->no3)
#define CSIMK01      (((volatile __near __bitf_T *)0xFFE4)->no4)
#define SRMK0        (((volatile __near __bitf_T *)0xFFE4)->no4)
#define SREMK0       (((volatile __near __bitf_T *)0xFFE4)->no5)
#define TMMK01H      (((volatile __near __bitf_T *)0xFFE4)->no6)
#define TMMK00       (((volatile __near __bitf_T *)0xFFE4)->no7)
#define MK0H         (*(volatile __near unsigned char  *)0xFFE5)
#define MK0H_bit     (*(volatile __near __bitf_T *)0xFFE5)
#define TMMK01       (((volatile __near __bitf_T *)0xFFE5)->no0)
#define ADMK         (((volatile __near __bitf_T *)0xFFE5)->no1)
#define KRMK         (((volatile __near __bitf_T *)0xFFE5)->no2)
#define PMK2         (((volatile __near __bitf_T *)0xFFE5)->no3)
#define PMK3         (((volatile __near __bitf_T *)0xFFE5)->no4)
#define TMMK03H      (((volatile __near __bitf_T *)0xFFE5)->no5)
#define IICAMK0      (((volatile __near __bitf_T *)0xFFE5)->no6)
#define TMMK02       (((volatile __near __bitf_T *)0xFFE5)->no7)
#define MK1L         (*(volatile __near unsigned char  *)0xFFE6)
#define MK1L_bit     (*(volatile __near __bitf_T *)0xFFE6)
#define TMMK03       (((volatile __near __bitf_T *)0xFFE6)->no0)
#define ITMK         (((volatile __near __bitf_T *)0xFFE6)->no1)
#define CMPMK0       (((volatile __near __bitf_T *)0xFFE6)->no2)
#define PR00L        (*(volatile __near unsigned char  *)0xFFE8)
#define PR00L_bit    (*(volatile __near __bitf_T *)0xFFE8)
#define WDTIPR0      (((volatile __near __bitf_T *)0xFFE8)->no0)
#define PPR00        (((volatile __near __bitf_T *)0xFFE8)->no1)
#define PPR01        (((volatile __near __bitf_T *)0xFFE8)->no2)
#define CSIPR000     (((volatile __near __bitf_T *)0xFFE8)->no3)
#define IICPR000     (((volatile __near __bitf_T *)0xFFE8)->no3)
#define STPR00       (((volatile __near __bitf_T *)0xFFE8)->no3)
#define CSIPR001     (((volatile __near __bitf_T *)0xFFE8)->no4)
#define SRPR00       (((volatile __near __bitf_T *)0xFFE8)->no4)
#define SREPR00      (((volatile __near __bitf_T *)0xFFE8)->no5)
#define TMPR001H     (((volatile __near __bitf_T *)0xFFE8)->no6)
#define TMPR000      (((volatile __near __bitf_T *)0xFFE8)->no7)
#define PR00H        (*(volatile __near unsigned char  *)0xFFE9)
#define PR00H_bit    (*(volatile __near __bitf_T *)0xFFE9)
#define TMPR001      (((volatile __near __bitf_T *)0xFFE9)->no0)
#define ADPR0        (((volatile __near __bitf_T *)0xFFE9)->no1)
#define KRPR0        (((volatile __near __bitf_T *)0xFFE9)->no2)
#define PPR02        (((volatile __near __bitf_T *)0xFFE9)->no3)
#define PPR03        (((volatile __near __bitf_T *)0xFFE9)->no4)
#define TMPR003H     (((volatile __near __bitf_T *)0xFFE9)->no5)
#define IICAPR00     (((volatile __near __bitf_T *)0xFFE9)->no6)
#define TMPR002      (((volatile __near __bitf_T *)0xFFE9)->no7)
#define PR01L        (*(volatile __near unsigned char  *)0xFFEA)
#define PR01L_bit    (*(volatile __near __bitf_T *)0xFFEA)
#define TMPR003      (((volatile __near __bitf_T *)0xFFEA)->no0)
#define ITPR0        (((volatile __near __bitf_T *)0xFFEA)->no1)
#define CMPPR00      (((volatile __near __bitf_T *)0xFFEA)->no2)
#define PR10L        (*(volatile __near unsigned char  *)0xFFEC)
#define PR10L_bit    (*(volatile __near __bitf_T *)0xFFEC)
#define WDTIPR1      (((volatile __near __bitf_T *)0xFFEC)->no0)
#define PPR10        (((volatile __near __bitf_T *)0xFFEC)->no1)
#define PPR11        (((volatile __near __bitf_T *)0xFFEC)->no2)
#define CSIPR100     (((volatile __near __bitf_T *)0xFFEC)->no3)
#define IICPR100     (((volatile __near __bitf_T *)0xFFEC)->no3)
#define STPR10       (((volatile __near __bitf_T *)0xFFEC)->no3)
#define CSIPR101     (((volatile __near __bitf_T *)0xFFEC)->no4)
#define SRPR10       (((volatile __near __bitf_T *)0xFFEC)->no4)
#define SREPR10      (((volatile __near __bitf_T *)0xFFEC)->no5)
#define TMPR101H     (((volatile __near __bitf_T *)0xFFEC)->no6)
#define TMPR100      (((volatile __near __bitf_T *)0xFFEC)->no7)
#define PR10H        (*(volatile __near unsigned char  *)0xFFED)
#define PR10H_bit    (*(volatile __near __bitf_T *)0xFFED)
#define TMPR101      (((volatile __near __bitf_T *)0xFFED)->no0)
#define ADPR1        (((volatile __near __bitf_T *)0xFFED)->no1)
#define KRPR1        (((volatile __near __bitf_T *)0xFFED)->no2)
#define PPR12        (((volatile __near __bitf_T *)0xFFED)->no3)
#define PPR13        (((volatile __near __bitf_T *)0xFFED)->no4)
#define TMPR103H     (((volatile __near __bitf_T *)0xFFED)->no5)
#define IICAPR10     (((volatile __near __bitf_T *)0xFFED)->no6)
#define TMPR102      (((volatile __near __bitf_T *)0xFFED)->no7)
#define PR11L        (*(volatile __near unsigned char  *)0xFFEE)
#define PR11L_bit    (*(volatile __near __bitf_T *)0xFFEE)
#define TMPR103      (((volatile __near __bitf_T *)0xFFEE)->no0)
#define ITPR1        (((volatile __near __bitf_T *)0xFFEE)->no1)
#define CMPPR10      (((volatile __near __bitf_T *)0xFFEE)->no2)
#define PMC          (*(volatile __near unsigned char  *)0xFFFE)
#define PMC_bit      (*(volatile __near __bitf_T *)0xFFFE)
#define MAA          (((volatile __near __bitf_T *)0xFFFE)->no0)


#define INTWDTI                         0x0004
#define INTP0                           0x0006
#define INTP1                           0x0008
#define INTCSI00                        0x000A
#define INTIIC00                        0x000A
#define INTST0                          0x000A
#define INTCSI01                        0x000C
#define INTSR0                          0x000C
#define INTSRE0                         0x000E
#define INTTM01H                        0x0010
#define INTTM00                         0x0012
#define INTTM01                         0x0014
#define INTAD                           0x0016
#define INTKR                           0x0018
#define INTP2                           0x001A
#define INTP3                           0x001C
#define INTTM03H                        0x001E
#define INTIICA0                        0x0020
#define INTTM02                         0x0022
#define INTTM03                         0x0024
#define INTIT                           0x0026
#define INTCMP0                         0x0028

#endif
