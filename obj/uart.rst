                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jul 18 12:39:08 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module uart
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _TIM2_config
                                     13 	.globl _TIM2_cmd
                                     14 	.globl _TIM_config
                                     15 	.globl _TIM_cmd
                                     16 	.globl _TF2
                                     17 	.globl _EXF2
                                     18 	.globl _RCLK
                                     19 	.globl _TCLK
                                     20 	.globl _EXEN2
                                     21 	.globl _TR2
                                     22 	.globl _CT2
                                     23 	.globl _CPRL2
                                     24 	.globl _P4_0
                                     25 	.globl _P4_1
                                     26 	.globl _P4_2
                                     27 	.globl _P4_3
                                     28 	.globl _PX3
                                     29 	.globl _EX3
                                     30 	.globl _IE3
                                     31 	.globl _IT3
                                     32 	.globl _PX2
                                     33 	.globl _EX2
                                     34 	.globl _IE2
                                     35 	.globl _IT2
                                     36 	.globl _CY
                                     37 	.globl _AC
                                     38 	.globl _F0
                                     39 	.globl _RS1
                                     40 	.globl _RS0
                                     41 	.globl _OV
                                     42 	.globl _F1
                                     43 	.globl _P
                                     44 	.globl _PS
                                     45 	.globl _PT1
                                     46 	.globl _PX1
                                     47 	.globl _PT0
                                     48 	.globl _PX0
                                     49 	.globl _RD
                                     50 	.globl _WR
                                     51 	.globl _T1
                                     52 	.globl _T0
                                     53 	.globl _INT1
                                     54 	.globl _INT0
                                     55 	.globl _TXD
                                     56 	.globl _RXD
                                     57 	.globl _P3_7
                                     58 	.globl _P3_6
                                     59 	.globl _P3_5
                                     60 	.globl _P3_4
                                     61 	.globl _P3_3
                                     62 	.globl _P3_2
                                     63 	.globl _P3_1
                                     64 	.globl _P3_0
                                     65 	.globl _EA
                                     66 	.globl _ES
                                     67 	.globl _ET1
                                     68 	.globl _EX1
                                     69 	.globl _ET0
                                     70 	.globl _EX0
                                     71 	.globl _P2_7
                                     72 	.globl _P2_6
                                     73 	.globl _P2_5
                                     74 	.globl _P2_4
                                     75 	.globl _P2_3
                                     76 	.globl _P2_2
                                     77 	.globl _P2_1
                                     78 	.globl _P2_0
                                     79 	.globl _SM0
                                     80 	.globl _SM1
                                     81 	.globl _SM2
                                     82 	.globl _REN
                                     83 	.globl _TB8
                                     84 	.globl _RB8
                                     85 	.globl _TI
                                     86 	.globl _RI
                                     87 	.globl _P1_7
                                     88 	.globl _P1_6
                                     89 	.globl _P1_5
                                     90 	.globl _P1_4
                                     91 	.globl _P1_3
                                     92 	.globl _P1_2
                                     93 	.globl _P1_1
                                     94 	.globl _P1_0
                                     95 	.globl _TF1
                                     96 	.globl _TR1
                                     97 	.globl _TF0
                                     98 	.globl _TR0
                                     99 	.globl _IE1
                                    100 	.globl _IT1
                                    101 	.globl _IE0
                                    102 	.globl _IT0
                                    103 	.globl _P0_7
                                    104 	.globl _P0_6
                                    105 	.globl _P0_5
                                    106 	.globl _P0_4
                                    107 	.globl _P0_3
                                    108 	.globl _P0_2
                                    109 	.globl _P0_1
                                    110 	.globl _P0_0
                                    111 	.globl _P4
                                    112 	.globl _ISP_CONTR
                                    113 	.globl _ISP_TRIG
                                    114 	.globl _ISP_CMD
                                    115 	.globl _ISP_ADDRL
                                    116 	.globl _ISP_ADDRH
                                    117 	.globl _ISP_DATA
                                    118 	.globl _WDT_CONTR
                                    119 	.globl _TH2
                                    120 	.globl _TL2
                                    121 	.globl _RCAP2H
                                    122 	.globl _RCAP2L
                                    123 	.globl _T2MOD
                                    124 	.globl _T2CON
                                    125 	.globl _XICON
                                    126 	.globl _IPH
                                    127 	.globl _SADDR1
                                    128 	.globl _AUXR1
                                    129 	.globl _AUXR
                                    130 	.globl _B
                                    131 	.globl _ACC
                                    132 	.globl _PSW
                                    133 	.globl _IP
                                    134 	.globl _P3
                                    135 	.globl _IE
                                    136 	.globl _P2
                                    137 	.globl _SBUF
                                    138 	.globl _SCON
                                    139 	.globl _P1
                                    140 	.globl _TH1
                                    141 	.globl _TH0
                                    142 	.globl _TL1
                                    143 	.globl _TL0
                                    144 	.globl _TMOD
                                    145 	.globl _TCON
                                    146 	.globl _PCON
                                    147 	.globl _DPH
                                    148 	.globl _DPL
                                    149 	.globl _SP
                                    150 	.globl _P0
                                    151 	.globl _UART_getTimerInitValue_PARM_2
                                    152 	.globl _UART_cmd_multiBaudrate
                                    153 	.globl _UART_cmd_receive
                                    154 	.globl _UART_config
                                    155 	.globl _UART_getTimerInitValue
                                    156 	.globl _UART_isReceived
                                    157 	.globl _UART_isTransmitted
                                    158 	.globl _UART_sendByte
                                    159 	.globl _UART_sendString
                                    160 	.globl _UART_setMode
                                    161 	.globl _UART_INT_setPriority
                                    162 	.globl _UART_INT_cmd
                                    163 ;--------------------------------------------------------
                                    164 ; special function registers
                                    165 ;--------------------------------------------------------
                                    166 	.area RSEG    (ABS,DATA)
      000000                        167 	.org 0x0000
                           000080   168 _P0	=	0x0080
                           000081   169 _SP	=	0x0081
                           000082   170 _DPL	=	0x0082
                           000083   171 _DPH	=	0x0083
                           000087   172 _PCON	=	0x0087
                           000088   173 _TCON	=	0x0088
                           000089   174 _TMOD	=	0x0089
                           00008A   175 _TL0	=	0x008a
                           00008B   176 _TL1	=	0x008b
                           00008C   177 _TH0	=	0x008c
                           00008D   178 _TH1	=	0x008d
                           000090   179 _P1	=	0x0090
                           000098   180 _SCON	=	0x0098
                           000099   181 _SBUF	=	0x0099
                           0000A0   182 _P2	=	0x00a0
                           0000A8   183 _IE	=	0x00a8
                           0000B0   184 _P3	=	0x00b0
                           0000B8   185 _IP	=	0x00b8
                           0000D0   186 _PSW	=	0x00d0
                           0000E0   187 _ACC	=	0x00e0
                           0000F0   188 _B	=	0x00f0
                           00008E   189 _AUXR	=	0x008e
                           0000A2   190 _AUXR1	=	0x00a2
                           0000A9   191 _SADDR1	=	0x00a9
                           0000B7   192 _IPH	=	0x00b7
                           0000C0   193 _XICON	=	0x00c0
                           0000C8   194 _T2CON	=	0x00c8
                           0000C9   195 _T2MOD	=	0x00c9
                           0000CA   196 _RCAP2L	=	0x00ca
                           0000CB   197 _RCAP2H	=	0x00cb
                           0000CC   198 _TL2	=	0x00cc
                           0000CD   199 _TH2	=	0x00cd
                           0000E1   200 _WDT_CONTR	=	0x00e1
                           0000E2   201 _ISP_DATA	=	0x00e2
                           0000E3   202 _ISP_ADDRH	=	0x00e3
                           0000E4   203 _ISP_ADDRL	=	0x00e4
                           0000E5   204 _ISP_CMD	=	0x00e5
                           0000E6   205 _ISP_TRIG	=	0x00e6
                           0000E7   206 _ISP_CONTR	=	0x00e7
                           0000E8   207 _P4	=	0x00e8
                                    208 ;--------------------------------------------------------
                                    209 ; special function bits
                                    210 ;--------------------------------------------------------
                                    211 	.area RSEG    (ABS,DATA)
      000000                        212 	.org 0x0000
                           000080   213 _P0_0	=	0x0080
                           000081   214 _P0_1	=	0x0081
                           000082   215 _P0_2	=	0x0082
                           000083   216 _P0_3	=	0x0083
                           000084   217 _P0_4	=	0x0084
                           000085   218 _P0_5	=	0x0085
                           000086   219 _P0_6	=	0x0086
                           000087   220 _P0_7	=	0x0087
                           000088   221 _IT0	=	0x0088
                           000089   222 _IE0	=	0x0089
                           00008A   223 _IT1	=	0x008a
                           00008B   224 _IE1	=	0x008b
                           00008C   225 _TR0	=	0x008c
                           00008D   226 _TF0	=	0x008d
                           00008E   227 _TR1	=	0x008e
                           00008F   228 _TF1	=	0x008f
                           000090   229 _P1_0	=	0x0090
                           000091   230 _P1_1	=	0x0091
                           000092   231 _P1_2	=	0x0092
                           000093   232 _P1_3	=	0x0093
                           000094   233 _P1_4	=	0x0094
                           000095   234 _P1_5	=	0x0095
                           000096   235 _P1_6	=	0x0096
                           000097   236 _P1_7	=	0x0097
                           000098   237 _RI	=	0x0098
                           000099   238 _TI	=	0x0099
                           00009A   239 _RB8	=	0x009a
                           00009B   240 _TB8	=	0x009b
                           00009C   241 _REN	=	0x009c
                           00009D   242 _SM2	=	0x009d
                           00009E   243 _SM1	=	0x009e
                           00009F   244 _SM0	=	0x009f
                           0000A0   245 _P2_0	=	0x00a0
                           0000A1   246 _P2_1	=	0x00a1
                           0000A2   247 _P2_2	=	0x00a2
                           0000A3   248 _P2_3	=	0x00a3
                           0000A4   249 _P2_4	=	0x00a4
                           0000A5   250 _P2_5	=	0x00a5
                           0000A6   251 _P2_6	=	0x00a6
                           0000A7   252 _P2_7	=	0x00a7
                           0000A8   253 _EX0	=	0x00a8
                           0000A9   254 _ET0	=	0x00a9
                           0000AA   255 _EX1	=	0x00aa
                           0000AB   256 _ET1	=	0x00ab
                           0000AC   257 _ES	=	0x00ac
                           0000AF   258 _EA	=	0x00af
                           0000B0   259 _P3_0	=	0x00b0
                           0000B1   260 _P3_1	=	0x00b1
                           0000B2   261 _P3_2	=	0x00b2
                           0000B3   262 _P3_3	=	0x00b3
                           0000B4   263 _P3_4	=	0x00b4
                           0000B5   264 _P3_5	=	0x00b5
                           0000B6   265 _P3_6	=	0x00b6
                           0000B7   266 _P3_7	=	0x00b7
                           0000B0   267 _RXD	=	0x00b0
                           0000B1   268 _TXD	=	0x00b1
                           0000B2   269 _INT0	=	0x00b2
                           0000B3   270 _INT1	=	0x00b3
                           0000B4   271 _T0	=	0x00b4
                           0000B5   272 _T1	=	0x00b5
                           0000B6   273 _WR	=	0x00b6
                           0000B7   274 _RD	=	0x00b7
                           0000B8   275 _PX0	=	0x00b8
                           0000B9   276 _PT0	=	0x00b9
                           0000BA   277 _PX1	=	0x00ba
                           0000BB   278 _PT1	=	0x00bb
                           0000BC   279 _PS	=	0x00bc
                           0000D0   280 _P	=	0x00d0
                           0000D1   281 _F1	=	0x00d1
                           0000D2   282 _OV	=	0x00d2
                           0000D3   283 _RS0	=	0x00d3
                           0000D4   284 _RS1	=	0x00d4
                           0000D5   285 _F0	=	0x00d5
                           0000D6   286 _AC	=	0x00d6
                           0000D7   287 _CY	=	0x00d7
                           0000C0   288 _IT2	=	0x00c0
                           0000C1   289 _IE2	=	0x00c1
                           0000C2   290 _EX2	=	0x00c2
                           0000C3   291 _PX2	=	0x00c3
                           0000C4   292 _IT3	=	0x00c4
                           0000C5   293 _IE3	=	0x00c5
                           0000C6   294 _EX3	=	0x00c6
                           0000C7   295 _PX3	=	0x00c7
                           0000EB   296 _P4_3	=	0x00eb
                           0000EA   297 _P4_2	=	0x00ea
                           0000E9   298 _P4_1	=	0x00e9
                           0000E8   299 _P4_0	=	0x00e8
                           0000C8   300 _CPRL2	=	0x00c8
                           0000C9   301 _CT2	=	0x00c9
                           0000CA   302 _TR2	=	0x00ca
                           0000CB   303 _EXEN2	=	0x00cb
                           0000CC   304 _TCLK	=	0x00cc
                           0000CD   305 _RCLK	=	0x00cd
                           0000CE   306 _EXF2	=	0x00ce
                           0000CF   307 _TF2	=	0x00cf
                                    308 ;--------------------------------------------------------
                                    309 ; overlayable register banks
                                    310 ;--------------------------------------------------------
                                    311 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        312 	.ds 8
                                    313 ;--------------------------------------------------------
                                    314 ; internal ram data
                                    315 ;--------------------------------------------------------
                                    316 	.area DSEG    (DATA)
      000021                        317 _UART_config_tc_1_41:
      000021                        318 	.ds 6
      000027                        319 _UART_config_tc2_1_41:
      000027                        320 	.ds 6
      00002D                        321 _UART_getTimerInitValue_PARM_2:
      00002D                        322 	.ds 1
                                    323 ;--------------------------------------------------------
                                    324 ; overlayable items in internal ram 
                                    325 ;--------------------------------------------------------
                                    326 	.area	OSEG    (OVR,DATA)
                                    327 	.area	OSEG    (OVR,DATA)
                                    328 	.area	OSEG    (OVR,DATA)
                                    329 	.area	OSEG    (OVR,DATA)
                                    330 	.area	OSEG    (OVR,DATA)
                                    331 	.area	OSEG    (OVR,DATA)
                                    332 	.area	OSEG    (OVR,DATA)
                                    333 ;--------------------------------------------------------
                                    334 ; indirectly addressable internal ram data
                                    335 ;--------------------------------------------------------
                                    336 	.area ISEG    (DATA)
                                    337 ;--------------------------------------------------------
                                    338 ; absolute internal ram data
                                    339 ;--------------------------------------------------------
                                    340 	.area IABS    (ABS,DATA)
                                    341 	.area IABS    (ABS,DATA)
                                    342 ;--------------------------------------------------------
                                    343 ; bit data
                                    344 ;--------------------------------------------------------
                                    345 	.area BSEG    (BIT)
                                    346 ;--------------------------------------------------------
                                    347 ; paged external ram data
                                    348 ;--------------------------------------------------------
                                    349 	.area PSEG    (PAG,XDATA)
                                    350 ;--------------------------------------------------------
                                    351 ; external ram data
                                    352 ;--------------------------------------------------------
                                    353 	.area XSEG    (XDATA)
                                    354 ;--------------------------------------------------------
                                    355 ; absolute external ram data
                                    356 ;--------------------------------------------------------
                                    357 	.area XABS    (ABS,XDATA)
                                    358 ;--------------------------------------------------------
                                    359 ; external initialized ram data
                                    360 ;--------------------------------------------------------
                                    361 	.area XISEG   (XDATA)
                                    362 	.area HOME    (CODE)
                                    363 	.area GSINIT0 (CODE)
                                    364 	.area GSINIT1 (CODE)
                                    365 	.area GSINIT2 (CODE)
                                    366 	.area GSINIT3 (CODE)
                                    367 	.area GSINIT4 (CODE)
                                    368 	.area GSINIT5 (CODE)
                                    369 	.area GSINIT  (CODE)
                                    370 	.area GSFINAL (CODE)
                                    371 	.area CSEG    (CODE)
                                    372 ;--------------------------------------------------------
                                    373 ; global & static initialisations
                                    374 ;--------------------------------------------------------
                                    375 	.area HOME    (CODE)
                                    376 	.area GSINIT  (CODE)
                                    377 	.area GSFINAL (CODE)
                                    378 	.area GSINIT  (CODE)
                                    379 ;--------------------------------------------------------
                                    380 ; Home
                                    381 ;--------------------------------------------------------
                                    382 	.area HOME    (CODE)
                                    383 	.area HOME    (CODE)
                                    384 ;--------------------------------------------------------
                                    385 ; code
                                    386 ;--------------------------------------------------------
                                    387 	.area CSEG    (CODE)
                                    388 ;------------------------------------------------------------
                                    389 ;Allocation info for local variables in function 'UART_cmd_multiBaudrate'
                                    390 ;------------------------------------------------------------
                                    391 ;a                         Allocated to registers r7 
                                    392 ;------------------------------------------------------------
                                    393 ;	../src/uart.c:20: void UART_cmd_multiBaudrate(Action a)
                                    394 ;	-----------------------------------------
                                    395 ;	 function UART_cmd_multiBaudrate
                                    396 ;	-----------------------------------------
      000871                        397 _UART_cmd_multiBaudrate:
                           000007   398 	ar7 = 0x07
                           000006   399 	ar6 = 0x06
                           000005   400 	ar5 = 0x05
                           000004   401 	ar4 = 0x04
                           000003   402 	ar3 = 0x03
                           000002   403 	ar2 = 0x02
                           000001   404 	ar1 = 0x01
                           000000   405 	ar0 = 0x00
      000871 AF 82            [24]  406 	mov	r7,dpl
                                    407 ;	../src/uart.c:22: PCON = (PCON & 0x7F) | ((unsigned char)a << 0x7);
      000873 74 7F            [12]  408 	mov	a,#0x7F
      000875 55 87            [12]  409 	anl	a,_PCON
      000877 FE               [12]  410 	mov	r6,a
      000878 EF               [12]  411 	mov	a,r7
      000879 03               [12]  412 	rr	a
      00087A 54 80            [12]  413 	anl	a,#0x80
      00087C 4E               [12]  414 	orl	a,r6
      00087D F5 87            [12]  415 	mov	_PCON,a
      00087F 22               [24]  416 	ret
                                    417 ;------------------------------------------------------------
                                    418 ;Allocation info for local variables in function 'UART_cmd_receive'
                                    419 ;------------------------------------------------------------
                                    420 ;a                         Allocated to registers r7 
                                    421 ;------------------------------------------------------------
                                    422 ;	../src/uart.c:31: void UART_cmd_receive(Action a)
                                    423 ;	-----------------------------------------
                                    424 ;	 function UART_cmd_receive
                                    425 ;	-----------------------------------------
      000880                        426 _UART_cmd_receive:
                                    427 ;	../src/uart.c:33: REN = a;
      000880 E5 82            [12]  428 	mov	a,dpl
      000882 24 FF            [12]  429 	add	a,#0xff
      000884 92 9C            [24]  430 	mov	_REN,c
      000886 22               [24]  431 	ret
                                    432 ;------------------------------------------------------------
                                    433 ;Allocation info for local variables in function 'UART_config'
                                    434 ;------------------------------------------------------------
                                    435 ;uc                        Allocated to registers r5 r6 r7 
                                    436 ;tc                        Allocated with name '_UART_config_tc_1_41'
                                    437 ;tc2                       Allocated with name '_UART_config_tc2_1_41'
                                    438 ;------------------------------------------------------------
                                    439 ;	../src/uart.c:42: void UART_config(UART_configTypeDef *uc)
                                    440 ;	-----------------------------------------
                                    441 ;	 function UART_config
                                    442 ;	-----------------------------------------
      000887                        443 _UART_config:
      000887 AD 82            [24]  444 	mov	r5,dpl
      000889 AE 83            [24]  445 	mov	r6,dph
      00088B AF F0            [24]  446 	mov	r7,b
                                    447 ;	../src/uart.c:47: UART_INT_cmd(uc->interruptState);
      00088D 74 02            [12]  448 	mov	a,#0x02
      00088F 2D               [12]  449 	add	a,r5
      000890 FA               [12]  450 	mov	r2,a
      000891 E4               [12]  451 	clr	a
      000892 3E               [12]  452 	addc	a,r6
      000893 FB               [12]  453 	mov	r3,a
      000894 8F 04            [24]  454 	mov	ar4,r7
      000896 8A 82            [24]  455 	mov	dpl,r2
      000898 8B 83            [24]  456 	mov	dph,r3
      00089A 8C F0            [24]  457 	mov	b,r4
      00089C 12 0C 42         [24]  458 	lcall	__gptrget
      00089F F5 82            [12]  459 	mov	dpl,a
      0008A1 C0 07            [24]  460 	push	ar7
      0008A3 C0 06            [24]  461 	push	ar6
      0008A5 C0 05            [24]  462 	push	ar5
      0008A7 12 0B 17         [24]  463 	lcall	_UART_INT_cmd
      0008AA D0 05            [24]  464 	pop	ar5
      0008AC D0 06            [24]  465 	pop	ar6
      0008AE D0 07            [24]  466 	pop	ar7
                                    467 ;	../src/uart.c:48: UART_INT_setPriority(uc->interruptPriority);
      0008B0 74 03            [12]  468 	mov	a,#0x03
      0008B2 2D               [12]  469 	add	a,r5
      0008B3 FA               [12]  470 	mov	r2,a
      0008B4 E4               [12]  471 	clr	a
      0008B5 3E               [12]  472 	addc	a,r6
      0008B6 FB               [12]  473 	mov	r3,a
      0008B7 8F 04            [24]  474 	mov	ar4,r7
      0008B9 8A 82            [24]  475 	mov	dpl,r2
      0008BB 8B 83            [24]  476 	mov	dph,r3
      0008BD 8C F0            [24]  477 	mov	b,r4
      0008BF 12 0C 42         [24]  478 	lcall	__gptrget
      0008C2 F5 82            [12]  479 	mov	dpl,a
      0008C4 C0 07            [24]  480 	push	ar7
      0008C6 C0 06            [24]  481 	push	ar6
      0008C8 C0 05            [24]  482 	push	ar5
      0008CA 12 0A F6         [24]  483 	lcall	_UART_INT_setPriority
      0008CD D0 05            [24]  484 	pop	ar5
      0008CF D0 06            [24]  485 	pop	ar6
      0008D1 D0 07            [24]  486 	pop	ar7
                                    487 ;	../src/uart.c:49: UART_cmd_multiBaudrate(uc->multiBaudrate);
      0008D3 74 05            [12]  488 	mov	a,#0x05
      0008D5 2D               [12]  489 	add	a,r5
      0008D6 FA               [12]  490 	mov	r2,a
      0008D7 E4               [12]  491 	clr	a
      0008D8 3E               [12]  492 	addc	a,r6
      0008D9 FB               [12]  493 	mov	r3,a
      0008DA 8F 04            [24]  494 	mov	ar4,r7
      0008DC 8A 82            [24]  495 	mov	dpl,r2
      0008DE 8B 83            [24]  496 	mov	dph,r3
      0008E0 8C F0            [24]  497 	mov	b,r4
      0008E2 12 0C 42         [24]  498 	lcall	__gptrget
      0008E5 F5 82            [12]  499 	mov	dpl,a
      0008E7 C0 07            [24]  500 	push	ar7
      0008E9 C0 06            [24]  501 	push	ar6
      0008EB C0 05            [24]  502 	push	ar5
      0008ED 12 08 71         [24]  503 	lcall	_UART_cmd_multiBaudrate
      0008F0 D0 05            [24]  504 	pop	ar5
      0008F2 D0 06            [24]  505 	pop	ar6
      0008F4 D0 07            [24]  506 	pop	ar7
                                    507 ;	../src/uart.c:50: UART_setMode(uc->mode);
      0008F6 74 04            [12]  508 	mov	a,#0x04
      0008F8 2D               [12]  509 	add	a,r5
      0008F9 FA               [12]  510 	mov	r2,a
      0008FA E4               [12]  511 	clr	a
      0008FB 3E               [12]  512 	addc	a,r6
      0008FC FB               [12]  513 	mov	r3,a
      0008FD 8F 04            [24]  514 	mov	ar4,r7
      0008FF 8A 82            [24]  515 	mov	dpl,r2
      000901 8B 83            [24]  516 	mov	dph,r3
      000903 8C F0            [24]  517 	mov	b,r4
      000905 12 0C 42         [24]  518 	lcall	__gptrget
      000908 F5 82            [12]  519 	mov	dpl,a
      00090A C0 07            [24]  520 	push	ar7
      00090C C0 06            [24]  521 	push	ar6
      00090E C0 05            [24]  522 	push	ar5
      000910 12 0A E6         [24]  523 	lcall	_UART_setMode
      000913 D0 05            [24]  524 	pop	ar5
      000915 D0 06            [24]  525 	pop	ar6
      000917 D0 07            [24]  526 	pop	ar7
                                    527 ;	../src/uart.c:51: UART_cmd_receive(uc->receiveState);
      000919 74 06            [12]  528 	mov	a,#0x06
      00091B 2D               [12]  529 	add	a,r5
      00091C FA               [12]  530 	mov	r2,a
      00091D E4               [12]  531 	clr	a
      00091E 3E               [12]  532 	addc	a,r6
      00091F FB               [12]  533 	mov	r3,a
      000920 8F 04            [24]  534 	mov	ar4,r7
      000922 8A 82            [24]  535 	mov	dpl,r2
      000924 8B 83            [24]  536 	mov	dph,r3
      000926 8C F0            [24]  537 	mov	b,r4
      000928 12 0C 42         [24]  538 	lcall	__gptrget
      00092B F5 82            [12]  539 	mov	dpl,a
      00092D C0 07            [24]  540 	push	ar7
      00092F C0 06            [24]  541 	push	ar6
      000931 C0 05            [24]  542 	push	ar5
      000933 12 08 80         [24]  543 	lcall	_UART_cmd_receive
      000936 D0 05            [24]  544 	pop	ar5
      000938 D0 06            [24]  545 	pop	ar6
      00093A D0 07            [24]  546 	pop	ar7
                                    547 ;	../src/uart.c:53: switch(uc->tim)
      00093C 74 07            [12]  548 	mov	a,#0x07
      00093E 2D               [12]  549 	add	a,r5
      00093F FA               [12]  550 	mov	r2,a
      000940 E4               [12]  551 	clr	a
      000941 3E               [12]  552 	addc	a,r6
      000942 FB               [12]  553 	mov	r3,a
      000943 8F 04            [24]  554 	mov	ar4,r7
      000945 8A 82            [24]  555 	mov	dpl,r2
      000947 8B 83            [24]  556 	mov	dph,r3
      000949 8C F0            [24]  557 	mov	b,r4
      00094B 12 0C 42         [24]  558 	lcall	__gptrget
      00094E FC               [12]  559 	mov	r4,a
      00094F BC 01 02         [24]  560 	cjne	r4,#0x01,00113$
      000952 80 06            [24]  561 	sjmp	00101$
      000954                        562 00113$:
      000954 BC 02 02         [24]  563 	cjne	r4,#0x02,00114$
      000957 80 48            [24]  564 	sjmp	00102$
      000959                        565 00114$:
      000959 22               [24]  566 	ret
                                    567 ;	../src/uart.c:55: case PERIPH_TIM_1:
      00095A                        568 00101$:
                                    569 ;	../src/uart.c:56: tc.function          = TIM_FUNC_TIM;
      00095A 75 21 00         [24]  570 	mov	_UART_config_tc_1_41,#0x00
                                    571 ;	../src/uart.c:57: tc.interruptState    = DISABLE;
      00095D 75 22 00         [24]  572 	mov	(_UART_config_tc_1_41 + 0x0001),#0x00
                                    573 ;	../src/uart.c:58: tc.interruptPriority = DISABLE;
      000960 75 23 00         [24]  574 	mov	(_UART_config_tc_1_41 + 0x0002),#0x00
                                    575 ;	../src/uart.c:59: tc.mode              = TIM_MODE_2;
      000963 75 24 02         [24]  576 	mov	(_UART_config_tc_1_41 + 0x0003),#0x02
                                    577 ;	../src/uart.c:60: tc.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM_1);
      000966 8D 82            [24]  578 	mov	dpl,r5
      000968 8E 83            [24]  579 	mov	dph,r6
      00096A 8F F0            [24]  580 	mov	b,r7
      00096C 12 0C 42         [24]  581 	lcall	__gptrget
      00096F FB               [12]  582 	mov	r3,a
      000970 A3               [24]  583 	inc	dptr
      000971 12 0C 42         [24]  584 	lcall	__gptrget
      000974 FC               [12]  585 	mov	r4,a
      000975 75 2D 01         [24]  586 	mov	_UART_getTimerInitValue_PARM_2,#0x01
      000978 8B 82            [24]  587 	mov	dpl,r3
      00097A 8C 83            [24]  588 	mov	dph,r4
      00097C 12 09 E4         [24]  589 	lcall	_UART_getTimerInitValue
      00097F E5 82            [12]  590 	mov	a,dpl
      000981 85 83 F0         [24]  591 	mov	b,dph
      000984 F5 25            [12]  592 	mov	((_UART_config_tc_1_41 + 0x0004) + 0),a
      000986 85 F0 26         [24]  593 	mov	((_UART_config_tc_1_41 + 0x0004) + 1),b
                                    594 ;	../src/uart.c:61: TIM_config(PERIPH_TIM_1,&tc);
      000989 75 19 21         [24]  595 	mov	_TIM_config_PARM_2,#_UART_config_tc_1_41
      00098C 75 1A 00         [24]  596 	mov	(_TIM_config_PARM_2 + 1),#0x00
      00098F 75 1B 40         [24]  597 	mov	(_TIM_config_PARM_2 + 2),#0x40
      000992 75 82 01         [24]  598 	mov	dpl,#0x01
      000995 12 05 17         [24]  599 	lcall	_TIM_config
                                    600 ;	../src/uart.c:62: TIM_cmd(PERIPH_TIM_1,ENABLE);
      000998 75 1C 01         [24]  601 	mov	_TIM_cmd_PARM_2,#0x01
      00099B 75 82 01         [24]  602 	mov	dpl,#0x01
                                    603 ;	../src/uart.c:63: break;
                                    604 ;	../src/uart.c:65: case PERIPH_TIM2:
      00099E 02 04 FD         [24]  605 	ljmp	_TIM_cmd
      0009A1                        606 00102$:
                                    607 ;	../src/uart.c:66: tc2.function          = TIM2_FUNC_TIM;
      0009A1 75 27 00         [24]  608 	mov	_UART_config_tc2_1_41,#0x00
                                    609 ;	../src/uart.c:67: tc2.interruptState    = DISABLE;
      0009A4 75 28 00         [24]  610 	mov	(_UART_config_tc2_1_41 + 0x0001),#0x00
                                    611 ;	../src/uart.c:68: tc2.interruptPriority = DISABLE;
      0009A7 75 29 00         [24]  612 	mov	(_UART_config_tc2_1_41 + 0x0002),#0x00
                                    613 ;	../src/uart.c:69: tc2.mode              = TIM2_MODE_baudrateProducer;
      0009AA 75 2A 30         [24]  614 	mov	(_UART_config_tc2_1_41 + 0x0003),#0x30
                                    615 ;	../src/uart.c:70: tc2.value             = UART_getTimerInitValue(uc->baudrate,PERIPH_TIM2);
      0009AD 8D 82            [24]  616 	mov	dpl,r5
      0009AF 8E 83            [24]  617 	mov	dph,r6
      0009B1 8F F0            [24]  618 	mov	b,r7
      0009B3 12 0C 42         [24]  619 	lcall	__gptrget
      0009B6 FD               [12]  620 	mov	r5,a
      0009B7 A3               [24]  621 	inc	dptr
      0009B8 12 0C 42         [24]  622 	lcall	__gptrget
      0009BB FE               [12]  623 	mov	r6,a
      0009BC 75 2D 02         [24]  624 	mov	_UART_getTimerInitValue_PARM_2,#0x02
      0009BF 8D 82            [24]  625 	mov	dpl,r5
      0009C1 8E 83            [24]  626 	mov	dph,r6
      0009C3 12 09 E4         [24]  627 	lcall	_UART_getTimerInitValue
      0009C6 AE 82            [24]  628 	mov	r6,dpl
      0009C8 AF 83            [24]  629 	mov	r7,dph
      0009CA 8E 2B            [24]  630 	mov	((_UART_config_tc2_1_41 + 0x0004) + 0),r6
      0009CC 8F 2C            [24]  631 	mov	((_UART_config_tc2_1_41 + 0x0004) + 1),r7
                                    632 ;	../src/uart.c:71: RCAP2L = tc2.value;
      0009CE 8E CA            [24]  633 	mov	_RCAP2L,r6
                                    634 ;	../src/uart.c:72: RCAP2H = (tc2.value >> 8);
      0009D0 8F CB            [24]  635 	mov	_RCAP2H,r7
                                    636 ;	../src/uart.c:73: TIM2_config(&tc2);
      0009D2 90 00 27         [24]  637 	mov	dptr,#_UART_config_tc2_1_41
      0009D5 75 F0 40         [24]  638 	mov	b,#0x40
      0009D8 12 07 58         [24]  639 	lcall	_TIM2_config
                                    640 ;	../src/uart.c:74: T2MOD = 0x02;
      0009DB 75 C9 02         [24]  641 	mov	_T2MOD,#0x02
                                    642 ;	../src/uart.c:75: TIM2_cmd(ENABLE);
      0009DE 75 82 01         [24]  643 	mov	dpl,#0x01
                                    644 ;	../src/uart.c:79: }
      0009E1 02 07 49         [24]  645 	ljmp	_TIM2_cmd
                                    646 ;------------------------------------------------------------
                                    647 ;Allocation info for local variables in function 'UART_getTimerInitValue'
                                    648 ;------------------------------------------------------------
                                    649 ;tim                       Allocated with name '_UART_getTimerInitValue_PARM_2'
                                    650 ;baud                      Allocated to registers r6 r7 
                                    651 ;tmp                       Allocated to registers r5 
                                    652 ;------------------------------------------------------------
                                    653 ;	../src/uart.c:88: unsigned int UART_getTimerInitValue(unsigned int baud,PERIPH_TIM tim)
                                    654 ;	-----------------------------------------
                                    655 ;	 function UART_getTimerInitValue
                                    656 ;	-----------------------------------------
      0009E4                        657 _UART_getTimerInitValue:
      0009E4 AE 82            [24]  658 	mov	r6,dpl
      0009E6 AF 83            [24]  659 	mov	r7,dph
                                    660 ;	../src/uart.c:90: unsigned char tmp = 0x00;
      0009E8 7D 00            [12]  661 	mov	r5,#0x00
                                    662 ;	../src/uart.c:93: switch(tim)
      0009EA 74 01            [12]  663 	mov	a,#0x01
      0009EC B5 2D 02         [24]  664 	cjne	a,_UART_getTimerInitValue_PARM_2,00131$
      0009EF 80 0B            [24]  665 	sjmp	00101$
      0009F1                        666 00131$:
      0009F1 74 02            [12]  667 	mov	a,#0x02
      0009F3 B5 2D 03         [24]  668 	cjne	a,_UART_getTimerInitValue_PARM_2,00132$
      0009F6 02 0A 7C         [24]  669 	ljmp	00111$
      0009F9                        670 00132$:
      0009F9 02 0A 9F         [24]  671 	ljmp	00113$
                                    672 ;	../src/uart.c:95: case PERIPH_TIM_1:
      0009FC                        673 00101$:
                                    674 ;	../src/uart.c:96: if(PCON & 0x80)     /* multi baudrate mode */
      0009FC E5 87            [12]  675 	mov	a,_PCON
      0009FE 30 E7 3D         [24]  676 	jnb	acc.7,00109$
                                    677 ;	../src/uart.c:98: if(baud > _FRE_OSC_/12/16)
      000A01 8E 01            [24]  678 	mov	ar1,r6
      000A03 8F 02            [24]  679 	mov	ar2,r7
      000A05 7B 00            [12]  680 	mov	r3,#0x00
      000A07 7C 00            [12]  681 	mov	r4,#0x00
      000A09 C3               [12]  682 	clr	c
      000A0A E4               [12]  683 	clr	a
      000A0B 99               [12]  684 	subb	a,r1
      000A0C 74 E1            [12]  685 	mov	a,#0xE1
      000A0E 9A               [12]  686 	subb	a,r2
      000A0F E4               [12]  687 	clr	a
      000A10 9B               [12]  688 	subb	a,r3
      000A11 74 80            [12]  689 	mov	a,#(0x00 ^ 0x80)
      000A13 8C F0            [24]  690 	mov	b,r4
      000A15 63 F0 80         [24]  691 	xrl	b,#0x80
      000A18 95 F0            [12]  692 	subb	a,b
      000A1A 50 04            [24]  693 	jnc	00103$
                                    694 ;	../src/uart.c:101: return 0x0000;
      000A1C 90 00 00         [24]  695 	mov	dptr,#0x0000
      000A1F 22               [24]  696 	ret
      000A20                        697 00103$:
                                    698 ;	../src/uart.c:105: tmp = (256 - _FRE_OSC_/16/12/baud);  
      000A20 89 1C            [24]  699 	mov	__divslong_PARM_2,r1
      000A22 8A 1D            [24]  700 	mov	(__divslong_PARM_2 + 1),r2
      000A24 8B 1E            [24]  701 	mov	(__divslong_PARM_2 + 2),r3
      000A26 8C 1F            [24]  702 	mov	(__divslong_PARM_2 + 3),r4
      000A28 90 E1 00         [24]  703 	mov	dptr,#0xE100
      000A2B E4               [12]  704 	clr	a
      000A2C F5 F0            [12]  705 	mov	b,a
      000A2E 12 0B F0         [24]  706 	lcall	__divslong
      000A31 A9 82            [24]  707 	mov	r1,dpl
      000A33 AA 83            [24]  708 	mov	r2,dph
      000A35 AB F0            [24]  709 	mov	r3,b
      000A37 FC               [12]  710 	mov	r4,a
      000A38 C3               [12]  711 	clr	c
      000A39 E4               [12]  712 	clr	a
      000A3A 99               [12]  713 	subb	a,r1
      000A3B FD               [12]  714 	mov	r5,a
      000A3C 80 61            [24]  715 	sjmp	00113$
      000A3E                        716 00109$:
                                    717 ;	../src/uart.c:110: if(baud > _FRE_OSC_/12/32)
      000A3E 8E 01            [24]  718 	mov	ar1,r6
      000A40 8F 02            [24]  719 	mov	ar2,r7
      000A42 7B 00            [12]  720 	mov	r3,#0x00
      000A44 7C 00            [12]  721 	mov	r4,#0x00
      000A46 C3               [12]  722 	clr	c
      000A47 74 80            [12]  723 	mov	a,#0x80
      000A49 99               [12]  724 	subb	a,r1
      000A4A 74 70            [12]  725 	mov	a,#0x70
      000A4C 9A               [12]  726 	subb	a,r2
      000A4D E4               [12]  727 	clr	a
      000A4E 9B               [12]  728 	subb	a,r3
      000A4F 74 80            [12]  729 	mov	a,#(0x00 ^ 0x80)
      000A51 8C F0            [24]  730 	mov	b,r4
      000A53 63 F0 80         [24]  731 	xrl	b,#0x80
      000A56 95 F0            [12]  732 	subb	a,b
      000A58 50 04            [24]  733 	jnc	00106$
                                    734 ;	../src/uart.c:112: return 0x0000;
      000A5A 90 00 00         [24]  735 	mov	dptr,#0x0000
      000A5D 22               [24]  736 	ret
      000A5E                        737 00106$:
                                    738 ;	../src/uart.c:116: tmp = (256 - _FRE_OSC_/32/12/baud);
      000A5E 89 1C            [24]  739 	mov	__divslong_PARM_2,r1
      000A60 8A 1D            [24]  740 	mov	(__divslong_PARM_2 + 1),r2
      000A62 8B 1E            [24]  741 	mov	(__divslong_PARM_2 + 2),r3
      000A64 8C 1F            [24]  742 	mov	(__divslong_PARM_2 + 3),r4
      000A66 90 70 80         [24]  743 	mov	dptr,#0x7080
      000A69 E4               [12]  744 	clr	a
      000A6A F5 F0            [12]  745 	mov	b,a
      000A6C 12 0B F0         [24]  746 	lcall	__divslong
      000A6F A9 82            [24]  747 	mov	r1,dpl
      000A71 AA 83            [24]  748 	mov	r2,dph
      000A73 AB F0            [24]  749 	mov	r3,b
      000A75 FC               [12]  750 	mov	r4,a
      000A76 C3               [12]  751 	clr	c
      000A77 E4               [12]  752 	clr	a
      000A78 99               [12]  753 	subb	a,r1
      000A79 FD               [12]  754 	mov	r5,a
                                    755 ;	../src/uart.c:119: break;
                                    756 ;	../src/uart.c:121: case PERIPH_TIM2:
      000A7A 80 23            [24]  757 	sjmp	00113$
      000A7C                        758 00111$:
                                    759 ;	../src/uart.c:122: return tmp = (65536 - (_FRE_OSC_/32/baud));
      000A7C 8E 1C            [24]  760 	mov	__divslong_PARM_2,r6
      000A7E 8F 1D            [24]  761 	mov	(__divslong_PARM_2 + 1),r7
      000A80 75 1E 00         [24]  762 	mov	(__divslong_PARM_2 + 2),#0x00
      000A83 75 1F 00         [24]  763 	mov	(__divslong_PARM_2 + 3),#0x00
      000A86 90 46 00         [24]  764 	mov	dptr,#0x4600
      000A89 75 F0 05         [24]  765 	mov	b,#0x05
      000A8C E4               [12]  766 	clr	a
      000A8D 12 0B F0         [24]  767 	lcall	__divslong
      000A90 AB 82            [24]  768 	mov	r3,dpl
      000A92 C3               [12]  769 	clr	c
      000A93 E4               [12]  770 	clr	a
      000A94 9B               [12]  771 	subb	a,r3
      000A95 FB               [12]  772 	mov	r3,a
      000A96 33               [12]  773 	rlc	a
      000A97 95 E0            [12]  774 	subb	a,acc
      000A99 FF               [12]  775 	mov	r7,a
      000A9A 8B 82            [24]  776 	mov	dpl,r3
      000A9C 8F 83            [24]  777 	mov	dph,r7
                                    778 ;	../src/uart.c:126: }	
      000A9E 22               [24]  779 	ret
      000A9F                        780 00113$:
                                    781 ;	../src/uart.c:127: return (tmp << 0x8) | tmp;
      000A9F 7F 00            [12]  782 	mov	r7,#0x00
      000AA1 8D 06            [24]  783 	mov	ar6,r5
      000AA3 7C 00            [12]  784 	mov	r4,#0x00
      000AA5 ED               [12]  785 	mov	a,r5
      000AA6 4C               [12]  786 	orl	a,r4
      000AA7 F5 82            [12]  787 	mov	dpl,a
      000AA9 EF               [12]  788 	mov	a,r7
      000AAA 4E               [12]  789 	orl	a,r6
      000AAB F5 83            [12]  790 	mov	dph,a
      000AAD 22               [24]  791 	ret
                                    792 ;------------------------------------------------------------
                                    793 ;Allocation info for local variables in function 'UART_isReceived'
                                    794 ;------------------------------------------------------------
                                    795 ;	../src/uart.c:136: FunctionalState UART_isReceived(void)
                                    796 ;	-----------------------------------------
                                    797 ;	 function UART_isReceived
                                    798 ;	-----------------------------------------
      000AAE                        799 _UART_isReceived:
                                    800 ;	../src/uart.c:138: return (FunctionalState)RI;
      000AAE A2 98            [12]  801 	mov	c,_RI
      000AB0 E4               [12]  802 	clr	a
      000AB1 33               [12]  803 	rlc	a
      000AB2 F5 82            [12]  804 	mov	dpl,a
      000AB4 22               [24]  805 	ret
                                    806 ;------------------------------------------------------------
                                    807 ;Allocation info for local variables in function 'UART_isTransmitted'
                                    808 ;------------------------------------------------------------
                                    809 ;	../src/uart.c:147: FunctionalState UART_isTransmitted(void)
                                    810 ;	-----------------------------------------
                                    811 ;	 function UART_isTransmitted
                                    812 ;	-----------------------------------------
      000AB5                        813 _UART_isTransmitted:
                                    814 ;	../src/uart.c:149: return (FunctionalState)TI;
      000AB5 A2 99            [12]  815 	mov	c,_TI
      000AB7 E4               [12]  816 	clr	a
      000AB8 33               [12]  817 	rlc	a
      000AB9 F5 82            [12]  818 	mov	dpl,a
      000ABB 22               [24]  819 	ret
                                    820 ;------------------------------------------------------------
                                    821 ;Allocation info for local variables in function 'UART_sendByte'
                                    822 ;------------------------------------------------------------
                                    823 ;dat                       Allocated to registers 
                                    824 ;------------------------------------------------------------
                                    825 ;	../src/uart.c:158: void UART_sendByte(unsigned char dat)
                                    826 ;	-----------------------------------------
                                    827 ;	 function UART_sendByte
                                    828 ;	-----------------------------------------
      000ABC                        829 _UART_sendByte:
      000ABC 85 82 99         [24]  830 	mov	_SBUF,dpl
                                    831 ;	../src/uart.c:161: while(!TI);
      000ABF                        832 00101$:
                                    833 ;	../src/uart.c:162: TI = RESET;
      000ABF 10 99 02         [24]  834 	jbc	_TI,00112$
      000AC2 80 FB            [24]  835 	sjmp	00101$
      000AC4                        836 00112$:
      000AC4 22               [24]  837 	ret
                                    838 ;------------------------------------------------------------
                                    839 ;Allocation info for local variables in function 'UART_sendString'
                                    840 ;------------------------------------------------------------
                                    841 ;str                       Allocated to registers 
                                    842 ;------------------------------------------------------------
                                    843 ;	../src/uart.c:171: void UART_sendString(char *str)
                                    844 ;	-----------------------------------------
                                    845 ;	 function UART_sendString
                                    846 ;	-----------------------------------------
      000AC5                        847 _UART_sendString:
      000AC5 AD 82            [24]  848 	mov	r5,dpl
      000AC7 AE 83            [24]  849 	mov	r6,dph
      000AC9 AF F0            [24]  850 	mov	r7,b
                                    851 ;	../src/uart.c:173: while(*str != '\0')
      000ACB                        852 00104$:
      000ACB 8D 82            [24]  853 	mov	dpl,r5
      000ACD 8E 83            [24]  854 	mov	dph,r6
      000ACF 8F F0            [24]  855 	mov	b,r7
      000AD1 12 0C 42         [24]  856 	lcall	__gptrget
      000AD4 FC               [12]  857 	mov	r4,a
      000AD5 60 0E            [24]  858 	jz	00107$
                                    859 ;	../src/uart.c:175: SBUF = *str;
      000AD7 8C 99            [24]  860 	mov	_SBUF,r4
                                    861 ;	../src/uart.c:176: while(!TI);
      000AD9                        862 00101$:
                                    863 ;	../src/uart.c:177: TI = RESET;     /* clear */
      000AD9 10 99 02         [24]  864 	jbc	_TI,00123$
      000ADC 80 FB            [24]  865 	sjmp	00101$
      000ADE                        866 00123$:
                                    867 ;	../src/uart.c:178: str++;
      000ADE 0D               [12]  868 	inc	r5
      000ADF BD 00 E9         [24]  869 	cjne	r5,#0x00,00104$
      000AE2 0E               [12]  870 	inc	r6
      000AE3 80 E6            [24]  871 	sjmp	00104$
      000AE5                        872 00107$:
      000AE5 22               [24]  873 	ret
                                    874 ;------------------------------------------------------------
                                    875 ;Allocation info for local variables in function 'UART_setMode'
                                    876 ;------------------------------------------------------------
                                    877 ;m                         Allocated to registers r7 
                                    878 ;------------------------------------------------------------
                                    879 ;	../src/uart.c:188: void UART_setMode(UART_MODE m)
                                    880 ;	-----------------------------------------
                                    881 ;	 function UART_setMode
                                    882 ;	-----------------------------------------
      000AE6                        883 _UART_setMode:
      000AE6 AF 82            [24]  884 	mov	r7,dpl
                                    885 ;	../src/uart.c:190: SCON = (SCON & 0x3F) | ((unsigned char)m << 0x6);
      000AE8 74 3F            [12]  886 	mov	a,#0x3F
      000AEA 55 98            [12]  887 	anl	a,_SCON
      000AEC FE               [12]  888 	mov	r6,a
      000AED EF               [12]  889 	mov	a,r7
      000AEE 03               [12]  890 	rr	a
      000AEF 03               [12]  891 	rr	a
      000AF0 54 C0            [12]  892 	anl	a,#0xC0
      000AF2 4E               [12]  893 	orl	a,r6
      000AF3 F5 98            [12]  894 	mov	_SCON,a
      000AF5 22               [24]  895 	ret
                                    896 ;------------------------------------------------------------
                                    897 ;Allocation info for local variables in function 'UART_INT_setPriority'
                                    898 ;------------------------------------------------------------
                                    899 ;p                         Allocated to registers r7 
                                    900 ;------------------------------------------------------------
                                    901 ;	../src/uart.c:199: void UART_INT_setPriority(INTR_PIOR p)
                                    902 ;	-----------------------------------------
                                    903 ;	 function UART_INT_setPriority
                                    904 ;	-----------------------------------------
      000AF6                        905 _UART_INT_setPriority:
      000AF6 AF 82            [24]  906 	mov	r7,dpl
                                    907 ;	../src/uart.c:201: IP = (IP & 0xEF) | ((p & 0x01) << 0x4);
      000AF8 74 EF            [12]  908 	mov	a,#0xEF
      000AFA 55 B8            [12]  909 	anl	a,_IP
      000AFC FE               [12]  910 	mov	r6,a
      000AFD 74 01            [12]  911 	mov	a,#0x01
      000AFF 5F               [12]  912 	anl	a,r7
      000B00 C4               [12]  913 	swap	a
      000B01 54 F0            [12]  914 	anl	a,#0xF0
      000B03 4E               [12]  915 	orl	a,r6
      000B04 F5 B8            [12]  916 	mov	_IP,a
                                    917 ;	../src/uart.c:202: IPH = (IPH & 0xEF) | ((p & 0x02) << 0x3);
      000B06 74 EF            [12]  918 	mov	a,#0xEF
      000B08 55 B7            [12]  919 	anl	a,_IPH
      000B0A FE               [12]  920 	mov	r6,a
      000B0B 53 07 02         [24]  921 	anl	ar7,#0x02
      000B0E EF               [12]  922 	mov	a,r7
      000B0F C4               [12]  923 	swap	a
      000B10 03               [12]  924 	rr	a
      000B11 54 F8            [12]  925 	anl	a,#0xF8
      000B13 4E               [12]  926 	orl	a,r6
      000B14 F5 B7            [12]  927 	mov	_IPH,a
      000B16 22               [24]  928 	ret
                                    929 ;------------------------------------------------------------
                                    930 ;Allocation info for local variables in function 'UART_INT_cmd'
                                    931 ;------------------------------------------------------------
                                    932 ;a                         Allocated to registers r7 
                                    933 ;------------------------------------------------------------
                                    934 ;	../src/uart.c:211: void UART_INT_cmd(Action a)
                                    935 ;	-----------------------------------------
                                    936 ;	 function UART_INT_cmd
                                    937 ;	-----------------------------------------
      000B17                        938 _UART_INT_cmd:
                                    939 ;	../src/uart.c:213: ES = a;
      000B17 E5 82            [12]  940 	mov	a,dpl
      000B19 24 FF            [12]  941 	add	a,#0xff
      000B1B 92 AC            [24]  942 	mov	_ES,c
      000B1D 22               [24]  943 	ret
                                    944 	.area CSEG    (CODE)
                                    945 	.area CONST   (CODE)
                                    946 	.area XINIT   (CODE)
                                    947 	.area CABS    (ABS,CODE)
