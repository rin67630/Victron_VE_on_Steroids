void wirelessRun()
{
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
      UDP.beginPacket(UDP_ADDR, UDP_PORT);
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

} // End wirelessRun()
