void setup()
{
  delay(3000); // Wait for serial monitor to be started
  Serial.begin(SERIAL_SPEED);
  Serial.printf("\n\n\nVictron Logger at work,\nSerial @ %u Baud\n", SERIAL_SPEED);
  pinMode(STDLED, OUTPUT);
  // Witty Color LEDs
  pinMode(REDLED, INPUT);    // Tx0 after Serial.Swap()
  pinMode(GRNLED, INPUT);    // Not assigned
  pinMode(BLULED, INPUT);    // Rx0 after Serial.Swap()

  // Networking and Time
  getWiFi();
  //WiFi.printDiag(Serial);
  Serial.printf("MAC address: %s , \nHostname: %s", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
  digitalWrite(STDLED, true);

  getNTP();
  delay(3000);

  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  Serial.println("\nGot Epoch");
  getTimeData();         // breaks down the Epoch into discrete values.
  sprintf(charbuff, "Now is %02d:%02d:%02d, Date is %s, %02d %s %04d", Hour, Minute, Second, DayName, Day, MonthName, Year);
  Serial.println(charbuff);

  TelnetStream.begin();
  Serial.println("Console available on Telnet");
  otaInit();
  Serial.println("OTA ready");
  delay(500);
  Serial.println("Swapping Serial, bye, cu on Telnet");  
  Serial.flush();
  delay(500);
  Serial.swap();
 

  wirelessPage = ' ';
  serialPage = ' ';
  displayPage = ' ';

} //End Setup
