
//----------------------- HARDWARE OPTIONS ---------------------------------
#define AO_IS_DOUBLEBATTERY        // _NONE , _DOUBLEBATTERY , _HALFBATTERY, _PANEL
#define A0_MAX       50   // if A0 is used, define the voltage of the full range measure
#define D7_IS_NONE        // _NONE , _VICTRON
#define OLED_IS_NONE      // _NONE , _48X48 , _128X48
#define OLED_IS_NORMAL    // _IS_NORMAL, _IS_REVERSED To turn the display 180° if required
#define INA_IS_226       // _NONE , _226
//#include "MPPT_75_15.h"
#include "SHUNT_10A_75mV.h" 
//#include "LiFePo_13V_100Ah.h"

//----------------------- SOFTWARE OPTIONS ---------------------------------
#define WEATHER_IS_OWM     // _NONE , _OWM              // (Source of the Weather Information)
#define DASHBRD_IS_THINGER // _NONE , _THINGER          // (Internet Dashboard)
#define TERM_IS_SERIAL     // _NONE , _TELNET, _SERIAL , _SOFTSER // where do Menus and Reports occur: _SERIAL and D7_IS_VICTRON mutually exclusive )
#define UDP_IS_RECEIVE     // _NONE , _SEND , _RECEIVE  // (UDP Inter-ESP Communication)
#define COM_IS_MIDNIGHT    // _NONE , _MIDNIGHT         // Periodical reports to computer
#define ESP_UDP_ADDR   "192.168.188.5"                  // (IP of the receiving ESP) 
#define ESP_UDP_PORT    4200  // (Port used to send/receive Values to other ESP)
#define COM_UDP_ADDR   "192.168.188.1"                  // (IP of the receiving computer for night reports) 
#define COM_UDP_PORT    4200                            // (Port used to send/receive Values to other computer) 
#define DEVICE_NAME    "Steroids"                       // Name of the device used as Hostname and at Thinger.io

//--------------------------- ESP SETUP -------------------------------------
#define WIFI_REPEAT          500
#define WIFI_MAXTRIES        20
#define WIFI_POWER           7.5

//----------------------DO NOT EDIT until you know what you do -------------
#define SERIAL_SPEED          19200
#define SCL        D1    // GPIO05 for I2C (Wire) SDA
#define SDA        D3    // GPIO04 for I2C (Wire) SCL
#define LDR        A0
#define BUTTON     D2    // GPIO04
#define STDLED     D4    // GPIO02 
#define REDLED     D8    // GPIO15 (used as TX after Serial.swap,n/a on WemosD1)
#define GRNLED     D6    // GPIO12
#define BLULED     D7    // GPIO13 (used as RX after Serial.swap)
#define RELAY1     D0    // GPIO16 Relay or FET control 1
#define RELAY2     D5    // GPIO14 Relay or FET control 2

//#define V 3   // generates a conflict with Library/Arduino15/packages/esp8266/hardware/esp8266/3.0.2/tools/sdk/include/bearssl/bearssl_rand.h:205:16: note: in expansion of macro 'V'
