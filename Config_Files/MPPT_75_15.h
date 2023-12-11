// MPPT 75 | 15

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

/*
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
*/
#define ESTIMATE_PANEL_POWER
String Chrg_State_Desc[] = {"IDLE", "FAUL", "BULK", "ABSO", "FLOA", "STOR", "EQUA"}; // for charger state description
String Chrg_State ;
