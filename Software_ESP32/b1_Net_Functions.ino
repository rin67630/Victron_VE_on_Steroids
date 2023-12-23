#define runEvery(t) for (static uint16_t _lasttime; \
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t); \
                         _lasttime += (t))

#if defined(TERM_IS_SOFTSER)
#if defined(D7_IS_VICTRON)
SoftwareSerial SwSerial(1, 3);  // SoftwareSerial goes to the regular Serial ports
#else
SoftwareSerial SwSerial(13, 15);  // SoftwareSerial goes to D7,D8
#endif
#endif

#if defined(DASHBRD_IS_THINGER)
ThingerESP32 thing(THINGER_USERNAME, THINGER_DEVICE, THINGER_DEVICE_CREDENTIALS);
#endif

#if defined(DASHBRD_IS_INFLUX)
InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);
#endif

void getWiFi()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    byte wifiConnectCounter = 1;
    Serial.println();
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(WIFI_REPEAT);
      Serial.print(".");
      wifiConnectCounter++;
      if (wifiConnectCounter > WIFI_MAXTRIES)
      {
       Serial.printf("\n\nBad SSID or PASS?\n");
        WiFi.disconnect();
        Serial.printf("\nRunning offline, enter time date & time (dd/mm/yyyy hh:mm:ss) before using the menu\n");
        break;
      }
    }
    delay(50);
    WiFi.setHostname(DEVICE_NAME);
  }
  ip = WiFi.localIP();
  Serial.print("\nDone: RRSI= ");   Serial.print(WiFi.RSSI());
  sprintf(charbuff, "dB, IP= %03d . %03d . %03d . %03d \n",  ip[0], ip[1], ip[2], ip[3]);
  Serial.printf(charbuff);
}

void myIP()
{
  sprintf(charbuff, "IP= %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
}

//********* Time management*************

void getNTP() 
{
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
  now = time(nullptr);
  Epoch = now;
}
void getEpoch()
{
  now = time(nullptr);
  Epoch = now;
}

void getTimeData()
{
  timeinfo  = localtime(&now);  // cf: https://www.cplusplus.com/reference/ctime/localtime/
  Second    = timeinfo->tm_sec;
  Minute    = timeinfo->tm_min;
  Hour      = timeinfo->tm_hour;
  Weekday   = timeinfo->tm_wday + 1 ;
  Day       = timeinfo->tm_mday;
  Month     = timeinfo->tm_mon + 1;
  Year      = timeinfo->tm_year + 1900; //returns years since 1900
  strftime (DayName,   12, "%A", timeinfo); //cf: https://www.cplusplus.com/reference/ctime/strftime/
  strftime (MonthName, 12, "%B", timeinfo);
  strftime (Time,      10, "%T", timeinfo);
  strftime (Date,      12, "%d/%m/%Y", timeinfo);
}

void buffTimeData()   // writes the time/date in Charbuff for print or display
{
  strftime(charbuff, sizeof(charbuff), " %R %d%b ", timeinfo);
}

//*** Other Math / conversions ***
bool inRange(int x, int low, int high) // checks if a value is in boundaries
{
  if (x >= low && x <= high)
    return true;
  return false;
}


void setTimefromSerial()           // Enter time over serial
{
  if (Serial.available() > 0)
  {
    // read in the user input
    Day = Serial.parseInt();
    Month = Serial.parseInt();
    Year = Serial.parseInt();
    Hour = Serial.parseInt();
    Minute = Serial.parseInt();
    Second = Serial.parseInt();
    boolean validDate = (inRange(Day, 1, 31) && inRange(Month, 1, 12) && inRange(Year, 2021, 2031));
    boolean validTime = (inRange(Hour, 0, 23) && inRange(Minute, 0, 59) && inRange(Second, 0, 59));
    if (validTime && validDate)
    {
      configTime(0, 0, "pool.ntp.org");    // Repair timezone
      setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 3);
      tzset();
      struct tm t;                         //Prepare time strucure
      time_t t_of_day;
      t.tm_year = Year - 1900; // Year - 1900
      t.tm_mon = Month - 1;     // Month, where 0 = jan
      t.tm_mday = Day ;      // Day of the month
      t.tm_hour = Hour;
      t.tm_min = Minute;
      t.tm_sec = Second;
      t.tm_isdst = -1;         // Is DST on? 1 = yes, 0 = no, -1 = unknown
      t_of_day = mktime(&t);
      struct timeval tv;                   //Extending to mandatory microseconds
      tv.tv_sec = t_of_day;  // epoch time (seconds)
      tv.tv_usec = 0;    // microseconds
      settimeofday(&tv, 0);                //Setting Clock
    }
  }
}
void otaInit() {
  if (WiFi.status() == WL_CONNECTED) {
    // Over the Air Framework
    ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else {  // U_FS
        type = "filesystem";
      }
      // NOTE: if updating FS this would be the place to unmount FS using FS.end()
      Serial.println("Start updating " + type);
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) {
        Serial.printf("Auth Failed\n");
      } else if (error == OTA_BEGIN_ERROR) {
        Serial.printf("Begin Failed\n");
      } else if (error == OTA_CONNECT_ERROR) {
        Serial.printf("Connect Failed\n");
      } else if (error == OTA_RECEIVE_ERROR) {
        Serial.printf("Receive Failed\n");
      } else if (error == OTA_END_ERROR) {
        Serial.printf("End Failed\n");
      }
    });
    ArduinoOTA.setHostname(DEVICE_NAME);
    Serial.print("\nStart OTA on ");
    Serial.println(DEVICE_NAME);
    ArduinoOTA.begin();
  }
}
