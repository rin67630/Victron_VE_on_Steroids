// SHUNT_500A_50mV

// ***Electrical parameters***   (Adjust, if you use other shunts than R100)
#define SHUNT0   10000          // Nominal Shunt resistor value in microOhm (Channel 1 of the INA, connected to the battery)
#define AMPERE0   500             // Max expected intensity in operation
#define IFACTORB   1000000   // Battery Current correction factor 1000000 is normal,  -1000000 reverses shunt, change value to correct for wrong Amp values
 