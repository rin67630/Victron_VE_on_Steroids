//*** Include Own Configuration files ***
#include "Credentials.h"
#include "Config.h"

// *** libraries***  (including with <> takes by priority global files, including with "" takes local files).
#include <Wire.h>
#include <ArduinoOTA.h>
#include "time.h"  // built-in
//#include <FS.h>
#include <EEPROM.h>
#include "InterpolationLib.h"

#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#elif defined(ARDUINO_ARCH_ESP32)
#include <WiFi.h>
// #define LED_BUILTIN 2       //no built-in LED on an ESP32, using GPIO2.
//#include <WebServer.h>
#include <HTTPClient.h>
//using SDClass = fs::SDFS;
#endif


//#include <AutoConnectCredential.h>
#ifdef SCREEN_IS_64x48
#include <SSD1306.h>                              // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
SSD1306 display(0x3c, SDA, SCL, GEOMETRY_64_48);  // WEMOS OLED 64*48 shield
#endif

#ifdef SCREEN_IS_128x64
#include <SSD1306.h>                               // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
SSD1306 display(0x3c, SDA, SCL, GEOMETRY_128_64);  //OLED 128*64 soldered
#endif

#ifdef SCREEN_IS_HW364A                           // This module has SCL on D5 (GPIO12) and SDA on D6 (GPIO14) !
#define SDA 14
#define SCL 12
#define RST 16
#include <SSD1306.h>
SSD1306 display(0x3c, 14, 12); //, GEOMETRY_128_64, 16);
#endif

#ifdef SCREEN_IS_WEMOS32
#define SDA 5
#define SCL 4
#define RST 16
#include <SSD1306.h>
SSD1306 display(0x3c);
#endif

#ifdef SCREEN_IS_HELTEC
#define SDA 4
#define SCL 15
#define RST 16
#include <SSD1306.h>
SSD1306 display(0x3c);  //cut: , SDA, SCL, GEOMETRY_128_64, RST)
#endif

#ifdef SCREEN_IS_TTGO
#include <TFT_eSPI.h>
#include <SPI.h>
#include <MoToButtons.h>    // from Library (MoBaTools).
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
#define STDLED 2
#define REDLED 15
#define GRNLED 13
#define BLULED 12
#define A0 36
#define BUTTON_UP 35
#define BUTTON_DOWN 0
#define TOUCH_CS 21
#define ROTARY_ENCODER_A_PIN 25       // Rotary Encoder A
#define ROTARY_ENCODER_B_PIN 26       // Rotary Encoder B
#define ROTARY_ENCODER_BUTTON_PIN 33  // Rotary Encoder Switch
#define ROTARY_ENCODER_STEPS 4        // Rotary Encoder Delta (Steps) not an input!
#define TFT_GREY 0x5AEB               // better Grey
#define TFT_VERMILON 0xFA60           // better Orange
#endif


#ifdef D7_IS_DROK
#include <BuckPSU.h>
BuckPSU psu(Serial);
#endif

//*** Buffers ***
static char charbuff[120];  //Char buffer for many functions

#ifdef WEATHER_SOURCE_IS_OWM
#include <ArduinoJson.h>  // Libs for Webscraping
#define OPEN_WEATHER_MAP_URL "http://api.openweathermap.org/data/2.5/weather?id=" OPEN_WEATHER_MAP_LOCATION_ID "&appid=" OPEN_WEATHER_MAP_APP_ID "&units=" OPEN_WEATHER_MAP_UNITS "&lang=" OPEN_WEATHER_MAP_LANGUAGE
WiFiClient WifiClient;
#endif

#ifdef WEATHER_SOURCE_IS_BME680  // Local Temperature / Pressure / Humidity sensor
#include "Adafruit_Sensor.h"
#include "Adafruit_BME680.h"
Adafruit_BME680 bme;  ///< Create an instance of the BME280 class
#endif

#if defined(DASHBRD_IS_THINGER)
#if defined(ARDUINO_ARCH_ESP8266)
//ThingerESP8266 thing(THINGER_USERNAME, WiFi.getHostname(), DEVICE_CREDENTIALS);
ThingerESP8266 thing(THINGER_USERNAME, DEVICE_NAME, DEVICE_CREDENTIALS);
#else
//ThingerESP32 thing(THINGER_USERNAME, WiFi.getHostname(), DEVICE_CREDENTIALS);
ThingerESP32 thing(THINGER_USERNAME,  DEVICE_NAME, DEVICE_CREDENTIALS);
#endif
#endif

#if defined(DASHBRD_IS_INFLUX)   //not yet fully implemented
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

/*
  #ifndef SCREEN_IS_NONE
  #include "SSD1306Wire.h"  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
  #endif
*/
// *** Instanciations ***

// Parameters for MoToButtons
#ifdef SCREEN_IS_TTGO
#define MAX8BUTTONS  // This saves ressources if you don't need more than 8 buttons
const byte buttonPins[] = { BUTTON_UP, BUTTON_DOWN, ROTARY_ENCODER_BUTTON_PIN };
enum : byte { UP,
              DOWN,
              ROT
            };
const byte buttonCount = sizeof(buttonPins);
MoToButtons Buttons(buttonPins, buttonCount, 130, 5000);  //  130ms debounce. 5 s to distinguish short/long
#endif

//***Variables for Time***
tm* timeinfo;  //localtime returns a pointer to a tm struct static int by Second;
tm* offsettedTimeinfo;
time_t now;
time_t offsettedNow;
time_t Epoch;
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
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;
boolean TrigEvent;
unsigned int RunMillis[28];  // keep trace of consumed time

byte serialReceived;
//*** Variables for User Commands ***
byte serialPage;
byte displayPage;
byte displaySubPage;
byte wirelessPage;
bool resetCoulomb;
bool restart;
bool freezePsonUpdate;


static IPAddress ip;

#if defined(D7_IS_VICTRON)
//***Variables for Victron***
char receivedChars[buffsize];                        // an array to store the received data
char tempChars[buffsize];                            // an array to manipulate the received data
char recv_label[num_keywords][label_bytes] = { 0 };  // {0} tells the compiler to initalize it with 0.
char recv_value[num_keywords][value_bytes] = { 0 };  // That does not mean it is filled with 0's
char value[num_keywords][value_bytes] = { 0 };       // The array that holds the verified data
static byte blockindex = 0;
bool new_data = false;
bool blockend = false;
#endif
String StateKeywords[] = {"Off ", "Low", "Fau", "Bul" , "Abs", "Flo", "Str", "Equ", "   ", "   "};

#if defined (D7_IS_DROK)
//Nothing yet...
#endif

//***Parameters Battery POC
double perc[10] = {  0,  20,  30,  40,  50,  60,  70,  80,  90, 100  };
#ifdef TYPE_IS_LIION
double cha[10]  = { 324, 336, 348, 360, 372, 384, 396, 408, 420, 430 };
double dis[10]  = { 300, 324, 336, 348, 360, 372, 384, 396, 408, 420 };
#endif

#ifdef TYPE_IS_LIFEPO
double cha[10] = { 300, 315, 322, 325, 327, 330, 332, 335, 340, 365 };
double dis[10] = { 280, 300, 315, 322, 325, 327, 330, 332, 335, 340 };
#endif

#ifdef TYPE_IS_LEAD
double cha[10] = { 198, 201, 203, 205, 207, 208, 212, 218, 225, 238 };
double dis[10] = { 175, 189, 196, 198, 201, 203, 205, 207, 208, 212 };
#endif


struct payload {
  //***Operating Values from Victron/SmartShunt***
  float BatV;   // V   Battery voltage, V
  float BatV1;  // V   Battery voltage, V  (Double or half Voltage)
  float BatI;   // I   Battery current, A
  float BatW;   // W BatV*BatI

  float PanV;  // VPV Panel voltage,   V
  float PanI;  // PanW/PanV
  float PanW;  // PPV Panel power,     W

  float LodI;  // IL  Load Current     A
  float LodW;  //  BatI*BatV
  float IOhm;  //  dV / dI

  int ChSt;       // CS  Charge state (not POC), 0 to 9
  int Err;        // ERR Error code, 0 to 119
  boolean LodOn;  // LOAD ON Load output state, ON/OFF
} payload;

struct setpoints {
  //***Operating Values from Victron/SmartShunt***
  float BatV;   // V   Battery voltage, V
  float BatI;   // I   Battery current, A
  float PanV;  // VPV Panel voltage,   V
} setpoints;

struct targets {
  //***Operating Values from Victron/SmartShunt***
  float BatV;   // V   Battery voltage, V
  float BatI;   // I   Battery current, A
  float PanV;  // VPV Panel voltage,   V
} targets;

unsigned char UDPCharPayload[sizeof(payload) + 2]; //  Array of characters as image of the structure for UDP xmit/rcv
String JSONpayload;

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
float BatAh[36];    //  Ah statistics
//float BatWh[36];  //  Wh statistics
float BatVavg[36];  //  Avg Statistics
float currentInt;   //  Averaging bucket for hourly stats
long nCurrent;      //  Counter for averaging

time_t LastFloat;  //  Time of last float
time_t LastVMin;   //  Time of minimum Voltage

// ***Full Cycle Test results
float BatAHD;  // Battery total discharge capacity
float BatAHC;  // Battery total charge capacity
float BatPoC;  // Percentage of charge
float CellV;   // Cell voltage

// ***Power Integrations and mean values***
float dBatI;  // delta_voltage
float dBatV;  // delta_current

// ***Weather***
float temperature;
float humidity;
float pressure;
float wind_speed;
int wind_direction;
int cloudiness;
String weather_summary;

#ifndef INA_IS_NONE
byte devicesFound = 0;
float ina1_voltage;
float ina1_current;
float ina1_shunt;
float ina1_power;
#endif
