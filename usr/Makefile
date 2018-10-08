#Author     :Weilun Fong | wlf(at)zhishan-iot.tk
#Date       :2018-09-16
#Description:Makefile for HML_FwLib_STC89, it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.tk
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
#Tar-mcu    :STC micro STC89 series (STC89C52RC, STC89C54RD, etc.)
#Tar-project:HML_FwLib_STC89
#Version    :v0.0.2

#important directories#
DIR_OUTPUT     = ../obj
HML_FWLIB_INC  = ../inc
HML_FWLIB_SRC  = ../src
#operation parameter#
CFLAGS         = -c -o ${DIR_OUTPUT}/ -I ${HML_FWLIB_INC} --std-sdcc99 -L ${DIR_OUTPUT}/hml_fw.lib
LFLAGS         = -rcs
#target#
TARGET         = output
REL_TARGET     =  $(addprefix ${DIR_OUTPUT}/, exti.rel gpio.rel isp.rel mem.rel rst.rel tim.rel tim2.rel uart.rel util.rel wdt.rel)
#tool-chain#
CC             = sdcc
LL             = sdar

#function define#
#function-clean#
define clean_obj
	@cd ${DIR_OUTPUT} && (find . -name "*.asm" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.ihx" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lk"  | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lst" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.map" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.mem" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.rel" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.rst" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.sym" | xargs rm -rfv)
endef
#function-show_version#
define show_version
	@echo ===================================================
	@echo "MK-HML_FwLib_STC89 [v0.0.2]"
	@echo "Copyright(c) 2018 ZHISHAN-IoT, all rights reserved."
	@echo "Written by Weilun Fong <wlf(at)zhishan-iot.tk>"
	@echo ===================================================
endef

all:startup $(TARGET).hex
	@echo
	@echo ===================================================
	@echo Make done!
	@echo Makefile - HML_FwLib_STC89
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================

output.hex:output.ihx
	@echo generate .hex file
	@cd ${DIR_OUTPUT} && packihx $(TARGET).ihx > $(TARGET).hex
output.ihx:test.rel hml_fw.lib
	@echo
	@echo generate .ihx file
	@cd ${DIR_OUTPUT}/ && $(CC) $^ -o $(TARGET).ihx

#source files of HML_FwLib_STC89#
hml_fw.lib:
ifeq ($(wildcard ${DIR_OUTPUT}/hml_fw.lib), )

	@echo make static link library hml_fw.lib
	@echo CC ${HML_FWLIB_SRC}/exti.c
	@$(CC) ${HML_FWLIB_SRC}/exti.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/gpio.c
	@$(CC) ${HML_FWLIB_SRC}/gpio.c $(CFLAGS)

	@echo CC ${HML_FWLIB_SRC}/isp.c
	@$(CC) ${HML_FWLIB_SRC}/isp.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/mem.c
	@$(CC) ${HML_FWLIB_SRC}/mem.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/rst.c
	@$(CC) ${HML_FWLIB_SRC}/rst.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/tim.c
	@$(CC) ${HML_FWLIB_SRC}/tim.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/tim2.c
	@$(CC) ${HML_FWLIB_SRC}/tim2.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/uart.c
	@$(CC) ${HML_FWLIB_SRC}/uart.c $(CFLAGS)

	@echo CC ${HML_FWLIB_SRC}/util.c
	@$(CC) ${HML_FWLIB_SRC}/util.c $(CFLAGS)
	
	@echo CC ${HML_FWLIB_SRC}/wdt.c
	@$(CC) ${HML_FWLIB_SRC}/wdt.c $(CFLAGS)
	
	@echo LL ${DIR_OUTPUT}/hml_fw.lib
	@cd ${DIR_OUTPUT} && $(LL) $(LFLAGS) hml_fw.lib $(notdir $(REL_TARGET))
	@echo
	
endif	
#source file of user#	
test.rel:test.c hml_fw.lib
	@echo complie user source code
	@echo CC test.c
	@$(CC) $^ $(CFLAGS) -L ${DIR_OUTPUT}/hml_fw.lib

#startup information#	
startup:
	@echo
	$(show_version)
	@echo
	@echo start at `date "+%Y-%m-%d %H:%M:%S"`
	@echo

#clean temp files#	
.PHONY:clean
clean:
	@echo
	$(show_version)
	@echo
	@echo start to clean...
	@echo
	$(clean_obj)
	@echo
	@echo ===================================================
	@echo Make clean done!
	@echo Makefile - HML_FwLib_STC89
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
	
.PHONY:mostlyclean 
mostlyclean:
	@echo
	$(show_version)
	@echo
	@echo start to clean mostly...
	@echo
	$(clean_obj)
	@cd ${DIR_OUTPUT} && (find . -name "*.hex" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lib" | xargs rm -rfv)
	@echo
	@echo ===================================================
	@echo Make mostlyclean done!
	@echo Makefile - HML_FwLib_STC89
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
