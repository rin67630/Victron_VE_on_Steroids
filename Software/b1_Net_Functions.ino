void getWiFi()              // From memory , Using Defaults, or using SmartConfig
{
  int retry = 0;
  WiFi.mode(WIFI_STA);      // configure WiFi in Station Mode
  wifi_station_set_hostname(HOST_NAME);
  wifi_station_set_auto_connect(true);
  delay(WIFI_REPEAT);
  Serial.println("Attempt to connect to WiFi network from EEPROM");
  WiFi.begin();
  delay(WIFI_REPEAT);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    digitalWrite(STDLED, not digitalRead(STDLED));
    delay(WIFI_REPEAT) ;
    if (retry++ >= WIFI_MAXTRIES) break;
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("\nConnection timeout expired! Start with default");
    retry = 0;
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(WIFI_REPEAT * 2 );
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      digitalWrite(STDLED, not digitalRead(STDLED));
      delay(WIFI_REPEAT);
      if (retry++ >= WIFI_MAXTRIES) break;
    }
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connection timeout expired! Start SmartConfig…");
    retry = 0;
    WiFi.beginSmartConfig();
    digitalWrite(STDLED, false);
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      digitalWrite(STDLED, not digitalRead(STDLED));
      delay(WIFI_REPEAT * 4);
      if (retry++ >= WIFI_MAXTRIES) break;
      if (WiFi.smartConfigDone())
      {
        Serial.println("SmartConfig success!");
        break; // exit from loop
      }
    }
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connection timeout expired! Running without Network");
    WiFi.mode(WIFI_OFF);
  } else {
    // show WiFi connection data
    Serial.println("Connection succeeded");
    //WiFi.printDiag(Serial);

    // show the IP address assigned to our device
    Serial.println(WiFi.localIP());
    digitalWrite(STDLED, true);
  }
} // End Void GetWiFi

void disConnect()
{
  //  WiFi.disconnect(); //temporarily disconnect WiFi as it's no longer needed
  WiFi.mode(WIFI_OFF);
  // WiFi.forceSleepBegin();  can it save power?
  // WiFi.forceSleepWake();
}

void myIP()
{
  sprintf(charbuff, "IP= %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
}

// Time management
void getNTP()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    configTime(MYTZ, NTP_SERVER);
    now = 1577833200000;   //01 Jan 2020 12:00
  }
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

  strftime (DayName , 12, "%A", timeinfo); //cf: https://www.cplusplus.com/reference/ctime/strftime/
  strftime (MonthName, 12, "%B", timeinfo);
  strftime (Time, 10, "%T", timeinfo);
  strftime (Date, 12, "%d/%m/%Y", timeinfo);
}

void otaInit()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    // Over the Air Framework
    ArduinoOTA.onStart([]()
    {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else { // U_FS
        type = "filesystem";
      }
      // NOTE: if updating FS this would be the place to unmount FS using FS.end()
      Serial.println("Start updating " + type);
    });
    ArduinoOTA.onEnd([]()
    {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
    {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error)
    {
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
    ArduinoOTA.setHostname(HOST_NAME);
    Serial.print("\nStart OTA on ");
    Serial.println (HOST_NAME);
    ArduinoOTA.begin();
  }
}
