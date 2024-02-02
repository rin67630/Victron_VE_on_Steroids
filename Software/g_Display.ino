void displayRun()
{
  yield();

  switch  (displayPage)
  {
#ifndef OLED_IS_NONE
    case ' ': 
      display.clear();     
      break;  
#endif  
    case '0':      //   Victron Data
#ifdef OLED_IS_64x48
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(0, 0,  "Panl =" + String(payload.PanV)   + "V");
      display.drawString(0, 12, "Batt  =" + String(payload.BatV) + "V");
      //    display.drawString(0, 24, "Curr  ="+String(payload.BatI) +"A");
      sprintf(charbuff, "Curr  =%1.3fA", payload.BatI); display.drawString(0, 24, charbuff);
      display.drawString(0, 36, "Powr="  + String(payload.BatW)   + "W");
      display.display();
#endif
#ifdef OLED_IS_128x64
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      // Draw Information matrix
      display.drawString(10, 0,  "|  Panel");
      display.drawString(50, 0,  "| Battery");
      display.drawString(90, 0,  "| Output");
      display.drawString(0, 12, "V ");
      sprintf(charbuff, "| %2.2f", payload.PanV); display.drawString(10, 12, charbuff);
      sprintf(charbuff, "| %2.2f", payload.BatV); display.drawString(50, 12, charbuff);
      sprintf(charbuff, "| %2.2f", payload.BatV); display.drawString(90, 12, charbuff);
      display.drawString(0, 24, "A ");
      sprintf(charbuff, "| %1.3f", payload.PanI); display.drawString(10, 24, charbuff);
      sprintf(charbuff, "| %1.3f", payload.BatI); display.drawString(50, 24, charbuff);
      sprintf(charbuff, "| %1.3f", payload.LodI); display.drawString(90, 24, charbuff);
      display.drawString(0, 36, "W ");
      sprintf(charbuff, "| %2.2f", payload.PanW); display.drawString(10, 36, charbuff);
      sprintf(charbuff, "| %2.2f", payload.BatW); display.drawString(50, 36, charbuff);
      sprintf(charbuff, "| %2.2f", payload.LodW); display.drawString(90, 36, charbuff);

      buffTimeData();
      display.drawString(0, 50, charbuff);

      display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
      display.display();
#endif
      break;
    case '1':   // Smart shunt
#ifdef OLED_IS_64x48
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(0, 0,  "Volt =" + String(payload.BatV) + "V");
      sprintf(charbuff, "Curr =%1.3fA", payload.BatI); display.drawString(0, 12, charbuff);
      display.drawString(0, 24, "Powr="  + String(payload.BatW)   + "W");
      sprintf(charbuff, "Resi =%1.3fA", payload.IOhm); display.drawString(0, 36, charbuff);
      display.display();
#endif
#ifdef OLED_IS_128x64
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      // Draw Volt Ampere
      //      Watt int Resistance
      display.drawString(0, 0, "Smart Shunt");
      display.setFont(ArialMT_Plain_16);
      sprintf(charbuff, "%2.2f", payload.BatV); display.drawString(0, 12, charbuff);
      display.drawString(45, 12, "V");
      sprintf(charbuff, " %1.3f", payload.BatI); display.drawString(60, 12, charbuff);
      display.drawString(110, 12, "A");
      sprintf(charbuff, "%2.2f", payload.BatW); display.drawString(0, 30, charbuff);
      display.drawString(45, 30, "W");
      sprintf(charbuff, " %1.2f", payload.IOhm*1000); display.drawString(60, 30, charbuff);
      display.drawString(100, 30, "mR ");
      buffTimeData();
      display.setFont(ArialMT_Plain_10);      
      display.drawString(0, 50, charbuff);
      display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
      display.display();
#endif
      break;
    case '2':      // Temperature / Pressure / Humidity

#ifdef OLED_IS_64x48
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(0, 0,  "Temp =" + String(temperature) + "°C");
      sprintf(charbuff, "Press =%4.0fhP", pressure); display.drawString(0, 12, charbuff);
      display.drawString(0, 24, "Humi="  + String(humidity)   + "%");
      sprintf(charbuff, "Wind =%2.3fA", wind_speed); display.drawString(0, 36, charbuff);
      display.display();
#endif
#ifdef OLED_IS_128x64
      display.clear();
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      // Draw Volt Ampere
      //      Watt int Resistance
#if defined (WEATHER_IS_BME680)
      display.drawString(0, 0, "BME680 Air Values");
#endif
#if defined (WEATHER_IS_OWM)
      display.drawString(0, 0, "Open Weather Air Values");
#endif
#if defined (WEATHER_IS_NONE)
      display.drawString(0, 0, "Sorry, no Air Values");
#endif
      display.setFont(ArialMT_Plain_16);
      sprintf(charbuff, "%2.2f", temperature); display.drawString(0, 12, charbuff);
      display.drawString(45, 12, "°C");
      sprintf(charbuff, " %4.0f", pressure); display.drawString(60, 12, charbuff);
      display.drawString(100, 12, "mB");
      sprintf(charbuff, "%2.2f", humidity); display.drawString(0, 30, charbuff);
      display.drawString(45, 30, "%");
      sprintf(charbuff, " %1.2f", wind_speed); display.drawString(60, 30, charbuff);
      display.drawString(100, 30, "m/s ");
      buffTimeData();
      display.setFont(ArialMT_Plain_10);      
      display.drawString(0, 50, charbuff);
      display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
      display.display();
#endif
      break;      
}  // Endif Switch
}  // End DisplayRun
