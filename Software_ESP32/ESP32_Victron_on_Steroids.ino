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
              V . Connect directly to 32 / GPIO32 
              (don't mind the 5V level; the output is very weak and will be clipped to 3,3V anyway)


    TTGO TFT COLOR

    GND           3,3V
    GND           A0  (GPIO36)
    SDA           A1  (GPIO37)
    SCL           A2  (GPIO38)
    TX1           A3  (GPIO39)
    GPIO02        RX1 (GPIO32) 
    GPIO15        SW Rot Encoder  (GPIO33)
    GPIO13        A  Rot Encoder  (GPIO25)
    GPIO12        B  Rot Encoder  (GPIO26)
    GND           GPIO 27
    GND           GND
    3,3V          5V


  Get values via Telnet
  telnet <IPADDR>
*/
