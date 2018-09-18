                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Apr  3 2018) (Linux)
                                      4 ; This file was generated Wed Jul 18 12:39:08 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module gpio
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _GPIO_toggleBitValue_PARM_2
                                     13 	.globl _GPIO_setBitValue_PARM_2
                                     14 	.globl _GPIO_resetBitValue_PARM_2
                                     15 	.globl _GPIO_getBitValue_PARM_2
                                     16 	.globl _GPIO_configPort_PARM_2
                                     17 	.globl _TF2
                                     18 	.globl _EXF2
                                     19 	.globl _RCLK
                                     20 	.globl _TCLK
                                     21 	.globl _EXEN2
                                     22 	.globl _TR2
                                     23 	.globl _CT2
                                     24 	.globl _CPRL2
                                     25 	.globl _P4_0
                                     26 	.globl _P4_1
                                     27 	.globl _P4_2
                                     28 	.globl _P4_3
                                     29 	.globl _PX3
                                     30 	.globl _EX3
                                     31 	.globl _IE3
                                     32 	.globl _IT3
                                     33 	.globl _PX2
                                     34 	.globl _EX2
                                     35 	.globl _IE2
                                     36 	.globl _IT2
                                     37 	.globl _CY
                                     38 	.globl _AC
                                     39 	.globl _F0
                                     40 	.globl _RS1
                                     41 	.globl _RS0
                                     42 	.globl _OV
                                     43 	.globl _F1
                                     44 	.globl _P
                                     45 	.globl _PS
                                     46 	.globl _PT1
                                     47 	.globl _PX1
                                     48 	.globl _PT0
                                     49 	.globl _PX0
                                     50 	.globl _RD
                                     51 	.globl _WR
                                     52 	.globl _T1
                                     53 	.globl _T0
                                     54 	.globl _INT1
                                     55 	.globl _INT0
                                     56 	.globl _TXD
                                     57 	.globl _RXD
                                     58 	.globl _P3_7
                                     59 	.globl _P3_6
                                     60 	.globl _P3_5
                                     61 	.globl _P3_4
                                     62 	.globl _P3_3
                                     63 	.globl _P3_2
                                     64 	.globl _P3_1
                                     65 	.globl _P3_0
                                     66 	.globl _EA
                                     67 	.globl _ES
                                     68 	.globl _ET1
                                     69 	.globl _EX1
                                     70 	.globl _ET0
                                     71 	.globl _EX0
                                     72 	.globl _P2_7
                                     73 	.globl _P2_6
                                     74 	.globl _P2_5
                                     75 	.globl _P2_4
                                     76 	.globl _P2_3
                                     77 	.globl _P2_2
                                     78 	.globl _P2_1
                                     79 	.globl _P2_0
                                     80 	.globl _SM0
                                     81 	.globl _SM1
                                     82 	.globl _SM2
                                     83 	.globl _REN
                                     84 	.globl _TB8
                                     85 	.globl _RB8
                                     86 	.globl _TI
                                     87 	.globl _RI
                                     88 	.globl _P1_7
                                     89 	.globl _P1_6
                                     90 	.globl _P1_5
                                     91 	.globl _P1_4
                                     92 	.globl _P1_3
                                     93 	.globl _P1_2
                                     94 	.globl _P1_1
                                     95 	.globl _P1_0
                                     96 	.globl _TF1
                                     97 	.globl _TR1
                                     98 	.globl _TF0
                                     99 	.globl _TR0
                                    100 	.globl _IE1
                                    101 	.globl _IT1
                                    102 	.globl _IE0
                                    103 	.globl _IT0
                                    104 	.globl _P0_7
                                    105 	.globl _P0_6
                                    106 	.globl _P0_5
                                    107 	.globl _P0_4
                                    108 	.globl _P0_3
                                    109 	.globl _P0_2
                                    110 	.globl _P0_1
                                    111 	.globl _P0_0
                                    112 	.globl _P4
                                    113 	.globl _ISP_CONTR
                                    114 	.globl _ISP_TRIG
                                    115 	.globl _ISP_CMD
                                    116 	.globl _ISP_ADDRL
                                    117 	.globl _ISP_ADDRH
                                    118 	.globl _ISP_DATA
                                    119 	.globl _WDT_CONTR
                                    120 	.globl _TH2
                                    121 	.globl _TL2
                                    122 	.globl _RCAP2H
                                    123 	.globl _RCAP2L
                                    124 	.globl _T2MOD
                                    125 	.globl _T2CON
                                    126 	.globl _XICON
                                    127 	.globl _IPH
                                    128 	.globl _SADDR1
                                    129 	.globl _AUXR1
                                    130 	.globl _AUXR
                                    131 	.globl _B
                                    132 	.globl _ACC
                                    133 	.globl _PSW
                                    134 	.globl _IP
                                    135 	.globl _P3
                                    136 	.globl _IE
                                    137 	.globl _P2
                                    138 	.globl _SBUF
                                    139 	.globl _SCON
                                    140 	.globl _P1
                                    141 	.globl _TH1
                                    142 	.globl _TH0
                                    143 	.globl _TL1
                                    144 	.globl _TL0
                                    145 	.globl _TMOD
                                    146 	.globl _TCON
                                    147 	.globl _PCON
                                    148 	.globl _DPH
                                    149 	.globl _DPL
                                    150 	.globl _SP
                                    151 	.globl _P0
                                    152 	.globl _GPIO_configBitValue_PARM_3
                                    153 	.globl _GPIO_configBitValue_PARM_2
                                    154 	.globl _GPIO_configBitValue
                                    155 	.globl _GPIO_configPort
                                    156 	.globl _GPIO_getBitValue
                                    157 	.globl _GPIO_resetBitValue
                                    158 	.globl _GPIO_setBitValue
                                    159 	.globl _GPIO_toggleBitValue
                                    160 ;--------------------------------------------------------
                                    161 ; special function registers
                                    162 ;--------------------------------------------------------
                                    163 	.area RSEG    (ABS,DATA)
      000000                        164 	.org 0x0000
                           000080   165 _P0	=	0x0080
                           000081   166 _SP	=	0x0081
                           000082   167 _DPL	=	0x0082
                           000083   168 _DPH	=	0x0083
                           000087   169 _PCON	=	0x0087
                           000088   170 _TCON	=	0x0088
                           000089   171 _TMOD	=	0x0089
                           00008A   172 _TL0	=	0x008a
                           00008B   173 _TL1	=	0x008b
                           00008C   174 _TH0	=	0x008c
                           00008D   175 _TH1	=	0x008d
                           000090   176 _P1	=	0x0090
                           000098   177 _SCON	=	0x0098
                           000099   178 _SBUF	=	0x0099
                           0000A0   179 _P2	=	0x00a0
                           0000A8   180 _IE	=	0x00a8
                           0000B0   181 _P3	=	0x00b0
                           0000B8   182 _IP	=	0x00b8
                           0000D0   183 _PSW	=	0x00d0
                           0000E0   184 _ACC	=	0x00e0
                           0000F0   185 _B	=	0x00f0
                           00008E   186 _AUXR	=	0x008e
                           0000A2   187 _AUXR1	=	0x00a2
                           0000A9   188 _SADDR1	=	0x00a9
                           0000B7   189 _IPH	=	0x00b7
                           0000C0   190 _XICON	=	0x00c0
                           0000C8   191 _T2CON	=	0x00c8
                           0000C9   192 _T2MOD	=	0x00c9
                           0000CA   193 _RCAP2L	=	0x00ca
                           0000CB   194 _RCAP2H	=	0x00cb
                           0000CC   195 _TL2	=	0x00cc
                           0000CD   196 _TH2	=	0x00cd
                           0000E1   197 _WDT_CONTR	=	0x00e1
                           0000E2   198 _ISP_DATA	=	0x00e2
                           0000E3   199 _ISP_ADDRH	=	0x00e3
                           0000E4   200 _ISP_ADDRL	=	0x00e4
                           0000E5   201 _ISP_CMD	=	0x00e5
                           0000E6   202 _ISP_TRIG	=	0x00e6
                           0000E7   203 _ISP_CONTR	=	0x00e7
                           0000E8   204 _P4	=	0x00e8
                                    205 ;--------------------------------------------------------
                                    206 ; special function bits
                                    207 ;--------------------------------------------------------
                                    208 	.area RSEG    (ABS,DATA)
      000000                        209 	.org 0x0000
                           000080   210 _P0_0	=	0x0080
                           000081   211 _P0_1	=	0x0081
                           000082   212 _P0_2	=	0x0082
                           000083   213 _P0_3	=	0x0083
                           000084   214 _P0_4	=	0x0084
                           000085   215 _P0_5	=	0x0085
                           000086   216 _P0_6	=	0x0086
                           000087   217 _P0_7	=	0x0087
                           000088   218 _IT0	=	0x0088
                           000089   219 _IE0	=	0x0089
                           00008A   220 _IT1	=	0x008a
                           00008B   221 _IE1	=	0x008b
                           00008C   222 _TR0	=	0x008c
                           00008D   223 _TF0	=	0x008d
                           00008E   224 _TR1	=	0x008e
                           00008F   225 _TF1	=	0x008f
                           000090   226 _P1_0	=	0x0090
                           000091   227 _P1_1	=	0x0091
                           000092   228 _P1_2	=	0x0092
                           000093   229 _P1_3	=	0x0093
                           000094   230 _P1_4	=	0x0094
                           000095   231 _P1_5	=	0x0095
                           000096   232 _P1_6	=	0x0096
                           000097   233 _P1_7	=	0x0097
                           000098   234 _RI	=	0x0098
                           000099   235 _TI	=	0x0099
                           00009A   236 _RB8	=	0x009a
                           00009B   237 _TB8	=	0x009b
                           00009C   238 _REN	=	0x009c
                           00009D   239 _SM2	=	0x009d
                           00009E   240 _SM1	=	0x009e
                           00009F   241 _SM0	=	0x009f
                           0000A0   242 _P2_0	=	0x00a0
                           0000A1   243 _P2_1	=	0x00a1
                           0000A2   244 _P2_2	=	0x00a2
                           0000A3   245 _P2_3	=	0x00a3
                           0000A4   246 _P2_4	=	0x00a4
                           0000A5   247 _P2_5	=	0x00a5
                           0000A6   248 _P2_6	=	0x00a6
                           0000A7   249 _P2_7	=	0x00a7
                           0000A8   250 _EX0	=	0x00a8
                           0000A9   251 _ET0	=	0x00a9
                           0000AA   252 _EX1	=	0x00aa
                           0000AB   253 _ET1	=	0x00ab
                           0000AC   254 _ES	=	0x00ac
                           0000AF   255 _EA	=	0x00af
                           0000B0   256 _P3_0	=	0x00b0
                           0000B1   257 _P3_1	=	0x00b1
                           0000B2   258 _P3_2	=	0x00b2
                           0000B3   259 _P3_3	=	0x00b3
                           0000B4   260 _P3_4	=	0x00b4
                           0000B5   261 _P3_5	=	0x00b5
                           0000B6   262 _P3_6	=	0x00b6
                           0000B7   263 _P3_7	=	0x00b7
                           0000B0   264 _RXD	=	0x00b0
                           0000B1   265 _TXD	=	0x00b1
                           0000B2   266 _INT0	=	0x00b2
                           0000B3   267 _INT1	=	0x00b3
                           0000B4   268 _T0	=	0x00b4
                           0000B5   269 _T1	=	0x00b5
                           0000B6   270 _WR	=	0x00b6
                           0000B7   271 _RD	=	0x00b7
                           0000B8   272 _PX0	=	0x00b8
                           0000B9   273 _PT0	=	0x00b9
                           0000BA   274 _PX1	=	0x00ba
                           0000BB   275 _PT1	=	0x00bb
                           0000BC   276 _PS	=	0x00bc
                           0000D0   277 _P	=	0x00d0
                           0000D1   278 _F1	=	0x00d1
                           0000D2   279 _OV	=	0x00d2
                           0000D3   280 _RS0	=	0x00d3
                           0000D4   281 _RS1	=	0x00d4
                           0000D5   282 _F0	=	0x00d5
                           0000D6   283 _AC	=	0x00d6
                           0000D7   284 _CY	=	0x00d7
                           0000C0   285 _IT2	=	0x00c0
                           0000C1   286 _IE2	=	0x00c1
                           0000C2   287 _EX2	=	0x00c2
                           0000C3   288 _PX2	=	0x00c3
                           0000C4   289 _IT3	=	0x00c4
                           0000C5   290 _IE3	=	0x00c5
                           0000C6   291 _EX3	=	0x00c6
                           0000C7   292 _PX3	=	0x00c7
                           0000EB   293 _P4_3	=	0x00eb
                           0000EA   294 _P4_2	=	0x00ea
                           0000E9   295 _P4_1	=	0x00e9
                           0000E8   296 _P4_0	=	0x00e8
                           0000C8   297 _CPRL2	=	0x00c8
                           0000C9   298 _CT2	=	0x00c9
                           0000CA   299 _TR2	=	0x00ca
                           0000CB   300 _EXEN2	=	0x00cb
                           0000CC   301 _TCLK	=	0x00cc
                           0000CD   302 _RCLK	=	0x00cd
                           0000CE   303 _EXF2	=	0x00ce
                           0000CF   304 _TF2	=	0x00cf
                                    305 ;--------------------------------------------------------
                                    306 ; overlayable register banks
                                    307 ;--------------------------------------------------------
                                    308 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        309 	.ds 8
                                    310 ;--------------------------------------------------------
                                    311 ; internal ram data
                                    312 ;--------------------------------------------------------
                                    313 	.area DSEG    (DATA)
      000013                        314 _GPIO_configBitValue_PARM_2:
      000013                        315 	.ds 1
      000014                        316 _GPIO_configBitValue_PARM_3:
      000014                        317 	.ds 1
                                    318 ;--------------------------------------------------------
                                    319 ; overlayable items in internal ram 
                                    320 ;--------------------------------------------------------
                                    321 	.area	OSEG    (OVR,DATA)
      00001C                        322 _GPIO_configPort_PARM_2:
      00001C                        323 	.ds 1
                                    324 	.area	OSEG    (OVR,DATA)
      00001C                        325 _GPIO_getBitValue_PARM_2:
      00001C                        326 	.ds 1
                                    327 	.area	OSEG    (OVR,DATA)
      00001C                        328 _GPIO_resetBitValue_PARM_2:
      00001C                        329 	.ds 1
                                    330 	.area	OSEG    (OVR,DATA)
      00001C                        331 _GPIO_setBitValue_PARM_2:
      00001C                        332 	.ds 1
                                    333 	.area	OSEG    (OVR,DATA)
      00001C                        334 _GPIO_toggleBitValue_PARM_2:
      00001C                        335 	.ds 1
                                    336 ;--------------------------------------------------------
                                    337 ; indirectly addressable internal ram data
                                    338 ;--------------------------------------------------------
                                    339 	.area ISEG    (DATA)
                                    340 ;--------------------------------------------------------
                                    341 ; absolute internal ram data
                                    342 ;--------------------------------------------------------
                                    343 	.area IABS    (ABS,DATA)
                                    344 	.area IABS    (ABS,DATA)
                                    345 ;--------------------------------------------------------
                                    346 ; bit data
                                    347 ;--------------------------------------------------------
                                    348 	.area BSEG    (BIT)
                                    349 ;--------------------------------------------------------
                                    350 ; paged external ram data
                                    351 ;--------------------------------------------------------
                                    352 	.area PSEG    (PAG,XDATA)
                                    353 ;--------------------------------------------------------
                                    354 ; external ram data
                                    355 ;--------------------------------------------------------
                                    356 	.area XSEG    (XDATA)
                                    357 ;--------------------------------------------------------
                                    358 ; absolute external ram data
                                    359 ;--------------------------------------------------------
                                    360 	.area XABS    (ABS,XDATA)
                                    361 ;--------------------------------------------------------
                                    362 ; external initialized ram data
                                    363 ;--------------------------------------------------------
                                    364 	.area XISEG   (XDATA)
                                    365 	.area HOME    (CODE)
                                    366 	.area GSINIT0 (CODE)
                                    367 	.area GSINIT1 (CODE)
                                    368 	.area GSINIT2 (CODE)
                                    369 	.area GSINIT3 (CODE)
                                    370 	.area GSINIT4 (CODE)
                                    371 	.area GSINIT5 (CODE)
                                    372 	.area GSINIT  (CODE)
                                    373 	.area GSFINAL (CODE)
                                    374 	.area CSEG    (CODE)
                                    375 ;--------------------------------------------------------
                                    376 ; global & static initialisations
                                    377 ;--------------------------------------------------------
                                    378 	.area HOME    (CODE)
                                    379 	.area GSINIT  (CODE)
                                    380 	.area GSFINAL (CODE)
                                    381 	.area GSINIT  (CODE)
                                    382 ;--------------------------------------------------------
                                    383 ; Home
                                    384 ;--------------------------------------------------------
                                    385 	.area HOME    (CODE)
                                    386 	.area HOME    (CODE)
                                    387 ;--------------------------------------------------------
                                    388 ; code
                                    389 ;--------------------------------------------------------
                                    390 	.area CSEG    (CODE)
                                    391 ;------------------------------------------------------------
                                    392 ;Allocation info for local variables in function 'GPIO_configBitValue'
                                    393 ;------------------------------------------------------------
                                    394 ;pin                       Allocated with name '_GPIO_configBitValue_PARM_2'
                                    395 ;f                         Allocated with name '_GPIO_configBitValue_PARM_3'
                                    396 ;gpio                      Allocated to registers r7 
                                    397 ;------------------------------------------------------------
                                    398 ;	../src/gpio.c:23: void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f)
                                    399 ;	-----------------------------------------
                                    400 ;	 function GPIO_configBitValue
                                    401 ;	-----------------------------------------
      0001C3                        402 _GPIO_configBitValue:
                           000007   403 	ar7 = 0x07
                           000006   404 	ar6 = 0x06
                           000005   405 	ar5 = 0x05
                           000004   406 	ar4 = 0x04
                           000003   407 	ar3 = 0x03
                           000002   408 	ar2 = 0x02
                           000001   409 	ar1 = 0x01
                           000000   410 	ar0 = 0x00
      0001C3 AF 82            [24]  411 	mov	r7,dpl
                                    412 ;	../src/gpio.c:25: if(f==RESET)
      0001C5 E5 14            [12]  413 	mov	a,_GPIO_configBitValue_PARM_3
      0001C7 70 08            [24]  414 	jnz	00102$
                                    415 ;	../src/gpio.c:27: GPIO_resetBitValue(gpio,pin);
      0001C9 85 13 1C         [24]  416 	mov	_GPIO_resetBitValue_PARM_2,_GPIO_configBitValue_PARM_2
      0001CC 8F 82            [24]  417 	mov	dpl,r7
      0001CE 02 02 54         [24]  418 	ljmp	_GPIO_resetBitValue
      0001D1                        419 00102$:
                                    420 ;	../src/gpio.c:31: GPIO_setBitValue(gpio,pin);
      0001D1 85 13 1C         [24]  421 	mov	_GPIO_setBitValue_PARM_2,_GPIO_configBitValue_PARM_2
      0001D4 8F 82            [24]  422 	mov	dpl,r7
      0001D6 02 02 90         [24]  423 	ljmp	_GPIO_setBitValue
                                    424 ;------------------------------------------------------------
                                    425 ;Allocation info for local variables in function 'GPIO_configPort'
                                    426 ;------------------------------------------------------------
                                    427 ;val                       Allocated with name '_GPIO_configPort_PARM_2'
                                    428 ;gpio                      Allocated to registers r7 
                                    429 ;------------------------------------------------------------
                                    430 ;	../src/gpio.c:43: void GPIO_configPort(PERIPH_GPIO gpio,unsigned char val)
                                    431 ;	-----------------------------------------
                                    432 ;	 function GPIO_configPort
                                    433 ;	-----------------------------------------
      0001D9                        434 _GPIO_configPort:
                                    435 ;	../src/gpio.c:45: switch(gpio)
      0001D9 E5 82            [12]  436 	mov	a,dpl
      0001DB FF               [12]  437 	mov	r7,a
      0001DC 24 FB            [12]  438 	add	a,#0xff - 0x04
      0001DE 40 29            [24]  439 	jc	00108$
      0001E0 EF               [12]  440 	mov	a,r7
      0001E1 2F               [12]  441 	add	a,r7
      0001E2 2F               [12]  442 	add	a,r7
      0001E3 90 01 E7         [24]  443 	mov	dptr,#00114$
      0001E6 73               [24]  444 	jmp	@a+dptr
      0001E7                        445 00114$:
      0001E7 02 01 F6         [24]  446 	ljmp	00101$
      0001EA 02 01 FA         [24]  447 	ljmp	00102$
      0001ED 02 01 FE         [24]  448 	ljmp	00103$
      0001F0 02 02 02         [24]  449 	ljmp	00104$
      0001F3 02 02 06         [24]  450 	ljmp	00105$
                                    451 ;	../src/gpio.c:47: case PERIPH_GPIO_0:P0 = val;break;
      0001F6                        452 00101$:
      0001F6 85 1C 80         [24]  453 	mov	_P0,_GPIO_configPort_PARM_2
                                    454 ;	../src/gpio.c:48: case PERIPH_GPIO_1:P1 = val;break;
      0001F9 22               [24]  455 	ret
      0001FA                        456 00102$:
      0001FA 85 1C 90         [24]  457 	mov	_P1,_GPIO_configPort_PARM_2
                                    458 ;	../src/gpio.c:49: case PERIPH_GPIO_2:P2 = val;break;
      0001FD 22               [24]  459 	ret
      0001FE                        460 00103$:
      0001FE 85 1C A0         [24]  461 	mov	_P2,_GPIO_configPort_PARM_2
                                    462 ;	../src/gpio.c:50: case PERIPH_GPIO_3:P3 = val;break;
      000201 22               [24]  463 	ret
      000202                        464 00104$:
      000202 85 1C B0         [24]  465 	mov	_P3,_GPIO_configPort_PARM_2
                                    466 ;	../src/gpio.c:51: case PERIPH_GPIO_4:P4 = val;break;
      000205 22               [24]  467 	ret
      000206                        468 00105$:
      000206 85 1C E8         [24]  469 	mov	_P4,_GPIO_configPort_PARM_2
                                    470 ;	../src/gpio.c:53: }
      000209                        471 00108$:
      000209 22               [24]  472 	ret
                                    473 ;------------------------------------------------------------
                                    474 ;Allocation info for local variables in function 'GPIO_getBitValue'
                                    475 ;------------------------------------------------------------
                                    476 ;pin                       Allocated with name '_GPIO_getBitValue_PARM_2'
                                    477 ;gpio                      Allocated to registers r7 
                                    478 ;value                     Allocated to registers r6 
                                    479 ;------------------------------------------------------------
                                    480 ;	../src/gpio.c:64: FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
                                    481 ;	-----------------------------------------
                                    482 ;	 function GPIO_getBitValue
                                    483 ;	-----------------------------------------
      00020A                        484 _GPIO_getBitValue:
      00020A AF 82            [24]  485 	mov	r7,dpl
                                    486 ;	../src/gpio.c:66: unsigned char value=0;
      00020C 7E 00            [12]  487 	mov	r6,#0x00
                                    488 ;	../src/gpio.c:68: switch(gpio)
      00020E EF               [12]  489 	mov	a,r7
      00020F 24 FB            [12]  490 	add	a,#0xff - 0x04
      000211 40 37            [24]  491 	jc	00107$
      000213 EF               [12]  492 	mov	a,r7
      000214 2F               [12]  493 	add	a,r7
      000215 2F               [12]  494 	add	a,r7
      000216 90 02 1A         [24]  495 	mov	dptr,#00120$
      000219 73               [24]  496 	jmp	@a+dptr
      00021A                        497 00120$:
      00021A 02 02 29         [24]  498 	ljmp	00101$
      00021D 02 02 30         [24]  499 	ljmp	00102$
      000220 02 02 37         [24]  500 	ljmp	00103$
      000223 02 02 3E         [24]  501 	ljmp	00104$
      000226 02 02 45         [24]  502 	ljmp	00105$
                                    503 ;	../src/gpio.c:70: case PERIPH_GPIO_0:value = P0 & pin;break;
      000229                        504 00101$:
      000229 E5 1C            [12]  505 	mov	a,_GPIO_getBitValue_PARM_2
      00022B 55 80            [12]  506 	anl	a,_P0
      00022D FE               [12]  507 	mov	r6,a
                                    508 ;	../src/gpio.c:71: case PERIPH_GPIO_1:value = P1 & pin;break;
      00022E 80 1A            [24]  509 	sjmp	00107$
      000230                        510 00102$:
      000230 E5 1C            [12]  511 	mov	a,_GPIO_getBitValue_PARM_2
      000232 55 90            [12]  512 	anl	a,_P1
      000234 FE               [12]  513 	mov	r6,a
                                    514 ;	../src/gpio.c:72: case PERIPH_GPIO_2:value = P2 & pin;break;
      000235 80 13            [24]  515 	sjmp	00107$
      000237                        516 00103$:
      000237 E5 1C            [12]  517 	mov	a,_GPIO_getBitValue_PARM_2
      000239 55 A0            [12]  518 	anl	a,_P2
      00023B FE               [12]  519 	mov	r6,a
                                    520 ;	../src/gpio.c:73: case PERIPH_GPIO_3:value = P3 & pin;break;
      00023C 80 0C            [24]  521 	sjmp	00107$
      00023E                        522 00104$:
      00023E E5 1C            [12]  523 	mov	a,_GPIO_getBitValue_PARM_2
      000240 55 B0            [12]  524 	anl	a,_P3
      000242 FE               [12]  525 	mov	r6,a
                                    526 ;	../src/gpio.c:74: case PERIPH_GPIO_4:value = P4 & pin;break;
      000243 80 05            [24]  527 	sjmp	00107$
      000245                        528 00105$:
      000245 E5 1C            [12]  529 	mov	a,_GPIO_getBitValue_PARM_2
      000247 55 E8            [12]  530 	anl	a,_P4
      000249 FE               [12]  531 	mov	r6,a
                                    532 ;	../src/gpio.c:76: }
      00024A                        533 00107$:
                                    534 ;	../src/gpio.c:77: if(value==0)
      00024A EE               [12]  535 	mov	a,r6
                                    536 ;	../src/gpio.c:79: return RESET;
      00024B 70 03            [24]  537 	jnz	00109$
      00024D F5 82            [12]  538 	mov	dpl,a
      00024F 22               [24]  539 	ret
      000250                        540 00109$:
                                    541 ;	../src/gpio.c:83: return SET;
      000250 75 82 01         [24]  542 	mov	dpl,#0x01
      000253 22               [24]  543 	ret
                                    544 ;------------------------------------------------------------
                                    545 ;Allocation info for local variables in function 'GPIO_resetBitValue'
                                    546 ;------------------------------------------------------------
                                    547 ;pin                       Allocated with name '_GPIO_resetBitValue_PARM_2'
                                    548 ;gpio                      Allocated to registers r7 
                                    549 ;------------------------------------------------------------
                                    550 ;	../src/gpio.c:95: void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
                                    551 ;	-----------------------------------------
                                    552 ;	 function GPIO_resetBitValue
                                    553 ;	-----------------------------------------
      000254                        554 _GPIO_resetBitValue:
                                    555 ;	../src/gpio.c:97: switch(gpio)
      000254 E5 82            [12]  556 	mov	a,dpl
      000256 FF               [12]  557 	mov	r7,a
      000257 24 FB            [12]  558 	add	a,#0xff - 0x04
      000259 40 34            [24]  559 	jc	00108$
      00025B EF               [12]  560 	mov	a,r7
      00025C 2F               [12]  561 	add	a,r7
      00025D 2F               [12]  562 	add	a,r7
      00025E 90 02 62         [24]  563 	mov	dptr,#00114$
      000261 73               [24]  564 	jmp	@a+dptr
      000262                        565 00114$:
      000262 02 02 71         [24]  566 	ljmp	00101$
      000265 02 02 77         [24]  567 	ljmp	00102$
      000268 02 02 7D         [24]  568 	ljmp	00103$
      00026B 02 02 83         [24]  569 	ljmp	00104$
      00026E 02 02 89         [24]  570 	ljmp	00105$
                                    571 ;	../src/gpio.c:99: case PERIPH_GPIO_0:P0 = P0 & (~pin);break;
      000271                        572 00101$:
      000271 E5 1C            [12]  573 	mov	a,_GPIO_resetBitValue_PARM_2
      000273 F4               [12]  574 	cpl	a
      000274 52 80            [12]  575 	anl	_P0,a
                                    576 ;	../src/gpio.c:100: case PERIPH_GPIO_1:P1 = P1 & (~pin);break;
      000276 22               [24]  577 	ret
      000277                        578 00102$:
      000277 E5 1C            [12]  579 	mov	a,_GPIO_resetBitValue_PARM_2
      000279 F4               [12]  580 	cpl	a
      00027A 52 90            [12]  581 	anl	_P1,a
                                    582 ;	../src/gpio.c:101: case PERIPH_GPIO_2:P2 = P2 & (~pin);break;
      00027C 22               [24]  583 	ret
      00027D                        584 00103$:
      00027D E5 1C            [12]  585 	mov	a,_GPIO_resetBitValue_PARM_2
      00027F F4               [12]  586 	cpl	a
      000280 52 A0            [12]  587 	anl	_P2,a
                                    588 ;	../src/gpio.c:102: case PERIPH_GPIO_3:P3 = P3 & (~pin);break;
      000282 22               [24]  589 	ret
      000283                        590 00104$:
      000283 E5 1C            [12]  591 	mov	a,_GPIO_resetBitValue_PARM_2
      000285 F4               [12]  592 	cpl	a
      000286 52 B0            [12]  593 	anl	_P3,a
                                    594 ;	../src/gpio.c:103: case PERIPH_GPIO_4:P4 = P4 & (~pin);break;
      000288 22               [24]  595 	ret
      000289                        596 00105$:
      000289 E5 1C            [12]  597 	mov	a,_GPIO_resetBitValue_PARM_2
      00028B F4               [12]  598 	cpl	a
      00028C FF               [12]  599 	mov	r7,a
      00028D 52 E8            [12]  600 	anl	_P4,a
                                    601 ;	../src/gpio.c:105: }
      00028F                        602 00108$:
      00028F 22               [24]  603 	ret
                                    604 ;------------------------------------------------------------
                                    605 ;Allocation info for local variables in function 'GPIO_setBitValue'
                                    606 ;------------------------------------------------------------
                                    607 ;pin                       Allocated with name '_GPIO_setBitValue_PARM_2'
                                    608 ;gpio                      Allocated to registers r7 
                                    609 ;------------------------------------------------------------
                                    610 ;	../src/gpio.c:116: void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
                                    611 ;	-----------------------------------------
                                    612 ;	 function GPIO_setBitValue
                                    613 ;	-----------------------------------------
      000290                        614 _GPIO_setBitValue:
                                    615 ;	../src/gpio.c:118: switch(gpio)
      000290 E5 82            [12]  616 	mov	a,dpl
      000292 FF               [12]  617 	mov	r7,a
      000293 24 FB            [12]  618 	add	a,#0xff - 0x04
      000295 40 2E            [24]  619 	jc	00108$
      000297 EF               [12]  620 	mov	a,r7
      000298 2F               [12]  621 	add	a,r7
      000299 2F               [12]  622 	add	a,r7
      00029A 90 02 9E         [24]  623 	mov	dptr,#00114$
      00029D 73               [24]  624 	jmp	@a+dptr
      00029E                        625 00114$:
      00029E 02 02 AD         [24]  626 	ljmp	00101$
      0002A1 02 02 B2         [24]  627 	ljmp	00102$
      0002A4 02 02 B7         [24]  628 	ljmp	00103$
      0002A7 02 02 BC         [24]  629 	ljmp	00104$
      0002AA 02 02 C1         [24]  630 	ljmp	00105$
                                    631 ;	../src/gpio.c:120: case PERIPH_GPIO_0:P0 = P0 | pin;break;
      0002AD                        632 00101$:
      0002AD E5 1C            [12]  633 	mov	a,_GPIO_setBitValue_PARM_2
      0002AF 42 80            [12]  634 	orl	_P0,a
                                    635 ;	../src/gpio.c:121: case PERIPH_GPIO_1:P1 = P1 | pin;break;
      0002B1 22               [24]  636 	ret
      0002B2                        637 00102$:
      0002B2 E5 1C            [12]  638 	mov	a,_GPIO_setBitValue_PARM_2
      0002B4 42 90            [12]  639 	orl	_P1,a
                                    640 ;	../src/gpio.c:122: case PERIPH_GPIO_2:P2 = P2 | pin;break;
      0002B6 22               [24]  641 	ret
      0002B7                        642 00103$:
      0002B7 E5 1C            [12]  643 	mov	a,_GPIO_setBitValue_PARM_2
      0002B9 42 A0            [12]  644 	orl	_P2,a
                                    645 ;	../src/gpio.c:123: case PERIPH_GPIO_3:P3 = P3 | pin;break;
      0002BB 22               [24]  646 	ret
      0002BC                        647 00104$:
      0002BC E5 1C            [12]  648 	mov	a,_GPIO_setBitValue_PARM_2
      0002BE 42 B0            [12]  649 	orl	_P3,a
                                    650 ;	../src/gpio.c:124: case PERIPH_GPIO_4:P4 = P4 | pin;break;
      0002C0 22               [24]  651 	ret
      0002C1                        652 00105$:
      0002C1 E5 1C            [12]  653 	mov	a,_GPIO_setBitValue_PARM_2
      0002C3 42 E8            [12]  654 	orl	_P4,a
                                    655 ;	../src/gpio.c:126: }
      0002C5                        656 00108$:
      0002C5 22               [24]  657 	ret
                                    658 ;------------------------------------------------------------
                                    659 ;Allocation info for local variables in function 'GPIO_toggleBitValue'
                                    660 ;------------------------------------------------------------
                                    661 ;pin                       Allocated with name '_GPIO_toggleBitValue_PARM_2'
                                    662 ;gpio                      Allocated to registers r7 
                                    663 ;------------------------------------------------------------
                                    664 ;	../src/gpio.c:137: void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
                                    665 ;	-----------------------------------------
                                    666 ;	 function GPIO_toggleBitValue
                                    667 ;	-----------------------------------------
      0002C6                        668 _GPIO_toggleBitValue:
                                    669 ;	../src/gpio.c:139: switch(gpio)
      0002C6 E5 82            [12]  670 	mov	a,dpl
      0002C8 FF               [12]  671 	mov	r7,a
      0002C9 24 FB            [12]  672 	add	a,#0xff - 0x04
      0002CB 40 74            [24]  673 	jc	00108$
      0002CD EF               [12]  674 	mov	a,r7
      0002CE 2F               [12]  675 	add	a,r7
      0002CF 2F               [12]  676 	add	a,r7
      0002D0 90 02 D4         [24]  677 	mov	dptr,#00114$
      0002D3 73               [24]  678 	jmp	@a+dptr
      0002D4                        679 00114$:
      0002D4 02 02 E3         [24]  680 	ljmp	00101$
      0002D7 02 02 F6         [24]  681 	ljmp	00102$
      0002DA 02 03 09         [24]  682 	ljmp	00103$
      0002DD 02 03 1C         [24]  683 	ljmp	00104$
      0002E0 02 03 2F         [24]  684 	ljmp	00105$
                                    685 ;	../src/gpio.c:141: case PERIPH_GPIO_0:P0 = P0 & (~pin) | (~P0) & pin;break;
      0002E3                        686 00101$:
      0002E3 E5 1C            [12]  687 	mov	a,_GPIO_toggleBitValue_PARM_2
      0002E5 F4               [12]  688 	cpl	a
      0002E6 FF               [12]  689 	mov	r7,a
      0002E7 E5 80            [12]  690 	mov	a,_P0
      0002E9 52 07            [12]  691 	anl	ar7,a
      0002EB E5 80            [12]  692 	mov	a,_P0
      0002ED F4               [12]  693 	cpl	a
      0002EE FE               [12]  694 	mov	r6,a
      0002EF E5 1C            [12]  695 	mov	a,_GPIO_toggleBitValue_PARM_2
      0002F1 5E               [12]  696 	anl	a,r6
      0002F2 4F               [12]  697 	orl	a,r7
      0002F3 F5 80            [12]  698 	mov	_P0,a
                                    699 ;	../src/gpio.c:142: case PERIPH_GPIO_1:P1 = P1 & (~pin) | (~P1) & pin;break;
      0002F5 22               [24]  700 	ret
      0002F6                        701 00102$:
      0002F6 E5 1C            [12]  702 	mov	a,_GPIO_toggleBitValue_PARM_2
      0002F8 F4               [12]  703 	cpl	a
      0002F9 FF               [12]  704 	mov	r7,a
      0002FA E5 90            [12]  705 	mov	a,_P1
      0002FC 52 07            [12]  706 	anl	ar7,a
      0002FE E5 90            [12]  707 	mov	a,_P1
      000300 F4               [12]  708 	cpl	a
      000301 FE               [12]  709 	mov	r6,a
      000302 E5 1C            [12]  710 	mov	a,_GPIO_toggleBitValue_PARM_2
      000304 5E               [12]  711 	anl	a,r6
      000305 4F               [12]  712 	orl	a,r7
      000306 F5 90            [12]  713 	mov	_P1,a
                                    714 ;	../src/gpio.c:143: case PERIPH_GPIO_2:P2 = P2 & (~pin) | (~P2) & pin;break;
      000308 22               [24]  715 	ret
      000309                        716 00103$:
      000309 E5 1C            [12]  717 	mov	a,_GPIO_toggleBitValue_PARM_2
      00030B F4               [12]  718 	cpl	a
      00030C FF               [12]  719 	mov	r7,a
      00030D E5 A0            [12]  720 	mov	a,_P2
      00030F 52 07            [12]  721 	anl	ar7,a
      000311 E5 A0            [12]  722 	mov	a,_P2
      000313 F4               [12]  723 	cpl	a
      000314 FE               [12]  724 	mov	r6,a
      000315 E5 1C            [12]  725 	mov	a,_GPIO_toggleBitValue_PARM_2
      000317 5E               [12]  726 	anl	a,r6
      000318 4F               [12]  727 	orl	a,r7
      000319 F5 A0            [12]  728 	mov	_P2,a
                                    729 ;	../src/gpio.c:144: case PERIPH_GPIO_3:P3 = P3 & (~pin) | (~P3) & pin;break;
      00031B 22               [24]  730 	ret
      00031C                        731 00104$:
      00031C E5 1C            [12]  732 	mov	a,_GPIO_toggleBitValue_PARM_2
      00031E F4               [12]  733 	cpl	a
      00031F FF               [12]  734 	mov	r7,a
      000320 E5 B0            [12]  735 	mov	a,_P3
      000322 52 07            [12]  736 	anl	ar7,a
      000324 E5 B0            [12]  737 	mov	a,_P3
      000326 F4               [12]  738 	cpl	a
      000327 FE               [12]  739 	mov	r6,a
      000328 E5 1C            [12]  740 	mov	a,_GPIO_toggleBitValue_PARM_2
      00032A 5E               [12]  741 	anl	a,r6
      00032B 4F               [12]  742 	orl	a,r7
      00032C F5 B0            [12]  743 	mov	_P3,a
                                    744 ;	../src/gpio.c:145: case PERIPH_GPIO_4:P4 = P4 & (~pin) | (~P4) & pin;break;
      00032E 22               [24]  745 	ret
      00032F                        746 00105$:
      00032F E5 1C            [12]  747 	mov	a,_GPIO_toggleBitValue_PARM_2
      000331 F4               [12]  748 	cpl	a
      000332 FF               [12]  749 	mov	r7,a
      000333 E5 E8            [12]  750 	mov	a,_P4
      000335 52 07            [12]  751 	anl	ar7,a
      000337 E5 E8            [12]  752 	mov	a,_P4
      000339 F4               [12]  753 	cpl	a
      00033A FE               [12]  754 	mov	r6,a
      00033B E5 1C            [12]  755 	mov	a,_GPIO_toggleBitValue_PARM_2
      00033D 5E               [12]  756 	anl	a,r6
      00033E 4F               [12]  757 	orl	a,r7
      00033F F5 E8            [12]  758 	mov	_P4,a
                                    759 ;	../src/gpio.c:147: }
      000341                        760 00108$:
      000341 22               [24]  761 	ret
                                    762 	.area CSEG    (CODE)
                                    763 	.area CONST   (CODE)
                                    764 	.area XINIT   (CODE)
                                    765 	.area CABS    (ABS,CODE)
