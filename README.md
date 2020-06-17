# VL53L0X(STMicro) ToF sensor with RL78/G10 software library (Rev.20200416)

This is a project to use VL53L0X ToF sensor with RL78/G10
included with CS+ environment setting files provided by Renesas Electronics Corp.
So you can easily modify and add this codes with CS+ on Windows PC.
  
Let's enjoy it !

## Information for target board

RL78/G10 board "AE-R5F10Y47ASP" is provided by Akizukidenshi in Japan.
  
Akizuki : http://akizukidenshi.com/catalog/g/gK-09035/
  
  
ToF sensor board is "AE-VL53L0X" by Akizukidenshi or "#15310" by Strawberry Linux
  
Akizuki : http://akizukidenshi.com/catalog/g/gM-12590/

Strawberry Linux : https://strawberry-linux.com/catalog/items?code=15310


## Installation

Import this project into CS+.
  

## Usage

The protocol stack is defined with an ICS3.5 provided by KONDO Kagaku.
ICS3.5 uses "Data=8bit, Stop=1bit, Parity=EVEN, baudrate=1.5Mbps."
You will get 4 sensor unit data when master MCU/MPU send 4 bytes data as follows :

|Command|SC|Address|Length|
|-------|--|-------|------|
|0xA0+ID|0x7F|0(fiexed)|2(fiexed)|
  
ID is defined as D_MY_ID in "cg_src/r_cg_userdefine.h".
  

## Current Support Peripherals

|Function Name        | Pin Name        | notes |
|:--------------------|:---------------:|:------|
|I2C I/F              |P06/SCLA0        | connecting to ToF sensor | 
|I2C I/F              |P07/SDAA0        | connecting to ToF sensor | 
|UART I/F             |P00/TxD0         | connecting to RxD of master MCU/MPU | 
|UART I/F             |P01/RxD0         | connecting to TxD of master MCU/MPU | 
|X'tal                |X1,X2            | mounted on board |
|OCD Debugger I/F     |RESET, TOOL0     | connecting to DEBUGGER |
|Non Connections      |P02-05, P41, P137 | |
  
You can refer CAD data with Eagle(.brd and .sch) to understand the circuit.
  
|File Name | purpose |
|:--------:|:-------:|
|RL78G10_ToF_A2.brd| PCB pattern data for ToF sensor with R5F10Y47ASP|
|RL78G10_ToF_A2.sch| circuit data |
|--------|-------|
|RL78G10_E1.brd| PCB pattern data connecting to E1/E2/E2Lite |
|RL78G10_E1.sch| circuit data |
  
