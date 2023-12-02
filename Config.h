
//--------------------------- ESP SETUP -------------------------------------

#define WIFI_REPEAT          500
#define WIFI_MAXTRIES        20

#define SERIAL_SPEED          19200
#define HOST_NAME            "Victron_Telnet"

#define SCL        D1   // D1 GPIO05 for I2C (Wire) System Clock
#define SDA        D2   // D2 GPIO04 for I2C (Wire) System Data
#define LDR        A0
#define BUTTON     D2   // GPIO04
#define STDLED     D4   // GPIO02 (& Console2 TX)
#define REDLED     D8   // GPIO15
#define GRNLED     D6   // GPIO12
#define BLULED     D7   // GPIO13 

//--------------------------- VICTRON SETUP -------------------------------------

/*  ***Protocol for a MPPT Solar converter ***
PID 0xA043 -- Product ID for BlueSolar 
FW 119 -- Firmware version of controller, v1.19
SER# HQXXXXXXXXX -- Serial number
V 13790 -- Battery voltage, mV
I -10 -- Battery current, mA
VPV 15950 -- Panel voltage, mV
PPV 0 -- Panel power, W
CS 5 -- Charge state, 0 to 9
ERR 0 -- Error code, 0 to 119
LOAD ON -- Load output state, ON/OFF
IL 0 -- Load current, mA
H19 0 -- Yield total, kWh
H20 0 -- Yield today, kWh
H21 397 -- Maximum power today, W
H22 0 -- Yield yesterday, kWh
H23 0 -- Maximum power yesterday, W
HSDS 0 -- Day sequence number, 0 to 365
Checksum l:A0002000148 -- Message checksum
 */

#define MPPT_75_15    // Define used Victron Device 

// Supported:
// "MPPT 75  | 10"
// "MPPT 75  | 15" tested with FW 1.56
// "MPPT 100 | 20" tested with FW 1.5 / 1.56
// "MPPT 100 | 30" tested with FW 1.59

//--------------------------- SETUP -------------------------------------

// MPPT 75 | 10
#ifdef MPPT_75_10

  const byte buffsize = 32;
  const byte value_bytes = 33;
  const byte label_bytes = 9;
  const byte num_keywords = 18;

  char keywords[num_keywords][label_bytes] = 
  {
  "PID",
  "FW",
  "SER#",
  "V",
  "I",
  "VPV",
  "PPV",
  "CS",
  "ERR",
  "LOAD",
  "IL",
  "H19",
  "H20",
  "H21",
  "H22",
  "H23",
  "HSDS",
  "Checksum"
  };
  #define PID 0
  #define FW 1
  #define SER 2 // Offically SER# but # does not play that well as macro
  #define V 3     // ScV
  #define I 4     // ScI
  #define VPV 5   // PVV
  #define PPV 6   // PVI = PVV / VPV
  #define CS 7    // ScS
  #define ERR 8   // ScERR
  #define LOAD 9  // SLs
  #define IL 10   // SLI
  #define H19 11
  #define H20 12
  #define H21 13
  #define H22 14
  #define H23 15
  #define HSDS 16
  #define CHECKSUM 17
  
#define ESTIMATE_PANEL_POWER

#endif
//----------------------------------------------------------------

// MPPT 75 | 15 old FW
#ifdef MPPT_75_15_OLD
  const byte buffsize = 32;
  const byte value_bytes = 33;
  const byte label_bytes = 9;
  const byte num_keywords = 19;

  char keywords[num_keywords][label_bytes] = 
  {
  "PID",
  "FW",
  "SER#",
  "V",
  "I",
  "VPV",
  "PPV",
  "CS",
  "MPPT",
  "ERR",
  "LOAD",
  "IL",
  "H19",
  "H20",
  "H21",
  "H22",
  "H23",
  "HSDS",
  "Checksum"
  };
  #define PID 0
  #define FW 1
  #define SER 2 // Offically SER# but # does not play that well as macro
  #define V 3     // ScV
  #define I 4     // ScI
  #define VPV 5   // PVV
  #define PPV 6   // PVI = PVV / VPV
  #define CS 7    // ScS
  #define MPPT 8
  #define ERR 9   // ScERR
  #define LOAD 10  // SLs
  #define IL 11   // SLI
  #define H19 12
  #define H20 13
  #define H21 14
  #define H22 15
  #define H23 16
  #define HSDS 17
  #define CHECKSUM 18
#define ESTIMATE_PANEL_POWER

#endif

// MPPT 75 | 15 new
#ifdef MPPT_75_15
  const byte buffsize = 32;
  const byte value_bytes = 33;
  const byte label_bytes = 9;
  const byte num_keywords = 20;

  char keywords[num_keywords][label_bytes] = 
  {
  "PID",
  "FW",
  "SER#",
  "V",
  "I",
  "VPV",
  "PPV",
  "CS",
  "MPPT",
  "OR",
  "ERR",
  "LOAD",
  "IL",
  "H19",
  "H20",
  "H21",
  "H22",
  "H23",
  "HSDS",
  "Checksum"
  };
  #define PID 0
  #define FW 1
  #define SER 2
  #define V 3
  #define I 4
  #define VPV 5
  #define PPV 6
  #define MPPT 7
  #define OR 8
  #define CS 9
  #define ERR 10
  #define LOAD 11
  #define IL 12
  #define H19 13
  #define H20 14
  #define H21 15
  #define H22 16
  #define H23 17
  #define HSDS 18
  #define CHECKSUM 19
#define ESTIMATE_PANEL_POWER

#endif

//----------------------------------------------------------------

// MPPT 100 | 20
#ifdef MPPT_100_20

  const byte buffsize = 32;
  const byte value_bytes = 33;
  const byte label_bytes = 9;
  const byte num_keywords = 20;

  char keywords[num_keywords][label_bytes] = 
  {
  "PID",
  "FW",
  "SER#",
  "V",
  "I",
  "VPV",
  "PPV",
  "CS",
  "MPPT",
  "OR",
  "ERR",
  "LOAD",
  "IL",
  "H19",
  "H20",
  "H21",
  "H22",
  "H23",
  "HSDS",
  "Checksum"
  };
  #define PID 0
  #define FW 1
  #define SER 2
  #define V 3
  #define I 4
  #define VPV 5
  #define PPV 6
  #define MPPT 7
  #define OR 8
  #define CS 9
  #define ERR 10
  #define LOAD 11
  #define IL 12
  #define H19 13
  #define H20 14
  #define H21 15
  #define H22 16
  #define H23 17
  #define HSDS 18
  #define CHECKSUM 19
#endif


//----------------------------------------------------------------

// MPPT 100 | 30
#ifdef MPPT_100_30

  const byte buffsize = 32;
  const byte value_bytes = 33;
  const byte label_bytes = 9;
  const byte num_keywords = 20;

  char keywords[num_keywords][label_bytes] = 
  {
  "PID",
  "FW",
  "SER#",
  "V",
  "I",
  "VPV",
  "PPV",
  "CS",
  "MPPT",
  "OR",
  "ERR",
  "LOAD",
  "IL",
  "H19",
  "H20",
  "H21",
  "H22",
  "H23",
  "HSDS",
  "Checksum"
  };
  #define PID 0
  #define FW 1
  #define SER 2
  #define V 3
  #define I 4
  #define VPV 5
  #define PPV 6
  #define MPPT 7
  #define OR 8
  #define CS 9
  #define ERR 10
  #define LOAD 11
  #define IL 12
  #define H19 13
  #define H20 14
  #define H21 15
  #define H22 16
  #define H23 17
  #define HSDS 18
  #define CHECKSUM 19
#endif
