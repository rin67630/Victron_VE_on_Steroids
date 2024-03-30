// N.B. Compile sketch with following board settings: 
//- for option 8266:           LolinWEMOSD1 (Clone)     
//- for option TTGO:           TTGO T1 
//- for option HELTEC LoRa:    HELTEC WiFi Lora32  (Not V2 !) from HELTEC, not generic
//----------------------- HARDWARE OPTIONS ---------------------------------
#define CONTR_IS_ESP8266  //_IS_HELTEC, _IS_TTGO, _IS_ESP8266, _IS_ESP32;                     Choice of ESP controller boards
#define SCREEN_IS_NONE    // _NONE , _64x48 , _128x64, _TTG0, _HELTEC, _WEMOS32 ; 
#define SCREEN_IS_REVERSED// _IS_NORMAL, _IS_REVERSED To turn the display 180° if required
#define BRIGHTNESS  255   // PWM value for default brightness with TTGO 0=totally dark;255=totally shiny

#define A0_IS_SIMUL       // _NONE , _DOUBLEBATTERY , _HALFBATTERY, _PANEL, _POT, _SIMUL
#define A0_MAX       38   // if A0 is used, define the voltage of the full range measure
#define D0_IS_NONE        // _NONE , _RELAY1
#define D5_IS_NONE        // _NONE , _RELAY2
#define D6_IS_NONE        // _NONE , _RELAY3, _VE_BLOCK, _VE_START_STOP
#define D7_IS_NONE        // _NONE , _RELAY4; _VICTRON
#include "MPPT_75_15.h"   // Type of Victron controller (Only relevant if D7_IS_VICTRON)
#define INA_IS_NONE       // _NONE , _226
#include "SHUNT_10A_75mV.h" // Shunt Characteristics  (only relevant if INA_IS_226)
#define INA_VBUS_IS_FULL  // _FULL _HALF   (when high voltage schematic is used)
#define NUMBER_CELLS      4   // Number of cell in Battery
#define AH_CELLS          100 // AH of the battery
#define TYPE_IS_LIFEPO    // _LIFEPO, _LEAD, _LIION
#define POC_IS_TABLE      // _TABLE, _VICTRON   defines if POC is estmated from a table or comes from Victron

//----------------------- SOFTWARE OPTIONS ---------------------------------
#define WEATHER_IS_OWM    // _NONE , _OWM , _BME680        // (Source of the Weather Information)
#define DASHBRD_IS_NONE   // _NONE , _THINGER              // (Internet Dashboard)
#define TERM_IS_TELNET    // _NONE , _TELNET, _SERIAL , _SOFTSER, _2SERIAL // defines where do Menus and Reports occur: _SERIAL and D7_IS_VICTRON are mutually exclusive )
#define UDP_IS_SEND       // _NONE , _SEND , _RECEIVE      // (UDP Inter-ESP Communication)
#define ESP_UDP_ADDR       "192.168.188.85"                // (IP of the receiving ESP having UDP_IS_RECEIVE) 
#define ESP_UDP_PORT       4200  // (Port used to send/receive Values to other ESP)
#define COM_IS_NONE       // _NONE , _HOURLY ,_MIDNIGHT    // Periodical reports to computer 
#define COM_UDP_ADDR       "192.168.188.96"                // (IP of the receiving computer for night reports) 
#define COM_UDP_PORT       4230                            // (Port used to send/receive Values to other computer) 
#define DEVICE_NAME        "Witty"                         // Name of the device used as Hostname and at Thinger.io
#define DEVICE_NUMBER      0                               // 0 if no ESP32 supervisor, else 1..4

//--------------------------- WiFi Options -------------------------------------
#define WIFI_REPEAT          1000     //mS for retry
#define WIFI_MAXTRIES        30
#define WIFI_POWER           7.5

//----------------------DO NOT EDIT until you know what you do -------------
#define SERIAL_SPEED      19200
#define LDR               A0
#define RELAY1            16    // D0  Relay or FET control 1
#define RELAY2            14    // D5  Relay or FET control 2
#define REDLED            15    // D8
#define BLULED            13    // D7 <-- Victron
#define GRNLED            12    // D6
