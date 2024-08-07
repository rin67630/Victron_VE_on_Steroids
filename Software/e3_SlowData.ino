// This part is processed every second
void data1SRun() { 
#if defined(D7_IS_DROK)
  HandleNewData();                   //Interpret Results
  EstimateIOhm();                    //Estimate internal resistance
#endif

#if defined (D7_IS_VICTRON) || defined(D7_IS_DROK)
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

#ifdef A0_IS_SIMUL                                                    //Simulating a solar panel from LDR of a Witty.
  payload.BatI = float(map(A0Raw, 15, 1023, 0, 100 * A0_MAX)) / 150;  // Amperes Simulated Panel
  if ((BatPoC < 95 ) && (BatPoC >= 30 )) payload.BatV += (payload.BatI - payload.LodI) / (3600 * AH_CELLS) ; //integration of the current to the battery voltage
  if ((BatPoC >= 95 ) && (payload.LodI < 0 )) payload.BatV += (payload.BatI - payload.LodI) / (3600 * AH_CELLS) ;
  if ((BatPoC <= 30 ) && (payload.LodI > 0 )) payload.BatV += (payload.BatI - payload.LodI) / (3600 * AH_CELLS) ;
  if (A0Raw > 200) 
  {
    payload.PanV = 38 + float(random(100)) / 100;
  } else {
    payload.PanV = float(map(A0Raw, 15, 200, 0, 37000)) / 1000;  // Dawn below A0=200
  }
  payload.PanV -= payload.BatI * 0.8;  // Substract current load effect
  payload.BatW = payload.BatV * payload.BatI;
  payload.PanW = payload.BatW * 1.07;  // assuming 93% efficiency
  payload.PanI = payload.PanW / payload.PanV;
  payload.LodW = payload.BatV * payload.LodI;
#endif

#ifdef A0_IS_PANEL
  payload.PanV += (float(map(A0Raw, 0, 1023, 0, A0_MAX)) / 1000 - payload.PanV) / 10;  // Volt Smoothed 1seconds
#endif
#if defined (A0_IS_DOUBLEBATTERY) || defined (A0_IS_HALFBATTERY)
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

/*
#ifndef ADS_IS_NONE
#ifdef ADC_IS_ADS1115             //Sensing with much better dedicated ADC (highly recommended)
  adc.setVoltageRange_mV(ADS_Ch3_Range);
  adc.setCompareChannels(FB_Vout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_VoutRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS_Ch2_Range);
  adc.setCompareChannels(FB_Iout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_IoutRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS_Ch1_Range);
  adc.setCompareChannels(FB_Vin_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_VinRaw = adc.getResult_mV();

  if (FB_Iin_PIN == FB_Iout_PIN)
  {
    ADC_IinRaw = ADC_IoutRaw * ADC_VoutRaw/ADC_VinRaw * 1.1;  // Input current is simulated with 90% efficiency
  } else {                                                    // Input current is measured along a shunt
    adc.setVoltageRange_mV(ADS_Ch0_Range);
    adc.setCompareChannels(FB_Iin_PIN);
    adc.startSingleMeasurement();
    while (adc.isBusy()) {
      yield();
    }
    ADC_IinRaw =  adc.getResult_mV() * -10;
  }
  #endif
*/
  // *** Battery Percentage of Charge ***
#ifdef POC_IS_TABLE
  if (payload.BatI > 0.05)  // chosing the charging series values
  {
    BatPoC = float(Interpolation::ConstrainedSpline(cha, perc, 10, long(CellV * 100)));
  } else {  // chosing the discharging series values
    BatPoC = float(Interpolation::ConstrainedSpline(dis, perc, 10, long(CellV * 100)));
  }
#endif
}
