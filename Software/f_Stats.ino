void statsRun()
{

  /* todo Compute these values ? ***
    BatDD;          //  Deepest Discharge (Ah since last Float?)
    BatAD;          //  Average Discharge -"-
    BatLD;          //  Last Discharge    -"-
    BatCD;          //  Cumulative Discharges -"-
    BatMC;          //  Max Charge (Ah since Min Bat Voltage )
    BatAC;          //  Average Charge -"-
    BatLC;          //  Last Charge    -"-
    BatCC;          //  Cumulative Charges -"-
    BatMV;          //  Number of Deep Discharges
    BatOV;          //  Number of Overvoltages
  */

  // *** Battery hourly integration ***
  currentInt += payload.BatI;
  nCurrent ++;

  // *** Battery hourly array handling ***

  if (HourExpiring)
  {
    BatAh[Hour] = currentInt / nCurrent;
    nCurrent = 0;
    currentInt = 0;
    BatAh[25] = BatAh[Hour];   //last hour
    BatAh[26] = 0;             // today (0h->current hour)
    for  (byte n = 0; n <= Hour; n++)
    {
      BatAh[26] = BatAh[26] + BatAh[n];
    }
    BatVavg[Hour] = payload.BatV;
    BatVavg[25] = payload.BatV;
    BatVavg[26] = 0;              // today (0h->current hour)
    for  (byte n = 0; n <= Hour; n++)
    {
      BatVavg[26] = BatVavg[26] + BatVavg[n];
    }
    BatVavg[26] = BatVavg[26] / (Hour + 1) ;
  } // end hour expiring

  if (DayExpiring)
  {
    BatAh[27] = BatAh[26];
    BatAh[28] = BatAh[27];
    BatAh[29] = BatAh[28];
    BatAh[30] = BatAh[29];
    BatVavg[27] = BatVavg[26];
    BatVavg[28] = BatVavg[27];
    BatVavg[29] = BatVavg[28];
    BatVavg[30] = BatVavg[29];
  }

  // ***  Persistancy ***
  // requested to survive reset

  if (Minute % 10 == 2 && Second == 10)                      // call every 10 minutes
  {
    //Persistance

    pson persistance;
    persistance["currentInt"]    = currentInt ;
    persistance["nCurrent"]      = nCurrent;
    persistance["Ah/hour"]       = BatAh[25];
    persistance["Ah/yesterday"]  = BatAh[27];

    persistance["temperature"]   = outdoor_temperature;
    persistance["humidity"]      = outdoor_humidity;
    persistance["pressure"]      = outdoor_pressure;
    persistance["wind"]          = wind_speed;
    persistance["direction"]     = wind_direction;
    persistance["cloudiness"]    = cloudiness;
    persistance["summary"]       = weather_summary;
    persistance["last_update"]   = SecondOfDay;
    thing.set_property("persistance", persistance, true);
  }

  if (Minute % 10 == 2 && Second == 11)                      // call every 10 minutes (one second later)
  {
    pson statAh;           // 0..23=hour, 25=current.
    statAh["00h"] = BatAh[0];
    statAh["01h"] = BatAh[1];
    statAh["02h"] = BatAh[2];
    statAh["03h"] = BatAh[3];
    statAh["04h"] = BatAh[4];
    statAh["05h"] = BatAh[5];
    statAh["06h"] = BatAh[6];
    statAh["09h"] = BatAh[7];
    statAh["08h"] = BatAh[8];
    statAh["09h"] = BatAh[9];
    statAh["10h"] = BatAh[10];
    statAh["11h"] = BatAh[11];
    statAh["12h"] = BatAh[12];
    statAh["13h"] = BatAh[13];
    statAh["14h"] = BatAh[14];
    statAh["15h"] = BatAh[15];
    statAh["16h"] = BatAh[16];
    statAh["17h"] = BatAh[17];
    statAh["18h"] = BatAh[18];
    statAh["19h"] = BatAh[19];
    statAh["20h"] = BatAh[20];
    statAh["21h"] = BatAh[21];
    statAh["22h"] = BatAh[22];
    statAh["23h"] = BatAh[23];
    statAh["LastHour"] = BatAh[25];
    statAh["Yesterday"] = BatAh[27];
    statAh["Today"] = BatAh[26];
    thing.set_property("statAh", statAh);
  }

  if (Minute % 10 == 2 && Second == 11)                      // call every 10 minutes (one second later)
  {
    pson statVh;           // 0..23=hour, 25=current.
    statVh["00h"] = BatVavg[0];
    statVh["01h"] = BatVavg[1];
    statVh["02h"] = BatVavg[2];
    statVh["03h"] = BatVavg[3];
    statVh["04h"] = BatVavg[4];
    statVh["05h"] = BatVavg[5];
    statVh["06h"] = BatVavg[6];
    statVh["09h"] = BatVavg[7];
    statVh["08h"] = BatVavg[8];
    statVh["09h"] = BatVavg[9];
    statVh["10h"] = BatVavg[10];
    statVh["11h"] = BatVavg[11];
    statVh["12h"] = BatVavg[12];
    statVh["13h"] = BatVavg[13];
    statVh["14h"] = BatVavg[14];
    statVh["15h"] = BatVavg[15];
    statVh["16h"] = BatVavg[16];
    statVh["17h"] = BatVavg[17];
    statVh["18h"] = BatVavg[18];
    statVh["19h"] = BatVavg[19];
    statVh["20h"] = BatVavg[20];
    statVh["21h"] = BatVavg[21];
    statVh["22h"] = BatVavg[22];
    statVh["23h"] = BatVavg[23];
    statVh["LastHour"] = BatVavg[25];
    statVh["Yesterday"] = BatVavg[27];
    statVh["Today"] = BatAh[26];
    thing.set_property("statVh", statVh);
  }

#ifdef WEATHER_IS_OWM
  if (WiFi.status() == WL_CONNECTED)
  {
    if (Minute % 10 == 3 && Second == 32)                    // call every 10 minutes
    {
      HTTPClient http;
      http.begin(WifiClient, OPEN_WEATHER_MAP_URL);
      int httpCode2 = http.GET();
      if (httpCode2 == HTTP_CODE_OK)
      {
        JSONpayload = http.getString();
        DynamicJsonDocument doc(1024);
        auto error = deserializeJson(doc, JSONpayload.c_str());
        if ( not error)
        {
          outdoor_temperature  = doc["main"]["temp"];
          outdoor_pressure     = doc["main"]["pressure"];
          outdoor_humidity     = doc["main"]["humidity"];
          wind_speed           = doc["wind"]["speed"];
          wind_direction       = doc["wind"]["deg"];
          cloudiness           = doc["clouds"]["all"];  // % Clouds
          const char* w        = doc["weather"][0]["description"];
          weather_summary = w;
        }
        //Console1.println("\nGot weather from OWM");
      } else {
        //Console1.print("\n OWM rejected URL: "); Console1.print(OPEN_WEATHER_MAP_URL);
      }
      http.end();
    }  // End minute %10...
  }  // end Wifi connected
#endif
}
