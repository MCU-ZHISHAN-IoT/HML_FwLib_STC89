/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:STC89Cxx header file
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC89 series
 * @Version:V1
 */
#ifndef ___STC89_H___
#define ___STC89_H___

#include <8051.h>

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
/* XICON */
__sbit __at (0xC0) IT2   ;
__sbit __at (0xC1) IE2   ;
__sbit __at (0xC2) EX2   ;
__sbit __at (0xC3) PX2   ;
__sbit __at (0xC4) IT3   ;
__sbit __at (0xC5) IE3   ;
__sbit __at (0xC6) EX3   ;
__sbit __at (0xC7) PX3   ;

/* P4 */
__sbit __at (0xEB) P4_3  ;
__sbit __at (0xEA) P4_2  ;
__sbit __at (0xE9) P4_1  ;
__sbit __at (0xE8) P4_0  ;

/* T2 */
__sbit __at (0xC8) CPRL2 ;
__sbit __at (0xC9) CT2   ;
__sbit __at (0xCA) TR2   ;
__sbit __at (0xCB) EXEN2 ;
__sbit __at (0xCC) TCLK  ;
__sbit __at (0xCD) RCLK  ;
__sbit __at (0xCE) EXF2  ;
__sbit __at (0xCF) TF2   ;

/* --- @interrupt vector --- */
#define TF2_VECTOR 5    /* 0x2b timer 2 */
#define IE2_VECTOR 6    /* 0x33 external interrupt 2 */
#define IE3_VECTOR 7    /* 0x3B external interrupt 3 */

#endif