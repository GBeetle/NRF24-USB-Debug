NRF24 debugger 

A nrf24 debug tool for Welkin(https://github.com/GBeetle/welkin)

command

HEAD | CMD_ID | ARG1 | ARG2 | ARG3 | ARG4 | CHECK | TAIL
0x7E | xxxxxx | xxxx | xxxx | xxxx | xxxx | xxxxx | 0xAA

COMMAAND_ID
0x01  read_register
0X02  write_register
0x03  read_registers
0x04  write_registers
0x05  CE_CONTROL        ARG1: 1(HIGH) 0(LOW)
0x06  CS_CONTROL        ARG1: 1(HIGH) 0(LOW)
