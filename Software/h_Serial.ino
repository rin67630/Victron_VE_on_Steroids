void serialRun()
{
  switch (serialPage)
  {
    case 'A':  // Print A0
      static int i = 0;
      char timeStr[20];
      sprintf(timeStr, "%02d-%02d-%02d %02d:%02d:%02d", Year, Month, Day, Hour, Minute, Second);

      Console1.print(i++);
      Console1.print(" ");
      Console1.print(timeStr);
      Console1.print(" A0: ");
      Console1.println(analogRead(A0));
      break;

    case 'V' : //Print Values
      Console1.printf("BatV:%3.2f BatI:%2.3f BatW: %3.2f PanV: %3.2f PanW: %3.2f, LoadI %3.2f, LoadW %3.2f, IOhm %3.4f\n", payload.BatV, payload.BatI, payload.BatW, payload.PanV, payload.PanW, payload.LodI, payload.LodW, payload.IOhm);
      break;

    case 'D' : //Debug report
      Console1.printf("BatV:%3.2f BatI:%2.3f DelV: %3.4f DelI: %3.4f, IOhm %3.4f\n", payload.BatV, payload.BatI, dBatV, dBatI, payload.IOhm);
      break;

    case 'I' : //Print Victron VE Identifiers list
      for (int i = 0; i < num_keywords; i++)
      {
        for (int i = 0; i < num_keywords; i++)
        {
          Console1.print(keywords[i]);
          Console1.print(",");
          Console1.println(value[i]);
        }
      }
      break;

    case 'J':   // Job Duration Report for debuggging
      Console1.printf("\nJob Durations(mS) Current - Max\nVict:%03i - %03i \nFast:%03i - %03i\nSlow:%03i - %03i\nStat:%03i - %03i\nDisp:%03i - %03i\nSeri:%03i - %03i\nWifi:%03i - %03i\n",
                      RunMillis[1] - RunMillis[0], RunMillis[14], RunMillis[3] - RunMillis[2], RunMillis[15], RunMillis[5] - RunMillis[4], RunMillis[16], RunMillis[7] - RunMillis[6], RunMillis[17],
                      RunMillis[9] - RunMillis[8], RunMillis[18], RunMillis[11] - RunMillis[10], RunMillis[19], RunMillis[13] - RunMillis[12], RunMillis[20]);
      // serialPage = 0; // disabled One shot reset serial page.
      break;
    case 'W':   // Weather Plot
      Console1.printf("Temp:%+05.1f Hum:%.1f Press:%.0f WindSpeed:%.1f Direction:%u\n", outdoor_temperature, outdoor_humidity, outdoor_pressure, wind_speed, wind_direction);
      serialPage = ' ';
      break;
  } // end Switch Serial page
}
