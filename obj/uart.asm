;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
; This file was generated Wed Jul 18 12:39:08 2018
;--------------------------------------------------------
	.module uart
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIM2_config
	.globl _TIM2_cmd
	.globl _TIM_config
	.globl _TIM_cmd
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
	.globl _UART_getTimerInitValue_PARM_2
	.globl _UART_cmd_multiBaudrate
	.globl _UART_cmd_receive
	.globl _UART_config
	.globl _UART_getTimerInitValue
	.globl _UART_isReceived
	.globl _UART_isTransmitted
	.globl _UART_sendByte
	.globl _UART_sendString
	.globl _UART_setMode
	.globl _UART_INT_setPriority
	.globl _UART_INT_cmd
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
_UART_config_tc_1_41:
	.ds 6
_UART_config_tc2_1_41:
	.ds 6
_UART_getTimerInitValue_PARM_2:
	.ds 1
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
;Allocation info for local variables in function 'UART_cmd_multiBaudrate'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/uart.c:20: void UART_cmd_multiBaudrate(Action a)
;	-----------------------------------------
;	 function UART_cmd_multiBaudrate
;	-----------------------------------------
_UART_cmd_multiBaudrate:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
;	../src/uart.c:22: PCON = (PCON & 0x7F) | ((unsigned char)a << 0x7);
	mov	a,#0x7F
	anl	a,_PCON
	mov	r6,a
	mov	a,r7
	rr	a
	anl	a,#0x80
	orl	a,r6
	mov	_PCON,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_cmd_receive'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/uart.c:31: void UART_cmd_receive(Action a)
;	-----------------------------------------
;	 function UART_cmd_receive
;	-----------------------------------------
_UART_cmd_receive:
;	../src/uart.c:33: REN = a;
	mov	a,dpl
	add	a,#0xff
	mov	_REN,c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_config'
;------------------------------------------------------------
;uc                        Allocated to registers r5 r6 r7 
;tc                        Allocated with name '_UART_config_tc_1_41'
;tc2                       Allocated with name '_UART_config_tc2_1_41'
;------------------------------------------------------------
;	../src/uart.c:42: void UART_config(UART_configTypeDef *uc)
;	-----------------------------------------
;	 function UART_config
;	-----------------------------------------
_UART_config:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	../src/uart.c:47: UART_INT_cmd(uc->interruptState);
	mov	a,#0x02
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
	lcall	_UART_INT_cmd
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/uart.c:48: UART_INT_setPriority(uc->interruptPriority);
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
	lcall	_UART_INT_setPriority
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/uart.c:49: UART_cmd_multiBaudrate(uc->multiBaudrate);
	mov	a,#0x05
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
	lcall	_UART_cmd_multiBaudrate
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/uart.c:50: UART_setMode(uc->mode);
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
	mov	dpl,a
	push	ar7
	push	ar6
	push	ar5
	lcall	_UART_setMode
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/uart.c:51: UART_cmd_receive(uc->receiveState);
	mov	a,#0x06
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
	lcall	_UART_cmd_receive
	pop	ar5
	pop	ar6
	pop	ar7
;	../src/uart.c:53: switch(uc->tim)
	mov	a,#0x07
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
	mov	r4,a
	cjne	r4,#0x01,00113$
	sjmp	00101$
00113$:
	cjne	r4,#0x02,00114$
	sjmp	00102$
00114$:
	ret
;	../src/uart.c:55: case PERIPH_TIM_1:
00101$:
;	../src/uart.c:56: tc.function          = TIM_FUNC_TIM;
	mov	_UART_config_tc_1_41,#0x00
;	../src/uart.c:57: tc.interruptState    = DISABLE;
	mov	(_UART_config_tc_1_41 + 0x0001),#0x00
;	../src/uart.c:58: tc.interruptPriority = DISABLE;
	mov	(_UART_config_tc_1_41 + 0x0002),#0x00
;	../src/uart.c:59: tc.mode              = TIM_MODE_2;
	mov	(_UART_config_tc_1_41 + 0x0003),#0x02
;	../src/uart.c:60: tc.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM_1);
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	_UART_getTimerInitValue_PARM_2,#0x01
	mov	dpl,r3
	mov	dph,r4
	lcall	_UART_getTimerInitValue
	mov	a,dpl
	mov	b,dph
	mov	((_UART_config_tc_1_41 + 0x0004) + 0),a
	mov	((_UART_config_tc_1_41 + 0x0004) + 1),b
;	../src/uart.c:61: TIM_config(PERIPH_TIM_1,&tc);
	mov	_TIM_config_PARM_2,#_UART_config_tc_1_41
	mov	(_TIM_config_PARM_2 + 1),#0x00
	mov	(_TIM_config_PARM_2 + 2),#0x40
	mov	dpl,#0x01
	lcall	_TIM_config
;	../src/uart.c:62: TIM_cmd(PERIPH_TIM_1,ENABLE);
	mov	_TIM_cmd_PARM_2,#0x01
	mov	dpl,#0x01
;	../src/uart.c:63: break;
;	../src/uart.c:65: case PERIPH_TIM2:
	ljmp	_TIM_cmd
00102$:
;	../src/uart.c:66: tc2.function          = TIM2_FUNC_TIM;
	mov	_UART_config_tc2_1_41,#0x00
;	../src/uart.c:67: tc2.interruptState    = DISABLE;
	mov	(_UART_config_tc2_1_41 + 0x0001),#0x00
;	../src/uart.c:68: tc2.interruptPriority = DISABLE;
	mov	(_UART_config_tc2_1_41 + 0x0002),#0x00
;	../src/uart.c:69: tc2.mode              = TIM2_MODE_baudrateProducer;
	mov	(_UART_config_tc2_1_41 + 0x0003),#0x30
;	../src/uart.c:70: tc2.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM2);
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	_UART_getTimerInitValue_PARM_2,#0x02
	mov	dpl,r5
	mov	dph,r6
	lcall	_UART_getTimerInitValue
	mov	r6,dpl
	mov	r7,dph
	mov	((_UART_config_tc2_1_41 + 0x0004) + 0),r6
	mov	((_UART_config_tc2_1_41 + 0x0004) + 1),r7
;	../src/uart.c:71: RCAP2L = tc2.value;
	mov	_RCAP2L,r6
;	../src/uart.c:72: RCAP2H = (tc2.value >> 8);
	mov	_RCAP2H,r7
;	../src/uart.c:73: TIM2_config(&tc2);
	mov	dptr,#_UART_config_tc2_1_41
	mov	b,#0x40
	lcall	_TIM2_config
;	../src/uart.c:74: T2MOD = 0x02;
	mov	_T2MOD,#0x02
;	../src/uart.c:75: TIM2_cmd(ENABLE);
	mov	dpl,#0x01
;	../src/uart.c:79: }
	ljmp	_TIM2_cmd
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_getTimerInitValue'
;------------------------------------------------------------
;tim                       Allocated with name '_UART_getTimerInitValue_PARM_2'
;baud                      Allocated to registers r6 r7 
;tmp                       Allocated to registers r5 
;------------------------------------------------------------
;	../src/uart.c:88: unsigned int UART_getTimerInitValue(unsigned int baud,PERIPH_TIM tim)
;	-----------------------------------------
;	 function UART_getTimerInitValue
;	-----------------------------------------
_UART_getTimerInitValue:
	mov	r6,dpl
	mov	r7,dph
;	../src/uart.c:90: unsigned char tmp = 0x00;
	mov	r5,#0x00
;	../src/uart.c:93: switch(tim)
	mov	a,#0x01
	cjne	a,_UART_getTimerInitValue_PARM_2,00131$
	sjmp	00101$
00131$:
	mov	a,#0x02
	cjne	a,_UART_getTimerInitValue_PARM_2,00132$
	ljmp	00111$
00132$:
	ljmp	00113$
;	../src/uart.c:95: case PERIPH_TIM_1:
00101$:
;	../src/uart.c:96: if(PCON & 0x80)     /* multi baudrate mode */
	mov	a,_PCON
	jnb	acc.7,00109$
;	../src/uart.c:98: if(baud > _FRE_OSC_/12/16)
	mov	ar1,r6
	mov	ar2,r7
	mov	r3,#0x00
	mov	r4,#0x00
	clr	c
	clr	a
	subb	a,r1
	mov	a,#0xE1
	subb	a,r2
	clr	a
	subb	a,r3
	mov	a,#(0x00 ^ 0x80)
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	jnc	00103$
;	../src/uart.c:101: return 0x0000;
	mov	dptr,#0x0000
	ret
00103$:
;	../src/uart.c:105: tmp = (256 - _FRE_OSC_/16/12/baud);  
	mov	__divslong_PARM_2,r1
	mov	(__divslong_PARM_2 + 1),r2
	mov	(__divslong_PARM_2 + 2),r3
	mov	(__divslong_PARM_2 + 3),r4
	mov	dptr,#0xE100
	clr	a
	mov	b,a
	lcall	__divslong
	mov	r1,dpl
	mov	r2,dph
	mov	r3,b
	mov	r4,a
	clr	c
	clr	a
	subb	a,r1
	mov	r5,a
	sjmp	00113$
00109$:
;	../src/uart.c:110: if(baud > _FRE_OSC_/12/32)
	mov	ar1,r6
	mov	ar2,r7
	mov	r3,#0x00
	mov	r4,#0x00
	clr	c
	mov	a,#0x80
	subb	a,r1
	mov	a,#0x70
	subb	a,r2
	clr	a
	subb	a,r3
	mov	a,#(0x00 ^ 0x80)
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	jnc	00106$
;	../src/uart.c:112: return 0x0000;
	mov	dptr,#0x0000
	ret
00106$:
;	../src/uart.c:116: tmp = (256 - _FRE_OSC_/32/12/baud);
	mov	__divslong_PARM_2,r1
	mov	(__divslong_PARM_2 + 1),r2
	mov	(__divslong_PARM_2 + 2),r3
	mov	(__divslong_PARM_2 + 3),r4
	mov	dptr,#0x7080
	clr	a
	mov	b,a
	lcall	__divslong
	mov	r1,dpl
	mov	r2,dph
	mov	r3,b
	mov	r4,a
	clr	c
	clr	a
	subb	a,r1
	mov	r5,a
;	../src/uart.c:119: break;
;	../src/uart.c:121: case PERIPH_TIM2:
	sjmp	00113$
00111$:
;	../src/uart.c:122: return tmp = (65536 - (_FRE_OSC_/32/baud));
	mov	__divslong_PARM_2,r6
	mov	(__divslong_PARM_2 + 1),r7
	mov	(__divslong_PARM_2 + 2),#0x00
	mov	(__divslong_PARM_2 + 3),#0x00
	mov	dptr,#0x4600
	mov	b,#0x05
	clr	a
	lcall	__divslong
	mov	r3,dpl
	clr	c
	clr	a
	subb	a,r3
	mov	r3,a
	rlc	a
	subb	a,acc
	mov	r7,a
	mov	dpl,r3
	mov	dph,r7
;	../src/uart.c:126: }	
	ret
00113$:
;	../src/uart.c:127: return (tmp << 0x8) | tmp;
	mov	r7,#0x00
	mov	ar6,r5
	mov	r4,#0x00
	mov	a,r5
	orl	a,r4
	mov	dpl,a
	mov	a,r7
	orl	a,r6
	mov	dph,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_isReceived'
;------------------------------------------------------------
;	../src/uart.c:136: FunctionalState UART_isReceived(void)
;	-----------------------------------------
;	 function UART_isReceived
;	-----------------------------------------
_UART_isReceived:
;	../src/uart.c:138: return (FunctionalState)RI;
	mov	c,_RI
	clr	a
	rlc	a
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_isTransmitted'
;------------------------------------------------------------
;	../src/uart.c:147: FunctionalState UART_isTransmitted(void)
;	-----------------------------------------
;	 function UART_isTransmitted
;	-----------------------------------------
_UART_isTransmitted:
;	../src/uart.c:149: return (FunctionalState)TI;
	mov	c,_TI
	clr	a
	rlc	a
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_sendByte'
;------------------------------------------------------------
;dat                       Allocated to registers 
;------------------------------------------------------------
;	../src/uart.c:158: void UART_sendByte(unsigned char dat)
;	-----------------------------------------
;	 function UART_sendByte
;	-----------------------------------------
_UART_sendByte:
	mov	_SBUF,dpl
;	../src/uart.c:161: while(!TI);
00101$:
;	../src/uart.c:162: TI = RESET;
	jbc	_TI,00112$
	sjmp	00101$
00112$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_sendString'
;------------------------------------------------------------
;str                       Allocated to registers 
;------------------------------------------------------------
;	../src/uart.c:171: void UART_sendString(char *str)
;	-----------------------------------------
;	 function UART_sendString
;	-----------------------------------------
_UART_sendString:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	../src/uart.c:173: while(*str != '\0')
00104$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00107$
;	../src/uart.c:175: SBUF = *str;
	mov	_SBUF,r4
;	../src/uart.c:176: while(!TI);
00101$:
;	../src/uart.c:177: TI = RESET;     /* clear */
	jbc	_TI,00123$
	sjmp	00101$
00123$:
;	../src/uart.c:178: str++;
	inc	r5
	cjne	r5,#0x00,00104$
	inc	r6
	sjmp	00104$
00107$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_setMode'
;------------------------------------------------------------
;m                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/uart.c:188: void UART_setMode(UART_MODE m)
;	-----------------------------------------
;	 function UART_setMode
;	-----------------------------------------
_UART_setMode:
	mov	r7,dpl
;	../src/uart.c:190: SCON = (SCON & 0x3F) | ((unsigned char)m << 0x6);
	mov	a,#0x3F
	anl	a,_SCON
	mov	r6,a
	mov	a,r7
	rr	a
	rr	a
	anl	a,#0xC0
	orl	a,r6
	mov	_SCON,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_INT_setPriority'
;------------------------------------------------------------
;p                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/uart.c:199: void UART_INT_setPriority(INTR_PIOR p)
;	-----------------------------------------
;	 function UART_INT_setPriority
;	-----------------------------------------
_UART_INT_setPriority:
	mov	r7,dpl
;	../src/uart.c:201: IP = (IP & 0xEF) | ((p & 0x01) << 0x4);
	mov	a,#0xEF
	anl	a,_IP
	mov	r6,a
	mov	a,#0x01
	anl	a,r7
	swap	a
	anl	a,#0xF0
	orl	a,r6
	mov	_IP,a
;	../src/uart.c:202: IPH = (IPH & 0xEF) | ((p & 0x02) << 0x3);
	mov	a,#0xEF
	anl	a,_IPH
	mov	r6,a
	anl	ar7,#0x02
	mov	a,r7
	swap	a
	rr	a
	anl	a,#0xF8
	orl	a,r6
	mov	_IPH,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_INT_cmd'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	../src/uart.c:211: void UART_INT_cmd(Action a)
;	-----------------------------------------
;	 function UART_INT_cmd
;	-----------------------------------------
_UART_INT_cmd:
;	../src/uart.c:213: ES = a;
	mov	a,dpl
	add	a,#0xff
	mov	_ES,c
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
