// *** Libraries ***

#include <ESP8266WiFi.h>
#include <time.h>
#include <TelnetStream.h>
#include <sntp.h>
#include <TZ.h>
#include <ArduinoOTA.h>
#include <TZ.h>

//*** Configuration ***

#include "Credentials.h"
#include "Config.h"

//***Variables for Time***
tm*        timeinfo;                 //localtime returns a pointer to a tm struct static int Second;
time_t     Epoch;
time_t     now;
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
byte    slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;
unsigned int RunMillis[28];  // keep trace of consumed time 

byte    serialPage;
byte    displayPage;
byte    wirelessPage;

static IPAddress ip;


//*** Buffers ***
static char charbuff[120];    //Char buffer for many functions

//***Variables for Victron***
char receivedChars[buffsize];                       // an array to store the received data
char tempChars[buffsize];                           // an array to manipulate the received data
char recv_label[num_keywords][label_bytes]  = {0};  // {0} tells the compiler to initalize it with 0.
char recv_value[num_keywords][value_bytes]  = {0};  // That does not mean it is filled with 0's
char value[num_keywords][value_bytes]       = {0};  // The array that holds the verified data
static byte blockindex = 0;
bool new_data = false;
bool blockend = false;

String Chrg_State_Desc[] = {"IDLE", "FAUL", "BULK", "ABSO", "FLOA", "STOR", "EQUA"}; // for charger state description 
String Chrg_State ;






//***Operating Values from Victron***
float BatV;           // V   Battery voltage, V
float BatI;           // I   Battery current, A
float PanV;           // VPV Panel voltage,   V
float PanW;           // PPV Panel power,     W
int   ChSt;           // CS  Charge state, 0 to 9
int   Err;            // ERR Error code, 0 to 119
boolean LodOn ;       // LOAD ON Load output state, ON/OFF
float LodI ;          // IL  Load Current    ,A
float TotKWh ;        // H19 Yield total, kWh
float TodKWh ;        // H19 Yield today, kWh
float TodMP ;         // H21 397 Maximum power today, W
float YesKWh ;        // H22 Yield yesterday, kWh
float YesMP ;         // H23 Maximum power yesterday, W
int   DaysOn ;        // HSDS Day sequence number, 0 to 365

//***Operating Values derived***
float BatW ;          //  BatV*BatI
float PanI ;          //  PanW/PanV
float LodW ;          //  LodI*BatV
float IOhm ;          //  dV / dI

// ***Power Integrations and mean values***
float dBatI ;         // delta_voltage
float dBatV ;         // delta_current

float BatWh;          // Wh of the current hour
float BatAh;          // Ah of the current hour
float Vavg;           // Avg voltage in hour



//*** Convenience macro for Timing ***
#define runEvery(t) for (static uint16_t _lasttime;(uint16_t)((uint16_t)millis() - _lasttime) >= (t);_lasttime += (t)) // Macro for Timing


//*** Instantiate Classes ***
WiFiClient WifiClient;
