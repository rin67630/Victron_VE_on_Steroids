void data1SRun() {
#ifdef D7_IS_VICTRON
  {
    //  ***Compute things that do not need to be done fast***
    //  ***Derive not measured data***
    payload.BatW = payload.BatI * payload.BatV;
    payload.LodW = payload.BatV * payload.LodI;
#ifdef ESTIMATE_PANEL_POWER
    payload.PanW = payload.BatW + payload.LodW * 1.08;  //the Low-Power Victron MPPT converters do not measure the panel power, here estimated with 92% conversion efficiency
    if (payload.PanW < 0) payload.PanW = 0;
#endif
    payload.PanI = payload.PanW / payload.PanV;
  }
#endif

  // === ( Measures)  ===

#ifndef A0_IS_NONE  // Smothed A0 Measure
  pinMode(A0, INPUT);
  // Performing 3 reads to get a reliable reading.
  int A0Raw = analogRead(A0);  // 1st read  0...1V = 0 ..1023
  delay(3);
  A0Raw += analogRead(A0);  // 2nd read
  delay(3);
  A0Raw += analogRead(A0);  // 3rd read
  A0Raw = A0Raw / 3;
#endif

#ifdef A0_IS_LUX    //Simulating a solar panel from LDR of a Witty.
  payload.BatI = float(map(A0Raw,15, 1023, 0, 100 * A0_MAX)) / 300;  // Amperes Simulated Panel
  payload.BatV = 12.9 + payload.BatI / 12;                           // Adding current load effect
  if (A0Raw > 100) 
  {
    payload.PanV = 32;
  } else {
    payload.PanV = float(map(A0Raw, 15, 100, 0, 32000)) / 1000;  // Dawn below A0=100
  }
  payload.PanV -= payload.BatI ;  // Substract current load effect
  payload.BatW = payload.BatV * payload.BatI;
  payload.PanW = payload.BatW * 1.07;  // assuming 93% efficiency
  payload.PanI = payload.PanW / payload.PanV;
  EstimateIOhm();
#endif

#ifdef A0_IS_PANEL
  payload.PanV += (float(map(A0Raw, 0, 1023, 0, A0_MAX)) / 1000 - payload.PanV) / 10;  // Volt Smoothed 1seconds
#else
  payload.BatV1 += (float(map(A0Raw, 0, 1023, 0, A0_MAX)) / 1000 - payload.BatV1) / 10;  // Volt Smoothed 1seconds
#endif


  //=== ( Measure with INA226) ===
#ifndef INA_IS_NONE
  // Battery measurements from INA226
  float v = ina1_voltage;
  float w = ina1_current;
  ina1_voltage = INA.getBusMilliVolts(0);
#if defined(INA_VBUS_IS_HALF)
  ina1_voltage = ina1_voltage * 2;
#endif
  ina1_shunt = INA.getShuntMicroVolts(0);
  ina1_current = INA.getBusMicroAmps(0);
  dBatV = ina1_voltage - v;                                      // mV
  dBatV = (ina1_current - w) / 1000;                             // mA
  payload.BatV += (ina1_voltage / 1000 - payload.BatV) / 3;      // Volt Smoothed 0.3seconds
  payload.BatI += (ina1_current / IFACTORB - payload.BatI) / 3;  // Ampere Smoothed 0.3seconds, set divisor negative to reverse current if required
  payload.BatW = payload.BatV * payload.BatI;
  EstimateIOhm();
#endif
}
