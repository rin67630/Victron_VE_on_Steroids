void loop()
{
    //*** Process Data from Victron VE port ***

  RunMillis[0] =  millis() - MillisMem;  
#if defined(D7_IS_VICTRON)  
  RecvWithEndMarker();               //Get Victron serial stream
  HandleNewData();                   //Interpret Results
#endif
  RunMillis[1] =  millis() - MillisMem;
  
  //*** Scheduler for other tasks ***  
  runEvery(125)                     //125mS cf Every Macro in Libs_Vars
  {
    RunMillis[2] =  millis() - MillisMem;
    getEpoch();                     // writes the Epoch (Numbers of seconds till 1.1.1970...
    getTimeData();                  // get Second, Minute...Year.
    menuRun();
    data125mSRun();
    RunMillis[3] =  millis() - MillisMem;

    // *** Processing slower tasks at 1 second pace, but shifted by 125mS slices to level load
    slice ++;                       //Launch jobs by the second in slices
    if (slice > 8) slice = 1;
    switch (slice)                  // These tasks will run every second, but at slices of 125mS
    {
      case 1:                       // Starting the timing flags
        SecondOfDay = Second + 60 * Minute + 3600 * Hour;  // 0 .. 86400
        if (Second == 0 )         // Starting a new Minute..
        {
          NewMinute = true;
          if (Minute == 0)        // Starting a new hour..
          {
            NewHour = true;
            if (Hour == 0)        // Starting a  new day..
            {
              NewDay = true;
            }
          }
        }
        if (Second == 59 )
        {
          MinuteExpiring = true;
          if (Minute == 59)       // Finishing the hour..
          {
            HourExpiring = true;
            if (Hour == 23)       // Finishing the day..
            {
              DayExpiring = true;
            }
          }
        }
        break;
      case 2:                       // Starting the data acquisition processing every second
        RunMillis[4] =  millis() - MillisMem;
        data1SRun();
        RunMillis[5] =  millis() - MillisMem;
        break;
      case 3:                       // Starting the statistics processing every second
        RunMillis[6] =  millis() - MillisMem;
        statsRun();
        RunMillis[7] =  millis() - MillisMem;
        break;
      case 4:                       // Starting the OTA Handler every second
        RunMillis[8] =  millis() - MillisMem;
        ArduinoOTA.handle();
        displayRun();               // Starting the display updates every second
        RunMillis[9] =  millis() - MillisMem;
        break;
      case 5:                       // Starting the serial outputs every second
        RunMillis[10] =  millis() - MillisMem;
        serialRun();
        RunMillis[11] =  millis() - MillisMem;
        break;
      case 7:                       // Starting the wireless communication every second
        RunMillis[12] =  millis() - MillisMem;
        if (WiFi.status() == WL_CONNECTED) wirelessRun();
        RunMillis[13] =  millis() - MillisMem;
        break;
      case 8:                     // Reinitializations and Timing report
        RunMillis[14] = max( RunMillis[14], RunMillis[1] - RunMillis[0]);   // Max Millis Victron handler
        RunMillis[15] = max( RunMillis[15], RunMillis[3] - RunMillis[2]);   // Max Millis Menu and 125mS Data
        RunMillis[16] = max( RunMillis[16], RunMillis[5] - RunMillis[4]);   // Max Millis 1S Data
        RunMillis[17] = max( RunMillis[17], RunMillis[7] - RunMillis[6]);   // Max Millis Stats
        RunMillis[18] = max( RunMillis[18], RunMillis[9] - RunMillis[8]);   // Max Millis Display
        RunMillis[19] = max( RunMillis[19], RunMillis[11] - RunMillis[10]); // Max Millis Serial
        RunMillis[20] = max( RunMillis[20], RunMillis[13] - RunMillis[12]); // Max Millis WiFi
        if (MinuteExpiring)
        {
          // Minutely
          if (HourExpiring)
          {
            //Hourly
            if (DayExpiring)
            {
              //Daily
            }
          }
        }
        NewMinute = false;
        MinuteExpiring = false;
        NewHour = false;
        HourExpiring = false;
        NewDay = false;
        DayExpiring = false;
        break;
    } // end Switch slice
  } // end Every 125mS
} // End Loop
