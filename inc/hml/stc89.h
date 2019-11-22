/*****************************************************************************/
/** 
 * \file        stc89.h
 * \author      Jiabin Hsu  | zsiothsu@zhishan-iot.tk
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       register define header file for STC89 series MCU
 * \note        
 * \version     
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_STC89_H___
#define ___HML_STC89_H___

#include <8051.h>
#include "hml/bit.h"

/*  BYTE Register  */
__sfr __at (0x8E) AUXR      ;
__sfr __at (0xA2) AUXR1     ;
__sfr __at (0xA9) SADDR1    ;
__sfr __at (0xB7) IPH       ;
__sfr __at (0xC0) XICON     ;
__sfr __at (0xC8) T2CON     ;
__sfr __at (0xC9) T2MOD     ;
__sfr __at (0xCA) RCAP2L    ;
__sfr __at (0xCB) RCAP2H    ;
__sfr __at (0xCC) TL2       ;
__sfr __at (0xCD) TH2       ;
__sfr __at (0xE1) WDT_CONTR ;
__sfr __at (0xE2) ISP_DATA  ;
__sfr __at (0xE3) ISP_ADDRH ;
__sfr __at (0xE4) ISP_ADDRL ;
__sfr __at (0xE5) ISP_CMD   ;
__sfr __at (0xE6) ISP_TRIG  ;
__sfr __at (0xE7) ISP_CONTR ;
__sfr __at (0xE8) P4        ;

/*  BIT Register  */
/* IE */
__sbit __at (0xAD) ET2      ;

/* IP */
__sbit __at (0xBD) PT2      ;

/* P1 */
__sbit __at (0x90) T2       ;          /* AFIO */
__sbit __at (0x91) T2EX     ;          /* AFIO */

/* P4 */
__sbit __at (0xE8) P4_0     ;
__sbit __at (0xE9) P4_1     ;
__sbit __at (0xEA) P4_2     ;
__sbit __at (0xEB) P4_3     ;

__sbit __at (0xEA) INT3     ;
__sbit __at (0xEB) INT2     ;

/* T2CON */
__sbit __at (0xC8) CPRL2    ;
__sbit __at (0xC9) T2_CT    ;
__sbit __at (0xCA) TR2      ;
__sbit __at (0xCB) EXEN2    ;
__sbit __at (0xCC) TCLK     ;
__sbit __at (0xCD) RCLK     ;
__sbit __at (0xCE) EXF2     ;
__sbit __at (0xCF) TF2      ;

/* XICON */
__sbit __at (0xC0) IT2      ;
__sbit __at (0xC1) IE2      ;
__sbit __at (0xC2) EX2      ;
__sbit __at (0xC3) PX2      ;
__sbit __at (0xC4) IT3      ;
__sbit __at (0xC5) IE3      ;
__sbit __at (0xC6) EX3      ;
__sbit __at (0xC7) PX3      ;

/* BIT number for bits that are not directly accessible */
/* AUXR bits */
#define BIT_NUM_ALEOFF    0
#define BIT_NUM_EXTRAM    1

/* AUXR1 bits */
#define BIT_NUM_DPS       0
#define BIT_NUM_GF2       3

/* IPH bits */
#define BIT_NUM_PX0H      0
#define BIT_NUM_PT0H      1
#define BIT_NUM_PX1H      2
#define BIT_NUM_PT1H      3
#define BIT_NUM_PSH       4
#define BIT_NUM_PT2H      5
#define BIT_NUM_PX2H      6
#define BIT_NUM_PX3H      7

/* ISP_CMD bits */
#define BIT_NUM_MS0       0
#define BIT_NUM_MS1       1
#define BIT_NUM_MS2       2

/* ISP_CONTR bits */
#define BIT_NUM_WT0       0
#define BIT_NUM_WT1       1
#define BIT_NUM_WT2       2
#define BIT_NUM_SWRST     5
#define BIT_NUM_SWBS      6
#define BIT_NUM_ISPEN     7

/* PCON bits */
#define BIT_NUM_IDL       0
#define BIT_NUM_PD        1
#define BIT_NUM_GF0       2
#define BIT_NUM_GF1       3
#define BIT_NUM_POF       4
#define BIT_NUM_SMOD0     6
#define BIT_NUM_SMOD      7

/* T2MOD bits */
#define BIT_NUM_DCEN      0
#define BIT_NUM_T2OE      1

/* TMOD bits */
#define BIT_NUM_T0_M0     0
#define BIT_NUM_T0_M1     1
#define BIT_NUM_T0_CT     2
#define BIT_NUM_T0_GATE   3
#define BIT_NUM_T1_M0     4
#define BIT_NUM_T1_M1     5
#define BIT_NUM_T1_CT     6
#define BIT_NUM_T1_GATE   7

/* WDT_CONTR bits */
#define BIT_NUM_PS0       0
#define BIT_NUM_PS1       1
#define BIT_NUM_PS2       2
#define BIT_NUM_IDLE_WDT  3
#define BIT_NUM_CLR_WDT   4
#define BIT_NUM_EN_WDT    5

/* BIT definitions for bits that are not directly accessible */
/* AUXR bits */
#define ALEOFF     BIT_MASK(BIT_NUM_ALEOFF)
#define EXTRAM     BIT_MASK(BIT_NUM_EXTRAM)

/* AUXR1 bits */
#define DPS        BIT_MASK(BIT_NUM_DPS)    /* DPTR register select bit */
#define GF2        BIT_MASK(BIT_NUM_GF2)

/* IPH bits */
#define PX0H       BIT_MASK(BIT_NUM_PX0H)
#define PT0H       BIT_MASK(BIT_NUM_PT0H)
#define PX1H       BIT_MASK(BIT_NUM_PX1H)
#define PT1H       BIT_MASK(BIT_NUM_PT1H)
#define PSH        BIT_MASK(BIT_NUM_PSH)
#define PT2H       BIT_MASK(BIT_NUM_PT2H)
#define PX2H       BIT_MASK(BIT_NUM_PX2H)
#define PX3H       BIT_MASK(BIT_NUM_PX3H)

/* ISP_CMD bits */
#define MS0        BIT_MASK(BIT_NUM_MS0)
#define MS1        BIT_MASK(BIT_NUM_MS1)
#define MS2        BIT_MASK(BIT_NUM_MS2)

/* ISP_CONTR bits */
#define WT0        BIT_MASK(BIT_NUM_WT0)
#define WT1        BIT_MASK(BIT_NUM_WT1)
#define WT2        BIT_MASK(BIT_NUM_WT2)
#define SWRST      BIT_MASK(BIT_NUM_SWRST)
#define SWBS       BIT_MASK(BIT_NUM_SWBS)
#define ISPEN      BIT_MASK(BIT_NUM_ISPEN)

/* PCON bits */
#define POF        BIT_MASK(BIT_NUM_POF)
#define SMOD0      BIT_MASK(BIT_NUM_SMOD0)

/* T2MOD bits */
#define DCEN       BIT_MASK(BIT_NUM_DCEN)
#define T2OE       BIT_MASK(BIT_NUM_T2OE)

/* WDT_CONTR bits */
#define PS0        BIT_MASK(BIT_NUM_PS0)
#define PS1        BIT_MASK(BIT_NUM_PS1)
#define PS2        BIT_MASK(BIT_NUM_PS2)
#define IDLE_WDT   BIT_MASK(BIT_NUM_IDLE_WDT)
#define CLR_WDT    BIT_MASK(BIT_NUM_CLR_WDT)
#define EN_WDT     BIT_MASK(BIT_NUM_EN_WDT)

/* Interrupt numbers: address = (number * 8) + 3 */
#define TF2_VECTOR 5    /* 0x2b timer 2 */
#define IE2_VECTOR 6    /* 0x33 external interrupt 2 */
#define IE3_VECTOR 7    /* 0x3B external interrupt 3 */

#endif
