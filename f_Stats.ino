void statsRun()
{
  //  ***Derive not measured data***
  BatW = BatI * BatV;  
  LodW = BatV * LodI;
#ifdef ESTIMATE_PANEL_POWER
  PanW = BatW + LodW * 1.08;    //the Low-Power Victron MPPT converters do not measure the panel power, here estimated with 92% conversion efficiency
#endif
  PanI = PanW / PanV;



  // ***Estimate battery's internal resistance***
  /*
    if (fabs(delta_current) > 50) raw_internal_resistance = fabs(delta_voltage / delta_current); // Evaluate battery internal resistance (r = dv / di) if deltaCurrent > 50mA.
    dashboard.load_internal_resistance += (raw_internal_resistance - dashboard.load_internal_resistance) / 100;
  */

  if (delta_current > 0.05) // only if variation strong enough.
  {
    if (delta_voltage < 0) delta_voltage = 0 - delta_voltage;
    if (delta_current < 0) delta_current = 0 - delta_current;
    internal_resistance += (delta_voltage / delta_current) / 20 - internal_resistance; // ( r = dv / di) and low-pass filter 20 sec.
  }
}
