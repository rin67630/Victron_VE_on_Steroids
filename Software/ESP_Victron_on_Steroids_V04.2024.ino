/*
Software from https://github.com/rin67630/Victron_VE_on_Steroids

Target Hardware modules: 
- Witty ESP8266 or WEMOS D1,  Board Setting: WEMOS D1 Mini (Clone), or ESP8266 Bare
- ESP32 TTGO (with Color Display), Board Setting: 
- ESP32 HELTEC LoRa V1 Board setting, Board Setting: Heltec WiFi LoRa 32 (not V2) 
- ESP32 with or without I2C OLED display. Board Setting: LoLin Wemos32 

Arduino IDE Preferences for above type of boards settings: http://arduino.esp8266.com/stable/package_esp8266com_index.json
https://github.com/HELTEC-Aaron-Lee/WiFi_Kit_series/releases/download/1.0.0/package_HELTEC_esp32_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

*** Victron connector (Grove / JST micro PH, 2mm type)
         _______________
        |               |
        |  Victron JST  |
        |_______________|
        |YEL|WHT|RED|BLK|
        | 1 | 2 | 3 | 4 |
        |+5V|TX |RX |GND|
        |___|_:::::_|___|
              |
              |
              V . Connect directly to  GPIO32 (ESP32)  D7 (ESP8266) (see pinouts below)
              (don't mind the 5V level; the output is very weak and will be clipped to 3,3V anyway)

***  Usage of the menu via Telnet  ***
Type telnet (the respecive module's IP Aaddress) on your Linux / MacOS terminal. 
On Windows, use PuTTY or WSL, the Windows implemantation of Telnet is broken.

*** The legal stuff ***
This software is open-source under creative common license CC BY-SA
It is given in the hope to be useful, but I am NOT RESPONSIBLE IN ANY WAY OF DAMAGES WAHTSOEVER 
occuring from the use of my software.
Be careful, high currents, DC voltages over 24V, Batteries can cause damages to property and/or health, even kill you !

*** Credits ***

Libraries:
Thanks to the respective owners of all libraries used:
-ESP8266 and ESP32 OLED driver for SSD1306 displays by ThingPulse, Fabrice Weinberg
-MobaTools by MicroBahner from which I took the Motobuttons.h lib
-Arduinojson by Benoit Blanchon <blog.benoitblanchon.fr>
-ThingerCore32 and Thinger.io by Alvaro Luis Bustamante
-TelnetStream by Juraj Andrassy
-INA226 by Rob Tillaart 
The other libraries are the standard libs from Arduino, Espressif, Adafruit...

*** Forked code ***
-Victron Parser: Thanks to Datjan for his parser code: https://github.com/datjan/esp8266-victron-mppt-solarchargecontroller

Presentation music: 
Lights by Sakura Girl | https://soundcloud.com/sakuragirl_official
Music promoted by https://www.chosic.com/free-music/all/


Software provide free under Creative Commons CC BY 3.0 license
https://creativecommons.org/licenses/by/3.0/

*** Pinout References ***
***  TTGO TFT COLOR Pinout
           GND           |   3,3V
           GND           |   A0             (GPIO36)  
(GPIO21)   SCL           |   A2             (GPIO38)
(GPIO22)   TX1           |   A3             (GPIO39)
(GPIO02)   GPIO02        |   RX1            (GPIO32) 
(GPIO15)   GPIO15   RED  |   SW Rot Encoder (GPIO33)
(GPIO13)   GPIO13   BLU  |   A  Rot Encoder (GPIO25)
(GPIO12)   GPIO12   GRN  |   B  Rot Encoder (GPIO26)
           GND           |   GPIO 27
           GND           |   GND
           3,3V          |   5V


*** SP8266 or WEMOS D1 Pinout
          REST         |       TX0
  A0      ADC          |       RX0
          Power Down   |       GPIO05  D1
  D0      GPIO16       | BTN   GPIO04  D2
  D5      GPIO14       |       GPIO00  D3
  D6      GPIO12 GRN   | LED   GPIO02  D4 TX1
  D7 RX0* GPIO13 BLU   | RED   GPIO15  D8 TX0*
          VCC          |       GND

  * after Serial.swap()

Witty  Pinout
          REST         |       TX0
  A0      ADC          |       RX0
          Power Down   |       GPIO05  D1  SCL
  D0      GPIO16       | BTN   GPIO04  D2  SDA   
  D5      GPIO14       |       GPIO00  D3
  D6      GPIO12 GRN   | LED   GPIO02  D4 TX1   (ESP)
  D7 RX0* GPIO13 BLU   | RED   GPIO15  D8 TX0*
          VCC          |       GND

*** ESP8266 or WEMOS D1  Pinout
          REST         |       TX0
  A0      ADC          |       RX0
  D0      GPIO16       |       GPIO05  D1   SCL
  D5      GPIO14       | BTN   GPIO04  D2   SDA
  D6      GPIO12 GRN   |       GPIO00  D3
  D7 RX0* GPIO13 BLU   | LED   GPIO02  D4 TX1
  D8 TX0* GPIO15 RED   |       GND
  3,3V    VCC          |       5V

  * after Serial.swap()
  
*/
