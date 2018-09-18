                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jul 18 12:39:08 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module tim2
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _TF2
                                     13 	.globl _EXF2
                                     14 	.globl _RCLK
                                     15 	.globl _TCLK
                                     16 	.globl _EXEN2
                                     17 	.globl _TR2
                                     18 	.globl _CT2
                                     19 	.globl _CPRL2
                                     20 	.globl _P4_0
                                     21 	.globl _P4_1
                                     22 	.globl _P4_2
                                     23 	.globl _P4_3
                                     24 	.globl _PX3
                                     25 	.globl _EX3
                                     26 	.globl _IE3
                                     27 	.globl _IT3
                                     28 	.globl _PX2
                                     29 	.globl _EX2
                                     30 	.globl _IE2
                                     31 	.globl _IT2
                                     32 	.globl _CY
                                     33 	.globl _AC
                                     34 	.globl _F0
                                     35 	.globl _RS1
                                     36 	.globl _RS0
                                     37 	.globl _OV
                                     38 	.globl _F1
                                     39 	.globl _P
                                     40 	.globl _PS
                                     41 	.globl _PT1
                                     42 	.globl _PX1
                                     43 	.globl _PT0
                                     44 	.globl _PX0
                                     45 	.globl _RD
                                     46 	.globl _WR
                                     47 	.globl _T1
                                     48 	.globl _T0
                                     49 	.globl _INT1
                                     50 	.globl _INT0
                                     51 	.globl _TXD
                                     52 	.globl _RXD
                                     53 	.globl _P3_7
                                     54 	.globl _P3_6
                                     55 	.globl _P3_5
                                     56 	.globl _P3_4
                                     57 	.globl _P3_3
                                     58 	.globl _P3_2
                                     59 	.globl _P3_1
                                     60 	.globl _P3_0
                                     61 	.globl _EA
                                     62 	.globl _ES
                                     63 	.globl _ET1
                                     64 	.globl _EX1
                                     65 	.globl _ET0
                                     66 	.globl _EX0
                                     67 	.globl _P2_7
                                     68 	.globl _P2_6
                                     69 	.globl _P2_5
                                     70 	.globl _P2_4
                                     71 	.globl _P2_3
                                     72 	.globl _P2_2
                                     73 	.globl _P2_1
                                     74 	.globl _P2_0
                                     75 	.globl _SM0
                                     76 	.globl _SM1
                                     77 	.globl _SM2
                                     78 	.globl _REN
                                     79 	.globl _TB8
                                     80 	.globl _RB8
                                     81 	.globl _TI
                                     82 	.globl _RI
                                     83 	.globl _P1_7
                                     84 	.globl _P1_6
                                     85 	.globl _P1_5
                                     86 	.globl _P1_4
                                     87 	.globl _P1_3
                                     88 	.globl _P1_2
                                     89 	.globl _P1_1
                                     90 	.globl _P1_0
                                     91 	.globl _TF1
                                     92 	.globl _TR1
                                     93 	.globl _TF0
                                     94 	.globl _TR0
                                     95 	.globl _IE1
                                     96 	.globl _IT1
                                     97 	.globl _IE0
                                     98 	.globl _IT0
                                     99 	.globl _P0_7
                                    100 	.globl _P0_6
                                    101 	.globl _P0_5
                                    102 	.globl _P0_4
                                    103 	.globl _P0_3
                                    104 	.globl _P0_2
                                    105 	.globl _P0_1
                                    106 	.globl _P0_0
                                    107 	.globl _P4
                                    108 	.globl _ISP_CONTR
                                    109 	.globl _ISP_TRIG
                                    110 	.globl _ISP_CMD
                                    111 	.globl _ISP_ADDRL
                                    112 	.globl _ISP_ADDRH
                                    113 	.globl _ISP_DATA
                                    114 	.globl _WDT_CONTR
                                    115 	.globl _TH2
                                    116 	.globl _TL2
                                    117 	.globl _RCAP2H
                                    118 	.globl _RCAP2L
                                    119 	.globl _T2MOD
                                    120 	.globl _T2CON
                                    121 	.globl _XICON
                                    122 	.globl _IPH
                                    123 	.globl _SADDR1
                                    124 	.globl _AUXR1
                                    125 	.globl _AUXR
                                    126 	.globl _B
                                    127 	.globl _ACC
                                    128 	.globl _PSW
                                    129 	.globl _IP
                                    130 	.globl _P3
                                    131 	.globl _IE
                                    132 	.globl _P2
                                    133 	.globl _SBUF
                                    134 	.globl _SCON
                                    135 	.globl _P1
                                    136 	.globl _TH1
                                    137 	.globl _TH0
                                    138 	.globl _TL1
                                    139 	.globl _TL0
                                    140 	.globl _TMOD
                                    141 	.globl _TCON
                                    142 	.globl _PCON
                                    143 	.globl _DPH
                                    144 	.globl _DPL
                                    145 	.globl _SP
                                    146 	.globl _P0
                                    147 	.globl _TIM2_calculateValue
                                    148 	.globl _TIM2_clearFlag
                                    149 	.globl _TIM2_cmd
                                    150 	.globl _TIM2_config
                                    151 	.globl _TIM2_getValue
                                    152 	.globl _TIM2_isOverflow
                                    153 	.globl _TIM2_setFunction
                                    154 	.globl _TIM2_setMode
                                    155 	.globl _TIM2_setValue
                                    156 	.globl _TIM2_INT_cmd
                                    157 	.globl _TIM2_INT_setPriority
                                    158 	.globl _TIM2_INT_T2EX_cmd
                                    159 ;--------------------------------------------------------
                                    160 ; special function registers
                                    161 ;--------------------------------------------------------
                                    162 	.area RSEG    (ABS,DATA)
      000000                        163 	.org 0x0000
                           000080   164 _P0	=	0x0080
                           000081   165 _SP	=	0x0081
                           000082   166 _DPL	=	0x0082
                           000083   167 _DPH	=	0x0083
                           000087   168 _PCON	=	0x0087
                           000088   169 _TCON	=	0x0088
                           000089   170 _TMOD	=	0x0089
                           00008A   171 _TL0	=	0x008a
                           00008B   172 _TL1	=	0x008b
                           00008C   173 _TH0	=	0x008c
                           00008D   174 _TH1	=	0x008d
                           000090   175 _P1	=	0x0090
                           000098   176 _SCON	=	0x0098
                           000099   177 _SBUF	=	0x0099
                           0000A0   178 _P2	=	0x00a0
                           0000A8   179 _IE	=	0x00a8
                           0000B0   180 _P3	=	0x00b0
                           0000B8   181 _IP	=	0x00b8
                           0000D0   182 _PSW	=	0x00d0
                           0000E0   183 _ACC	=	0x00e0
                           0000F0   184 _B	=	0x00f0
                           00008E   185 _AUXR	=	0x008e
                           0000A2   186 _AUXR1	=	0x00a2
                           0000A9   187 _SADDR1	=	0x00a9
                           0000B7   188 _IPH	=	0x00b7
                           0000C0   189 _XICON	=	0x00c0
                           0000C8   190 _T2CON	=	0x00c8
                           0000C9   191 _T2MOD	=	0x00c9
                           0000CA   192 _RCAP2L	=	0x00ca
                           0000CB   193 _RCAP2H	=	0x00cb
                           0000CC   194 _TL2	=	0x00cc
                           0000CD   195 _TH2	=	0x00cd
                           0000E1   196 _WDT_CONTR	=	0x00e1
                           0000E2   197 _ISP_DATA	=	0x00e2
                           0000E3   198 _ISP_ADDRH	=	0x00e3
                           0000E4   199 _ISP_ADDRL	=	0x00e4
                           0000E5   200 _ISP_CMD	=	0x00e5
                           0000E6   201 _ISP_TRIG	=	0x00e6
                           0000E7   202 _ISP_CONTR	=	0x00e7
                           0000E8   203 _P4	=	0x00e8
                                    204 ;--------------------------------------------------------
                                    205 ; special function bits
                                    206 ;--------------------------------------------------------
                                    207 	.area RSEG    (ABS,DATA)
      000000                        208 	.org 0x0000
                           000080   209 _P0_0	=	0x0080
                           000081   210 _P0_1	=	0x0081
                           000082   211 _P0_2	=	0x0082
                           000083   212 _P0_3	=	0x0083
                           000084   213 _P0_4	=	0x0084
                           000085   214 _P0_5	=	0x0085
                           000086   215 _P0_6	=	0x0086
                           000087   216 _P0_7	=	0x0087
                           000088   217 _IT0	=	0x0088
                           000089   218 _IE0	=	0x0089
                           00008A   219 _IT1	=	0x008a
                           00008B   220 _IE1	=	0x008b
                           00008C   221 _TR0	=	0x008c
                           00008D   222 _TF0	=	0x008d
                           00008E   223 _TR1	=	0x008e
                           00008F   224 _TF1	=	0x008f
                           000090   225 _P1_0	=	0x0090
                           000091   226 _P1_1	=	0x0091
                           000092   227 _P1_2	=	0x0092
                           000093   228 _P1_3	=	0x0093
                           000094   229 _P1_4	=	0x0094
                           000095   230 _P1_5	=	0x0095
                           000096   231 _P1_6	=	0x0096
                           000097   232 _P1_7	=	0x0097
                           000098   233 _RI	=	0x0098
                           000099   234 _TI	=	0x0099
                           00009A   235 _RB8	=	0x009a
                           00009B   236 _TB8	=	0x009b
                           00009C   237 _REN	=	0x009c
                           00009D   238 _SM2	=	0x009d
                           00009E   239 _SM1	=	0x009e
                           00009F   240 _SM0	=	0x009f
                           0000A0   241 _P2_0	=	0x00a0
                           0000A1   242 _P2_1	=	0x00a1
                           0000A2   243 _P2_2	=	0x00a2
                           0000A3   244 _P2_3	=	0x00a3
                           0000A4   245 _P2_4	=	0x00a4
                           0000A5   246 _P2_5	=	0x00a5
                           0000A6   247 _P2_6	=	0x00a6
                           0000A7   248 _P2_7	=	0x00a7
                           0000A8   249 _EX0	=	0x00a8
                           0000A9   250 _ET0	=	0x00a9
                           0000AA   251 _EX1	=	0x00aa
                           0000AB   252 _ET1	=	0x00ab
                           0000AC   253 _ES	=	0x00ac
                           0000AF   254 _EA	=	0x00af
                           0000B0   255 _P3_0	=	0x00b0
                           0000B1   256 _P3_1	=	0x00b1
                           0000B2   257 _P3_2	=	0x00b2
                           0000B3   258 _P3_3	=	0x00b3
                           0000B4   259 _P3_4	=	0x00b4
                           0000B5   260 _P3_5	=	0x00b5
                           0000B6   261 _P3_6	=	0x00b6
                           0000B7   262 _P3_7	=	0x00b7
                           0000B0   263 _RXD	=	0x00b0
                           0000B1   264 _TXD	=	0x00b1
                           0000B2   265 _INT0	=	0x00b2
                           0000B3   266 _INT1	=	0x00b3
                           0000B4   267 _T0	=	0x00b4
                           0000B5   268 _T1	=	0x00b5
                           0000B6   269 _WR	=	0x00b6
                           0000B7   270 _RD	=	0x00b7
                           0000B8   271 _PX0	=	0x00b8
                           0000B9   272 _PT0	=	0x00b9
                           0000BA   273 _PX1	=	0x00ba
                           0000BB   274 _PT1	=	0x00bb
                           0000BC   275 _PS	=	0x00bc
                           0000D0   276 _P	=	0x00d0
                           0000D1   277 _F1	=	0x00d1
                           0000D2   278 _OV	=	0x00d2
                           0000D3   279 _RS0	=	0x00d3
                           0000D4   280 _RS1	=	0x00d4
                           0000D5   281 _F0	=	0x00d5
                           0000D6   282 _AC	=	0x00d6
                           0000D7   283 _CY	=	0x00d7
                           0000C0   284 _IT2	=	0x00c0
                           0000C1   285 _IE2	=	0x00c1
                           0000C2   286 _EX2	=	0x00c2
                           0000C3   287 _PX2	=	0x00c3
                           0000C4   288 _IT3	=	0x00c4
                           0000C5   289 _IE3	=	0x00c5
                           0000C6   290 _EX3	=	0x00c6
                           0000C7   291 _PX3	=	0x00c7
                           0000EB   292 _P4_3	=	0x00eb
                           0000EA   293 _P4_2	=	0x00ea
                           0000E9   294 _P4_1	=	0x00e9
                           0000E8   295 _P4_0	=	0x00e8
                           0000C8   296 _CPRL2	=	0x00c8
                           0000C9   297 _CT2	=	0x00c9
                           0000CA   298 _TR2	=	0x00ca
                           0000CB   299 _EXEN2	=	0x00cb
                           0000CC   300 _TCLK	=	0x00cc
                           0000CD   301 _RCLK	=	0x00cd
                           0000CE   302 _EXF2	=	0x00ce
                           0000CF   303 _TF2	=	0x00cf
                                    304 ;--------------------------------------------------------
                                    305 ; overlayable register banks
                                    306 ;--------------------------------------------------------
                                    307 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        308 	.ds 8
                                    309 ;--------------------------------------------------------
                                    310 ; internal ram data
                                    311 ;--------------------------------------------------------
                                    312 	.area DSEG    (DATA)
                                    313 ;--------------------------------------------------------
                                    314 ; overlayable items in internal ram 
                                    315 ;--------------------------------------------------------
                                    316 	.area	OSEG    (OVR,DATA)
                                    317 	.area	OSEG    (OVR,DATA)
                                    318 	.area	OSEG    (OVR,DATA)
                                    319 	.area	OSEG    (OVR,DATA)
                                    320 	.area	OSEG    (OVR,DATA)
                                    321 	.area	OSEG    (OVR,DATA)
                                    322 	.area	OSEG    (OVR,DATA)
                                    323 ;--------------------------------------------------------
                                    324 ; indirectly addressable internal ram data
                                    325 ;--------------------------------------------------------
                                    326 	.area ISEG    (DATA)
                                    327 ;--------------------------------------------------------
                                    328 ; absolute internal ram data
                                    329 ;--------------------------------------------------------
                                    330 	.area IABS    (ABS,DATA)
                                    331 	.area IABS    (ABS,DATA)
                                    332 ;--------------------------------------------------------
                                    333 ; bit data
                                    334 ;--------------------------------------------------------
                                    335 	.area BSEG    (BIT)
                                    336 ;--------------------------------------------------------
                                    337 ; paged external ram data
                                    338 ;--------------------------------------------------------
                                    339 	.area PSEG    (PAG,XDATA)
                                    340 ;--------------------------------------------------------
                                    341 ; external ram data
                                    342 ;--------------------------------------------------------
                                    343 	.area XSEG    (XDATA)
                                    344 ;--------------------------------------------------------
                                    345 ; absolute external ram data
                                    346 ;--------------------------------------------------------
                                    347 	.area XABS    (ABS,XDATA)
                                    348 ;--------------------------------------------------------
                                    349 ; external initialized ram data
                                    350 ;--------------------------------------------------------
                                    351 	.area XISEG   (XDATA)
                                    352 	.area HOME    (CODE)
                                    353 	.area GSINIT0 (CODE)
                                    354 	.area GSINIT1 (CODE)
                                    355 	.area GSINIT2 (CODE)
                                    356 	.area GSINIT3 (CODE)
                                    357 	.area GSINIT4 (CODE)
                                    358 	.area GSINIT5 (CODE)
                                    359 	.area GSINIT  (CODE)
                                    360 	.area GSFINAL (CODE)
                                    361 	.area CSEG    (CODE)
                                    362 ;--------------------------------------------------------
                                    363 ; global & static initialisations
                                    364 ;--------------------------------------------------------
                                    365 	.area HOME    (CODE)
                                    366 	.area GSINIT  (CODE)
                                    367 	.area GSFINAL (CODE)
                                    368 	.area GSINIT  (CODE)
                                    369 ;--------------------------------------------------------
                                    370 ; Home
                                    371 ;--------------------------------------------------------
                                    372 	.area HOME    (CODE)
                                    373 	.area HOME    (CODE)
                                    374 ;--------------------------------------------------------
                                    375 ; code
                                    376 ;--------------------------------------------------------
                                    377 	.area CSEG    (CODE)
                                    378 ;------------------------------------------------------------
                                    379 ;Allocation info for local variables in function 'TIM2_calculateValue'
                                    380 ;------------------------------------------------------------
                                    381 ;time                      Allocated to registers 
                                    382 ;MaxTick                   Allocated to registers 
                                    383 ;------------------------------------------------------------
                                    384 ;	../src/tim2.c:20: unsigned int TIM2_calculateValue(unsigned int time)
                                    385 ;	-----------------------------------------
                                    386 ;	 function TIM2_calculateValue
                                    387 ;	-----------------------------------------
      0006F1                        388 _TIM2_calculateValue:
                           000007   389 	ar7 = 0x07
                           000006   390 	ar6 = 0x06
                           000005   391 	ar5 = 0x05
                           000004   392 	ar4 = 0x04
                           000003   393 	ar3 = 0x03
                           000002   394 	ar2 = 0x02
                           000001   395 	ar1 = 0x01
                           000000   396 	ar0 = 0x00
      0006F1 85 82 1C         [24]  397 	mov	__mulint_PARM_2,dpl
      0006F4 85 83 1D         [24]  398 	mov	(__mulint_PARM_2 + 1),dph
                                    399 ;	../src/tim2.c:23: if((time*12)/(_FRE_OSC_/1000000) >= MaxTick ) return 0;
      0006F7 90 00 0C         [24]  400 	mov	dptr,#0x000C
      0006FA 12 0B D3         [24]  401 	lcall	__mulint
      0006FD AE 82            [24]  402 	mov	r6,dpl
      0006FF AF 83            [24]  403 	mov	r7,dph
      000701 7D 00            [12]  404 	mov	r5,#0x00
      000703 7C 00            [12]  405 	mov	r4,#0x00
      000705 75 1C 0B         [24]  406 	mov	__divslong_PARM_2,#0x0B
      000708 E4               [12]  407 	clr	a
      000709 F5 1D            [12]  408 	mov	(__divslong_PARM_2 + 1),a
      00070B F5 1E            [12]  409 	mov	(__divslong_PARM_2 + 2),a
      00070D F5 1F            [12]  410 	mov	(__divslong_PARM_2 + 3),a
      00070F 8E 82            [24]  411 	mov	dpl,r6
      000711 8F 83            [24]  412 	mov	dph,r7
      000713 8D F0            [24]  413 	mov	b,r5
      000715 EC               [12]  414 	mov	a,r4
      000716 12 0B F0         [24]  415 	lcall	__divslong
      000719 AC 82            [24]  416 	mov	r4,dpl
      00071B AD 83            [24]  417 	mov	r5,dph
      00071D AE F0            [24]  418 	mov	r6,b
      00071F FF               [12]  419 	mov	r7,a
      000720 C3               [12]  420 	clr	c
      000721 EC               [12]  421 	mov	a,r4
      000722 94 FF            [12]  422 	subb	a,#0xFF
      000724 ED               [12]  423 	mov	a,r5
      000725 94 FF            [12]  424 	subb	a,#0xFF
      000727 EE               [12]  425 	mov	a,r6
      000728 94 00            [12]  426 	subb	a,#0x00
      00072A EF               [12]  427 	mov	a,r7
      00072B 64 80            [12]  428 	xrl	a,#0x80
      00072D 94 80            [12]  429 	subb	a,#0x80
      00072F 40 04            [24]  430 	jc	00102$
      000731 90 00 00         [24]  431 	mov	dptr,#0x0000
      000734 22               [24]  432 	ret
      000735                        433 00102$:
                                    434 ;	../src/tim2.c:24: else return (MaxTick+1-((time*12)/(_FRE_OSC_/1000000)));
      000735 C3               [12]  435 	clr	c
      000736 E4               [12]  436 	clr	a
      000737 9C               [12]  437 	subb	a,r4
      000738 FC               [12]  438 	mov	r4,a
      000739 E4               [12]  439 	clr	a
      00073A 9D               [12]  440 	subb	a,r5
      00073B FD               [12]  441 	mov	r5,a
      00073C E4               [12]  442 	clr	a
      00073D 9E               [12]  443 	subb	a,r6
      00073E E4               [12]  444 	clr	a
      00073F 9F               [12]  445 	subb	a,r7
      000740 8C 82            [24]  446 	mov	dpl,r4
      000742 8D 83            [24]  447 	mov	dph,r5
      000744 22               [24]  448 	ret
                                    449 ;------------------------------------------------------------
                                    450 ;Allocation info for local variables in function 'TIM2_clearFlag'
                                    451 ;------------------------------------------------------------
                                    452 ;	../src/tim2.c:34: void TIM2_clearFlag(void)
                                    453 ;	-----------------------------------------
                                    454 ;	 function TIM2_clearFlag
                                    455 ;	-----------------------------------------
      000745                        456 _TIM2_clearFlag:
                                    457 ;	../src/tim2.c:36: T2CON = T2CON & 0x7F;
      000745 53 C8 7F         [24]  458 	anl	_T2CON,#0x7F
      000748 22               [24]  459 	ret
                                    460 ;------------------------------------------------------------
                                    461 ;Allocation info for local variables in function 'TIM2_cmd'
                                    462 ;------------------------------------------------------------
                                    463 ;a                         Allocated to registers r7 
                                    464 ;------------------------------------------------------------
                                    465 ;	../src/tim2.c:46: void TIM2_cmd(Action a)
                                    466 ;	-----------------------------------------
                                    467 ;	 function TIM2_cmd
                                    468 ;	-----------------------------------------
      000749                        469 _TIM2_cmd:
      000749 AF 82            [24]  470 	mov	r7,dpl
                                    471 ;	../src/tim2.c:48: T2CON = (T2CON & 0xFB) | (a << 2);
      00074B 74 FB            [12]  472 	mov	a,#0xFB
      00074D 55 C8            [12]  473 	anl	a,_T2CON
      00074F FE               [12]  474 	mov	r6,a
      000750 EF               [12]  475 	mov	a,r7
      000751 2F               [12]  476 	add	a,r7
      000752 25 E0            [12]  477 	add	a,acc
      000754 4E               [12]  478 	orl	a,r6
      000755 F5 C8            [12]  479 	mov	_T2CON,a
      000757 22               [24]  480 	ret
                                    481 ;------------------------------------------------------------
                                    482 ;Allocation info for local variables in function 'TIM2_config'
                                    483 ;------------------------------------------------------------
                                    484 ;tc                        Allocated to registers r5 r6 r7 
                                    485 ;------------------------------------------------------------
                                    486 ;	../src/tim2.c:58: void TIM2_config(TIM2_configTypeDef *tc)
                                    487 ;	-----------------------------------------
                                    488 ;	 function TIM2_config
                                    489 ;	-----------------------------------------
      000758                        490 _TIM2_config:
                                    491 ;	../src/tim2.c:60: TIM2_setFunction(tc->function);
      000758 AD 82            [24]  492 	mov	r5,dpl
      00075A AE 83            [24]  493 	mov	r6,dph
      00075C AF F0            [24]  494 	mov	r7,b
      00075E 12 0C 42         [24]  495 	lcall	__gptrget
      000761 F5 82            [12]  496 	mov	dpl,a
      000763 C0 07            [24]  497 	push	ar7
      000765 C0 06            [24]  498 	push	ar6
      000767 C0 05            [24]  499 	push	ar5
      000769 12 08 13         [24]  500 	lcall	_TIM2_setFunction
      00076C D0 05            [24]  501 	pop	ar5
      00076E D0 06            [24]  502 	pop	ar6
      000770 D0 07            [24]  503 	pop	ar7
                                    504 ;	../src/tim2.c:61: TIM2_setMode(tc->mode);
      000772 74 03            [12]  505 	mov	a,#0x03
      000774 2D               [12]  506 	add	a,r5
      000775 FA               [12]  507 	mov	r2,a
      000776 E4               [12]  508 	clr	a
      000777 3E               [12]  509 	addc	a,r6
      000778 FB               [12]  510 	mov	r3,a
      000779 8F 04            [24]  511 	mov	ar4,r7
      00077B 8A 82            [24]  512 	mov	dpl,r2
      00077D 8B 83            [24]  513 	mov	dph,r3
      00077F 8C F0            [24]  514 	mov	b,r4
      000781 12 0C 42         [24]  515 	lcall	__gptrget
      000784 F5 82            [12]  516 	mov	dpl,a
      000786 C0 07            [24]  517 	push	ar7
      000788 C0 06            [24]  518 	push	ar6
      00078A C0 05            [24]  519 	push	ar5
      00078C 12 08 1D         [24]  520 	lcall	_TIM2_setMode
      00078F D0 05            [24]  521 	pop	ar5
      000791 D0 06            [24]  522 	pop	ar6
      000793 D0 07            [24]  523 	pop	ar7
                                    524 ;	../src/tim2.c:62: TIM2_setValue(tc->value);
      000795 74 04            [12]  525 	mov	a,#0x04
      000797 2D               [12]  526 	add	a,r5
      000798 FA               [12]  527 	mov	r2,a
      000799 E4               [12]  528 	clr	a
      00079A 3E               [12]  529 	addc	a,r6
      00079B FB               [12]  530 	mov	r3,a
      00079C 8F 04            [24]  531 	mov	ar4,r7
      00079E 8A 82            [24]  532 	mov	dpl,r2
      0007A0 8B 83            [24]  533 	mov	dph,r3
      0007A2 8C F0            [24]  534 	mov	b,r4
      0007A4 12 0C 42         [24]  535 	lcall	__gptrget
      0007A7 FA               [12]  536 	mov	r2,a
      0007A8 A3               [24]  537 	inc	dptr
      0007A9 12 0C 42         [24]  538 	lcall	__gptrget
      0007AC FB               [12]  539 	mov	r3,a
      0007AD 8A 82            [24]  540 	mov	dpl,r2
      0007AF 8B 83            [24]  541 	mov	dph,r3
      0007B1 C0 07            [24]  542 	push	ar7
      0007B3 C0 06            [24]  543 	push	ar6
      0007B5 C0 05            [24]  544 	push	ar5
      0007B7 12 08 27         [24]  545 	lcall	_TIM2_setValue
      0007BA D0 05            [24]  546 	pop	ar5
      0007BC D0 06            [24]  547 	pop	ar6
      0007BE D0 07            [24]  548 	pop	ar7
                                    549 ;	../src/tim2.c:63: TIM2_INT_cmd(tc->interruptState);
      0007C0 74 01            [12]  550 	mov	a,#0x01
      0007C2 2D               [12]  551 	add	a,r5
      0007C3 FA               [12]  552 	mov	r2,a
      0007C4 E4               [12]  553 	clr	a
      0007C5 3E               [12]  554 	addc	a,r6
      0007C6 FB               [12]  555 	mov	r3,a
      0007C7 8F 04            [24]  556 	mov	ar4,r7
      0007C9 8A 82            [24]  557 	mov	dpl,r2
      0007CB 8B 83            [24]  558 	mov	dph,r3
      0007CD 8C F0            [24]  559 	mov	b,r4
      0007CF 12 0C 42         [24]  560 	lcall	__gptrget
      0007D2 F5 82            [12]  561 	mov	dpl,a
      0007D4 C0 07            [24]  562 	push	ar7
      0007D6 C0 06            [24]  563 	push	ar6
      0007D8 C0 05            [24]  564 	push	ar5
      0007DA 12 08 30         [24]  565 	lcall	_TIM2_INT_cmd
      0007DD D0 05            [24]  566 	pop	ar5
      0007DF D0 06            [24]  567 	pop	ar6
      0007E1 D0 07            [24]  568 	pop	ar7
                                    569 ;	../src/tim2.c:64: TIM2_INT_setPriority(tc->interruptPriority);
      0007E3 74 02            [12]  570 	mov	a,#0x02
      0007E5 2D               [12]  571 	add	a,r5
      0007E6 FD               [12]  572 	mov	r5,a
      0007E7 E4               [12]  573 	clr	a
      0007E8 3E               [12]  574 	addc	a,r6
      0007E9 FE               [12]  575 	mov	r6,a
      0007EA 8D 82            [24]  576 	mov	dpl,r5
      0007EC 8E 83            [24]  577 	mov	dph,r6
      0007EE 8F F0            [24]  578 	mov	b,r7
      0007F0 12 0C 42         [24]  579 	lcall	__gptrget
      0007F3 F5 82            [12]  580 	mov	dpl,a
      0007F5 02 08 40         [24]  581 	ljmp	_TIM2_INT_setPriority
                                    582 ;------------------------------------------------------------
                                    583 ;Allocation info for local variables in function 'TIM2_getValue'
                                    584 ;------------------------------------------------------------
                                    585 ;	../src/tim2.c:73: unsigned int TIM2_getValue(void)
                                    586 ;	-----------------------------------------
                                    587 ;	 function TIM2_getValue
                                    588 ;	-----------------------------------------
      0007F8                        589 _TIM2_getValue:
                                    590 ;	../src/tim2.c:75: return (unsigned int)((TH2 << 0x8) | TL2);
      0007F8 AF CD            [24]  591 	mov	r7,_TH2
      0007FA 7E 00            [12]  592 	mov	r6,#0x00
      0007FC AC CC            [24]  593 	mov	r4,_TL2
      0007FE 7D 00            [12]  594 	mov	r5,#0x00
      000800 EC               [12]  595 	mov	a,r4
      000801 42 06            [12]  596 	orl	ar6,a
      000803 ED               [12]  597 	mov	a,r5
      000804 42 07            [12]  598 	orl	ar7,a
      000806 8E 82            [24]  599 	mov	dpl,r6
      000808 8F 83            [24]  600 	mov	dph,r7
      00080A 22               [24]  601 	ret
                                    602 ;------------------------------------------------------------
                                    603 ;Allocation info for local variables in function 'TIM2_isOverflow'
                                    604 ;------------------------------------------------------------
                                    605 ;	../src/tim2.c:84: bool TIM2_isOverflow()
                                    606 ;	-----------------------------------------
                                    607 ;	 function TIM2_isOverflow
                                    608 ;	-----------------------------------------
      00080B                        609 _TIM2_isOverflow:
                                    610 ;	../src/tim2.c:86: return (bool)(T2CON >> 7);
      00080B E5 C8            [12]  611 	mov	a,_T2CON
      00080D 23               [12]  612 	rl	a
      00080E 54 01            [12]  613 	anl	a,#0x01
      000810 24 FF            [12]  614 	add	a,#0xff
      000812 22               [24]  615 	ret
                                    616 ;------------------------------------------------------------
                                    617 ;Allocation info for local variables in function 'TIM2_setFunction'
                                    618 ;------------------------------------------------------------
                                    619 ;f                         Allocated to registers r7 
                                    620 ;------------------------------------------------------------
                                    621 ;	../src/tim2.c:96: void TIM2_setFunction(TIM2_function f)
                                    622 ;	-----------------------------------------
                                    623 ;	 function TIM2_setFunction
                                    624 ;	-----------------------------------------
      000813                        625 _TIM2_setFunction:
      000813 AF 82            [24]  626 	mov	r7,dpl
                                    627 ;	../src/tim2.c:98: T2CON = (T2CON & 0XCF) | f;
      000815 74 CF            [12]  628 	mov	a,#0xCF
      000817 55 C8            [12]  629 	anl	a,_T2CON
      000819 4F               [12]  630 	orl	a,r7
      00081A F5 C8            [12]  631 	mov	_T2CON,a
      00081C 22               [24]  632 	ret
                                    633 ;------------------------------------------------------------
                                    634 ;Allocation info for local variables in function 'TIM2_setMode'
                                    635 ;------------------------------------------------------------
                                    636 ;m                         Allocated to registers r7 
                                    637 ;------------------------------------------------------------
                                    638 ;	../src/tim2.c:108: void TIM2_setMode(TIM2_mode m)
                                    639 ;	-----------------------------------------
                                    640 ;	 function TIM2_setMode
                                    641 ;	-----------------------------------------
      00081D                        642 _TIM2_setMode:
      00081D AF 82            [24]  643 	mov	r7,dpl
                                    644 ;	../src/tim2.c:110: T2CON = (T2CON & 0xCE) | m;
      00081F 74 CE            [12]  645 	mov	a,#0xCE
      000821 55 C8            [12]  646 	anl	a,_T2CON
      000823 4F               [12]  647 	orl	a,r7
      000824 F5 C8            [12]  648 	mov	_T2CON,a
      000826 22               [24]  649 	ret
                                    650 ;------------------------------------------------------------
                                    651 ;Allocation info for local variables in function 'TIM2_setValue'
                                    652 ;------------------------------------------------------------
                                    653 ;val                       Allocated to registers r6 r7 
                                    654 ;------------------------------------------------------------
                                    655 ;	../src/tim2.c:120: void TIM2_setValue(unsigned int val)
                                    656 ;	-----------------------------------------
                                    657 ;	 function TIM2_setValue
                                    658 ;	-----------------------------------------
      000827                        659 _TIM2_setValue:
      000827 AE 82            [24]  660 	mov	r6,dpl
      000829 AF 83            [24]  661 	mov	r7,dph
                                    662 ;	../src/tim2.c:122: TH2 = (val>>8);
      00082B 8F CD            [24]  663 	mov	_TH2,r7
                                    664 ;	../src/tim2.c:123: TL2 = val;
      00082D 8E CC            [24]  665 	mov	_TL2,r6
      00082F 22               [24]  666 	ret
                                    667 ;------------------------------------------------------------
                                    668 ;Allocation info for local variables in function 'TIM2_INT_cmd'
                                    669 ;------------------------------------------------------------
                                    670 ;a                         Allocated to registers r7 
                                    671 ;------------------------------------------------------------
                                    672 ;	../src/tim2.c:133: void TIM2_INT_cmd(Action a)
                                    673 ;	-----------------------------------------
                                    674 ;	 function TIM2_INT_cmd
                                    675 ;	-----------------------------------------
      000830                        676 _TIM2_INT_cmd:
      000830 AF 82            [24]  677 	mov	r7,dpl
                                    678 ;	../src/tim2.c:135: IE = (IE & 0xDF) | (a << 5);
      000832 74 DF            [12]  679 	mov	a,#0xDF
      000834 55 A8            [12]  680 	anl	a,_IE
      000836 FE               [12]  681 	mov	r6,a
      000837 EF               [12]  682 	mov	a,r7
      000838 C4               [12]  683 	swap	a
      000839 23               [12]  684 	rl	a
      00083A 54 E0            [12]  685 	anl	a,#0xE0
      00083C 4E               [12]  686 	orl	a,r6
      00083D F5 A8            [12]  687 	mov	_IE,a
      00083F 22               [24]  688 	ret
                                    689 ;------------------------------------------------------------
                                    690 ;Allocation info for local variables in function 'TIM2_INT_setPriority'
                                    691 ;------------------------------------------------------------
                                    692 ;p                         Allocated to registers r7 
                                    693 ;------------------------------------------------------------
                                    694 ;	../src/tim2.c:145: void TIM2_INT_setPriority(INTR_PIOR p)
                                    695 ;	-----------------------------------------
                                    696 ;	 function TIM2_INT_setPriority
                                    697 ;	-----------------------------------------
      000840                        698 _TIM2_INT_setPriority:
      000840 AF 82            [24]  699 	mov	r7,dpl
                                    700 ;	../src/tim2.c:147: IP = (IP & 0xDF) | ((p & 0x01) << 0x5);
      000842 74 DF            [12]  701 	mov	a,#0xDF
      000844 55 B8            [12]  702 	anl	a,_IP
      000846 FE               [12]  703 	mov	r6,a
      000847 74 01            [12]  704 	mov	a,#0x01
      000849 5F               [12]  705 	anl	a,r7
      00084A C4               [12]  706 	swap	a
      00084B 23               [12]  707 	rl	a
      00084C 54 E0            [12]  708 	anl	a,#0xE0
      00084E 4E               [12]  709 	orl	a,r6
      00084F F5 B8            [12]  710 	mov	_IP,a
                                    711 ;	../src/tim2.c:148: IPH = (IPH & 0xDF) | ((p & 0x02) << 0x4);
      000851 74 DF            [12]  712 	mov	a,#0xDF
      000853 55 B7            [12]  713 	anl	a,_IPH
      000855 FE               [12]  714 	mov	r6,a
      000856 53 07 02         [24]  715 	anl	ar7,#0x02
      000859 EF               [12]  716 	mov	a,r7
      00085A C4               [12]  717 	swap	a
      00085B 54 F0            [12]  718 	anl	a,#0xF0
      00085D 4E               [12]  719 	orl	a,r6
      00085E F5 B7            [12]  720 	mov	_IPH,a
      000860 22               [24]  721 	ret
                                    722 ;------------------------------------------------------------
                                    723 ;Allocation info for local variables in function 'TIM2_INT_T2EX_cmd'
                                    724 ;------------------------------------------------------------
                                    725 ;a                         Allocated to registers r7 
                                    726 ;------------------------------------------------------------
                                    727 ;	../src/tim2.c:158: void TIM2_INT_T2EX_cmd(Action a)
                                    728 ;	-----------------------------------------
                                    729 ;	 function TIM2_INT_T2EX_cmd
                                    730 ;	-----------------------------------------
      000861                        731 _TIM2_INT_T2EX_cmd:
      000861 AF 82            [24]  732 	mov	r7,dpl
                                    733 ;	../src/tim2.c:160: T2CON = (T2CON & 0xF7) | (a << 3);
      000863 74 F7            [12]  734 	mov	a,#0xF7
      000865 55 C8            [12]  735 	anl	a,_T2CON
      000867 FE               [12]  736 	mov	r6,a
      000868 EF               [12]  737 	mov	a,r7
      000869 C4               [12]  738 	swap	a
      00086A 03               [12]  739 	rr	a
      00086B 54 F8            [12]  740 	anl	a,#0xF8
      00086D 4E               [12]  741 	orl	a,r6
      00086E F5 C8            [12]  742 	mov	_T2CON,a
      000870 22               [24]  743 	ret
                                    744 	.area CSEG    (CODE)
                                    745 	.area CONST   (CODE)
                                    746 	.area XINIT   (CODE)
                                    747 	.area CABS    (ABS,CODE)
