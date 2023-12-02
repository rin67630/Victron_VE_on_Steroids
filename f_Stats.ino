void statsRun()
{
  //  ***Derive not measured data***
  BatW = BatI * BatV;
  LodW = BatV * LodI;
#ifdef ESTIMATE_PANEL_POWER
  PanW = BatW + LodW * 1.08;    //the Low-Power Victron MPPT converters do not measure the panel power, here estimated with 92% conversion efficiency
#endif
  PanI = PanW / PanV;
}
