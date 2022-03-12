# ------------------------------------------------------------------------
# Author     : Jiabin Hsu  | zsiothsu@zhishan-iot.tk
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-03-12
# Description: config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc89.html
# Project    : HML_FwLib_STC89
# Version    : v0.0.2
# ------------------------------------------------------------------------

# Print note information
message(STATUS "Collect MCU config information")

# Options for print format
# [VERBOSE] Building print control, the value will be passed to CMake builtin
#   variable CMAKE_VERBOSE_MAKEFILE. CMake will print more when the value is
#   set as 'TRUE'
set(VERBOSE FALSE CACHE BOOL "Verbose mode")

# Options for MCU configurations
#  [MCU] MCU model option, user can get model support list via cmake/cflags.cmake.
#   This parameters is case-insensitive.
set(MCU stc89c52rc)

# Options for MCU configurations
#  [CLKFRE] Specify frequency of MCU clock, the unit is Hz.
#  [PRESCALER] Specify MCU prescaler factor, the value must be 6(6T mode) or
#    12(12T mode).
set(CLKFRE 11059200 CACHE STRING "Frequency of MCU clock")
set(PRESCALER 12 CACHE STRING "Prescaler factor of system clock")
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
set(EXECUTABLE_C usr/test.c CACHE PATH "Path of executable source fils")
