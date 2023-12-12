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
  UDP.begin(ESP_UDP_PORT); 
  Serial.printf("\nOpening UDP port: %u", ESP_UDP_PORT);
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
  Wire.begin(SDA, SCL);
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
    out["PanV"]            = payload.PanV ;
    out["PanI"]            = payload.PanI ;
    out["PanW"]            = payload.PanW ;
    out["BatV"]            = payload.BatV ;
    out["BatI"]            = payload.BatI ;
    out["BatW"]            = payload.BatW ;
    out["LodI"]            = payload.LodI ;
    out["LodW"]            = payload.LodW ;
    out["Iohm"]             = payload.IOhm ;
    out["ChSt"] = payload.ChSt;
  };

  thing["weather"] >> [](pson & out)
  {
    out["temperature"] = outdoor_temperature;
    out["humidity"]    = outdoor_humidity;
    out["pressure"]    = outdoor_pressure;
    out["wind"]        = wind_speed;
    out["direction"]   = wind_direction;
    out["cloudiness"]  = cloudiness;    
    out["summary"]     = weather_summary;
  };

  thing["DAY"] >> [](pson & out)
  {
    out["BAhDay"] = BatAh[27];
    out["B00Ah"] = BatAh[0];
    out["B01Ah"] = BatAh[1];
    out["B02Ah"] = BatAh[2];
    out["B03Ah"] = BatAh[3];
    out["B04Ah"] = BatAh[4];
    out["B05Ah"] = BatAh[5];
    out["B06Ah"] = BatAh[6];
    out["B07Ah"] = BatAh[7];
    out["B08Ah"] = BatAh[8];
    out["B09Ah"] = BatAh[9];
    out["B10Ah"] = BatAh[10];
    out["B11Ah"] = BatAh[11];
    out["B12Ah"] = BatAh[12];
    out["B13Ah"] = BatAh[13];
    out["B14Ah"] = BatAh[14];
    out["B15Ah"] = BatAh[15];
    out["B16Ah"] = BatAh[16];
    out["B17Ah"] = BatAh[17];
    out["B18Ah"] = BatAh[18];
    out["B19Ah"] = BatAh[19];
    out["B20Ah"] = BatAh[20];
    out["B21Ah"] = BatAh[21];
    out["B22Ah"] = BatAh[22];
    out["B23Ah"] = BatAh[23];
    
    out["BVDay"] = BatVavg[27];
    out["B00V"] = BatVavg[0];
    out["B01V"] = BatVavg[1];
    out["B02V"] = BatVavg[2];
    out["B03V"] = BatVavg[3];
    out["B04V"] = BatVavg[4];
    out["B05V"] = BatVavg[5];
    out["B06V"] = BatVavg[6];
    out["B07V"] = BatVavg[7];
    out["B08V"] = BatVavg[8];
    out["B09V"] = BatVavg[9];
    out["B10V"] = BatVavg[10];
    out["B11V"] = BatVavg[11];
    out["B12V"] = BatVavg[12];
    out["B13V"] = BatVavg[13];
    out["B14V"] = BatVavg[14];
    out["B15V"] = BatVavg[15];
    out["B16V"] = BatVavg[16];
    out["B17V"] = BatVavg[17];
    out["B18V"] = BatVavg[18];
    out["B19V"] = BatVavg[19];
    out["B20V"] = BatVavg[20];
    out["B21V"] = BatVavg[21];
    out["B22V"] = BatVavg[22];
    out["B23V"] = BatVavg[23];
  };

  thing["HOUR"] >> [](pson & out)
  {
    out["Batv"]  = payload.BatV;
    out["BatI"]  = payload.BatI;
    out["Wbat"]  = payload.BatW;
    out["PanI"]  = payload.PanI ;
    out["Vpan"]  = payload.PanV ;
    out["Wpan"]  = payload.PanW;
    out["Ohm"]   = payload.IOhm;
    out["BatV"] = BatAh[25];
    out["percent_charged"] = payload.ChSt;

    out["temperature"]  = outdoor_temperature;
    out["humidity"]     = outdoor_humidity;
    out["pressure"]     = outdoor_pressure;
    out["wind"]         = wind_speed;
    out["direction"]    = wind_direction;
    out["summary"]      = weather_summary;
  };

  thing["MIN"] >> [](pson & out)
  {
    out["BatI"]      = payload.BatI ;  
    out["BatV"]      = payload.BatV ;  
    out["BatW"]      = payload.BatW ;  
    out["PanI"]      = payload.PanI ;
    out["PanV"]      = payload.PanV ;
    out["PanW"]      = payload.PanW ;
    out["LodI"]      = payload.LodI ;
    out["LodW"]      = payload.LodW ;
    out["BatAh"]      = BatAh[25];
  };

  //Communication with Thinger.io
  thing.handle();
  delay(1000); // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
#ifdef DASHBRD_IS_THINGER
  thing.get_property("persistance", persistance);
  currentInt          = persistance["currentInt"];
  nCurrent            = persistance["nCurrent"];
  BatAh[25]           = persistance["Ah/hour"];
  BatAh[27]           = persistance["Ah/yesterday"];
#endif
  outdoor_temperature = persistance["temperature"];
  outdoor_humidity    = persistance["humidity"];
  outdoor_pressure    = persistance["pressure"];
  wind_speed          = persistance["wind"];
  wind_direction      = persistance["direction"];

  pson statAh;
  thing.get_property("statAh", statAh);  // 0..23=hour, 25=payload.PanI, 26=statAh 24h, 27= BatAhDay, 28=BatAhNight, 29=BatAh22-24
  BatAh[0]  = statAh["00h"];
  BatAh[1]  = statAh["01h"];
  BatAh[2]  = statAh["02h"];
  BatAh[3]  = statAh["03h"];
  BatAh[4]  = statAh["04h"];
  BatAh[5]  = statAh["05h"];
  BatAh[6]  = statAh["06h"];
  BatAh[7]  = statAh["09h"];
  BatAh[8]  = statAh["08h"];
  BatAh[9]  = statAh["09h"];
  BatAh[10] = statAh["10h"];
  BatAh[11] = statAh["11h"];
  BatAh[12] = statAh["12h"];
  BatAh[13] = statAh["13h"];
  BatAh[14] = statAh["14h"];
  BatAh[15] = statAh["15h"];
  BatAh[16] = statAh["16h"];
  BatAh[17] = statAh["17h"];
  BatAh[18] = statAh["18h"];
  BatAh[19] = statAh["19h"];
  BatAh[20] = statAh["20h"];
  BatAh[21] = statAh["21h"];
  BatAh[22] = statAh["22h"];
  BatAh[23] = statAh["23h"];
  BatAh[25] = statAh["LastHour"];
  BatAh[27] = statAh["Yesterday"];
  BatAh[26] = statAh["Today"];

    pson statVh;
  thing.get_property("statVh", statVh);  // 0..23=hour, 25=payload.PanI, 26=statVh 24h, 27= BatAhDay, 28=BatAhNight, 29=BatAh22-24
  BatVavg[0]  = statVh["00h"];
  BatVavg[1]  = statVh["01h"];
  BatVavg[2]  = statVh["02h"];
  BatVavg[3]  = statVh["03h"];
  BatVavg[4]  = statVh["04h"];
  BatVavg[5]  = statVh["05h"];
  BatVavg[6]  = statVh["06h"];
  BatVavg[7]  = statVh["09h"];
  BatVavg[8]  = statVh["08h"];
  BatVavg[9]  = statVh["09h"];
  BatVavg[10] = statVh["10h"];
  BatVavg[11] = statVh["11h"];
  BatVavg[12] = statVh["12h"];
  BatVavg[13] = statVh["13h"];
  BatVavg[14] = statVh["14h"];
  BatVavg[15] = statVh["15h"];
  BatVavg[16] = statVh["16h"];
  BatVavg[17] = statVh["17h"];
  BatVavg[18] = statVh["18h"];
  BatVavg[19] = statVh["19h"];
  BatVavg[20] = statVh["20h"];
  BatVavg[21] = statVh["21h"];
  BatVavg[22] = statVh["22h"];
  BatVavg[23] = statVh["23h"];
  BatVavg[25] = statVh["LastHour"];
  BatVavg[27] = statVh["Yesterday"];
  BatVavg[26] = statVh["Today"];

#endif // defined (DASHBRD_IS_THINGER)

  // *** Defaults to start with ***
  wirelessPage = ' ';
  serialPage = ' ';
  displayPage = ' ';
  digitalWrite(GRNLED, false);

} //End Setup
