                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jul 18 12:39:08 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module exti
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _EXTI_setPriority_PARM_2
                                     13 	.globl _EXTI_setMode_PARM_2
                                     14 	.globl _EXTI_cmd_PARM_2
                                     15 	.globl _TF2
                                     16 	.globl _EXF2
                                     17 	.globl _RCLK
                                     18 	.globl _TCLK
                                     19 	.globl _EXEN2
                                     20 	.globl _TR2
                                     21 	.globl _CT2
                                     22 	.globl _CPRL2
                                     23 	.globl _P4_0
                                     24 	.globl _P4_1
                                     25 	.globl _P4_2
                                     26 	.globl _P4_3
                                     27 	.globl _PX3
                                     28 	.globl _EX3
                                     29 	.globl _IE3
                                     30 	.globl _IT3
                                     31 	.globl _PX2
                                     32 	.globl _EX2
                                     33 	.globl _IE2
                                     34 	.globl _IT2
                                     35 	.globl _CY
                                     36 	.globl _AC
                                     37 	.globl _F0
                                     38 	.globl _RS1
                                     39 	.globl _RS0
                                     40 	.globl _OV
                                     41 	.globl _F1
                                     42 	.globl _P
                                     43 	.globl _PS
                                     44 	.globl _PT1
                                     45 	.globl _PX1
                                     46 	.globl _PT0
                                     47 	.globl _PX0
                                     48 	.globl _RD
                                     49 	.globl _WR
                                     50 	.globl _T1
                                     51 	.globl _T0
                                     52 	.globl _INT1
                                     53 	.globl _INT0
                                     54 	.globl _TXD
                                     55 	.globl _RXD
                                     56 	.globl _P3_7
                                     57 	.globl _P3_6
                                     58 	.globl _P3_5
                                     59 	.globl _P3_4
                                     60 	.globl _P3_3
                                     61 	.globl _P3_2
                                     62 	.globl _P3_1
                                     63 	.globl _P3_0
                                     64 	.globl _EA
                                     65 	.globl _ES
                                     66 	.globl _ET1
                                     67 	.globl _EX1
                                     68 	.globl _ET0
                                     69 	.globl _EX0
                                     70 	.globl _P2_7
                                     71 	.globl _P2_6
                                     72 	.globl _P2_5
                                     73 	.globl _P2_4
                                     74 	.globl _P2_3
                                     75 	.globl _P2_2
                                     76 	.globl _P2_1
                                     77 	.globl _P2_0
                                     78 	.globl _SM0
                                     79 	.globl _SM1
                                     80 	.globl _SM2
                                     81 	.globl _REN
                                     82 	.globl _TB8
                                     83 	.globl _RB8
                                     84 	.globl _TI
                                     85 	.globl _RI
                                     86 	.globl _P1_7
                                     87 	.globl _P1_6
                                     88 	.globl _P1_5
                                     89 	.globl _P1_4
                                     90 	.globl _P1_3
                                     91 	.globl _P1_2
                                     92 	.globl _P1_1
                                     93 	.globl _P1_0
                                     94 	.globl _TF1
                                     95 	.globl _TR1
                                     96 	.globl _TF0
                                     97 	.globl _TR0
                                     98 	.globl _IE1
                                     99 	.globl _IT1
                                    100 	.globl _IE0
                                    101 	.globl _IT0
                                    102 	.globl _P0_7
                                    103 	.globl _P0_6
                                    104 	.globl _P0_5
                                    105 	.globl _P0_4
                                    106 	.globl _P0_3
                                    107 	.globl _P0_2
                                    108 	.globl _P0_1
                                    109 	.globl _P0_0
                                    110 	.globl _P4
                                    111 	.globl _ISP_CONTR
                                    112 	.globl _ISP_TRIG
                                    113 	.globl _ISP_CMD
                                    114 	.globl _ISP_ADDRL
                                    115 	.globl _ISP_ADDRH
                                    116 	.globl _ISP_DATA
                                    117 	.globl _WDT_CONTR
                                    118 	.globl _TH2
                                    119 	.globl _TL2
                                    120 	.globl _RCAP2H
                                    121 	.globl _RCAP2L
                                    122 	.globl _T2MOD
                                    123 	.globl _T2CON
                                    124 	.globl _XICON
                                    125 	.globl _IPH
                                    126 	.globl _SADDR1
                                    127 	.globl _AUXR1
                                    128 	.globl _AUXR
                                    129 	.globl _B
                                    130 	.globl _ACC
                                    131 	.globl _PSW
                                    132 	.globl _IP
                                    133 	.globl _P3
                                    134 	.globl _IE
                                    135 	.globl _P2
                                    136 	.globl _SBUF
                                    137 	.globl _SCON
                                    138 	.globl _P1
                                    139 	.globl _TH1
                                    140 	.globl _TH0
                                    141 	.globl _TL1
                                    142 	.globl _TL0
                                    143 	.globl _TMOD
                                    144 	.globl _TCON
                                    145 	.globl _PCON
                                    146 	.globl _DPH
                                    147 	.globl _DPL
                                    148 	.globl _SP
                                    149 	.globl _P0
                                    150 	.globl _EXTI_config_PARM_2
                                    151 	.globl _EXTI_config
                                    152 	.globl _EXTI_cmd
                                    153 	.globl _EXTI_setMode
                                    154 	.globl _EXTI_setPriority
                                    155 ;--------------------------------------------------------
                                    156 ; special function registers
                                    157 ;--------------------------------------------------------
                                    158 	.area RSEG    (ABS,DATA)
      000000                        159 	.org 0x0000
                           000080   160 _P0	=	0x0080
                           000081   161 _SP	=	0x0081
                           000082   162 _DPL	=	0x0082
                           000083   163 _DPH	=	0x0083
                           000087   164 _PCON	=	0x0087
                           000088   165 _TCON	=	0x0088
                           000089   166 _TMOD	=	0x0089
                           00008A   167 _TL0	=	0x008a
                           00008B   168 _TL1	=	0x008b
                           00008C   169 _TH0	=	0x008c
                           00008D   170 _TH1	=	0x008d
                           000090   171 _P1	=	0x0090
                           000098   172 _SCON	=	0x0098
                           000099   173 _SBUF	=	0x0099
                           0000A0   174 _P2	=	0x00a0
                           0000A8   175 _IE	=	0x00a8
                           0000B0   176 _P3	=	0x00b0
                           0000B8   177 _IP	=	0x00b8
                           0000D0   178 _PSW	=	0x00d0
                           0000E0   179 _ACC	=	0x00e0
                           0000F0   180 _B	=	0x00f0
                           00008E   181 _AUXR	=	0x008e
                           0000A2   182 _AUXR1	=	0x00a2
                           0000A9   183 _SADDR1	=	0x00a9
                           0000B7   184 _IPH	=	0x00b7
                           0000C0   185 _XICON	=	0x00c0
                           0000C8   186 _T2CON	=	0x00c8
                           0000C9   187 _T2MOD	=	0x00c9
                           0000CA   188 _RCAP2L	=	0x00ca
                           0000CB   189 _RCAP2H	=	0x00cb
                           0000CC   190 _TL2	=	0x00cc
                           0000CD   191 _TH2	=	0x00cd
                           0000E1   192 _WDT_CONTR	=	0x00e1
                           0000E2   193 _ISP_DATA	=	0x00e2
                           0000E3   194 _ISP_ADDRH	=	0x00e3
                           0000E4   195 _ISP_ADDRL	=	0x00e4
                           0000E5   196 _ISP_CMD	=	0x00e5
                           0000E6   197 _ISP_TRIG	=	0x00e6
                           0000E7   198 _ISP_CONTR	=	0x00e7
                           0000E8   199 _P4	=	0x00e8
                                    200 ;--------------------------------------------------------
                                    201 ; special function bits
                                    202 ;--------------------------------------------------------
                                    203 	.area RSEG    (ABS,DATA)
      000000                        204 	.org 0x0000
                           000080   205 _P0_0	=	0x0080
                           000081   206 _P0_1	=	0x0081
                           000082   207 _P0_2	=	0x0082
                           000083   208 _P0_3	=	0x0083
                           000084   209 _P0_4	=	0x0084
                           000085   210 _P0_5	=	0x0085
                           000086   211 _P0_6	=	0x0086
                           000087   212 _P0_7	=	0x0087
                           000088   213 _IT0	=	0x0088
                           000089   214 _IE0	=	0x0089
                           00008A   215 _IT1	=	0x008a
                           00008B   216 _IE1	=	0x008b
                           00008C   217 _TR0	=	0x008c
                           00008D   218 _TF0	=	0x008d
                           00008E   219 _TR1	=	0x008e
                           00008F   220 _TF1	=	0x008f
                           000090   221 _P1_0	=	0x0090
                           000091   222 _P1_1	=	0x0091
                           000092   223 _P1_2	=	0x0092
                           000093   224 _P1_3	=	0x0093
                           000094   225 _P1_4	=	0x0094
                           000095   226 _P1_5	=	0x0095
                           000096   227 _P1_6	=	0x0096
                           000097   228 _P1_7	=	0x0097
                           000098   229 _RI	=	0x0098
                           000099   230 _TI	=	0x0099
                           00009A   231 _RB8	=	0x009a
                           00009B   232 _TB8	=	0x009b
                           00009C   233 _REN	=	0x009c
                           00009D   234 _SM2	=	0x009d
                           00009E   235 _SM1	=	0x009e
                           00009F   236 _SM0	=	0x009f
                           0000A0   237 _P2_0	=	0x00a0
                           0000A1   238 _P2_1	=	0x00a1
                           0000A2   239 _P2_2	=	0x00a2
                           0000A3   240 _P2_3	=	0x00a3
                           0000A4   241 _P2_4	=	0x00a4
                           0000A5   242 _P2_5	=	0x00a5
                           0000A6   243 _P2_6	=	0x00a6
                           0000A7   244 _P2_7	=	0x00a7
                           0000A8   245 _EX0	=	0x00a8
                           0000A9   246 _ET0	=	0x00a9
                           0000AA   247 _EX1	=	0x00aa
                           0000AB   248 _ET1	=	0x00ab
                           0000AC   249 _ES	=	0x00ac
                           0000AF   250 _EA	=	0x00af
                           0000B0   251 _P3_0	=	0x00b0
                           0000B1   252 _P3_1	=	0x00b1
                           0000B2   253 _P3_2	=	0x00b2
                           0000B3   254 _P3_3	=	0x00b3
                           0000B4   255 _P3_4	=	0x00b4
                           0000B5   256 _P3_5	=	0x00b5
                           0000B6   257 _P3_6	=	0x00b6
                           0000B7   258 _P3_7	=	0x00b7
                           0000B0   259 _RXD	=	0x00b0
                           0000B1   260 _TXD	=	0x00b1
                           0000B2   261 _INT0	=	0x00b2
                           0000B3   262 _INT1	=	0x00b3
                           0000B4   263 _T0	=	0x00b4
                           0000B5   264 _T1	=	0x00b5
                           0000B6   265 _WR	=	0x00b6
                           0000B7   266 _RD	=	0x00b7
                           0000B8   267 _PX0	=	0x00b8
                           0000B9   268 _PT0	=	0x00b9
                           0000BA   269 _PX1	=	0x00ba
                           0000BB   270 _PT1	=	0x00bb
                           0000BC   271 _PS	=	0x00bc
                           0000D0   272 _P	=	0x00d0
                           0000D1   273 _F1	=	0x00d1
                           0000D2   274 _OV	=	0x00d2
                           0000D3   275 _RS0	=	0x00d3
                           0000D4   276 _RS1	=	0x00d4
                           0000D5   277 _F0	=	0x00d5
                           0000D6   278 _AC	=	0x00d6
                           0000D7   279 _CY	=	0x00d7
                           0000C0   280 _IT2	=	0x00c0
                           0000C1   281 _IE2	=	0x00c1
                           0000C2   282 _EX2	=	0x00c2
                           0000C3   283 _PX2	=	0x00c3
                           0000C4   284 _IT3	=	0x00c4
                           0000C5   285 _IE3	=	0x00c5
                           0000C6   286 _EX3	=	0x00c6
                           0000C7   287 _PX3	=	0x00c7
                           0000EB   288 _P4_3	=	0x00eb
                           0000EA   289 _P4_2	=	0x00ea
                           0000E9   290 _P4_1	=	0x00e9
                           0000E8   291 _P4_0	=	0x00e8
                           0000C8   292 _CPRL2	=	0x00c8
                           0000C9   293 _CT2	=	0x00c9
                           0000CA   294 _TR2	=	0x00ca
                           0000CB   295 _EXEN2	=	0x00cb
                           0000CC   296 _TCLK	=	0x00cc
                           0000CD   297 _RCLK	=	0x00cd
                           0000CE   298 _EXF2	=	0x00ce
                           0000CF   299 _TF2	=	0x00cf
                                    300 ;--------------------------------------------------------
                                    301 ; overlayable register banks
                                    302 ;--------------------------------------------------------
                                    303 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        304 	.ds 8
                                    305 ;--------------------------------------------------------
                                    306 ; internal ram data
                                    307 ;--------------------------------------------------------
                                    308 	.area DSEG    (DATA)
      000010                        309 _EXTI_config_PARM_2:
      000010                        310 	.ds 3
                                    311 ;--------------------------------------------------------
                                    312 ; overlayable items in internal ram 
                                    313 ;--------------------------------------------------------
                                    314 	.area	OSEG    (OVR,DATA)
      00001C                        315 _EXTI_cmd_PARM_2:
      00001C                        316 	.ds 1
                                    317 	.area	OSEG    (OVR,DATA)
      00001C                        318 _EXTI_setMode_PARM_2:
      00001C                        319 	.ds 1
                                    320 	.area	OSEG    (OVR,DATA)
      00001C                        321 _EXTI_setPriority_PARM_2:
      00001C                        322 	.ds 1
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
      000000                        336 _EXTI_setPriority_sloc0_1_0:
      000000                        337 	.ds 1
                                    338 ;--------------------------------------------------------
                                    339 ; paged external ram data
                                    340 ;--------------------------------------------------------
                                    341 	.area PSEG    (PAG,XDATA)
                                    342 ;--------------------------------------------------------
                                    343 ; external ram data
                                    344 ;--------------------------------------------------------
                                    345 	.area XSEG    (XDATA)
                                    346 ;--------------------------------------------------------
                                    347 ; absolute external ram data
                                    348 ;--------------------------------------------------------
                                    349 	.area XABS    (ABS,XDATA)
                                    350 ;--------------------------------------------------------
                                    351 ; external initialized ram data
                                    352 ;--------------------------------------------------------
                                    353 	.area XISEG   (XDATA)
                                    354 	.area HOME    (CODE)
                                    355 	.area GSINIT0 (CODE)
                                    356 	.area GSINIT1 (CODE)
                                    357 	.area GSINIT2 (CODE)
                                    358 	.area GSINIT3 (CODE)
                                    359 	.area GSINIT4 (CODE)
                                    360 	.area GSINIT5 (CODE)
                                    361 	.area GSINIT  (CODE)
                                    362 	.area GSFINAL (CODE)
                                    363 	.area CSEG    (CODE)
                                    364 ;--------------------------------------------------------
                                    365 ; global & static initialisations
                                    366 ;--------------------------------------------------------
                                    367 	.area HOME    (CODE)
                                    368 	.area GSINIT  (CODE)
                                    369 	.area GSFINAL (CODE)
                                    370 	.area GSINIT  (CODE)
                                    371 ;--------------------------------------------------------
                                    372 ; Home
                                    373 ;--------------------------------------------------------
                                    374 	.area HOME    (CODE)
                                    375 	.area HOME    (CODE)
                                    376 ;--------------------------------------------------------
                                    377 ; code
                                    378 ;--------------------------------------------------------
                                    379 	.area CSEG    (CODE)
                                    380 ;------------------------------------------------------------
                                    381 ;Allocation info for local variables in function 'EXTI_config'
                                    382 ;------------------------------------------------------------
                                    383 ;ec                        Allocated with name '_EXTI_config_PARM_2'
                                    384 ;exti                      Allocated to registers r7 
                                    385 ;------------------------------------------------------------
                                    386 ;	../src/exti.c:21: void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec)
                                    387 ;	-----------------------------------------
                                    388 ;	 function EXTI_config
                                    389 ;	-----------------------------------------
      000097                        390 _EXTI_config:
                           000007   391 	ar7 = 0x07
                           000006   392 	ar6 = 0x06
                           000005   393 	ar5 = 0x05
                           000004   394 	ar4 = 0x04
                           000003   395 	ar3 = 0x03
                           000002   396 	ar2 = 0x02
                           000001   397 	ar1 = 0x01
                           000000   398 	ar0 = 0x00
      000097 AF 82            [24]  399 	mov	r7,dpl
                                    400 ;	../src/exti.c:23: EXTI_setMode(exti,ec->mode);
      000099 AC 10            [24]  401 	mov	r4,_EXTI_config_PARM_2
      00009B AD 11            [24]  402 	mov	r5,(_EXTI_config_PARM_2 + 1)
      00009D AE 12            [24]  403 	mov	r6,(_EXTI_config_PARM_2 + 2)
      00009F 8C 82            [24]  404 	mov	dpl,r4
      0000A1 8D 83            [24]  405 	mov	dph,r5
      0000A3 8E F0            [24]  406 	mov	b,r6
      0000A5 12 0C 42         [24]  407 	lcall	__gptrget
      0000A8 F5 1C            [12]  408 	mov	_EXTI_setMode_PARM_2,a
      0000AA 8F 82            [24]  409 	mov	dpl,r7
      0000AC C0 07            [24]  410 	push	ar7
      0000AE C0 06            [24]  411 	push	ar6
      0000B0 C0 05            [24]  412 	push	ar5
      0000B2 C0 04            [24]  413 	push	ar4
      0000B4 12 01 0A         [24]  414 	lcall	_EXTI_setMode
      0000B7 D0 04            [24]  415 	pop	ar4
      0000B9 D0 05            [24]  416 	pop	ar5
      0000BB D0 06            [24]  417 	pop	ar6
      0000BD D0 07            [24]  418 	pop	ar7
                                    419 ;	../src/exti.c:24: EXTI_setPriority(exti,ec->priority);
      0000BF 0C               [12]  420 	inc	r4
      0000C0 BC 00 01         [24]  421 	cjne	r4,#0x00,00103$
      0000C3 0D               [12]  422 	inc	r5
      0000C4                        423 00103$:
      0000C4 8C 82            [24]  424 	mov	dpl,r4
      0000C6 8D 83            [24]  425 	mov	dph,r5
      0000C8 8E F0            [24]  426 	mov	b,r6
      0000CA 12 0C 42         [24]  427 	lcall	__gptrget
      0000CD F5 1C            [12]  428 	mov	_EXTI_setPriority_PARM_2,a
      0000CF 8F 82            [24]  429 	mov	dpl,r7
      0000D1 02 01 40         [24]  430 	ljmp	_EXTI_setPriority
                                    431 ;------------------------------------------------------------
                                    432 ;Allocation info for local variables in function 'EXTI_cmd'
                                    433 ;------------------------------------------------------------
                                    434 ;a                         Allocated with name '_EXTI_cmd_PARM_2'
                                    435 ;exti                      Allocated to registers r7 
                                    436 ;------------------------------------------------------------
                                    437 ;	../src/exti.c:34: void EXTI_cmd(PERIPH_EXTI exti,Action a)
                                    438 ;	-----------------------------------------
                                    439 ;	 function EXTI_cmd
                                    440 ;	-----------------------------------------
      0000D4                        441 _EXTI_cmd:
                                    442 ;	../src/exti.c:36: switch(exti)
      0000D4 E5 82            [12]  443 	mov	a,dpl
      0000D6 FF               [12]  444 	mov	r7,a
      0000D7 24 FC            [12]  445 	add	a,#0xff - 0x03
      0000D9 40 2E            [24]  446 	jc	00107$
      0000DB EF               [12]  447 	mov	a,r7
      0000DC 2F               [12]  448 	add	a,r7
      0000DD 2F               [12]  449 	add	a,r7
      0000DE 90 00 E2         [24]  450 	mov	dptr,#00113$
      0000E1 73               [24]  451 	jmp	@a+dptr
      0000E2                        452 00113$:
      0000E2 02 00 EE         [24]  453 	ljmp	00101$
      0000E5 02 00 F5         [24]  454 	ljmp	00102$
      0000E8 02 00 FC         [24]  455 	ljmp	00103$
      0000EB 02 01 03         [24]  456 	ljmp	00104$
                                    457 ;	../src/exti.c:38: case PERIPH_EXTI_0:EX0 = a;break;
      0000EE                        458 00101$:
      0000EE E5 1C            [12]  459 	mov	a,_EXTI_cmd_PARM_2
      0000F0 24 FF            [12]  460 	add	a,#0xff
      0000F2 92 A8            [24]  461 	mov	_EX0,c
                                    462 ;	../src/exti.c:39: case PERIPH_EXTI_1:EX1 = a;break;
      0000F4 22               [24]  463 	ret
      0000F5                        464 00102$:
      0000F5 E5 1C            [12]  465 	mov	a,_EXTI_cmd_PARM_2
      0000F7 24 FF            [12]  466 	add	a,#0xff
      0000F9 92 AA            [24]  467 	mov	_EX1,c
                                    468 ;	../src/exti.c:40: case PERIPH_EXTI_2:EX2 = a;break;
      0000FB 22               [24]  469 	ret
      0000FC                        470 00103$:
      0000FC E5 1C            [12]  471 	mov	a,_EXTI_cmd_PARM_2
      0000FE 24 FF            [12]  472 	add	a,#0xff
      000100 92 C2            [24]  473 	mov	_EX2,c
                                    474 ;	../src/exti.c:41: case PERIPH_EXTI_3:EX3 = a;break;
      000102 22               [24]  475 	ret
      000103                        476 00104$:
      000103 E5 1C            [12]  477 	mov	a,_EXTI_cmd_PARM_2
      000105 24 FF            [12]  478 	add	a,#0xff
      000107 92 C6            [24]  479 	mov	_EX3,c
                                    480 ;	../src/exti.c:43: }
      000109                        481 00107$:
      000109 22               [24]  482 	ret
                                    483 ;------------------------------------------------------------
                                    484 ;Allocation info for local variables in function 'EXTI_setMode'
                                    485 ;------------------------------------------------------------
                                    486 ;mod                       Allocated with name '_EXTI_setMode_PARM_2'
                                    487 ;exti                      Allocated to registers r7 
                                    488 ;------------------------------------------------------------
                                    489 ;	../src/exti.c:53: void EXTI_setMode(PERIPH_EXTI exti,EXTI_MOD mod)
                                    490 ;	-----------------------------------------
                                    491 ;	 function EXTI_setMode
                                    492 ;	-----------------------------------------
      00010A                        493 _EXTI_setMode:
                                    494 ;	../src/exti.c:55: switch(exti)
      00010A E5 82            [12]  495 	mov	a,dpl
      00010C FF               [12]  496 	mov	r7,a
      00010D 24 FC            [12]  497 	add	a,#0xff - 0x03
      00010F 40 2E            [24]  498 	jc	00107$
      000111 EF               [12]  499 	mov	a,r7
      000112 2F               [12]  500 	add	a,r7
      000113 2F               [12]  501 	add	a,r7
      000114 90 01 18         [24]  502 	mov	dptr,#00113$
      000117 73               [24]  503 	jmp	@a+dptr
      000118                        504 00113$:
      000118 02 01 24         [24]  505 	ljmp	00101$
      00011B 02 01 2B         [24]  506 	ljmp	00102$
      00011E 02 01 32         [24]  507 	ljmp	00103$
      000121 02 01 39         [24]  508 	ljmp	00104$
                                    509 ;	../src/exti.c:57: case PERIPH_EXTI_0:IT0 = mod;break;
      000124                        510 00101$:
      000124 E5 1C            [12]  511 	mov	a,_EXTI_setMode_PARM_2
      000126 24 FF            [12]  512 	add	a,#0xff
      000128 92 88            [24]  513 	mov	_IT0,c
                                    514 ;	../src/exti.c:58: case PERIPH_EXTI_1:IT1 = mod;break;
      00012A 22               [24]  515 	ret
      00012B                        516 00102$:
      00012B E5 1C            [12]  517 	mov	a,_EXTI_setMode_PARM_2
      00012D 24 FF            [12]  518 	add	a,#0xff
      00012F 92 8A            [24]  519 	mov	_IT1,c
                                    520 ;	../src/exti.c:59: case PERIPH_EXTI_2:IT2 = mod;break;
      000131 22               [24]  521 	ret
      000132                        522 00103$:
      000132 E5 1C            [12]  523 	mov	a,_EXTI_setMode_PARM_2
      000134 24 FF            [12]  524 	add	a,#0xff
      000136 92 C0            [24]  525 	mov	_IT2,c
                                    526 ;	../src/exti.c:60: case PERIPH_EXTI_3:IT3 = mod;break;
      000138 22               [24]  527 	ret
      000139                        528 00104$:
      000139 E5 1C            [12]  529 	mov	a,_EXTI_setMode_PARM_2
      00013B 24 FF            [12]  530 	add	a,#0xff
      00013D 92 C4            [24]  531 	mov	_IT3,c
                                    532 ;	../src/exti.c:62: }
      00013F                        533 00107$:
      00013F 22               [24]  534 	ret
                                    535 ;------------------------------------------------------------
                                    536 ;Allocation info for local variables in function 'EXTI_setPriority'
                                    537 ;------------------------------------------------------------
                                    538 ;p                         Allocated with name '_EXTI_setPriority_PARM_2'
                                    539 ;exti                      Allocated to registers r7 
                                    540 ;------------------------------------------------------------
                                    541 ;	../src/exti.c:72: void EXTI_setPriority(PERIPH_EXTI exti,INTR_PIOR p)
                                    542 ;	-----------------------------------------
                                    543 ;	 function EXTI_setPriority
                                    544 ;	-----------------------------------------
      000140                        545 _EXTI_setPriority:
                                    546 ;	../src/exti.c:74: switch(exti)
      000140 E5 82            [12]  547 	mov	a,dpl
      000142 FF               [12]  548 	mov	r7,a
      000143 24 FC            [12]  549 	add	a,#0xff - 0x03
      000145 50 01            [24]  550 	jnc	00112$
      000147 22               [24]  551 	ret
      000148                        552 00112$:
      000148 EF               [12]  553 	mov	a,r7
      000149 2F               [12]  554 	add	a,r7
      00014A 2F               [12]  555 	add	a,r7
      00014B 90 01 4F         [24]  556 	mov	dptr,#00113$
      00014E 73               [24]  557 	jmp	@a+dptr
      00014F                        558 00113$:
      00014F 02 01 5B         [24]  559 	ljmp	00101$
      000152 02 01 75         [24]  560 	ljmp	00102$
      000155 02 01 94         [24]  561 	ljmp	00103$
      000158 02 01 AC         [24]  562 	ljmp	00104$
                                    563 ;	../src/exti.c:76: case PERIPH_EXTI_0:
      00015B                        564 00101$:
                                    565 ;	../src/exti.c:79: IP  = (IP & 0xFE) | (p & 0x01);
      00015B 74 FE            [12]  566 	mov	a,#0xFE
      00015D 55 B8            [12]  567 	anl	a,_IP
      00015F FF               [12]  568 	mov	r7,a
      000160 74 01            [12]  569 	mov	a,#0x01
      000162 55 1C            [12]  570 	anl	a,_EXTI_setPriority_PARM_2
      000164 4F               [12]  571 	orl	a,r7
      000165 F5 B8            [12]  572 	mov	_IP,a
                                    573 ;	../src/exti.c:81: IPH = (IPH & 0xFE) | ((p >> 0x1) & 0x01);
      000167 74 FE            [12]  574 	mov	a,#0xFE
      000169 55 B7            [12]  575 	anl	a,_IPH
      00016B FF               [12]  576 	mov	r7,a
      00016C E5 1C            [12]  577 	mov	a,_EXTI_setPriority_PARM_2
      00016E 03               [12]  578 	rr	a
      00016F 54 01            [12]  579 	anl	a,#0x01
      000171 4F               [12]  580 	orl	a,r7
      000172 F5 B7            [12]  581 	mov	_IPH,a
                                    582 ;	../src/exti.c:82: } break;
                                    583 ;	../src/exti.c:83: case PERIPH_EXTI_1:
      000174 22               [24]  584 	ret
      000175                        585 00102$:
                                    586 ;	../src/exti.c:86: IP  = (IP & 0xFB) | ((p & 0x01) << 0x2);
      000175 74 FB            [12]  587 	mov	a,#0xFB
      000177 55 B8            [12]  588 	anl	a,_IP
      000179 FF               [12]  589 	mov	r7,a
      00017A 74 01            [12]  590 	mov	a,#0x01
      00017C 55 1C            [12]  591 	anl	a,_EXTI_setPriority_PARM_2
      00017E 25 E0            [12]  592 	add	a,acc
      000180 25 E0            [12]  593 	add	a,acc
      000182 4F               [12]  594 	orl	a,r7
      000183 F5 B8            [12]  595 	mov	_IP,a
                                    596 ;	../src/exti.c:88: IPH = (IPH & 0xFB) | ((p & 0x02) << 0x1);
      000185 74 FB            [12]  597 	mov	a,#0xFB
      000187 55 B7            [12]  598 	anl	a,_IPH
      000189 FF               [12]  599 	mov	r7,a
      00018A 74 02            [12]  600 	mov	a,#0x02
      00018C 55 1C            [12]  601 	anl	a,_EXTI_setPriority_PARM_2
      00018E 25 E0            [12]  602 	add	a,acc
      000190 4F               [12]  603 	orl	a,r7
      000191 F5 B7            [12]  604 	mov	_IPH,a
                                    605 ;	../src/exti.c:89: } break;
                                    606 ;	../src/exti.c:90: case PERIPH_EXTI_2:
      000193 22               [24]  607 	ret
      000194                        608 00103$:
                                    609 ;	../src/exti.c:93: PX2 = (p & 0x01);
      000194 E5 1C            [12]  610 	mov	a,_EXTI_setPriority_PARM_2
      000196 13               [12]  611 	rrc	a
      000197 92 00            [24]  612 	mov  _EXTI_setPriority_sloc0_1_0,c
      000199 92 C3            [24]  613 	mov	_PX2,c
                                    614 ;	../src/exti.c:95: IPH = (IPH & 0xBF) | ((p & 0x02)) << 0x6;
      00019B 74 BF            [12]  615 	mov	a,#0xBF
      00019D 55 B7            [12]  616 	anl	a,_IPH
      00019F FF               [12]  617 	mov	r7,a
      0001A0 74 02            [12]  618 	mov	a,#0x02
      0001A2 55 1C            [12]  619 	anl	a,_EXTI_setPriority_PARM_2
      0001A4 03               [12]  620 	rr	a
      0001A5 03               [12]  621 	rr	a
      0001A6 54 C0            [12]  622 	anl	a,#0xC0
      0001A8 4F               [12]  623 	orl	a,r7
      0001A9 F5 B7            [12]  624 	mov	_IPH,a
                                    625 ;	../src/exti.c:96: } break;
                                    626 ;	../src/exti.c:97: case PERIPH_EXTI_3:
      0001AB 22               [24]  627 	ret
      0001AC                        628 00104$:
                                    629 ;	../src/exti.c:100: PX3 = (p & 0x01);
      0001AC E5 1C            [12]  630 	mov	a,_EXTI_setPriority_PARM_2
      0001AE 13               [12]  631 	rrc	a
      0001AF 92 00            [24]  632 	mov  _EXTI_setPriority_sloc0_1_0,c
      0001B1 92 C7            [24]  633 	mov	_PX3,c
                                    634 ;	../src/exti.c:102: IPH = (IPH & 0x7F) | ((p & 0x02)) << 0x7;
      0001B3 74 7F            [12]  635 	mov	a,#0x7F
      0001B5 55 B7            [12]  636 	anl	a,_IPH
      0001B7 FF               [12]  637 	mov	r7,a
      0001B8 74 02            [12]  638 	mov	a,#0x02
      0001BA 55 1C            [12]  639 	anl	a,_EXTI_setPriority_PARM_2
      0001BC 03               [12]  640 	rr	a
      0001BD 54 80            [12]  641 	anl	a,#0x80
      0001BF 4F               [12]  642 	orl	a,r7
      0001C0 F5 B7            [12]  643 	mov	_IPH,a
                                    644 ;	../src/exti.c:105: }
      0001C2 22               [24]  645 	ret
                                    646 	.area CSEG    (CODE)
                                    647 	.area CONST   (CODE)
                                    648 	.area XINIT   (CODE)
                                    649 	.area CABS    (ABS,CODE)
