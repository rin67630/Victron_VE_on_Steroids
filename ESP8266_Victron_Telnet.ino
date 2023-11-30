/*
     Inspired from https://github.com/datjan/esp8266-victron-mppt-solarchargecontroller/blob/main/esp8266-victron-mppt-solarchargecontroller.ino
     modified for Telnet instead of Software Serial
     Target: Witty ESP8266 or Wemos D1:  Board Setting: Wemos D1

*** Victron connector (Grove 2mm type) ***
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
              V . Connect directly to D7 / GPIO13 
              (don't mind the 5V level; the output is very weak and will be clipped to 3,3V anyway)

*** Witty ESP8266 or Wemos D1 Pinout      

          REST         |       TX0
          ADC    LDR   |       RX0 
          CH_PD        |       GPIO05  D1
  D0      GPIO16       | BTN   GPIO04  D2
  D5      GPIO14       |       GPIO00  D3
  D6      GPIO12 RGB-G |       GPIO02  D4 TX1
  D7 RX0* GPIO13 RGB-B | RGB-R GPIO15  D8 TX0*
          VCC          |       GND

*  after Serial.swap()

Feed the Witty ESP8266 or Wemos D1 over a 12V / 5V micro buck converter

 Get values via WebUI
  http://<IPADDR>

  Get values via JSON
  GET http://<IPADDR>/rest

  Get values via Telnet
  telnet <IPADDR>
*/
