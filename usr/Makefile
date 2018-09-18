#Author     :Weilun Fong | wlf(at)zhishan-iot.tk
#Date       :2018-09-16
#Description:Makefile for HML_FwLib_STC89, it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.tk
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
#Tar-mcu    :STC micro STC89 series (STC89C52RC, STC89C54RD, etc.)
#Tar-project:HML_FwLib_STC89
#Vesrion    :v0.0.1

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
	@echo "MAKEFILE - HML_FwLib_STC89: completed at `date "+%Y-%m-%d %H:%M:%S"`"
	
$(TARGET).hex:$(TARGET).ihx
	@echo generate .hex file
	@cd ${DIR_OUTPUT} && packihx $(HEX_TARGET).ihx > $(TARGET).hex
$(TARGET).ihx:test.rel exti.rel gpio.rel isp.rel mem.rel rst.rel tim.rel tim2.rel uart.rel util.rel wdt.rel
	@echo
	@echo generate .ihx file
	@cd ${DIR_OUTPUT} && $(CC) $^ -o $(HEX_TARGET).ihx

#source files of HML_FwLib_STC89#
exti.rel:${HML_FWLIB_SRC}/exti.c
	@echo CC ${HML_FWLIB_SRC}/exti.c
	@$(CC) $< $(CFLAGS)
gpio.rel:${HML_FWLIB_SRC}/gpio.c
	@echo CC ${HML_FWLIB_SRC}/gpio.c
	@$(CC) $< $(CFLAGS)
isp.rel:${HML_FWLIB_SRC}/isp.c
	@echo CC ${HML_FWLIB_SRC}/isp.c
	@$(CC) $< $(CFLAGS)
mem.rel:${HML_FWLIB_SRC}/mem.c
	@echo CC ${HML_FWLIB_SRC}/mem.c
	@$(CC) $< $(CFLAGS)
rst.rel:${HML_FWLIB_SRC}/rst.c
	@echo CC ${HML_FWLIB_SRC}/rst.c
	@$(CC) $< $(CFLAGS)
tim.rel:${HML_FWLIB_SRC}/tim.c
	@echo CC ${HML_FWLIB_SRC}/tim.c
	@$(CC) $< $(CFLAGS)
tim2.rel:${HML_FWLIB_SRC}/tim2.c
	@echo CC ${HML_FWLIB_SRC}/tim2.c
	@$(CC) $< $(CFLAGS)
uart.rel:${HML_FWLIB_SRC}/uart.c
	@echo CC ${HML_FWLIB_SRC}/uart.c
	@$(CC) $< $(CFLAGS)
util.rel:${HML_FWLIB_SRC}/util.c
	@echo CC ${HML_FWLIB_SRC}/util.c
	@$(CC) $< $(CFLAGS)
wdt.rel:${HML_FWLIB_SRC}/wdt.c
	@echo CC ${HML_FWLIB_SRC}/wdt.c
	@$(CC) $< $(CFLAGS)
#source file of user#	
test.rel:test.c
	@echo CC test.c
	@$(CC) $< $(CFLAGS)

#startup information#
startup:
	@echo
	@echo "==================================================="
	@echo "MK-HML_FwLib_STC89 [v0.0.1]"
	@echo "Copyright(c) 2018 ZHISHAN-IoT, all rights reserved."
	@echo "Written by Weilun Fong <wlf(at)zhishan-iot.tk>"
	@echo "==================================================="
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89: start at `date "+%Y-%m-%d %H:%M:%S"`"
	@echo

#clean temp files#	
.PHONY:clean
clean:
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89:start to clean...."
	
	@cd ${DIR_OUTPUT} && (find . -name "*.asm" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.ihx" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lk"  | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lst" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.map" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.mem" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.rel" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.rst" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.sym" | xargs rm -rfv)
	
	@echo
	@echo "MAKEFILE - HML_FwLib_STC89: complete to clean."
	
.PHONY:mostlyclean 
mostlyclean:clean
	@echo "MAKEFILE - HML_FwLib_STC89: start to clean mostly...."
	@cd ${DIR_OUTPUT} && (find . -name "*.hex" | xargs rm -rfv)
	@echo "MAKEFILE - HML_FwLib_STC89: complete to clean mostly."
	