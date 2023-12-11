void data1SRun()
{
//  ***Compute things that do not need to be done fast***
  //  ***Derive not measured data***
  payload.BatW = payload.BatI * payload.BatV;
  payload.LodW = payload.BatV * payload.LodI;
#ifdef ESTIMATE_PANEL_POWER
  payload.PanW = payload.BatW + payload.LodW * 1.08;    //the Low-Power Victron MPPT converters do not measure the panel power, here estimated with 92% conversion efficiency
#endif
  payload.PanI = payload.PanW / payload.PanV;
}
