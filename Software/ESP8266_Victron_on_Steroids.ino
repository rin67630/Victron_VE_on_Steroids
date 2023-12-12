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

*** Witty ESP8266 Pinout      

          RESET        |       GPIO001 TX0
  0..1V   ADC    LDR   |       GPIO003 RX0 
  PwerDwn CH_PD        |       GPIO05  D1      SCL
  D0      GPIO16       | BTN   GPIO04  D2      SDA   On board Button
  D5      GPIO14       |       GPIO00  D3         (Flash)
  D6      GPIO12 RGB-G |       GPIO02  D4 TX1 , PWM, onboard LED
  D7 RX0* GPIO13 RGB-B | RGB-R GPIO15  D8 TX0*   
          VCC 5V       |       GND

*** Wemos D1 Pinout

          RESET        |       GPIO001 TX0
  0..3,3V ADC          |       GPIO003 RX0 
  D0      GPIO16       |       GPIO05  D1      SCL
  D5      GPIO14       | BTN   GPIO04  D2      SDA
  D6 RX0  GPIO12       |       GPIO00  D3         (Flash)
  D7 TX0  GPIO13       |       GPIO02  D4 TX1 , PWM, onboard LED
  D8 TX0* GPIO15       |       GND
  +3,3V                |       +5V VCC

*  after Serial.swap()

Feed the Witty ESP8266 or Wemos D1 over a 12V / 5V micro buck converter

  Get values via Telnet
  telnet <IPADDR>
*/
