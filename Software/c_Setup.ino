void setup()
{
  delay(3000); // Wait for serial monitor to be started
  Serial.begin(SERIAL_SPEED);
  Serial.setRxBufferSize(1024);
  Serial.printf("\n\n\nVictron Logger at work,\nSerial @ %u Baud\n", SERIAL_SPEED);
  pinMode(STDLED, OUTPUT);   // Blue LED on the ESP
  // Witty Color LEDs
  pinMode(REDLED, INPUT);    // Tx0 after Serial.Swap()
  pinMode(GRNLED, OUTPUT);   // For debugging
  pinMode(BLULED, INPUT);    // Rx0 after Serial.Swap()

  // Networking and Time
  getWiFi();
  //WiFi.printDiag(Serial);
  Serial.printf("MAC address: %s , \nHostname: %s", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
  digitalWrite(STDLED, true);

  getNTP();
  delay(3000);

#ifndef UDP_IS_NONE  
  UDP.begin(UDP_PORT);   // Opening UDP port
  Serial.printf("\n Opening UDP port: %u", UDP_PORT);
#endif

  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  Serial.println("\nGot Epoch");
  getTimeData();         // breaks down the Epoch into discrete values.
  sprintf(charbuff, "Now is %02d:%02d:%02d, Date is %s, %02d %s %04d", Hour, Minute, Second, DayName, Day, MonthName, Year);
  Serial.println(charbuff);

  otaInit();
  Serial.println("OTA ready");
  delay(500);

#if defined (TERM_IS_SERIAL)
  Serial.println("Menu ready!");
#endif

#if defined (TERM_IS_SOFTSER)
  SwSerial.begin(SERIAL_SPEED);
  Serial.println("Menu ready on SoftSerial");
#endif

#if defined (TERM_IS_TELNET)
  TelnetStream.begin();
  Serial.println("Menu ready on Telnet");
  Serial.flush();
  delay(500);
#endif

#if defined (D7_IS_VICTRON)
  Serial.swap();
#endif

#ifndef OLED_IS_NONE
  // Initialising the UI will init the display too.
  display.init();
  delay(1000);
#ifdef OLED_IS_REVERSED
  display.flipScreenVertically();
#endif
  display.clear();
  delay(50);
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 0,  DEVICE_NAME);
  display.drawString(0, 12, "Try connect..");
  display.display();
#endif

#if defined INA_IS_226
  // INA 226 Panel Sensor
  INA.begin( AMPERE0 , SHUNT0, 0);      // Define max Ampere, Shunt value, Address
  INA.setBusConversion(100);            // Maximum conversion time 100ms
  INA.setShuntConversion(100);          // Maximum conversion time 100ms
  INA.setAveraging(32);                  // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH); // Bus/shunt measured continuously
  //  INA.alertOnPowerOverLimit(true;450000); //Set alert when power over 45W.
#endif


#if defined (DASHBRD_IS_THINGER)
  // *** Thinger configuration ***
  // definition of structures for transmission
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  // resource output example (i.e. reading a sensor value) https://docs.thinger.io/coding#define-output-resources
  // https://docs.thinger.io/coding#read-multiple-data
  // it is a bit confusing, but Thinger code placed in setup will be executed when required by the payload.


  // Device
  thing["menu"] << [](pson & in) {
    displayPage    = in["displayPage"];
    displaySubPage = in["displaySubPage"];
    serialPage     = in["serialPage"];
    wirelessPage   = in["wirelessPage"];
  };

  thing["measure"] >> [](pson & out)
  {
    out["Vpan"]            = payload.PanV ;
    out["PanI"]            = payload.PanI ;
    out["Wpan"]            = payload.PanW ;
    out["Batv"]            = payload.BatV ;
    out["BatI"]            = payload.BatI ;
    out["Wbat"]            = payload.BatW ;
    out["Iaux"]            = payload.LodI ;
    out["Waux"]            = payload.LodW ;
    out["ohm"]             = payload.IOhm ;
    out["percent_charged"] = payload.BatC;
  };

  thing["weather"] >> [](pson & out)
  {
    out["temperature"] = outdoor_temperature;
    out["humidity"]    = outdoor_humidity;
    out["pressure"]    = outdoor_pressure;
    out["wind"]        = wind_speed;
    out["direction"]   = wind_direction;
    out["summary"]     = weather_summary;
  };

  thing["DAY"] >> [](pson & out)
  {
    out["BAhDay"] = BatAh[27];
    out["BV@0h"]  = voltageAt0H;
    out["BVDiff"] = voltageDelta;
    out["B00h"] = BatAh[0];
    out["B01h"] = BatAh[1];
    out["B02h"] = BatAh[2];
    out["B03h"] = BatAh[3];
    out["B04h"] = BatAh[4];
    out["B05h"] = BatAh[5];
    out["B06h"] = BatAh[6];
    out["B07h"] = BatAh[7];
    out["B08h"] = BatAh[8];
    out["B09h"] = BatAh[9];
    out["B10h"] = BatAh[10];
    out["B11h"] = BatAh[11];
    out["B12h"] = BatAh[12];
    out["B13h"] = BatAh[13];
    out["B14h"] = BatAh[14];
    out["B15h"] = BatAh[15];
    out["B16h"] = BatAh[16];
    out["B17h"] = BatAh[17];
    out["B18h"] = BatAh[18];
    out["B19h"] = BatAh[19];
    out["B20h"] = BatAh[20];
    out["B21h"] = BatAh[21];
    out["B22h"] = BatAh[22];
    out["B23h"] = BatAh[23];
  };

  thing["HOUR"] >> [](pson & out)
  {
    out["Batv"]  = payload.Batv;
    out["BatI"]  = payload.BatI;
    out["Wbat"]  = payload.Wbat;
    out["PanI"]  = payload.PanI ;
    out["Vpan"]  = payload.Vpan ;
    out["Wpan"]  = payload.Wpan ;
    out["Ohm"]   = payload.internal_resistance ;
    out["BatAh"] = BatAh[25];
    out["percent_charged"] = payload.percent_charged;

    out["temperature"]  = outdoor_temperature;
    out["humidity"]     = outdoor_humidity;
    out["pressure"]     = outdoor_pressure;
    out["wind"]         = wind_speed;
    out["direction"]    = wind_direction;
    out["summary"]      = weather_summary;
  };

  thing["MIN"] >> [](pson & out)
  {
    out["BatI"]      = payload_10min.BatI / 600 ;  // Ø of last 10 Minutes
    out["Batv"]      = payload_10min.Batv / 600 ;  // Ø of last 10 Minutes
    out["Wbat"]      = payload_10min.Wbat / 600 ;  // Ø of last 10 Minutes
    out["PanI"]      = payload.PanI ;
    out["Vpan"]      = payload.Panv ;
    out["Wpan"]      = payload.PanW ;
    out["Iaux"]      = payload.LodI ;
    out["Waux"]      = payload.LodW ;
    out["BatAh"]      = BatAh[25];
  };

  //Communication with Thinger.io
  thing.handle();
  delay(1000); // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
#if (defined BAT_SOURCE_IS_INA) || (defined BAT_SOURCE_IS_UDP)
  thing.get_property("persistance", persistance);
  currentInt          = persistance["currentInt"];
  nCurrent            = persistance["nCurrent"];
  BatAh[25]           = persistance["Ah/hour"];
  BatAh[27]           = persistance["Ah/yesterday"];
  voltageDelta        = persistance["voltageDelta"];
  voltageAt0H         = persistance["voltageAt0H"];
#endif
  outdoor_temperature = persistance["temperature"];
  outdoor_humidity    = persistance["humidity"];
  outdoor_pressure    = persistance["pressure"];
  wind_speed          = persistance["wind"];
  wind_direction      = persistance["direction"];

  pson BATmAh;
  thing.get_property("BAT", BATmAh);  // 0..23=hour, 25=payload.PanI, 26=BATmAh 24h, 27= BatAhDay, 28=BatAhNight, 29=BatAh22-24
  BatAh[0]  = BATmAh["00h"];
  BatAh[1]  = BATmAh["01h"];
  BatAh[2]  = BATmAh["02h"];
  BatAh[3]  = BATmAh["03h"];
  BatAh[4]  = BATmAh["04h"];
  BatAh[5]  = BATmAh["05h"];
  BatAh[6]  = BATmAh["06h"];
  BatAh[7]  = BATmAh["09h"];
  BatAh[8]  = BATmAh["08h"];
  BatAh[9]  = BATmAh["09h"];
  BatAh[10] = BATmAh["10h"];
  BatAh[11] = BATmAh["11h"];
  BatAh[12] = BATmAh["12h"];
  BatAh[13] = BATmAh["13h"];
  BatAh[14] = BATmAh["14h"];
  BatAh[15] = BATmAh["15h"];
  BatAh[16] = BATmAh["16h"];
  BatAh[17] = BATmAh["17h"];
  BatAh[18] = BATmAh["18h"];
  BatAh[19] = BATmAh["19h"];
  BatAh[20] = BATmAh["20h"];
  BatAh[21] = BATmAh["21h"];
  BatAh[22] = BATmAh["22h"];
  BatAh[23] = BATmAh["23h"];
  BatAh[25] = BATmAh["LastHour"];
  BatAh[27] = BATmAh["Yesterday"];
  BatAh[26] = BATmAh["Today"];

#endif // defined (DASHBRD_IS_THINGER)

  // *** Defaults to start with ***
  wirelessPage = ' ';
  serialPage = ' ';
  displayPage = ' ';
  digitalWrite(GRNLED, false);

} //End Setup
