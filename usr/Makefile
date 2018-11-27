#Author     :Weilun Fong | wlf(at)zhishan-iot.tk
#Date       :2018-11-26
#Description:Makefile for HML_FwLib_STC89, it will generate a hex format file finally
#E-mail     :mcu(at)zhishan-iot.tk
#Make-tool  :GNU Make (http://www.gnu.org/software/make/manual/make.html)
#Page       :https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
#Tar-mcu    :STC micro STC89 series (STC89C52RC, STC89C54RD, etc.)
#Tar-project:HML_FwLib_STC89
#Version    :v0.0.3

#important directories#
DIR_ROOT       = ..
DIR_INC        = $(DIR_ROOT)/inc
DIR_OUTPUT     = $(DIR_ROOT)/obj
DIR_SRC        = $(DIR_ROOT)/src
#important files#
HML_SRC_FILES  = $(wildcard ${DIR_SRC}/*.c)
HML_SRC_NAMES  = $(basename $(notdir ${HML_SRC_FILES}))
HML_REL_FILES  = $(addsuffix .rel, $(addprefix ${DIR_OUTPUT}/, ${HML_SRC_NAMES}))
#operation parameter#
CFLAGS         = -c -o ${DIR_OUTPUT}/ -I ${DIR_INC} --std-sdcc99 -L ${DIR_OUTPUT}/hml_fw.lib
LFLAGS         = -rcs
#target#
HML_FWLIB_NAME = HML_FwLib_STC89
TARGET         = output
#tool-chain#
CC             = sdcc
LL             = sdar

###function define###
#function-clean#
define clean_obj
	@echo
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
#function-show_end_information#
define show_end_information
	@echo
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo Makefile - $(HML_FWLIB_NAME)
	@echo ---------------------------------------------------
	@echo completed at `date "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
endef
#function-show_version#
define show_version
	@echo ===================================================
	@echo "MK-$(HML_FWLIB_NAME) [v0.0.3]"
	@echo "Copyright(c) 2018 ZHISHAN-IoT, all rights reserved."
	@echo "Written by Weilun Fong <wlf(at)zhishan-iot.tk>"
	@echo ===================================================
	@echo
endef

###build works###
all:startup $(TARGET).hex
	$(show_end_information)

$(TARGET).hex:$(TARGET).ihx
	@echo generate .hex file
	@cd ${DIR_OUTPUT} && packihx $< > $@
$(TARGET).ihx:test.rel hml_fw.lib
	@echo generate .ihx file
	@cd ${DIR_OUTPUT} && $(CC) $^ -o $@

#compile source file(*.c)
$(HML_REL_FILES):$(HML_SRC_FILES)
ifeq ($(wildcard ${DIR_OUTPUT}/hml_fw.lib), )
	@echo make static link library hml_fw.lib
	@(for cur_file in $(HML_SRC_FILES); do \
		echo CC "$$cur_file";              \
		$(CC) "$$cur_file" $(CFLAGS);      \
	done)
endif
#generate static library
hml_fw.lib:$(HML_REL_FILES)
ifeq ($(wildcard ${DIR_OUTPUT}/hml_fw.lib), )
	@echo LL ${DIR_OUTPUT}/$@
	@$(LL) $(LFLAGS) $(DIR_OUTPUT)/$@ $(HML_REL_FILES)
	@echo
endif
#startup information#
startup:
	$(show_version)
	@echo start at `date "+%Y-%m-%d %H:%M:%S"`
	@echo
#compile source file of user#
test.rel:test.c hml_fw.lib
	@echo compile user source code
	@echo CC $<
	@$(CC) $< $(CFLAGS) -L ${DIR_OUTPUT}/hml_fw.lib
	@echo

###special operation###
#clean temp files#
.PHONY:clean
clean:
	$(show_version)
	@echo start to clean...
	$(clean_obj)
	$(show_end_information)
	
.PHONY:mostlyclean 
mostlyclean:
	$(show_version)
	@echo start to clean mostly...
	$(clean_obj)
	@cd ${DIR_OUTPUT} && (find . -name "*.hex" | xargs rm -rfv)
	@cd ${DIR_OUTPUT} && (find . -name "*.lib" | xargs rm -rfv)
	$(show_end_information)
