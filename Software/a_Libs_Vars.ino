//*** Include Configuration files ***
#include "Credentials.h"
#include "Config.h"

//*** Convenience macro for Timing ***
#define runEvery(t) for (static uint16_t _lasttime; (uint16_t)((uint16_t)millis() - _lasttime) >= (t); _lasttime += (t))  // Macro for Timing

// *** Libraries and instanciations***

#include <ESP8266WiFi.h>
WiFiClient WifiClient;
#include <ESP8266HTTPClient.h>
//HTTPClient http;
#include <time.h>
#include <sntp.h>
#include <TZ.h>
#include <ArduinoOTA.h>

#ifndef INA_IS_NONE
#include <Wire.h> 
#include <INA.h>
INA_Class INA;
#endif

#ifndef UDP_IS_NONE
#include <WiFiUdp.h>
WiFiUDP UDP;
#endif

#ifdef WEATHER_IS_OWM
#include <ArduinoJson.h>  // Libs for Webscraping
#define OPEN_WEATHER_MAP_URL  "http://api.openweathermap.org/data/2.5/weather?id=" OPEN_WEATHER_MAP_LOCATION_ID "&appid=" OPEN_WEATHER_MAP_APP_ID "&units=" OPEN_WEATHER_MAP_UNITS "&lang="  OPEN_WEATHER_MAP_LANGUAGE
#endif


#if defined(DASHBRD_IS_THINGER)
#include <ThingerESP8266.h>
//#include <ThingerConsole.h>
#endif

#if defined(DASHBRD_IS_INFLUX)
#include <InfluxDBClient.h>
#include <InfluxDbCloud.h>
#endif

#if defined(TERM_IS_SOFTSER)
#include <SoftwareSerial.h>
#define Console1 SoftwareSerial
#endif

#if defined(TERM_IS_SERIAL)
#define Console1 Serial
#endif

#if defined(TERM_IS_TELNET)
#include <TelnetStream.h>
#define Console1 TelnetStream
#endif

#ifndef OLED_IS_NONE
#include "SSD1306Wire.h"  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
#endif



//***Variables for Time***
tm* timeinfo;  //localtime returns a pointer to a tm struct static int Second;
time_t Epoch;
time_t now;
byte Second;
long SecondOfDay;
long MillisMem;
long MillisMem2;
byte Minute;
byte Hour;
byte Day;
byte Month;
unsigned int Year;
byte Weekday;
char DayName[16];
char MonthName[16];
char Time[16];
char Date[16];

//*** Varables for the scheduler ***
byte slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;
unsigned int RunMillis[28];  // keep trace of consumed time

byte serialPage;
byte displayPage;
byte displaySubPage;
byte wirelessPage;

static IPAddress ip;


//*** Buffers ***
static char charbuff[120];  //Char buffer for many functions

//***Variables for Victron***
char receivedChars[buffsize];                        // an array to store the received data
char tempChars[buffsize];                            // an array to manipulate the received data
char recv_label[num_keywords][label_bytes] = { 0 };  // {0} tells the compiler to initalize it with 0.
char recv_value[num_keywords][value_bytes] = { 0 };  // That does not mean it is filled with 0's
char value[num_keywords][value_bytes] = { 0 };       // The array that holds the verified data
static byte blockindex = 0;
bool new_data = false;
bool blockend = false;



struct payload {
  //***Operating Values from Victron/SmartShunt***
  float BatV;  // V   Battery voltage, V
  float BatI;  // I   Battery current, A
  float BatW;  //  BatV*BatI

  float PanV;  // VPV Panel voltage,   V
  float PanI;  // PanW/PanV
  float PanW;  // PPV Panel power,     W

  float LodI;  // IL  Load Current     A
  float LodW;  //  LodI*BatV
  float IOhm;  //  dV / dI

  int ChSt;       // CS  Charge state, 0 to 9
  int Err;        // ERR Error code, 0 to 119
  boolean LodOn;  // LOAD ON Load output state, ON/OFF
} payload;

char UDPCharPayload[sizeof(payload)];  //  Array of characters as image of the structure for UDP xmit/rcv
String  JSONpayload;

//***Operating Values Integrated from Victron***
float TotKWh;  // H19 Yield total, kWh
float TodKWh;  // H19 Yield today, kWh
float TodMP;   // H21 397 Maximum power today, W
float YesKWh;  // H22 Yield yesterday, kWh
float YesMP;   // H23 Maximum power yesterday, W
int DaysOn;    // HSDS Day sequence number, 0 to 365



//***Operating Values integrated until reset***
float BatDD;  //  Deepest Discharge (Ah since last Float)
float BatAD;  //  Average Discharge -"-
float BatLD;  //  Last Discharge    -"-
float BatCD;  //  Cumulative Discharges -"-
float BatMC;  //  Max Charge (Ah since Min Bat Voltage )
float BatAC;  //  Average Charge -"-
float BatLC;  //  Last Charge    -"-
float BatCC;  //  Cumulative Charges -"-
float BatMV;  //  Number of Deep Discharges
float BatOV;  //  Number of Overvoltages

//*** Hourly integrated Values
float BatAh[26];    //  Wh of the current hour
float BatWh[26];    //  Ah of the current hour
float BatVavg[26];  //  Avg voltage in hour
float currentInt;   //  Averaging bucket for hourly stats
long nCurrent;      //  Counter for averaging

time_t LastFloat;  //  Time of last float
time_t LastVMin;   //  Time of minimum Voltage

// ***Full Cycle Test results
float BatAHD;  // Battery total discharge capacity
float BatAHC;  // Battery total charge capacity

// ***Power Integrations and mean values***
float dBatI;  // delta_voltage
float dBatV;  // delta_current

// ***Weather***
float outdoor_temperature;
float outdoor_humidity;
float outdoor_pressure;
float wind_speed;
int   wind_direction;
int   cloudiness;
String weather_summary;
