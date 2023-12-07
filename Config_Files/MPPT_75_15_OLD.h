// MPPT 75 | 15 old FW
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
