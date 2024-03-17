void displayRun() {
  // *** TTGO display processing ***

#if defined(SCREEN_IS_TTGO)  //TTG0 color screen
// Reference https://github.com/Bodmer/User_Manual_TFT_eSPI/blob/master/TFT_eSPI.cpp.All.pdf
  if (displayPage == '0') 
  { digitalWrite(TFT_BL, false);
  }else{
    digitalWrite(TFT_BL, true);
    ledcWrite(TFT_BL, BRIGHTNESS);  // Adjust screen brightnesss
    // Time line
    tft.setTextColor(TFT_GREY, TFT_BLACK);
    tft.setCursor(0, 110, 4);    // X, Y , Font
    buffTimeData();
    tft.print(charbuff);
    tft.setTextColor(TFT_PURPLE, TFT_BLACK);
    tft.println("...");
    tft.fillRect(0, 130, 120, 2, TFT_BLACK);          //clear seconds progress bar
    tft.fillRect(0, 130, Second * 2, 2, TFT_PURPLE);  //display seconds progress bar
    tft.setTextColor(TFT_PURPLE, TFT_BLACK);

    // Right Charge Bargraph
    // The TFT-eSPI library draws from left to right, from top to bottom
    // To draw a bargraph from bottom to top the best is to draw a full rectangle and to overwrite
    // from top to bottom with the background color.
    tft.fillRect(231, 30, 6, 78, TFT_GREY);      // 100% progress bar
    tft.fillRect(231, 30, 6, 78 - payload.ChSt * 8, TFT_BLACK);

    // Button descriptions
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.setCursor(225, 0, 4); 
    tft.print(">");
    tft.setCursor(225, 113, 4);
    tft.print("<");

    // Overview Line
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(0, 0, 2);
    sprintf(charbuff, " %05.2fVi | %05.2fVo | %05.2fA0 | ", payload.PanV, payload.BatV, payload.BatI);
    tft.println(charbuff);
  } // end if displayPage

  switch (displayPage) {
    case '0':
      break;

    case '1':  // BatVolt /BatAmpere  Display (output)
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print(" V/A ");  // highlight CV

      // Variables
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setCursor(10, 16, 7);
      sprintf(charbuff, "%05.2f ", payload.BatV);
      tft.print(charbuff);
      tft.setCursor(160, 34, 4);
      tft.print("V (o)");
      tft.setTextColor(TFT_VERMILON, TFT_BLACK);
      tft.setCursor(10, 64, 7);
      sprintf(charbuff, "%05.2f ", payload.BatI);
      tft.print(charbuff);
      tft.setCursor(160, 85, 4);
      tft.print("A (o)");
      break;

    case '2':  // PanVolt /BatWatt  Display (input)
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print(" Inp ");  // highlight CV

      // Variables
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      tft.setCursor(10, 16, 7);
      sprintf(charbuff, "%05.2f ", payload.PanV);
      tft.print(charbuff);
      tft.setCursor(160, 34, 4);
      tft.print("V (i)");
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      tft.setCursor(10, 64, 7);
      sprintf(charbuff, "%05.2f ", payload.BatW);
      tft.print(charbuff);
      tft.setCursor(160, 85, 4);
      tft.print("W (o)");
      break;

    case '3':  // Power Supply Display
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print(" PS ");

      // Variables
      tft.setTextColor(TFT_GOLD, TFT_BLACK);
      tft.setCursor(0, 25, 4);
      sprintf(charbuff, "%06.2fVi ", payload.PanV);
      tft.print(charbuff);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setCursor(110, 25, 4);
      sprintf(charbuff, "%06.3fVo ", payload.BatV);
      tft.println(charbuff);
      tft.setTextColor(TFT_VERMILON, TFT_BLACK);
      tft.setCursor(0, 55, 4);
      sprintf(charbuff, "%06.3fA ", payload.BatI);
      tft.println(charbuff);
      tft.setTextColor(TFT_OLIVE, TFT_BLACK);
      tft.setCursor(110, 55, 4);
      sprintf(charbuff, "%06.2fAh ", BatAh[27]);
      tft.println(charbuff);
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      tft.setCursor(0, 85, 4);
      sprintf(charbuff, "%06.2fW ", payload.BatW);
      tft.println(charbuff);
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      tft.setCursor(110, 85, 4);
      sprintf(charbuff, "%06.1fWh ", BatAh[27] * BatVavg[27]);
      tft.println(charbuff);
      break;

    case '4':  // Summary Display
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print(" Bat ");

      // Variables
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setCursor(0, 25, 4);
      sprintf(charbuff, "%06.2fV ", BatVavg[24]);
      tft.print(charbuff);
      tft.setTextColor(TFT_OLIVE, TFT_BLACK);
      tft.setCursor(110, 25, 4);
      sprintf(charbuff, "%06.2fAh ", BatAh[24]);
      tft.println(charbuff);
      tft.setTextColor(TFT_BROWN, TFT_BLACK);
      tft.setCursor(0, 55, 4);
      sprintf(charbuff, "%3.2fmR", payload.IOhm * 1000);
      tft.println(charbuff);
      tft.setTextColor(TFT_OLIVE, TFT_BLACK);
      tft.setCursor(110, 55, 4);
      sprintf(charbuff, "%06.2fAh ", BatAh[27]);
      tft.println(charbuff);
      tft.setTextColor(TFT_ORANGE, TFT_BLACK);
      tft.setCursor(0, 85, 4);
      sprintf(charbuff, "%02i %%PoC ", int(payload.ChSt * 10));
      tft.println(charbuff);
      tft.setTextColor(TFT_OLIVE, TFT_BLACK);
      tft.setCursor(110, 85, 4);
      sprintf(charbuff, "%06.1fAh ", BatAh[27]);
      tft.println(charbuff);
      break;

case '5':  // Vh Ah Instant  / Hour / Day
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print("IHD");

      // Variables
      tft.setTextColor(TFT_BLACK, TFT_DARKGREY);
      tft.setCursor(0, 20, 4);
      tft.print("           Inst|H(-1)|Day");
      //    tft.print("       Instant  |   LastHr  |   Day");
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setCursor(0, 40, 4);
      tft.print("V" ); 
      tft.setCursor(30, 40, 4); 
      sprintf(charbuff, " %04.1f", BatVavg[24]);
      tft.print(charbuff);
      tft.setCursor(100, 40, 4);
      sprintf(charbuff, " %04.1f", BatVavg[25]);
      tft.print(charbuff);
      tft.setCursor(170, 40, 4);
      sprintf(charbuff, " %04.1f", BatVavg[27]);
      tft.print(charbuff);
      tft.setTextColor(TFT_VERMILON, TFT_BLACK);
      tft.setCursor(0, 60, 4);
      tft.print("Ah ");
      tft.setCursor(30, 60);
      sprintf(charbuff, " %04.2f", BatAh[24]);
      tft.print(charbuff);
      tft.setCursor(100, 60, 4);
      sprintf(charbuff, " %04.2f", BatAh[25]);
      tft.print(charbuff);
      tft.setCursor(170, 60, 4);
      sprintf(charbuff, " %04.2f", BatAh[27]);
      tft.print(charbuff);
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      tft.setCursor(0, 84, 4);
      tft.print("Wh ");
      tft.setCursor(30, 84, 4);
      sprintf(charbuff, " %04.1f", BatAh[24] * BatVavg[24]);
      tft.print(charbuff);
      tft.setCursor(100, 84, 4);
      sprintf(charbuff, " %04.1f", BatAh[25] * BatVavg[25]);
      tft.print(charbuff);
      tft.setCursor(170, 84, 4);
      sprintf(charbuff, " %04.1f", BatAh[27] * BatVavg[27]);
      tft.print(charbuff);
      break;

    case '6':  // STAT Display
      // Page name
      tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
      tft.setCursor(186, 0, 2);
      tft.print(" Sta ");

      // Variables
      BatAh[31] = 1;                 // to avoid a division / 0
      for (byte n = 0; n < 24; n++)  // Display 24 hourly bargraphs
      {
        if (BatAh[n] > 0) {
          tft.fillRect(7 * n + 55, 20, 5, 78, TFT_OLIVE);                                    //Bargraphs
          tft.fillRect(7 * n + 55, 20, 5, byte(78 - 78 * BatAh[n] / BatAh[31]), TFT_BLACK);  //Positive Values
        }
        if (BatAh[n] < 0) {
          tft.fillRect(7 * n + 55, 20, 5, 78, TFT_MAROON);                                   //Bargraphs
          tft.fillRect(7 * n + 55, 20, 5, byte(78 + 78 * BatAh[n] / BatAh[31]), TFT_BLACK);  //Negative values
        }
        tft.setCursor(0, 20, 2);
        tft.setTextColor(TFT_GREY, TFT_BLACK);     // Axis description
        BatAh[31] = max(BatAh[31], BatAh[n] + 1);  // max Ah harvested (+1 to determine plot span)
      }
      tft.setCursor(15, 20, 2);
      sprintf(charbuff, "%05.2f", BatAh[31]);
      tft.println(charbuff);  // printing Axis max
      tft.drawFastVLine(53, 20, 79, TFT_GREY);
      tft.drawFastHLine(54, 99, 170, TFT_GREY);
      tft.setCursor(0, 52, 2);
      tft.print("Ah(24)");
      tft.setCursor(43, 84, 2);
      tft.print("0");
      break;
  }     // end switch (displayPage)
#endif  //SCREEN_IS_TTGO

    // *** HELTEC / WEMOS display processing ***
#if defined(SCREEN_IS_HELTEC) || defined(SCREEN_IS_WEMOS32) || defined(SCREEN_IS_128x64)
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  switch (displayPage) {
    case '0':
      break;
    case '1':
      display.setFont(ArialMT_Plain_10);
      sprintf(charbuff, "%5.2f Vi", payload.PanV);
      display.drawString(0, 0, charbuff);
      sprintf(charbuff, "%5.2f Vo", payload.BatV);
      display.drawString(42, 0, charbuff);
      sprintf(charbuff, "%5.2f Ao", payload.BatI);
      display.drawString(88, 0, charbuff);
      display.drawString(45, 16, "Vi");
      display.drawString(110, 16, "Vo");
      display.drawString(45, 36, "Ao");
      display.drawString(112, 36, "W");
      display.setFont(ArialMT_Plain_16);
      sprintf(charbuff, "%05.2f", payload.PanV);
      display.drawString(0, 12, charbuff);
      sprintf(charbuff, "%05.2f", payload.BatV);
      display.drawString(65, 12, charbuff);
      sprintf(charbuff, "%05.2f", payload.BatI);
      display.drawString(0, 32, charbuff);
      sprintf(charbuff, "%05.1f", payload.BatW);
      display.drawString(65, 32, charbuff);
      display.setFont(ArialMT_Plain_10);
      break;
    case '2':  // Value matrix
      display.drawString(10, 0, "| Panel");
      display.drawString(50, 0, "| Battr");
      display.drawString(90, 0, "| Outpt");
      display.drawString(0, 12, "V ");
      sprintf(charbuff, "| %05.2f", payload.PanV);
      display.drawString(10, 12, charbuff);
      sprintf(charbuff, "| %05.2f", payload.BatV);
      display.drawString(50, 12, charbuff);
      sprintf(charbuff, "| %05.2f", payload.BatV);
      display.drawString(90, 12, charbuff);
      display.drawString(0, 24, "A ");
      sprintf(charbuff, "| %05.3f", payload.PanI);
      display.drawString(10, 24, charbuff);
      sprintf(charbuff, "| %05.3f", payload.BatI);
      display.drawString(50, 24, charbuff);
      sprintf(charbuff, "| %05.3f", payload.BatI);
      display.drawString(90, 24, charbuff);
      display.drawString(0, 36, "W ");
      sprintf(charbuff, "| %05.2f", payload.PanW);
      display.drawString(10, 36, charbuff);
      sprintf(charbuff, "| %05.2f", payload.BatW);
      display.drawString(50, 36, charbuff);
      sprintf(charbuff, "| %05.2f", BatAh[27] * BatVavg[27]);
      display.drawString(90, 36, charbuff);
      break;
    case '3':
      // Battery
      display.setFont(ArialMT_Plain_10);
      sprintf(charbuff, "Battery");
      display.drawString(0, 0, charbuff);
      sprintf(charbuff, "%5.4f R", payload.IOhm);
      display.drawString(42, 0, charbuff);
      sprintf(charbuff, "%02u %%", payload.ChSt);
      display.drawString(88, 0, charbuff);
      display.drawString(45, 16, "Vo");
      display.drawString(110, 16, "Ah");
      display.drawString(45, 36, "Ao");
      display.drawString(108, 36, "Wh");
      display.setFont(ArialMT_Plain_16);
      sprintf(charbuff, "%05.2f", payload.BatV);
      display.drawString(0, 12, charbuff);
      sprintf(charbuff, "%05.2f", BatAh[27] * BatVavg[27]);
      display.drawString(65, 12, charbuff);
      sprintf(charbuff, "%05.2f", payload.BatI);
      display.drawString(0, 32, charbuff);
      sprintf(charbuff, "%05.1f", payload.BatW);
      display.drawString(65, 32, charbuff);
      display.setFont(ArialMT_Plain_10);
      break;
    case '4':  // Statistic
      display.drawString(12, 0, " Instant | Lst Hr  | Day");
      display.drawString(0, 12, "V ");
      sprintf(charbuff, "| %05.2f", BatVavg[24]);
      display.drawString(12, 12, charbuff);
      sprintf(charbuff, "| %05.2f", BatVavg[25]);
      display.drawString(50, 12, charbuff);
      sprintf(charbuff, "| %05.2f", BatVavg[27]);
      display.drawString(90, 12, charbuff);
      display.drawString(0, 24, "Ah ");
      sprintf(charbuff, "| %05.3f", BatAh[24]);
      display.drawString(12, 24, charbuff);
      sprintf(charbuff, "| %05.3f", BatAh[25]);
      display.drawString(50, 24, charbuff);
      sprintf(charbuff, "| %05.3f", BatAh[27]);
      display.drawString(90, 24, charbuff);
      display.drawString(0, 36, "Wh ");
      sprintf(charbuff, "| %05.2f", BatAh[24] * BatVavg[24]);
      display.drawString(12, 36, charbuff);
      sprintf(charbuff, "| %05.2f", BatAh[25] * BatVavg[25]);
      display.drawString(50, 36, charbuff);
      sprintf(charbuff, "| %05.2f", BatAh[27] * BatVavg[27]);
      display.drawString(90, 36, charbuff);
      break;
  }
  buffTimeData();
  display.drawString(0, 50, charbuff);
  if (payload.PanW > 0.03) {
    sprintf(charbuff, "Cha:%02u %%", payload.ChSt);
    display.drawString(75, 50, charbuff);
  }
  display.fillRect(0, 63, Second * 2, 1);  //display seconds progress bar
  display.display();
#endif  //SCREEN_IS_HELTEC

// *** Small OLED 64*48 display processing ***
#ifdef SCREEN_IS_64x48
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0,  "Pan =" + String(payload.PanV) + "V");
  display.drawString(0, 12, "Bat  =" + String(payload.BatV) + "V");
  //display.drawString(0, 24, "Cur =" +String(payload.BatI)  +"A"); //print Current with defaults
  sprintf(charbuff, "Cur  =%1.3fA", payload.BatI);                 //print Current with 3 decimals
  display.drawString(0, 24, charbuff);
  display.drawString(0, 36, "Pow =" + String(payload.BatW) + "W");
  display.display();
#endif

}
