// N.B. Compile sketch with following board settings: 
//- for option 8266:           LolinWEMOSD1 (Clone)     
//- for option TTGO:           TTGO T1 
//- for option HELTEC LoRa:    HELTEC WiFi Lora32  (Not V2 !) from HELTEC, not generic
//----------------------- HARDWARE OPTIONS ---------------------------------
#define SCREEN_IS_128x64   // _NONE , _64x48 , _128x64, _TTG0, _HELTEC, _WEMOS32 _HW364A ; 
#define SCREEN_IS_REVERSED // _IS_NORMAL, _IS_REVERSED To turn the display 180° if required
#define BRIGHTNESS 128     // PWM value for default brightness with TTGO 0=totally dark;255=totally shiny

//----------------------- SOFTWARE OPTIONS ---------------------------------
#define DASHBRD_IS_NONE    // _NONE , _THINGER          // (Internet Dashboard)
#define TERM_IS_TELNET     // _TELNET, _SERIAL , _SOFTSER, _2SERIAL // defines where do Menus and Reports occur: _SERIAL and D7_IS_VICTRON are mutually exclusive )
#define UDP_IS_NONE        // _NONE , _SEND , _RECEIVE  // (UDP Inter-ESP Communication)
#define COM_IS_NONE        // _NONE , _HOURLY           // Periodical reports to computer 
#define ESP_UDP_ADDR       "192.168.188.85"                 // (IP of the receiving ESP having UDP_IS_RECEIVE) 
#define ESP_UDP_PORT       4200  // (Port used to send/receive Values to other ESP)
#define COM_UDP_ADDR       "192.168.188.96"              // (IP of the receiving computer for night reports) 
#define COM_UDP_PORT       4230                          // (Port used to send/receive Values to other computer) 
//#define // DEVICE_NAME        "Steroids"                  // Name of the device used as Hostname and at Thinger.io 
#define DEVICE_NAME        WiFi.getHostname()            // Device name is automatic from MAC-Address
#define DEVICE_NUMBER      0 

//----------------------- MEASUREMENT OPTIONS---------------------------------
#define WEATHER_SOURCE_IS_OWM     // _NONE , _OWM , _BME680       // (Source of weather Information, URL in Credentials.h)
#define A0_IS_SIMUL       // _NONE , _DOUBLEBATTERY , _HALFBATTERY, _PANEL, _POT, _SIMUL
#define A0_MAX       40   // if A0 is used, define the voltage of the full range measure
#define D0_IS_NONE        // _NONE , _RELAY1
#define D5_IS_NONE        // _NONE , _RELAY2
#define D6_IS_NONE        // _NONE , _RELAY3, _VE_BLOCK, _VE_START_STOP
#define D7_IS_VICTRON        // _NONE , _RELAY4; _VICTRON _DROK (DROK only ESP8266)
#define D8_IS_NONE        // _NONE , _DROK
//#include "MPPT_75_15.h"   // Type of Victron controller (only relevant if D7_IS_VICTRON)
#include "J3806.h"        // Type of DC/DC controler (only relevant if D7_IS_DROK)
#define INA_IS_NONE       // _NONE , _226    when measures come from an INA226 power sensor  (Smart shunt scenario)
#define ADS_IS_NONE       // _NONE , _1115   when measures come from an ADS1115 ADC converter (Drok type)
//#include "SHUNT_10A_75mV.h" // Shunt Characteristics  (only relevant if INA_IS_226)
#define INA_VBUS_IS_FULL  // _FULL _HALF   (when high voltage schematic is used)
#define NUMBER_CELLS      8     // Number of cell in Battery
#define AH_CELLS          100   // AH of the battery
#define TYPE_IS_LIFEPO    // _LIFEPO, _LEAD, _LIION
#define POC_IS_TABLE      // _TABLE, _VICTRON   defines if POC is estmated from a table or comes from Victron
                              // 0 if no ESP32 supervisor, else 1..4

//--------------------------- WiFi Options -------------------------------------
#define WIFI_REPEAT          500      //mS for retry
#define WIFI_MAXTRIES        30

#ifdef ARDUINO_ARCH_ESP8266
#define WIFI_POWER           7.5   // from 0.5 to 21.5 full power (more current draw)
#else                              // ESP32
#define WIFI_POWER           WIFI_POWER_11dBm
#endif
/*
 Available ESP32 RF power parameters: 
 WIFI_POWER_19_5dBm // 19.5dBm (19.5dBm output, highest supply current ~150mA) 
 WIFI_POWER_19dBm // 19dBm 
 WIFI_POWER_18_5dBm // 18.5dBm 
 WIFI_POWER_17dBm // 17dBm 
 WIFI_POWER_15dBm // 15dBm 
 WIFI_POWER_13dBm // 13dBm 
 WIFI_POWER_11dBm // 11dBm 
 WIFI_POWER_8_5dBm // 8dBm 
 WIFI_POWER_7dBm // 7dBm 
 WIFI_POWER_5dBm // 5dBm 
 WIFI_POWER_2dBm // 2dBm 
 WIFI_POWER_MINUS_1dBm // -1dBm (For -1dBm output, lowest supply current ~120mA)
 Available ESP8266 RF power parameters: any value in 0.5 steps from
0    (for lowest RF power output, supply current ~ 70mA  to
20.5 (for highest RF power output, supply current ~ 80mA  
 */
#define GRACE_PAUSE          //Suspend Network processing for a grace pause, if the remote server takes too long to react, in order to keep being reactive on menues

//----------------------DO NOT EDIT until you know what you do -------------
#define SERIAL_SPEED      9600
#define LDR               A0
#define RELAY1            16    // D0  Relay or FET control 1
#define RELAY2            14    // D5  Relay or FET control 2
#define REDLED            15    // D8
#define BLULED            13    // D7 <-- Victron
#define GRNLED            12    // D6


#if defined(D7_IS_DROK) && defined(ARDUINO_ARCH_ESP32)
#error "D7_IS_DROK not possible on ESP32"
#endif
