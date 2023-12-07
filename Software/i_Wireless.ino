void wirelessRun()
{
  switch (wirelessPage)
  {
    case 'A':  // Print A0
      static int i = 0;
      char timeStr[20];
      sprintf(timeStr, "%02d-%02d-%02d %02d:%02d:%02d", Year, Month, Day, Hour, Minute, Second);

      TelnetStream.print(i++);
      TelnetStream.print(" ");
      TelnetStream.print(timeStr);
      TelnetStream.print(" A0: ");
      TelnetStream.println(analogRead(A0));
      break;

    case 'V' : //Print Values
      TelnetStream.printf("BatV:%3.2f BatI:%2.3f BatW: %3.2f PanV: %3.2f PanW: %3.2f, LoadI %3.2f, LoadW %3.2f, IOhm %3.4f\n", BatV, BatI, BatW, PanV, PanW, LodI, LodW, IOhm);
      break;

    case 'D' : //Debug report
      TelnetStream.printf("BatV:%3.2f BatI:%2.3f DelV: %3.4f DelI: %3.4f, IOhm %3.4f\n", BatV, BatI, dBatV, dBatI, IOhm);
      break;

    case 'I' : //Print Victron VE Identifiers list
      for (int i = 0; i < num_keywords; i++)
      {
        for (int i = 0; i < num_keywords; i++)
        {
          TelnetStream.print(keywords[i]);
          TelnetStream.print(",");
          TelnetStream.println(value[i]);
        }
      }
      break;

    case 'J':   // Job Duration Report for debuggging
      TelnetStream.printf("\nJob Durations(mS) Current - Max\nVict:%03i - %03i \nFast:%03i - %03i\nSlow:%03i - %03i\nStat:%03i - %03i\nDisp:%03i - %03i\nSeri:%03i - %03i\nWifi:%03i - %03i\n",
                          RunMillis[1] - RunMillis[0], RunMillis[14], RunMillis[3] - RunMillis[2], RunMillis[15], RunMillis[5] - RunMillis[4], RunMillis[16], RunMillis[7] - RunMillis[6], RunMillis[17],
                          RunMillis[9] - RunMillis[8], RunMillis[18], RunMillis[11] - RunMillis[10], RunMillis[19], RunMillis[13] - RunMillis[12], RunMillis[20]);
      // serialPage = 0; // disabled One shot reset serial page.
      break;
  } // end Switch Wireless page
} // End wirelessRun()
