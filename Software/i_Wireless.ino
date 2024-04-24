void wirelessRun()
{

#if defined (DASHBRD_IS_THINGER)
  if (TrigEvent)   {
    thing.write_bucket("EVENT", "EVENT");
    TrigEvent = false;
  }
  if (NewDay)         thing.write_bucket("DAY", "DAY");
  if (HourExpiring)   thing.write_bucket("HOUR", "HOUR");
  if (MinuteExpiring) thing.write_bucket("MIN", "MIN");
#endif

  if (SecondOfDay == 39000)  //Somewehere during the middle of the day, resync time
  {
    getNTP();
    getTimeData();
  }
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

#ifdef COM_IS_HOURLY
  if (NewHour)  //Just before end of day
  {
    offsettedNow = now - 3600;  //One hour back.
    offsettedTimeinfo = localtime(&offsettedNow);
    strftime(charbuff, 30, "%x ", offsettedTimeinfo);
    UDP.println();
    UDP.print(charbuff);
    n = Hour - 1 ;
    if (Hour == -1) n = 23 ;
    UDP.printf("\n %+02.3f | %+02.3f | %s ", BatAh[n], BatVavg[n]), weather_summary;
  }
} // end second of Day
#endif //COM_IS_HOURLY

} // End wirelessRun()
