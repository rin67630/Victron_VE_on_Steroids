void wirelessRun()
{

#if defined (DASHBRD_IS_THINGER)
    if (TrigEvent)   {  thing.write_bucket("EVENT", "EVENT"); TrigEvent = false; }
    if (NewDay)         thing.write_bucket("DAY", "DAY");
    if (HourExpiring)   thing.write_bucket("HOUR", "HOUR");
    if (MinuteExpiring) thing.write_bucket("MIN", "MIN");  
#endif 
  
  /*
     ***   UDP Communication  ***
    I am using a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
    transmitting this array, and copying back the memory block of the array into the same structure on the other side.
    I dont use any header info, only the difference of size permits to validate the packet

    It is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
    and different sizes for between modules.
  */

#if defined (UDP_IS_SEND)
  memcpy(UDPCharPayload, &payload, sizeof(payload));
  UDP.beginPacket(ESP_UDP_ADDR, ESP_UDP_PORT);
  UDP.write(UDPCharPayload, sizeof(payload));
  UDP.endPacket();
#endif

#if defined (UDP_IS_RECEIVE)
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(GRNLED, true);
    int packetSize = UDP.parsePacket();
    if (packetSize == sizeof(payload))
    {
      UDP.read(UDPCharPayload, UDP_TX_PACKET_MAX_SIZE);
      memcpy(&payload, UDPCharPayload, sizeof(payload));
    }
    digitalWrite(GRNLED, false);
  }
#endif

#ifdef COM_IS_MIDNIGHT
  if (SecondOfDay == 86398)  //Just before end of day
  {
    UDP.beginPacket(COM_UDP_ADDR, COM_UDP_PORT);
    sprintf(charbuff, " \nMidnight Report for yesterday of \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
    UDP.print(charbuff);
    UDP.print  ("\n Hour   |");
    for  (byte n = 0; n < 12; n++)
    {
      UDP.printf("   %02u   |", n);
    }
    UDP.print  ("\n Bat Ah |");
    for  (byte n = 0; n < 12; n++)
    {
      UDP.printf(" %+02.3f |", BatAh[n]);
    }
    UDP.print  ("\n Bat V  |");
    for  (byte n = 0; n < 12; n++)
    {
      UDP.printf(" %+02.3f |", BatVavg[n]);
    }
    UDP.print  ("\n Hour   |");
    for  (byte n = 12; n < 24; n++)
    {
      UDP.printf("   %02u   |", n);
    }
    UDP.print  ("\n Bat Ah |");
    for  (byte n = 12; n < 24; n++)
    {
      UDP.printf(" %+02.3f |", BatAh[n]);
    }
    UDP.print  ("\n Bat V  |");
    for  (byte n = 12; n < 24; n++)
    {
      UDP.printf(" %+02.2f |", BatVavg[n]);
    }
    UDP.println("");
  } // end second of Day
#endif //COM_IS_MIDNIGHT

} // End wirelessRun()
