;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
; This file was generated Wed Jul 18 12:39:08 2018
;--------------------------------------------------------
	.module tim2
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _CT2
	.globl _CPRL2
	.globl _P4_0
	.globl _P4_1
	.globl _P4_2
	.globl _P4_3
	.globl _PX3
	.globl _EX3
	.globl _IE3
	.globl _IT3
	.globl _PX2
	.globl _EX2
	.globl _IE2
	.globl _IT2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _P4
	.globl _ISP_CONTR
	.globl _ISP_TRIG
	.globl _ISP_CMD
	.globl _ISP_ADDRL
	.globl _ISP_ADDRH
	.globl _ISP_DATA
	.globl _WDT_CONTR
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2MOD
	.globl _T2CON
	.globl _XICON
	.globl _IPH
	.globl _SADDR1
	.globl _AUXR1
	.globl _AUXR
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _TIM2_calculateValue
	.globl _TIM2_clearFlag
	.globl _TIM2_cmd
	.globl _TIM2_config
	.globl _TIM2_getValue
	.globl _TIM2_isOverflow
	.globl _TIM2_setFunction
	.globl _TIM2_setMode
	.globl _TIM2_setValue
	.globl _TIM2_INT_cmd
	.globl _TIM2_INT_setPriority
	.globl _TIM2_INT_T2EX_cmd
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_AUXR	=	0x008e
_AUXR1	=	0x00a2
_SADDR1	=	0x00a9
_IPH	=	0x00b7
_XICON	=	0x00c0
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_WDT_CONTR	=	0x00e1
_ISP_DATA	=	0x00e2
_ISP_ADDRH	=	0x00e3
_ISP_ADDRL	=	0x00e4
_ISP_CMD	=	0x00e5
_ISP_TRIG	=	0x00e6
_ISP_CONTR	=	0x00e7
_P4	=	0x00e8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_IT2	=	0x00c0
_IE2	=	0x00c1
_EX2	=	0x00c2
_PX2	=	0x00c3
_IT3	=	0x00c4
_IE3	=	0x00c5
_EX3	=	0x00c6
_PX3	=	0x00c7
_P4_3	=	0x00eb
_P4_2	=	0x00ea
_P4_1	=	0x00e9
_P4_0	=	0x00e8
_CPRL2	=	0x00c8
_CT2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_calculateValue'
;------------------------------------------------------------
;time                      Allocated to registers 
;MaxTick                   Allocated to registers 
;------------------------------------------------------------
;	../src/tim2.c:20: unsigned int TIM2_calculateValue(unsigned int time)
;	-----------------------------------------
;	 function TIM2_calculateValue
;	-----------------------------------------
_TIM2_calculateValue:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	__mulint_PARM_2,dpl
	mov	(__mulint_PARM_2 + 1),dph
;	../src/tim2.c:23: if((time*12)/(_FRE_OSC_/1000000) >= MaxTick ) return 0;
	mov	dptr,#0x000C
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	mov	r5,#0x00
	mov	r4,#0x00
	mov	__divslong_PARM_2,#0x0B
	clr	a
	mov	(__divslong_PARM_2 + 1),a
	mov	(__divslong_PARM_2 + 2),a
	mov	(__divslong_PARM_2 + 3),a
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	mov	a,r4
	lcall	__divslong
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	clr	c
	mov	a,r4
	subb	a,#0xFF
	mov	a,r5
	subb	a,#0xFF
	mov	a,r6
	subb	a,#0x00
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00102$
	mov	dptr,#0x0000
	ret
00102$:
;	../src/tim2.c:24: else return (MaxTick+1-((time*12)/(_FRE_OSC_/1000000)));
	clr	c
	clr	a
	subb	a,r4
	mov	r4,a
	clr	a
	subb	a,r5
	mov	r5,a
	clr	a
	subb	a,r6
	clr	a
	subb	a,r7
	mov	dpl,r4
	mov	dph,r5
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_clearFlag'
;------------------------------------------------------------
;	../src/tim2.c:34: void TIM2_clearFlag(void)
;	-----------------------------------------
;	 function TIM2_clearFlag
;	-----------------------------------------
_TIM2_clearFlag:
;	../src/tim2.c:36: T2CON = T2CON & 0x7F;
	anl	_T2CON,#0x7F
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_cmd'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:46: void TIM2_cmd(Action a)
;	-----------------------------------------
;	 function TIM2_cmd
;	-----------------------------------------
_TIM2_cmd:
	mov	r7,dpl
;	../src/tim2.c:48: T2CON = (T2CON & 0xFB) | (a << 2);
	mov	a,#0xFB
	anl	a,_T2CON
	mov	r6,a
	mov	a,r7
	add	a,r7
	add	a,acc
	orl	a,r6
	mov	_T2CON,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_config'
;------------------------------------------------------------
;tc                        Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	../src/tim2.c:58: void TIM2_config(TIM2_configTypeDef *tc)
;	-----------------------------------------
;	 function TIM2_config
;	-----------------------------------------
_TIM2_config:
;	../src/tim2.c:60: TIM2_setFunction(tc->function);
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	lcall	__gptrget
	mov	dpl,a
	push	ar7
	push	ar6
	push	ar5
	lcall	_TIM2_setFunction
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/tim2.c:61: TIM2_setMode(tc->mode);
	mov	a,#0x03
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	dpl,a
	push	ar7
	push	ar6
	push	ar5
	lcall	_TIM2_setMode
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/tim2.c:62: TIM2_setValue(tc->value);
	mov	a,#0x04
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	push	ar7
	push	ar6
	push	ar5
	lcall	_TIM2_setValue
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/tim2.c:63: TIM2_INT_cmd(tc->interruptState);
	mov	a,#0x01
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	dpl,a
	push	ar7
	push	ar6
	push	ar5
	lcall	_TIM2_INT_cmd
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/tim2.c:64: TIM2_INT_setPriority(tc->interruptPriority);
	mov	a,#0x02
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	dpl,a
	ljmp	_TIM2_INT_setPriority
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_getValue'
;------------------------------------------------------------
;	../src/tim2.c:73: unsigned int TIM2_getValue(void)
;	-----------------------------------------
;	 function TIM2_getValue
;	-----------------------------------------
_TIM2_getValue:
;	../src/tim2.c:75: return (unsigned int)((TH2 << 0x8) | TL2);
	mov	r7,_TH2
	mov	r6,#0x00
	mov	r4,_TL2
	mov	r5,#0x00
	mov	a,r4
	orl	ar6,a
	mov	a,r5
	orl	ar7,a
	mov	dpl,r6
	mov	dph,r7
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_isOverflow'
;------------------------------------------------------------
;	../src/tim2.c:84: bool TIM2_isOverflow()
;	-----------------------------------------
;	 function TIM2_isOverflow
;	-----------------------------------------
_TIM2_isOverflow:
;	../src/tim2.c:86: return (bool)(T2CON >> 7);
	mov	a,_T2CON
	rl	a
	anl	a,#0x01
	add	a,#0xff
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_setFunction'
;------------------------------------------------------------
;f                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:96: void TIM2_setFunction(TIM2_function f)
;	-----------------------------------------
;	 function TIM2_setFunction
;	-----------------------------------------
_TIM2_setFunction:
	mov	r7,dpl
;	../src/tim2.c:98: T2CON = (T2CON & 0XCF) | f;
	mov	a,#0xCF
	anl	a,_T2CON
	orl	a,r7
	mov	_T2CON,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_setMode'
;------------------------------------------------------------
;m                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:108: void TIM2_setMode(TIM2_mode m)
;	-----------------------------------------
;	 function TIM2_setMode
;	-----------------------------------------
_TIM2_setMode:
	mov	r7,dpl
;	../src/tim2.c:110: T2CON = (T2CON & 0xCE) | m;
	mov	a,#0xCE
	anl	a,_T2CON
	orl	a,r7
	mov	_T2CON,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_setValue'
;------------------------------------------------------------
;val                       Allocated to registers r6 r7 
;------------------------------------------------------------
;	../src/tim2.c:120: void TIM2_setValue(unsigned int val)
;	-----------------------------------------
;	 function TIM2_setValue
;	-----------------------------------------
_TIM2_setValue:
	mov	r6,dpl
	mov	r7,dph
;	../src/tim2.c:122: TH2 = (val>>8);
	mov	_TH2,r7
;	../src/tim2.c:123: TL2 = val;
	mov	_TL2,r6
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_INT_cmd'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:133: void TIM2_INT_cmd(Action a)
;	-----------------------------------------
;	 function TIM2_INT_cmd
;	-----------------------------------------
_TIM2_INT_cmd:
	mov	r7,dpl
;	../src/tim2.c:135: IE = (IE & 0xDF) | (a << 5);
	mov	a,#0xDF
	anl	a,_IE
	mov	r6,a
	mov	a,r7
	swap	a
	rl	a
	anl	a,#0xE0
	orl	a,r6
	mov	_IE,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_INT_setPriority'
;------------------------------------------------------------
;p                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:145: void TIM2_INT_setPriority(INTR_PIOR p)
;	-----------------------------------------
;	 function TIM2_INT_setPriority
;	-----------------------------------------
_TIM2_INT_setPriority:
	mov	r7,dpl
;	../src/tim2.c:147: IP = (IP & 0xDF) | ((p & 0x01) << 0x5);
	mov	a,#0xDF
	anl	a,_IP
	mov	r6,a
	mov	a,#0x01
	anl	a,r7
	swap	a
	rl	a
	anl	a,#0xE0
	orl	a,r6
	mov	_IP,a
;	../src/tim2.c:148: IPH = (IPH & 0xDF) | ((p & 0x02) << 0x4);
	mov	a,#0xDF
	anl	a,_IPH
	mov	r6,a
	anl	ar7,#0x02
	mov	a,r7
	swap	a
	anl	a,#0xF0
	orl	a,r6
	mov	_IPH,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIM2_INT_T2EX_cmd'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/tim2.c:158: void TIM2_INT_T2EX_cmd(Action a)
;	-----------------------------------------
;	 function TIM2_INT_T2EX_cmd
;	-----------------------------------------
_TIM2_INT_T2EX_cmd:
	mov	r7,dpl
;	../src/tim2.c:160: T2CON = (T2CON & 0xF7) | (a << 3);
	mov	a,#0xF7
	anl	a,_T2CON
	mov	r6,a
	mov	a,r7
	swap	a
	rr	a
	anl	a,#0xF8
	orl	a,r6
	mov	_T2CON,a
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
