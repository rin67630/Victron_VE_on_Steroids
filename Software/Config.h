
//----------------------- HARDWARE OPTIONS ---------------------------------
#define AO_IS_NONE        // _NONE , _DOUBLEBATTERY , _HALFBATTERY, _PANEL, _POT
#define A0_MAX       15   // if A0 is used, define the voltage of the full range measure
#define D0_IS_NONE        // _NONE , _RELAY1
#define D5_IS_NONE        // _NONE , _RELAY2
#define D6_IS_NONE        // _NONE , _RELAY3, _VE_BLOCK, _VE_START_STOP
#define D7_IS_NONE        // _NONE , _RELAY4; _VICTRON
#define OLED_IS_64x48     // _NONE , _64x48 , _128x64
#define OLED_IS_REVERSED  // _IS_NORMAL, _IS_REVERSED To turn the display 180° if required
#define INA_IS_226        // _NONE , _226
#define INA_VBUS_IS_HALF  // _FULL _HALF   (when high voltage schematic is used)
//#include "MPPT_75_15.h"
#include "SHUNT_10A_75mV.h" 
#include "LiFePo_13V_100Ah.h"

//----------------------- SOFTWARE OPTIONS ---------------------------------
#define WEATHER_IS_OWM  // _NONE , _OWM , _BME680    // (Source of the Weather Information)
#define DASHBRD_IS_NONE    // _NONE , _THINGER          // (Internet Dashboard)
#define TERM_IS_TELNET     // _NONE , _TELNET, _SERIAL , _SOFTSER // where do Menus and Reports occur: _SERIAL and D7_IS_VICTRON mutually exclusive )
#define UDP_IS_NONE        // _NONE , _SEND , _RECEIVE  // (UDP Inter-ESP Communication)
#define COM_IS_NONE        // _NONE , _MIDNIGHT         // Periodical reports to computer
#define ESP_UDP_ADDR   "192.168.188.64"                  // (IP of the receiving ESP) 
#define ESP_UDP_PORT    4200  // (Port used to send/receive Values to other ESP)
#define COM_UDP_ADDR   "192.168.188.1"                  // (IP of the receiving computer for night reports) 
#define COM_UDP_PORT    4200                            // (Port used to send/receive Values to other computer) 
#define DEVICE_NAME    "ESP_LP"                         // Name of the device used as Hostname and at Thinger.io
#define DEVICE_NUMBER   0                               // 0 if no ESP32 supervisor, else 1..4

//--------------------------- ESP SETUP -------------------------------------
#define WIFI_REPEAT          500
#define WIFI_MAXTRIES        20
#define WIFI_POWER           7.5

//----------------------DO NOT EDIT until you know what you do -------------
#define SERIAL_SPEED          19200
#define LDR        A0
#define BUTTON     D2    // GPIO04
#define STDLED     D4    // GPIO02 
#define REDLED     D8    // GPIO15 (used as TX after Serial.swap,n/a on WemosD1)
#define GRNLED     D6    // GPIO12
#define BLULED     D7    // GPIO13 (used as RX after Serial.swap)
#define RELAY1     D0    // GPIO16 Relay or FET control 1
#define RELAY2     D5    // GPIO14 Relay or FET control 2

//#define V 3   // generates a conflict with Library/Arduino15/packages/esp8266/hardware/esp8266/3.0.2/tools/sdk/include/bearssl/bearssl_rand.h:205:16: note: in expansion of macro 'V'
