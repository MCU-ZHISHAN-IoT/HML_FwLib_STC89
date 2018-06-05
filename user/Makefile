#Author     :Weilun Fong | wlf(at)zhishan-iot.ga
#Date       :2018-05-28
#Description:Makefile for HML_FwLib_STC89,it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.ga
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :http://hw.zhishan-iot.ga/page/hml/detail/fwlib_8051.html
#Vesrion    :v0.0.0

#compiler#
CC             = sdcc
CFLAGS         = -c -o ${DIR_OUTPUT}/ -I ${HML_FWLIB_INC} --std-sdcc99

#important directories#
DIR_OUTPUT     = ../obj
HML_FWLIB_INC  = ../inc
HML_FWLIB_SRC  = ../src

#target#
TARGET         = output
HEX_TARGET     = ${DIR_OUTPUT}/${TARGET}
	
all:startup $(TARGET).hex
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89:all work is done!"

output.hex:output.ihx
	@cd ${DIR_OUTPUT} && packihx $(HEX_TARGET).ihx > $(TARGET).hex
output.ihx:test.rel exti.rel gpio.rel isp.rel mem.rel tim.rel tim2.rel uart.rel util.rel wdt.rel
	@cd ${DIR_OUTPUT} && $(CC) $^ -o $(HEX_TARGET).ihx

#source files of HML_FwLib_STC89#
exti.rel:${HML_FWLIB_SRC}/exti.c
	@$(CC) $< $(CFLAGS)
gpio.rel:${HML_FWLIB_SRC}/gpio.c
	@$(CC) $< $(CFLAGS)
isp.rel:${HML_FWLIB_SRC}/isp.c
	@$(CC) $< $(CFLAGS)
mem.rel:${HML_FWLIB_SRC}/mem.c
	@$(CC) $< $(CFLAGS)
tim.rel:${HML_FWLIB_SRC}/tim.c
	@$(CC) $< $(CFLAGS)
tim2.rel:${HML_FWLIB_SRC}/tim2.c
	@$(CC) $< $(CFLAGS)
uart.rel:${HML_FWLIB_SRC}/uart.c
	@$(CC) $< $(CFLAGS)
util.rel:${HML_FWLIB_SRC}/util.c
	@$(CC) $< $(CFLAGS)
wdt.rel:${HML_FWLIB_SRC}/wdt.c
	@$(CC) $< $(CFLAGS)
#source file of user#	
test.rel:test.c
	@$(CC) $< $(CFLAGS)

#startup information#
startup:
	@echo
	@echo "MK-HML_FwLib_STC89 [v0.0.0]"
	@echo "Copyright(c) 2018 ZHISHAN-IoT, all rights reserved."
	@echo "Written by Weilun Fong <wlf(at)zhishan-iot.ga>"
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89:start to generate target file!"
	@echo

#clean temp files#	
.PHONY:clean
clean:
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89:start to clean...."
	@cd ${DIR_OUTPUT} && rm *.asm *.ihx *.lst *.lk *.map *.mem *.rel *.rst *.sym
	@echo "MAKEFILE - HML_FwLib_STC89:Ok"
	
.PHONY:mostlyclean 
mostlyclean:
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89:start to clean...."
	@cd ${DIR_OUTPUT} && rm *.asm *.hex *.ihx *.lst *.lk *.map *.mem *.rel *.rst *.sym
	@echo "MAKEFILE - HML_FwLib_STC89:Ok"
