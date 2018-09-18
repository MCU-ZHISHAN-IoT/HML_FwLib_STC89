                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jul 18 12:39:08 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module tim
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _TIM_INT_setPriority_PARM_2
                                     13 	.globl _TIM_INT_cmd_PARM_2
                                     14 	.globl _TIM_setValue_PARM_2
                                     15 	.globl _TIM_setMode_PARM_2
                                     16 	.globl _TIM_setFunction_PARM_2
                                     17 	.globl _TIM_cmd_PARM_2
                                     18 	.globl _TF2
                                     19 	.globl _EXF2
                                     20 	.globl _RCLK
                                     21 	.globl _TCLK
                                     22 	.globl _EXEN2
                                     23 	.globl _TR2
                                     24 	.globl _CT2
                                     25 	.globl _CPRL2
                                     26 	.globl _P4_0
                                     27 	.globl _P4_1
                                     28 	.globl _P4_2
                                     29 	.globl _P4_3
                                     30 	.globl _PX3
                                     31 	.globl _EX3
                                     32 	.globl _IE3
                                     33 	.globl _IT3
                                     34 	.globl _PX2
                                     35 	.globl _EX2
                                     36 	.globl _IE2
                                     37 	.globl _IT2
                                     38 	.globl _CY
                                     39 	.globl _AC
                                     40 	.globl _F0
                                     41 	.globl _RS1
                                     42 	.globl _RS0
                                     43 	.globl _OV
                                     44 	.globl _F1
                                     45 	.globl _P
                                     46 	.globl _PS
                                     47 	.globl _PT1
                                     48 	.globl _PX1
                                     49 	.globl _PT0
                                     50 	.globl _PX0
                                     51 	.globl _RD
                                     52 	.globl _WR
                                     53 	.globl _T1
                                     54 	.globl _T0
                                     55 	.globl _INT1
                                     56 	.globl _INT0
                                     57 	.globl _TXD
                                     58 	.globl _RXD
                                     59 	.globl _P3_7
                                     60 	.globl _P3_6
                                     61 	.globl _P3_5
                                     62 	.globl _P3_4
                                     63 	.globl _P3_3
                                     64 	.globl _P3_2
                                     65 	.globl _P3_1
                                     66 	.globl _P3_0
                                     67 	.globl _EA
                                     68 	.globl _ES
                                     69 	.globl _ET1
                                     70 	.globl _EX1
                                     71 	.globl _ET0
                                     72 	.globl _EX0
                                     73 	.globl _P2_7
                                     74 	.globl _P2_6
                                     75 	.globl _P2_5
                                     76 	.globl _P2_4
                                     77 	.globl _P2_3
                                     78 	.globl _P2_2
                                     79 	.globl _P2_1
                                     80 	.globl _P2_0
                                     81 	.globl _SM0
                                     82 	.globl _SM1
                                     83 	.globl _SM2
                                     84 	.globl _REN
                                     85 	.globl _TB8
                                     86 	.globl _RB8
                                     87 	.globl _TI
                                     88 	.globl _RI
                                     89 	.globl _P1_7
                                     90 	.globl _P1_6
                                     91 	.globl _P1_5
                                     92 	.globl _P1_4
                                     93 	.globl _P1_3
                                     94 	.globl _P1_2
                                     95 	.globl _P1_1
                                     96 	.globl _P1_0
                                     97 	.globl _TF1
                                     98 	.globl _TR1
                                     99 	.globl _TF0
                                    100 	.globl _TR0
                                    101 	.globl _IE1
                                    102 	.globl _IT1
                                    103 	.globl _IE0
                                    104 	.globl _IT0
                                    105 	.globl _P0_7
                                    106 	.globl _P0_6
                                    107 	.globl _P0_5
                                    108 	.globl _P0_4
                                    109 	.globl _P0_3
                                    110 	.globl _P0_2
                                    111 	.globl _P0_1
                                    112 	.globl _P0_0
                                    113 	.globl _P4
                                    114 	.globl _ISP_CONTR
                                    115 	.globl _ISP_TRIG
                                    116 	.globl _ISP_CMD
                                    117 	.globl _ISP_ADDRL
                                    118 	.globl _ISP_ADDRH
                                    119 	.globl _ISP_DATA
                                    120 	.globl _WDT_CONTR
                                    121 	.globl _TH2
                                    122 	.globl _TL2
                                    123 	.globl _RCAP2H
                                    124 	.globl _RCAP2L
                                    125 	.globl _T2MOD
                                    126 	.globl _T2CON
                                    127 	.globl _XICON
                                    128 	.globl _IPH
                                    129 	.globl _SADDR1
                                    130 	.globl _AUXR1
                                    131 	.globl _AUXR
                                    132 	.globl _B
                                    133 	.globl _ACC
                                    134 	.globl _PSW
                                    135 	.globl _IP
                                    136 	.globl _P3
                                    137 	.globl _IE
                                    138 	.globl _P2
                                    139 	.globl _SBUF
                                    140 	.globl _SCON
                                    141 	.globl _P1
                                    142 	.globl _TH1
                                    143 	.globl _TH0
                                    144 	.globl _TL1
                                    145 	.globl _TL0
                                    146 	.globl _TMOD
                                    147 	.globl _TCON
                                    148 	.globl _PCON
                                    149 	.globl _DPH
                                    150 	.globl _DPL
                                    151 	.globl _SP
                                    152 	.globl _P0
                                    153 	.globl _TIM_config_PARM_2
                                    154 	.globl _TIM_calculateValue_PARM_2
                                    155 	.globl _TIM_calculateValue
                                    156 	.globl _TIM_cmd
                                    157 	.globl _TIM_config
                                    158 	.globl _TIM_getValue
                                    159 	.globl _TIM_isOverflow
                                    160 	.globl _TIM_setFunction
                                    161 	.globl _TIM_setMode
                                    162 	.globl _TIM_setValue
                                    163 	.globl _TIM_INT_cmd
                                    164 	.globl _TIM_INT_setPriority
                                    165 ;--------------------------------------------------------
                                    166 ; special function registers
                                    167 ;--------------------------------------------------------
                                    168 	.area RSEG    (ABS,DATA)
      000000                        169 	.org 0x0000
                           000080   170 _P0	=	0x0080
                           000081   171 _SP	=	0x0081
                           000082   172 _DPL	=	0x0082
                           000083   173 _DPH	=	0x0083
                           000087   174 _PCON	=	0x0087
                           000088   175 _TCON	=	0x0088
                           000089   176 _TMOD	=	0x0089
                           00008A   177 _TL0	=	0x008a
                           00008B   178 _TL1	=	0x008b
                           00008C   179 _TH0	=	0x008c
                           00008D   180 _TH1	=	0x008d
                           000090   181 _P1	=	0x0090
                           000098   182 _SCON	=	0x0098
                           000099   183 _SBUF	=	0x0099
                           0000A0   184 _P2	=	0x00a0
                           0000A8   185 _IE	=	0x00a8
                           0000B0   186 _P3	=	0x00b0
                           0000B8   187 _IP	=	0x00b8
                           0000D0   188 _PSW	=	0x00d0
                           0000E0   189 _ACC	=	0x00e0
                           0000F0   190 _B	=	0x00f0
                           00008E   191 _AUXR	=	0x008e
                           0000A2   192 _AUXR1	=	0x00a2
                           0000A9   193 _SADDR1	=	0x00a9
                           0000B7   194 _IPH	=	0x00b7
                           0000C0   195 _XICON	=	0x00c0
                           0000C8   196 _T2CON	=	0x00c8
                           0000C9   197 _T2MOD	=	0x00c9
                           0000CA   198 _RCAP2L	=	0x00ca
                           0000CB   199 _RCAP2H	=	0x00cb
                           0000CC   200 _TL2	=	0x00cc
                           0000CD   201 _TH2	=	0x00cd
                           0000E1   202 _WDT_CONTR	=	0x00e1
                           0000E2   203 _ISP_DATA	=	0x00e2
                           0000E3   204 _ISP_ADDRH	=	0x00e3
                           0000E4   205 _ISP_ADDRL	=	0x00e4
                           0000E5   206 _ISP_CMD	=	0x00e5
                           0000E6   207 _ISP_TRIG	=	0x00e6
                           0000E7   208 _ISP_CONTR	=	0x00e7
                           0000E8   209 _P4	=	0x00e8
                                    210 ;--------------------------------------------------------
                                    211 ; special function bits
                                    212 ;--------------------------------------------------------
                                    213 	.area RSEG    (ABS,DATA)
      000000                        214 	.org 0x0000
                           000080   215 _P0_0	=	0x0080
                           000081   216 _P0_1	=	0x0081
                           000082   217 _P0_2	=	0x0082
                           000083   218 _P0_3	=	0x0083
                           000084   219 _P0_4	=	0x0084
                           000085   220 _P0_5	=	0x0085
                           000086   221 _P0_6	=	0x0086
                           000087   222 _P0_7	=	0x0087
                           000088   223 _IT0	=	0x0088
                           000089   224 _IE0	=	0x0089
                           00008A   225 _IT1	=	0x008a
                           00008B   226 _IE1	=	0x008b
                           00008C   227 _TR0	=	0x008c
                           00008D   228 _TF0	=	0x008d
                           00008E   229 _TR1	=	0x008e
                           00008F   230 _TF1	=	0x008f
                           000090   231 _P1_0	=	0x0090
                           000091   232 _P1_1	=	0x0091
                           000092   233 _P1_2	=	0x0092
                           000093   234 _P1_3	=	0x0093
                           000094   235 _P1_4	=	0x0094
                           000095   236 _P1_5	=	0x0095
                           000096   237 _P1_6	=	0x0096
                           000097   238 _P1_7	=	0x0097
                           000098   239 _RI	=	0x0098
                           000099   240 _TI	=	0x0099
                           00009A   241 _RB8	=	0x009a
                           00009B   242 _TB8	=	0x009b
                           00009C   243 _REN	=	0x009c
                           00009D   244 _SM2	=	0x009d
                           00009E   245 _SM1	=	0x009e
                           00009F   246 _SM0	=	0x009f
                           0000A0   247 _P2_0	=	0x00a0
                           0000A1   248 _P2_1	=	0x00a1
                           0000A2   249 _P2_2	=	0x00a2
                           0000A3   250 _P2_3	=	0x00a3
                           0000A4   251 _P2_4	=	0x00a4
                           0000A5   252 _P2_5	=	0x00a5
                           0000A6   253 _P2_6	=	0x00a6
                           0000A7   254 _P2_7	=	0x00a7
                           0000A8   255 _EX0	=	0x00a8
                           0000A9   256 _ET0	=	0x00a9
                           0000AA   257 _EX1	=	0x00aa
                           0000AB   258 _ET1	=	0x00ab
                           0000AC   259 _ES	=	0x00ac
                           0000AF   260 _EA	=	0x00af
                           0000B0   261 _P3_0	=	0x00b0
                           0000B1   262 _P3_1	=	0x00b1
                           0000B2   263 _P3_2	=	0x00b2
                           0000B3   264 _P3_3	=	0x00b3
                           0000B4   265 _P3_4	=	0x00b4
                           0000B5   266 _P3_5	=	0x00b5
                           0000B6   267 _P3_6	=	0x00b6
                           0000B7   268 _P3_7	=	0x00b7
                           0000B0   269 _RXD	=	0x00b0
                           0000B1   270 _TXD	=	0x00b1
                           0000B2   271 _INT0	=	0x00b2
                           0000B3   272 _INT1	=	0x00b3
                           0000B4   273 _T0	=	0x00b4
                           0000B5   274 _T1	=	0x00b5
                           0000B6   275 _WR	=	0x00b6
                           0000B7   276 _RD	=	0x00b7
                           0000B8   277 _PX0	=	0x00b8
                           0000B9   278 _PT0	=	0x00b9
                           0000BA   279 _PX1	=	0x00ba
                           0000BB   280 _PT1	=	0x00bb
                           0000BC   281 _PS	=	0x00bc
                           0000D0   282 _P	=	0x00d0
                           0000D1   283 _F1	=	0x00d1
                           0000D2   284 _OV	=	0x00d2
                           0000D3   285 _RS0	=	0x00d3
                           0000D4   286 _RS1	=	0x00d4
                           0000D5   287 _F0	=	0x00d5
                           0000D6   288 _AC	=	0x00d6
                           0000D7   289 _CY	=	0x00d7
                           0000C0   290 _IT2	=	0x00c0
                           0000C1   291 _IE2	=	0x00c1
                           0000C2   292 _EX2	=	0x00c2
                           0000C3   293 _PX2	=	0x00c3
                           0000C4   294 _IT3	=	0x00c4
                           0000C5   295 _IE3	=	0x00c5
                           0000C6   296 _EX3	=	0x00c6
                           0000C7   297 _PX3	=	0x00c7
                           0000EB   298 _P4_3	=	0x00eb
                           0000EA   299 _P4_2	=	0x00ea
                           0000E9   300 _P4_1	=	0x00e9
                           0000E8   301 _P4_0	=	0x00e8
                           0000C8   302 _CPRL2	=	0x00c8
                           0000C9   303 _CT2	=	0x00c9
                           0000CA   304 _TR2	=	0x00ca
                           0000CB   305 _EXEN2	=	0x00cb
                           0000CC   306 _TCLK	=	0x00cc
                           0000CD   307 _RCLK	=	0x00cd
                           0000CE   308 _EXF2	=	0x00ce
                           0000CF   309 _TF2	=	0x00cf
                                    310 ;--------------------------------------------------------
                                    311 ; overlayable register banks
                                    312 ;--------------------------------------------------------
                                    313 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        314 	.ds 8
                                    315 ;--------------------------------------------------------
                                    316 ; internal ram data
                                    317 ;--------------------------------------------------------
                                    318 	.area DSEG    (DATA)
      000016                        319 _TIM_calculateValue_PARM_2:
      000016                        320 	.ds 1
      000017                        321 _TIM_calculateValue_MaxTick_1_16:
      000017                        322 	.ds 2
      000019                        323 _TIM_config_PARM_2:
      000019                        324 	.ds 3
                                    325 ;--------------------------------------------------------
                                    326 ; overlayable items in internal ram 
                                    327 ;--------------------------------------------------------
                                    328 	.area	OSEG    (OVR,DATA)
      00001C                        329 _TIM_cmd_PARM_2:
      00001C                        330 	.ds 1
                                    331 	.area	OSEG    (OVR,DATA)
                                    332 	.area	OSEG    (OVR,DATA)
                                    333 	.area	OSEG    (OVR,DATA)
      00001C                        334 _TIM_setFunction_PARM_2:
      00001C                        335 	.ds 1
                                    336 	.area	OSEG    (OVR,DATA)
      00001C                        337 _TIM_setMode_PARM_2:
      00001C                        338 	.ds 1
                                    339 	.area	OSEG    (OVR,DATA)
      00001C                        340 _TIM_setValue_PARM_2:
      00001C                        341 	.ds 2
                                    342 	.area	OSEG    (OVR,DATA)
      00001C                        343 _TIM_INT_cmd_PARM_2:
      00001C                        344 	.ds 1
                                    345 	.area	OSEG    (OVR,DATA)
      00001C                        346 _TIM_INT_setPriority_PARM_2:
      00001C                        347 	.ds 1
                                    348 ;--------------------------------------------------------
                                    349 ; indirectly addressable internal ram data
                                    350 ;--------------------------------------------------------
                                    351 	.area ISEG    (DATA)
                                    352 ;--------------------------------------------------------
                                    353 ; absolute internal ram data
                                    354 ;--------------------------------------------------------
                                    355 	.area IABS    (ABS,DATA)
                                    356 	.area IABS    (ABS,DATA)
                                    357 ;--------------------------------------------------------
                                    358 ; bit data
                                    359 ;--------------------------------------------------------
                                    360 	.area BSEG    (BIT)
                                    361 ;--------------------------------------------------------
                                    362 ; paged external ram data
                                    363 ;--------------------------------------------------------
                                    364 	.area PSEG    (PAG,XDATA)
                                    365 ;--------------------------------------------------------
                                    366 ; external ram data
                                    367 ;--------------------------------------------------------
                                    368 	.area XSEG    (XDATA)
                                    369 ;--------------------------------------------------------
                                    370 ; absolute external ram data
                                    371 ;--------------------------------------------------------
                                    372 	.area XABS    (ABS,XDATA)
                                    373 ;--------------------------------------------------------
                                    374 ; external initialized ram data
                                    375 ;--------------------------------------------------------
                                    376 	.area XISEG   (XDATA)
                                    377 	.area HOME    (CODE)
                                    378 	.area GSINIT0 (CODE)
                                    379 	.area GSINIT1 (CODE)
                                    380 	.area GSINIT2 (CODE)
                                    381 	.area GSINIT3 (CODE)
                                    382 	.area GSINIT4 (CODE)
                                    383 	.area GSINIT5 (CODE)
                                    384 	.area GSINIT  (CODE)
                                    385 	.area GSFINAL (CODE)
                                    386 	.area CSEG    (CODE)
                                    387 ;--------------------------------------------------------
                                    388 ; global & static initialisations
                                    389 ;--------------------------------------------------------
                                    390 	.area HOME    (CODE)
                                    391 	.area GSINIT  (CODE)
                                    392 	.area GSFINAL (CODE)
                                    393 	.area GSINIT  (CODE)
                                    394 ;--------------------------------------------------------
                                    395 ; Home
                                    396 ;--------------------------------------------------------
                                    397 	.area HOME    (CODE)
                                    398 	.area HOME    (CODE)
                                    399 ;--------------------------------------------------------
                                    400 ; code
                                    401 ;--------------------------------------------------------
                                    402 	.area CSEG    (CODE)
                                    403 ;------------------------------------------------------------
                                    404 ;Allocation info for local variables in function 'TIM_calculateValue'
                                    405 ;------------------------------------------------------------
                                    406 ;m                         Allocated with name '_TIM_calculateValue_PARM_2'
                                    407 ;time                      Allocated to registers r6 r7 
                                    408 ;MaxTick                   Allocated with name '_TIM_calculateValue_MaxTick_1_16'
                                    409 ;------------------------------------------------------------
                                    410 ;	../src/tim.c:22: unsigned int TIM_calculateValue(unsigned int time,TIM_mode m)
                                    411 ;	-----------------------------------------
                                    412 ;	 function TIM_calculateValue
                                    413 ;	-----------------------------------------
      00044E                        414 _TIM_calculateValue:
                           000007   415 	ar7 = 0x07
                           000006   416 	ar6 = 0x06
                           000005   417 	ar5 = 0x05
                           000004   418 	ar4 = 0x04
                           000003   419 	ar3 = 0x03
                           000002   420 	ar2 = 0x02
                           000001   421 	ar1 = 0x01
                           000000   422 	ar0 = 0x00
      00044E AE 82            [24]  423 	mov	r6,dpl
      000450 AF 83            [24]  424 	mov	r7,dph
                                    425 ;	../src/tim.c:25: unsigned int MaxTick = 0x0000;
      000452 E4               [12]  426 	clr	a
      000453 F5 17            [12]  427 	mov	_TIM_calculateValue_MaxTick_1_16,a
      000455 F5 18            [12]  428 	mov	(_TIM_calculateValue_MaxTick_1_16 + 1),a
                                    429 ;	../src/tim.c:26: switch(m)
      000457 E5 16            [12]  430 	mov	a,_TIM_calculateValue_PARM_2
      000459 24 FC            [12]  431 	add	a,#0xff - 0x03
      00045B 40 34            [24]  432 	jc	00106$
      00045D E5 16            [12]  433 	mov	a,_TIM_calculateValue_PARM_2
      00045F 75 F0 03         [24]  434 	mov	b,#0x03
      000462 A4               [48]  435 	mul	ab
      000463 90 04 67         [24]  436 	mov	dptr,#00119$
      000466 73               [24]  437 	jmp	@a+dptr
      000467                        438 00119$:
      000467 02 04 73         [24]  439 	ljmp	00101$
      00046A 02 04 7B         [24]  440 	ljmp	00102$
      00046D 02 04 83         [24]  441 	ljmp	00103$
      000470 02 04 8B         [24]  442 	ljmp	00104$
                                    443 ;	../src/tim.c:28: case TIM_MODE_0:MaxTick = 0x1FFF;break; //(1<<13)-1
      000473                        444 00101$:
      000473 75 17 FF         [24]  445 	mov	_TIM_calculateValue_MaxTick_1_16,#0xFF
      000476 75 18 1F         [24]  446 	mov	(_TIM_calculateValue_MaxTick_1_16 + 1),#0x1F
                                    447 ;	../src/tim.c:29: case TIM_MODE_1:MaxTick = 0xFFFF;break; //(1<<16)-1
      000479 80 16            [24]  448 	sjmp	00106$
      00047B                        449 00102$:
      00047B 75 17 FF         [24]  450 	mov	_TIM_calculateValue_MaxTick_1_16,#0xFF
      00047E 75 18 FF         [24]  451 	mov	(_TIM_calculateValue_MaxTick_1_16 + 1),#0xFF
                                    452 ;	../src/tim.c:30: case TIM_MODE_2:MaxTick = 0x00FF;break; //(1<<8)-1
      000481 80 0E            [24]  453 	sjmp	00106$
      000483                        454 00103$:
      000483 75 17 FF         [24]  455 	mov	_TIM_calculateValue_MaxTick_1_16,#0xFF
      000486 75 18 00         [24]  456 	mov	(_TIM_calculateValue_MaxTick_1_16 + 1),#0x00
                                    457 ;	../src/tim.c:31: case TIM_MODE_3:MaxTick = 0x00FF;break; //(1<<8)-1
      000489 80 06            [24]  458 	sjmp	00106$
      00048B                        459 00104$:
      00048B 75 17 FF         [24]  460 	mov	_TIM_calculateValue_MaxTick_1_16,#0xFF
      00048E 75 18 00         [24]  461 	mov	(_TIM_calculateValue_MaxTick_1_16 + 1),#0x00
                                    462 ;	../src/tim.c:33: }
      000491                        463 00106$:
                                    464 ;	../src/tim.c:34: if((time*12)/(_FRE_OSC_/1000000) >= MaxTick ) return 0;
      000491 8E 1C            [24]  465 	mov	__mulint_PARM_2,r6
      000493 8F 1D            [24]  466 	mov	(__mulint_PARM_2 + 1),r7
      000495 90 00 0C         [24]  467 	mov	dptr,#0x000C
      000498 12 0B D3         [24]  468 	lcall	__mulint
      00049B AE 82            [24]  469 	mov	r6,dpl
      00049D AF 83            [24]  470 	mov	r7,dph
      00049F 7B 00            [12]  471 	mov	r3,#0x00
      0004A1 7A 00            [12]  472 	mov	r2,#0x00
      0004A3 75 1C 0B         [24]  473 	mov	__divslong_PARM_2,#0x0B
      0004A6 E4               [12]  474 	clr	a
      0004A7 F5 1D            [12]  475 	mov	(__divslong_PARM_2 + 1),a
      0004A9 F5 1E            [12]  476 	mov	(__divslong_PARM_2 + 2),a
      0004AB F5 1F            [12]  477 	mov	(__divslong_PARM_2 + 3),a
      0004AD 8E 82            [24]  478 	mov	dpl,r6
      0004AF 8F 83            [24]  479 	mov	dph,r7
      0004B1 8B F0            [24]  480 	mov	b,r3
      0004B3 EA               [12]  481 	mov	a,r2
      0004B4 12 0B F0         [24]  482 	lcall	__divslong
      0004B7 AA 82            [24]  483 	mov	r2,dpl
      0004B9 AB 83            [24]  484 	mov	r3,dph
      0004BB AE F0            [24]  485 	mov	r6,b
      0004BD FF               [12]  486 	mov	r7,a
      0004BE A8 17            [24]  487 	mov	r0,_TIM_calculateValue_MaxTick_1_16
      0004C0 A9 18            [24]  488 	mov	r1,(_TIM_calculateValue_MaxTick_1_16 + 1)
      0004C2 7C 00            [12]  489 	mov	r4,#0x00
      0004C4 7D 00            [12]  490 	mov	r5,#0x00
      0004C6 C3               [12]  491 	clr	c
      0004C7 EA               [12]  492 	mov	a,r2
      0004C8 98               [12]  493 	subb	a,r0
      0004C9 EB               [12]  494 	mov	a,r3
      0004CA 99               [12]  495 	subb	a,r1
      0004CB EE               [12]  496 	mov	a,r6
      0004CC 9C               [12]  497 	subb	a,r4
      0004CD EF               [12]  498 	mov	a,r7
      0004CE 64 80            [12]  499 	xrl	a,#0x80
      0004D0 8D F0            [24]  500 	mov	b,r5
      0004D2 63 F0 80         [24]  501 	xrl	b,#0x80
      0004D5 95 F0            [12]  502 	subb	a,b
      0004D7 40 04            [24]  503 	jc	00108$
      0004D9 90 00 00         [24]  504 	mov	dptr,#0x0000
      0004DC 22               [24]  505 	ret
      0004DD                        506 00108$:
                                    507 ;	../src/tim.c:35: else return (MaxTick+1-((time*12)/(_FRE_OSC_/1000000)));
      0004DD 74 01            [12]  508 	mov	a,#0x01
      0004DF 25 17            [12]  509 	add	a,_TIM_calculateValue_MaxTick_1_16
      0004E1 FC               [12]  510 	mov	r4,a
      0004E2 E4               [12]  511 	clr	a
      0004E3 35 18            [12]  512 	addc	a,(_TIM_calculateValue_MaxTick_1_16 + 1)
      0004E5 FD               [12]  513 	mov	r5,a
      0004E6 8C 00            [24]  514 	mov	ar0,r4
      0004E8 8D 01            [24]  515 	mov	ar1,r5
      0004EA E4               [12]  516 	clr	a
      0004EB FC               [12]  517 	mov	r4,a
      0004EC FD               [12]  518 	mov	r5,a
      0004ED E8               [12]  519 	mov	a,r0
      0004EE C3               [12]  520 	clr	c
      0004EF 9A               [12]  521 	subb	a,r2
      0004F0 FA               [12]  522 	mov	r2,a
      0004F1 E9               [12]  523 	mov	a,r1
      0004F2 9B               [12]  524 	subb	a,r3
      0004F3 FB               [12]  525 	mov	r3,a
      0004F4 EC               [12]  526 	mov	a,r4
      0004F5 9E               [12]  527 	subb	a,r6
      0004F6 ED               [12]  528 	mov	a,r5
      0004F7 9F               [12]  529 	subb	a,r7
      0004F8 8A 82            [24]  530 	mov	dpl,r2
      0004FA 8B 83            [24]  531 	mov	dph,r3
      0004FC 22               [24]  532 	ret
                                    533 ;------------------------------------------------------------
                                    534 ;Allocation info for local variables in function 'TIM_cmd'
                                    535 ;------------------------------------------------------------
                                    536 ;a                         Allocated with name '_TIM_cmd_PARM_2'
                                    537 ;tim                       Allocated to registers r7 
                                    538 ;------------------------------------------------------------
                                    539 ;	../src/tim.c:46: void TIM_cmd(PERIPH_TIM tim,Action a)
                                    540 ;	-----------------------------------------
                                    541 ;	 function TIM_cmd
                                    542 ;	-----------------------------------------
      0004FD                        543 _TIM_cmd:
      0004FD AF 82            [24]  544 	mov	r7,dpl
                                    545 ;	../src/tim.c:48: switch(tim)
      0004FF BF 00 02         [24]  546 	cjne	r7,#0x00,00113$
      000502 80 05            [24]  547 	sjmp	00101$
      000504                        548 00113$:
                                    549 ;	../src/tim.c:50: case PERIPH_TIM_0:TR0 = a;break;
      000504 BF 01 0F         [24]  550 	cjne	r7,#0x01,00105$
      000507 80 07            [24]  551 	sjmp	00102$
      000509                        552 00101$:
      000509 E5 1C            [12]  553 	mov	a,_TIM_cmd_PARM_2
      00050B 24 FF            [12]  554 	add	a,#0xff
      00050D 92 8C            [24]  555 	mov	_TR0,c
                                    556 ;	../src/tim.c:51: case PERIPH_TIM_1:TR1 = a;break;
      00050F 22               [24]  557 	ret
      000510                        558 00102$:
      000510 E5 1C            [12]  559 	mov	a,_TIM_cmd_PARM_2
      000512 24 FF            [12]  560 	add	a,#0xff
      000514 92 8E            [24]  561 	mov	_TR1,c
                                    562 ;	../src/tim.c:53: }
      000516                        563 00105$:
      000516 22               [24]  564 	ret
                                    565 ;------------------------------------------------------------
                                    566 ;Allocation info for local variables in function 'TIM_config'
                                    567 ;------------------------------------------------------------
                                    568 ;tc                        Allocated with name '_TIM_config_PARM_2'
                                    569 ;tim                       Allocated to registers r7 
                                    570 ;------------------------------------------------------------
                                    571 ;	../src/tim.c:64: void TIM_config(PERIPH_TIM tim,TIM_configTypeDef *tc)
                                    572 ;	-----------------------------------------
                                    573 ;	 function TIM_config
                                    574 ;	-----------------------------------------
      000517                        575 _TIM_config:
      000517 AF 82            [24]  576 	mov	r7,dpl
                                    577 ;	../src/tim.c:66: TIM_setFunction(tim,tc->function);
      000519 AC 19            [24]  578 	mov	r4,_TIM_config_PARM_2
      00051B AD 1A            [24]  579 	mov	r5,(_TIM_config_PARM_2 + 1)
      00051D AE 1B            [24]  580 	mov	r6,(_TIM_config_PARM_2 + 2)
      00051F 8C 82            [24]  581 	mov	dpl,r4
      000521 8D 83            [24]  582 	mov	dph,r5
      000523 8E F0            [24]  583 	mov	b,r6
      000525 12 0C 42         [24]  584 	lcall	__gptrget
      000528 F5 1C            [12]  585 	mov	_TIM_setFunction_PARM_2,a
      00052A 8F 82            [24]  586 	mov	dpl,r7
      00052C C0 07            [24]  587 	push	ar7
      00052E C0 06            [24]  588 	push	ar6
      000530 C0 05            [24]  589 	push	ar5
      000532 C0 04            [24]  590 	push	ar4
      000534 12 06 1D         [24]  591 	lcall	_TIM_setFunction
      000537 D0 04            [24]  592 	pop	ar4
      000539 D0 05            [24]  593 	pop	ar5
      00053B D0 06            [24]  594 	pop	ar6
      00053D D0 07            [24]  595 	pop	ar7
                                    596 ;	../src/tim.c:67: TIM_setMode(tim,tc->mode);
      00053F 74 03            [12]  597 	mov	a,#0x03
      000541 2C               [12]  598 	add	a,r4
      000542 F9               [12]  599 	mov	r1,a
      000543 E4               [12]  600 	clr	a
      000544 3D               [12]  601 	addc	a,r5
      000545 FA               [12]  602 	mov	r2,a
      000546 8E 03            [24]  603 	mov	ar3,r6
      000548 89 82            [24]  604 	mov	dpl,r1
      00054A 8A 83            [24]  605 	mov	dph,r2
      00054C 8B F0            [24]  606 	mov	b,r3
      00054E 12 0C 42         [24]  607 	lcall	__gptrget
      000551 F5 1C            [12]  608 	mov	_TIM_setMode_PARM_2,a
      000553 8F 82            [24]  609 	mov	dpl,r7
      000555 C0 07            [24]  610 	push	ar7
      000557 C0 06            [24]  611 	push	ar6
      000559 C0 05            [24]  612 	push	ar5
      00055B C0 04            [24]  613 	push	ar4
      00055D 12 06 48         [24]  614 	lcall	_TIM_setMode
      000560 D0 04            [24]  615 	pop	ar4
      000562 D0 05            [24]  616 	pop	ar5
      000564 D0 06            [24]  617 	pop	ar6
      000566 D0 07            [24]  618 	pop	ar7
                                    619 ;	../src/tim.c:68: TIM_setValue(tim,tc->value);
      000568 74 04            [12]  620 	mov	a,#0x04
      00056A 2C               [12]  621 	add	a,r4
      00056B F9               [12]  622 	mov	r1,a
      00056C E4               [12]  623 	clr	a
      00056D 3D               [12]  624 	addc	a,r5
      00056E FA               [12]  625 	mov	r2,a
      00056F 8E 03            [24]  626 	mov	ar3,r6
      000571 89 82            [24]  627 	mov	dpl,r1
      000573 8A 83            [24]  628 	mov	dph,r2
      000575 8B F0            [24]  629 	mov	b,r3
      000577 12 0C 42         [24]  630 	lcall	__gptrget
      00057A F5 1C            [12]  631 	mov	_TIM_setValue_PARM_2,a
      00057C A3               [24]  632 	inc	dptr
      00057D 12 0C 42         [24]  633 	lcall	__gptrget
      000580 F5 1D            [12]  634 	mov	(_TIM_setValue_PARM_2 + 1),a
      000582 8F 82            [24]  635 	mov	dpl,r7
      000584 C0 07            [24]  636 	push	ar7
      000586 C0 06            [24]  637 	push	ar6
      000588 C0 05            [24]  638 	push	ar5
      00058A C0 04            [24]  639 	push	ar4
      00058C 12 06 6C         [24]  640 	lcall	_TIM_setValue
      00058F D0 04            [24]  641 	pop	ar4
      000591 D0 05            [24]  642 	pop	ar5
      000593 D0 06            [24]  643 	pop	ar6
      000595 D0 07            [24]  644 	pop	ar7
                                    645 ;	../src/tim.c:69: TIM_INT_cmd(tim,tc->interruptState);
      000597 74 01            [12]  646 	mov	a,#0x01
      000599 2C               [12]  647 	add	a,r4
      00059A F9               [12]  648 	mov	r1,a
      00059B E4               [12]  649 	clr	a
      00059C 3D               [12]  650 	addc	a,r5
      00059D FA               [12]  651 	mov	r2,a
      00059E 8E 03            [24]  652 	mov	ar3,r6
      0005A0 89 82            [24]  653 	mov	dpl,r1
      0005A2 8A 83            [24]  654 	mov	dph,r2
      0005A4 8B F0            [24]  655 	mov	b,r3
      0005A6 12 0C 42         [24]  656 	lcall	__gptrget
      0005A9 F5 1C            [12]  657 	mov	_TIM_INT_cmd_PARM_2,a
      0005AB 8F 82            [24]  658 	mov	dpl,r7
      0005AD C0 07            [24]  659 	push	ar7
      0005AF C0 06            [24]  660 	push	ar6
      0005B1 C0 05            [24]  661 	push	ar5
      0005B3 C0 04            [24]  662 	push	ar4
      0005B5 12 06 8C         [24]  663 	lcall	_TIM_INT_cmd
      0005B8 D0 04            [24]  664 	pop	ar4
      0005BA D0 05            [24]  665 	pop	ar5
      0005BC D0 06            [24]  666 	pop	ar6
      0005BE D0 07            [24]  667 	pop	ar7
                                    668 ;	../src/tim.c:70: TIM_INT_setPriority(tim,tc->interruptPriority);
      0005C0 74 02            [12]  669 	mov	a,#0x02
      0005C2 2C               [12]  670 	add	a,r4
      0005C3 FC               [12]  671 	mov	r4,a
      0005C4 E4               [12]  672 	clr	a
      0005C5 3D               [12]  673 	addc	a,r5
      0005C6 FD               [12]  674 	mov	r5,a
      0005C7 8C 82            [24]  675 	mov	dpl,r4
      0005C9 8D 83            [24]  676 	mov	dph,r5
      0005CB 8E F0            [24]  677 	mov	b,r6
      0005CD 12 0C 42         [24]  678 	lcall	__gptrget
      0005D0 F5 1C            [12]  679 	mov	_TIM_INT_setPriority_PARM_2,a
      0005D2 8F 82            [24]  680 	mov	dpl,r7
      0005D4 02 06 A6         [24]  681 	ljmp	_TIM_INT_setPriority
                                    682 ;------------------------------------------------------------
                                    683 ;Allocation info for local variables in function 'TIM_getValue'
                                    684 ;------------------------------------------------------------
                                    685 ;tim                       Allocated to registers r7 
                                    686 ;------------------------------------------------------------
                                    687 ;	../src/tim.c:79: unsigned int TIM_getValue(PERIPH_TIM tim)
                                    688 ;	-----------------------------------------
                                    689 ;	 function TIM_getValue
                                    690 ;	-----------------------------------------
      0005D7                        691 _TIM_getValue:
      0005D7 AF 82            [24]  692 	mov	r7,dpl
                                    693 ;	../src/tim.c:81: switch(tim)
      0005D9 BF 00 02         [24]  694 	cjne	r7,#0x00,00113$
      0005DC 80 05            [24]  695 	sjmp	00101$
      0005DE                        696 00113$:
                                    697 ;	../src/tim.c:83: case PERIPH_TIM_0:return ((TH0 << 0x08) | TL0);
      0005DE BF 01 24         [24]  698 	cjne	r7,#0x01,00103$
      0005E1 80 11            [24]  699 	sjmp	00102$
      0005E3                        700 00101$:
      0005E3 AF 8C            [24]  701 	mov	r7,_TH0
      0005E5 7E 00            [12]  702 	mov	r6,#0x00
      0005E7 AC 8A            [24]  703 	mov	r4,_TL0
      0005E9 7D 00            [12]  704 	mov	r5,#0x00
      0005EB EC               [12]  705 	mov	a,r4
      0005EC 4E               [12]  706 	orl	a,r6
      0005ED F5 82            [12]  707 	mov	dpl,a
      0005EF ED               [12]  708 	mov	a,r5
      0005F0 4F               [12]  709 	orl	a,r7
      0005F1 F5 83            [12]  710 	mov	dph,a
                                    711 ;	../src/tim.c:84: case PERIPH_TIM_1:return ((TH1 << 0x08) | TL1);
      0005F3 22               [24]  712 	ret
      0005F4                        713 00102$:
      0005F4 AF 8D            [24]  714 	mov	r7,_TH1
      0005F6 7E 00            [12]  715 	mov	r6,#0x00
      0005F8 AC 8B            [24]  716 	mov	r4,_TL1
      0005FA 7D 00            [12]  717 	mov	r5,#0x00
      0005FC EC               [12]  718 	mov	a,r4
      0005FD 4E               [12]  719 	orl	a,r6
      0005FE F5 82            [12]  720 	mov	dpl,a
      000600 ED               [12]  721 	mov	a,r5
      000601 4F               [12]  722 	orl	a,r7
      000602 F5 83            [12]  723 	mov	dph,a
                                    724 ;	../src/tim.c:85: default:return 0;
      000604 22               [24]  725 	ret
      000605                        726 00103$:
      000605 90 00 00         [24]  727 	mov	dptr,#0x0000
                                    728 ;	../src/tim.c:86: }
      000608 22               [24]  729 	ret
                                    730 ;------------------------------------------------------------
                                    731 ;Allocation info for local variables in function 'TIM_isOverflow'
                                    732 ;------------------------------------------------------------
                                    733 ;tim                       Allocated to registers r7 
                                    734 ;------------------------------------------------------------
                                    735 ;	../src/tim.c:95: bool TIM_isOverflow(PERIPH_TIM tim)
                                    736 ;	-----------------------------------------
                                    737 ;	 function TIM_isOverflow
                                    738 ;	-----------------------------------------
      000609                        739 _TIM_isOverflow:
      000609 AF 82            [24]  740 	mov	r7,dpl
                                    741 ;	../src/tim.c:97: switch(tim)
      00060B BF 00 02         [24]  742 	cjne	r7,#0x00,00113$
      00060E 80 05            [24]  743 	sjmp	00101$
      000610                        744 00113$:
                                    745 ;	../src/tim.c:99: case PERIPH_TIM_0:return (bool)TF0;
      000610 BF 01 08         [24]  746 	cjne	r7,#0x01,00103$
      000613 80 03            [24]  747 	sjmp	00102$
      000615                        748 00101$:
      000615 A2 8D            [12]  749 	mov	c,_TF0
                                    750 ;	../src/tim.c:100: case PERIPH_TIM_1:return (bool)TF1;
      000617 22               [24]  751 	ret
      000618                        752 00102$:
      000618 A2 8F            [12]  753 	mov	c,_TF1
                                    754 ;	../src/tim.c:101: default:return false;
      00061A 22               [24]  755 	ret
      00061B                        756 00103$:
      00061B C3               [12]  757 	clr	c
                                    758 ;	../src/tim.c:102: }
      00061C 22               [24]  759 	ret
                                    760 ;------------------------------------------------------------
                                    761 ;Allocation info for local variables in function 'TIM_setFunction'
                                    762 ;------------------------------------------------------------
                                    763 ;f                         Allocated with name '_TIM_setFunction_PARM_2'
                                    764 ;tim                       Allocated to registers r7 
                                    765 ;------------------------------------------------------------
                                    766 ;	../src/tim.c:113: void TIM_setFunction(PERIPH_TIM tim,TIM_function f)
                                    767 ;	-----------------------------------------
                                    768 ;	 function TIM_setFunction
                                    769 ;	-----------------------------------------
      00061D                        770 _TIM_setFunction:
      00061D AF 82            [24]  771 	mov	r7,dpl
                                    772 ;	../src/tim.c:115: switch(tim)
      00061F BF 00 02         [24]  773 	cjne	r7,#0x00,00113$
      000622 80 05            [24]  774 	sjmp	00101$
      000624                        775 00113$:
                                    776 ;	../src/tim.c:117: case PERIPH_TIM_0:TMOD = (TMOD & 0xFB) | (f << 0x02);break;
      000624 BF 01 20         [24]  777 	cjne	r7,#0x01,00105$
      000627 80 0F            [24]  778 	sjmp	00102$
      000629                        779 00101$:
      000629 74 FB            [12]  780 	mov	a,#0xFB
      00062B 55 89            [12]  781 	anl	a,_TMOD
      00062D FF               [12]  782 	mov	r7,a
      00062E E5 1C            [12]  783 	mov	a,_TIM_setFunction_PARM_2
      000630 25 1C            [12]  784 	add	a,_TIM_setFunction_PARM_2
      000632 25 E0            [12]  785 	add	a,acc
      000634 4F               [12]  786 	orl	a,r7
      000635 F5 89            [12]  787 	mov	_TMOD,a
                                    788 ;	../src/tim.c:118: case PERIPH_TIM_1:TMOD = (TMOD & 0xBF) | (f << 0x06);break;
      000637 22               [24]  789 	ret
      000638                        790 00102$:
      000638 74 BF            [12]  791 	mov	a,#0xBF
      00063A 55 89            [12]  792 	anl	a,_TMOD
      00063C FF               [12]  793 	mov	r7,a
      00063D E5 1C            [12]  794 	mov	a,_TIM_setFunction_PARM_2
      00063F 03               [12]  795 	rr	a
      000640 03               [12]  796 	rr	a
      000641 54 C0            [12]  797 	anl	a,#0xC0
      000643 FE               [12]  798 	mov	r6,a
      000644 4F               [12]  799 	orl	a,r7
      000645 F5 89            [12]  800 	mov	_TMOD,a
                                    801 ;	../src/tim.c:120: }
      000647                        802 00105$:
      000647 22               [24]  803 	ret
                                    804 ;------------------------------------------------------------
                                    805 ;Allocation info for local variables in function 'TIM_setMode'
                                    806 ;------------------------------------------------------------
                                    807 ;m                         Allocated with name '_TIM_setMode_PARM_2'
                                    808 ;tim                       Allocated to registers r7 
                                    809 ;------------------------------------------------------------
                                    810 ;	../src/tim.c:131: void TIM_setMode(PERIPH_TIM tim,TIM_mode m)
                                    811 ;	-----------------------------------------
                                    812 ;	 function TIM_setMode
                                    813 ;	-----------------------------------------
      000648                        814 _TIM_setMode:
      000648 AF 82            [24]  815 	mov	r7,dpl
                                    816 ;	../src/tim.c:133: switch(tim)
      00064A BF 00 02         [24]  817 	cjne	r7,#0x00,00113$
      00064D 80 05            [24]  818 	sjmp	00101$
      00064F                        819 00113$:
                                    820 ;	../src/tim.c:135: case PERIPH_TIM_0:TMOD = (TMOD & 0xFC) | m;break;
      00064F BF 01 19         [24]  821 	cjne	r7,#0x01,00105$
      000652 80 09            [24]  822 	sjmp	00102$
      000654                        823 00101$:
      000654 74 FC            [12]  824 	mov	a,#0xFC
      000656 55 89            [12]  825 	anl	a,_TMOD
      000658 45 1C            [12]  826 	orl	a,_TIM_setMode_PARM_2
      00065A F5 89            [12]  827 	mov	_TMOD,a
                                    828 ;	../src/tim.c:136: case PERIPH_TIM_1:TMOD = (TMOD & 0xCF) | (m << 0x04);break;
      00065C 22               [24]  829 	ret
      00065D                        830 00102$:
      00065D 74 CF            [12]  831 	mov	a,#0xCF
      00065F 55 89            [12]  832 	anl	a,_TMOD
      000661 FF               [12]  833 	mov	r7,a
      000662 E5 1C            [12]  834 	mov	a,_TIM_setMode_PARM_2
      000664 C4               [12]  835 	swap	a
      000665 54 F0            [12]  836 	anl	a,#0xF0
      000667 FE               [12]  837 	mov	r6,a
      000668 4F               [12]  838 	orl	a,r7
      000669 F5 89            [12]  839 	mov	_TMOD,a
                                    840 ;	../src/tim.c:138: }
      00066B                        841 00105$:
      00066B 22               [24]  842 	ret
                                    843 ;------------------------------------------------------------
                                    844 ;Allocation info for local variables in function 'TIM_setValue'
                                    845 ;------------------------------------------------------------
                                    846 ;val                       Allocated with name '_TIM_setValue_PARM_2'
                                    847 ;tim                       Allocated to registers r7 
                                    848 ;------------------------------------------------------------
                                    849 ;	../src/tim.c:149: void TIM_setValue(PERIPH_TIM tim,unsigned int val)
                                    850 ;	-----------------------------------------
                                    851 ;	 function TIM_setValue
                                    852 ;	-----------------------------------------
      00066C                        853 _TIM_setValue:
      00066C AF 82            [24]  854 	mov	r7,dpl
                                    855 ;	../src/tim.c:151: switch(tim)
      00066E BF 00 02         [24]  856 	cjne	r7,#0x00,00113$
      000671 80 05            [24]  857 	sjmp	00101$
      000673                        858 00113$:
                                    859 ;	../src/tim.c:153: case PERIPH_TIM_0:
      000673 BF 01 15         [24]  860 	cjne	r7,#0x01,00105$
      000676 80 09            [24]  861 	sjmp	00102$
      000678                        862 00101$:
                                    863 ;	../src/tim.c:155: TH0 = (u8)((val >> 0x8) & 0x00FF);
      000678 AF 1D            [24]  864 	mov	r7,(_TIM_setValue_PARM_2 + 1)
      00067A 8F 8C            [24]  865 	mov	_TH0,r7
                                    866 ;	../src/tim.c:156: TL0 = (u8)(val & 0x00FF);
      00067C AE 1C            [24]  867 	mov	r6,_TIM_setValue_PARM_2
      00067E 8E 8A            [24]  868 	mov	_TL0,r6
                                    869 ;	../src/tim.c:157: } break;
                                    870 ;	../src/tim.c:158: case PERIPH_TIM_1:
      000680 22               [24]  871 	ret
      000681                        872 00102$:
                                    873 ;	../src/tim.c:160: TH1 = (u8)((val >> 0x8) & 0x00FF);
      000681 AF 1D            [24]  874 	mov	r7,(_TIM_setValue_PARM_2 + 1)
      000683 8F 8D            [24]  875 	mov	_TH1,r7
                                    876 ;	../src/tim.c:161: TL1 = (u8)(val & 0x00FF);
      000685 AE 1C            [24]  877 	mov	r6,_TIM_setValue_PARM_2
      000687 7F 00            [12]  878 	mov	r7,#0x00
      000689 8E 8B            [24]  879 	mov	_TL1,r6
                                    880 ;	../src/tim.c:164: }
      00068B                        881 00105$:
      00068B 22               [24]  882 	ret
                                    883 ;------------------------------------------------------------
                                    884 ;Allocation info for local variables in function 'TIM_INT_cmd'
                                    885 ;------------------------------------------------------------
                                    886 ;a                         Allocated with name '_TIM_INT_cmd_PARM_2'
                                    887 ;tim                       Allocated to registers r7 
                                    888 ;------------------------------------------------------------
                                    889 ;	../src/tim.c:175: void TIM_INT_cmd(PERIPH_TIM tim,Action a)
                                    890 ;	-----------------------------------------
                                    891 ;	 function TIM_INT_cmd
                                    892 ;	-----------------------------------------
      00068C                        893 _TIM_INT_cmd:
      00068C AF 82            [24]  894 	mov	r7,dpl
                                    895 ;	../src/tim.c:177: switch(tim)
      00068E BF 00 02         [24]  896 	cjne	r7,#0x00,00113$
      000691 80 05            [24]  897 	sjmp	00101$
      000693                        898 00113$:
                                    899 ;	../src/tim.c:179: case PERIPH_TIM_0:ET0 = a;break;
      000693 BF 01 0F         [24]  900 	cjne	r7,#0x01,00105$
      000696 80 07            [24]  901 	sjmp	00102$
      000698                        902 00101$:
      000698 E5 1C            [12]  903 	mov	a,_TIM_INT_cmd_PARM_2
      00069A 24 FF            [12]  904 	add	a,#0xff
      00069C 92 A9            [24]  905 	mov	_ET0,c
                                    906 ;	../src/tim.c:180: case PERIPH_TIM_1:ET1 = a;break;
      00069E 22               [24]  907 	ret
      00069F                        908 00102$:
      00069F E5 1C            [12]  909 	mov	a,_TIM_INT_cmd_PARM_2
      0006A1 24 FF            [12]  910 	add	a,#0xff
      0006A3 92 AB            [24]  911 	mov	_ET1,c
                                    912 ;	../src/tim.c:182: }
      0006A5                        913 00105$:
      0006A5 22               [24]  914 	ret
                                    915 ;------------------------------------------------------------
                                    916 ;Allocation info for local variables in function 'TIM_INT_setPriority'
                                    917 ;------------------------------------------------------------
                                    918 ;p                         Allocated with name '_TIM_INT_setPriority_PARM_2'
                                    919 ;tim                       Allocated to registers r7 
                                    920 ;------------------------------------------------------------
                                    921 ;	../src/tim.c:193: void TIM_INT_setPriority(PERIPH_TIM tim,INTR_PIOR p)
                                    922 ;	-----------------------------------------
                                    923 ;	 function TIM_INT_setPriority
                                    924 ;	-----------------------------------------
      0006A6                        925 _TIM_INT_setPriority:
      0006A6 AF 82            [24]  926 	mov	r7,dpl
                                    927 ;	../src/tim.c:195: switch(tim)
      0006A8 BF 00 02         [24]  928 	cjne	r7,#0x00,00113$
      0006AB 80 05            [24]  929 	sjmp	00101$
      0006AD                        930 00113$:
                                    931 ;	../src/tim.c:197: case PERIPH_TIM_0:
      0006AD BF 01 40         [24]  932 	cjne	r7,#0x01,00105$
      0006B0 80 1D            [24]  933 	sjmp	00102$
      0006B2                        934 00101$:
                                    935 ;	../src/tim.c:199: IP = (IP & 0xFD) | ((P & 0x01) << 0x1);
      0006B2 74 FD            [12]  936 	mov	a,#0xFD
      0006B4 55 B8            [12]  937 	anl	a,_IP
      0006B6 FF               [12]  938 	mov	r7,a
      0006B7 A2 D0            [12]  939 	mov	c,_P
      0006B9 E4               [12]  940 	clr	a
      0006BA 33               [12]  941 	rlc	a
      0006BB 54 01            [12]  942 	anl	a,#0x01
      0006BD 25 E0            [12]  943 	add	a,acc
      0006BF 4F               [12]  944 	orl	a,r7
      0006C0 F5 B8            [12]  945 	mov	_IP,a
                                    946 ;	../src/tim.c:200: IPH = (IPH & 0xFD) | (p & 0x02);
      0006C2 74 FD            [12]  947 	mov	a,#0xFD
      0006C4 55 B7            [12]  948 	anl	a,_IPH
      0006C6 FF               [12]  949 	mov	r7,a
      0006C7 74 02            [12]  950 	mov	a,#0x02
      0006C9 55 1C            [12]  951 	anl	a,_TIM_INT_setPriority_PARM_2
      0006CB 4F               [12]  952 	orl	a,r7
      0006CC F5 B7            [12]  953 	mov	_IPH,a
                                    954 ;	../src/tim.c:201: } break;
                                    955 ;	../src/tim.c:202: case PERIPH_TIM_1:
      0006CE 22               [24]  956 	ret
      0006CF                        957 00102$:
                                    958 ;	../src/tim.c:204: IP = (IP & 0xF7) | ((p & 0x01) << 0x3);
      0006CF 74 F7            [12]  959 	mov	a,#0xF7
      0006D1 55 B8            [12]  960 	anl	a,_IP
      0006D3 FF               [12]  961 	mov	r7,a
      0006D4 74 01            [12]  962 	mov	a,#0x01
      0006D6 55 1C            [12]  963 	anl	a,_TIM_INT_setPriority_PARM_2
      0006D8 C4               [12]  964 	swap	a
      0006D9 03               [12]  965 	rr	a
      0006DA 54 F8            [12]  966 	anl	a,#0xF8
      0006DC 4F               [12]  967 	orl	a,r7
      0006DD F5 B8            [12]  968 	mov	_IP,a
                                    969 ;	../src/tim.c:205: IPH = (IPH & 0xF7) | ((p & 0x02) << 0x2);
      0006DF 74 F7            [12]  970 	mov	a,#0xF7
      0006E1 55 B7            [12]  971 	anl	a,_IPH
      0006E3 FF               [12]  972 	mov	r7,a
      0006E4 74 02            [12]  973 	mov	a,#0x02
      0006E6 55 1C            [12]  974 	anl	a,_TIM_INT_setPriority_PARM_2
      0006E8 25 E0            [12]  975 	add	a,acc
      0006EA 25 E0            [12]  976 	add	a,acc
      0006EC FE               [12]  977 	mov	r6,a
      0006ED 4F               [12]  978 	orl	a,r7
      0006EE F5 B7            [12]  979 	mov	_IPH,a
                                    980 ;	../src/tim.c:208: }
      0006F0                        981 00105$:
      0006F0 22               [24]  982 	ret
                                    983 	.area CSEG    (CODE)
                                    984 	.area CONST   (CODE)
                                    985 	.area XINIT   (CODE)
                                    986 	.area CABS    (ABS,CODE)
