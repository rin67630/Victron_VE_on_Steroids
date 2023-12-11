void statsRun()
{
  
/* todo Compute these values ***
BatDD;          //  Deepest Discharge (Ah since last Float)
BatAD;          //  Average Discharge -"-
BatLD;          //  Last Discharge    -"-
BatCD;          //  Cumulative Discharges -"-
BatMC;          //  Max Charge (Ah since Min Bat Voltage )
BatAC;          //  Average Charge -"-
BatLC;          //  Last Charge    -"-
BatCC;          //  Cumulative Charges -"-
BatMV;          //  Number of Deep Discharges
BatOV;          //  Number of Overvoltages
*/

HourlyStats();

#ifdef WEATHER_IS_OWM
if (Minute %10 == 3)    // um Minuten 03, 13, 23, 33 usw...
{
  if (WiFi.status() == WL_CONNECTED)
  {
    if (Minute % 5 == 1 && Second == 32)                    // call every 5 minutes
    {
//      HTTPClient http;              // now defined at Global scope
      http.begin(WifiClient, OPEN_WEATHER_MAP_URL);
      int httpCode2 = http.GET();
      if (httpCode2 == HTTP_CODE_OK)
      {
        JSONpayload = http.getString();
        DynamicJsonDocument doc(1024);
        auto error = deserializeJson(doc, JSONpayload.c_str());
        if ( not error)
        {
          outdoor_temperature  = doc["main"]["temp"];
          outdoor_pressure     = doc["main"]["pressure"];
          outdoor_humidity     = doc["main"]["humidity"];
          wind_speed           = doc["wind"]["speed"];
          wind_direction       = doc["wind"]["deg"];
          cloudiness           = doc["clouds"]["all"];  // % Clouds
          const char* w        = doc["weather"][0]["description"]; 
          weather_summary = w;
        }
      }
      http.end();
    }
  }
}
#endif



}
