 /*
Victron-on-Steroids_HAL_Files
(Hardware Abstraction Layer)

These files are used to adapt different hardware configurations to the common Victron-on-Steroids software.
The complete Victron-on-Steroids_HAL_Files folder must be placed in the Arduino IDE libraries folder

Victron-on-Steroids is designed in a flexible way in order to support different hardware components:

*** Victron MPPT converters ***
- MPPT_75_10.h
- MPPT_75_15.h
- MPPT_75_15_old.h
- MPPT_100_10.h
- MPPT_100_30.h
etc.

*** Victron Smart shunts ***
- VSS_500.h

*** Dumb shunts ***
- 10A_75mV.h
- 30A_75mV.h
- 50A_75mV.h
- 200A_50mV.h
- 500A_50mV.h

*** ESP development boards ***
The development board files mainly contain the input output definitions. You should normally not change that content unless you know what you're doing.

- ESP8266                                -> Wemos_D1.h
- ESP8266 with OLED Display 64x64 Pixel  -> Wemos_D1_64x64.h
- ESP8266 with OLED Display 128x64 Pixel -> Wemos_D1_128x64.h
- ESP32 TTGO with TFT Display            -> TTG_LCD.h
- ESP32 WEMOS with OLED Display          -> Wemos_OLED.h
- Heltec ESP32 with LoRa and OLED Display-> Heltec_LoRa.h

*** Different battery chemistries ***
The battery chemistry files contain the different voltage levels, used for charging, you may change the battery capacity accordingly and the voltages if you know what you're doing. 
- Flooded Lead Acid 12V 100Ah           -> FLA12_100Ah.h
- Gel Lead Acid 12V 12Ah GEL12-12Ah.h
- LithiumIon 3*4 18650 cells in series  -> LiIon3S_4P_8Ah.h
- LiFePo 4*2 32650 cells in series      -> LiFePo_4S_2P_8Ah.h
- LiFePo 4*2 13V 100AH                  -> LiFePo_13V_100Ah.h
and so on...

There is no need to compile this .ino file all information are included in the main programm: This ino is just provided to facilitate editing.
Please think to save if you have modified something: Since you don't compile the content will not be saved automatically.

*** For reference: Protocol for a MPPT Solar converter ***

PID 0xA043 -- Product ID for BlueSolar 
FW 119 -- Firmware version of controller, v1.19
SER# HQXXXXXXXXX -- Serial number
V 13790 -- Battery voltage, mV
I -10 -- Battery current, mA
VPV 15950 -- Panel voltage, mV
PPV 0 -- Panel power, W
CS 5 -- Charge state, 0 to 9
ERR 0 -- Error code, 0 to 119
LOAD ON -- Load output state, ON/OFF
IL 0 -- Load current, mA
H19 0 -- Yield total, kWh
H20 0 -- Yield today, kWh
H21 397 -- Maximum power today, W
H22 0 -- Yield yesterday, kWh
H23 0 -- Maximum power yesterday, W
HSDS 0 -- Day sequence number, 0 to 365
Checksum l:A0002000148 -- Message checksum
*/
