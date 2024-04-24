// Macro for Timing
#define runEvery(t) for (static uint16_t _lasttime; \
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t); \
                         _lasttime += (t))

// Instantiate classes
#ifndef INA_IS_NONE
#include <INA.h>
INA_Class INA;
#endif

#ifndef UDP_IS_NONE
#include <WiFiUdp.h>
WiFiUDP UDP;
//#define UDP_TX_PACKET_MAX_SIZE 128  //increase UDP size redefined here?
#endif

HTTPClient http;
WiFiClient wifiClient;
//AutoConnectCredential();

void getWiFi()
{
  Serial.printf("Reconnecting to %s\n", WIFI_SSID);

  byte retry;
  WiFi.begin();
  WiFi.waitForConnectResult();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected");
  } else {
    Serial.println("Fail, try Credentials\n");
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
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFi.setAutoReconnect(1);
    WiFi.persistent(1);
  } else {
    Serial.println("Fail, try SmartConfig\n");
    retry = 0;
    WiFi.beginSmartConfig();
    digitalWrite(STDLED, false);
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      digitalWrite(STDLED, not digitalRead(STDLED));
      delay(WIFI_REPEAT * 10);
      if (retry++ >= WIFI_MAXTRIES) break;
      if (WiFi.smartConfigDone())
      {
        Serial.println("SmartConfig success!");
        break; // exit from loop
      }
    }
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFi.setAutoReconnect(1);
    WiFi.persistent(1);
    Serial.println("Connection OK!");
    // WiFi.printDiag(Serial);
  } else {
    Serial.println("giving up! no Network");
    WiFi.mode(WIFI_OFF);
  }

#ifdef ARDUINO_ARCH_ESP8266
  WiFi.setOutputPower(WIFI_POWER);         // 0..20
#else
  WiFi.setTxPower(byte(WIFI_POWER));       // 0..78
#endif
  ip = WiFi.localIP();
  Serial.print("Done: RRSI= ");  Serial.print(WiFi.RSSI()); Serial.print("dB");
  sprintf(charbuff, "dB, IP= %03d.%03d.%03d.%03d\n", ip[0], ip[1], ip[2], ip[3]);   Serial.printf(charbuff);
}//end getWiFi

void myIP() {
  sprintf(charbuff, "IP= %03d.%03d.%03d.%03d\n", ip[0], ip[1], ip[2], ip[3]);
}

//********* Time management*************

void getNTP() {
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
}
void getEpoch() {
  now = time(nullptr);
  Epoch = now;
}

void getTimeData() {
  timeinfo = localtime(&now);  // cf: https://www.cplusplus.com/reference/ctime/localtime/
  Second = timeinfo->tm_sec;
  Minute = timeinfo->tm_min;
  Hour = timeinfo->tm_hour;
  Weekday = timeinfo->tm_wday + 1;
  Day = timeinfo->tm_mday;
  Month = timeinfo->tm_mon + 1;
  Year = timeinfo->tm_year + 1900;        //returns years since 1900
  strftime(DayName, 12, "%A", timeinfo);  //cf: https://www.cplusplus.com/reference/ctime/strftime/
  strftime(MonthName, 12, "%B", timeinfo);
  strftime(Time, 10, "%T", timeinfo);
  strftime(Date, 12, "%d/%m/%Y", timeinfo);
}

void buffTimeData()  // writes the time/date in Charbuff for print or display
{
  strftime(charbuff, sizeof(charbuff), " %R %d%b ", timeinfo);
}

//*** Other Math / conversions ***
bool inRange(int x, int low, int high)  // checks if a value is in boundaries
{
  if (x >= low && x <= high)
    return true;
  return false;
}

void setTimefromSerial()  // Enter time over serial
{
  if (Serial.available() > 0) {
    // read in the user input
    Day = Serial.parseInt();
    Month = Serial.parseInt();
    Year = Serial.parseInt();
    Hour = Serial.parseInt();
    Minute = Serial.parseInt();
    Second = Serial.parseInt();
    boolean validDate = (inRange(Day, 1, 31) && inRange(Month, 1, 12) && inRange(Year, 2021, 2031));
    boolean validTime = (inRange(Hour, 0, 23) && inRange(Minute, 0, 59) && inRange(Second, 0, 59));
    if (validTime && validDate) {
      configTime(0, 0, "pool.ntp.org");  // Repair timezone
      setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 3);
      tzset();
      struct tm t;  //Prepare time strucure
      time_t t_of_day;
      t.tm_year = Year - 1900;  // Year - 1900
      t.tm_mon = Month - 1;     // Month, where 0 = jan
      t.tm_mday = Day;          // Day of the month
      t.tm_hour = Hour;
      t.tm_min = Minute;
      t.tm_sec = Second;
      t.tm_isdst = -1;  // Is DST on? 1 = yes, 0 = no, -1 = unknown
      t_of_day = mktime(&t);
      struct timeval tv;     //Extending to mandatory microseconds
      tv.tv_sec = t_of_day;  // epoch time (seconds)
      tv.tv_usec = 0;        // microseconds
      settimeofday(&tv, 0);  //Setting Clock
    }
  }
}
void initOTA() {
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

    ArduinoOTA.begin();
  }
}
