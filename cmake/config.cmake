# ------------------------------------------------------------------------
# Author     : Jiabin Hsu  | zsiothsu@zhishan-iot.tk
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-01-16
# Description: config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.0.1
# ------------------------------------------------------------------------

# Print note information
message(STATUS "Collect MCU config information")

# Options for print format
#  [CMAKE_VERBOSE_MAKEFILE] This is a builtin variable which provides by CMake.
# CMake will print more details, when its value is "TRUE".
set(CMAKE_VERBOSE_MAKEFILE FALSE)

# Options for MCU configurations
#  [MCU] MCU model option, user can get model support list via reading Makefile.mcu.
#   This parameters is case-insensitive.
set(MCU stc89c52rc)

# Options for MCU configurations
#  [CLKFRE] Specify frequency of MCU clock, the unit is Hz.
#  [PRESCALER] Specify MCU prescaler factor, the value must be 6(6T mode) or
#    12(12T mode).
set(CLKFRE 11059200)
set(PRESCALER 12)
#  [CODE] Specify total size of ROM(external+ on-chip) during compilation
#    manually (unit: KB)
#  [XRAM] Specify total size of external RAM during compilation manually
#    (unit: KB)
# set(CODE 8)
# set(XRAM 0)

# Options for build target
#  [EXECUTABLE_C] Specify user source file or Makefile will fill it with "test.c".
#    It's noticed that once use this option to compile specified .c file,
#    user should add this option when do all targets related to build operation,
#    such as clean and rebuild.
set(EXECUTABLE_C usr/test.c)
