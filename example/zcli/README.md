zCLI
====
zCLI is a lite command line interface which entirely runs on target MCU. It provides a basic frame to do command from user via 
UART and supports following functions:
+ basic input & output function
+ support \[backsapce\]
+ support hotkey \[tab\] for entering last history valid command automatically
+ clean screen
+ multi-parameter command(gap with space)
+ ...

![image](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC89/blob/master/example/zcli/zcli-usage-demo.gif)

zCLI just a toy, and it written by [Weilun Fong](mailto:wlf@zhishan-iot.tk) in 2020. However, it can also help people learn how 
to achieve a own CLI program on MCU with limited on-chip zone. zCLI is now released as a example file inside HML. Welcome PR or
issues to improve this CLI program, thx!
