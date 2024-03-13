void menuRun() {

#ifdef CONTR_IS_TTGO
  Buttons.processButtons();
  if (Buttons.shortPress(UP)) {
    displayPage = displayPage + 1;
    tft.fillScreen(TFT_BLACK);
  }
  if (Buttons.shortPress(DOWN)) {
    displayPage = displayPage - 1;
    tft.fillScreen(TFT_BLACK);
  }
#endif

  serialReceived = Console1.read();
  switch (serialReceived) {
    // Switching displays
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
      Console1.print("Switching display to ");
      Console1.write(serialReceived);
      Console1.println();
      displayPage = serialReceived;
#ifdef SCREEN_IS_TTGO
      tft.fillScreen(TFT_BLACK);
#endif
      break;

    case 'Z':  // Reset ESP
      Console1.printf("\nReset Device, Bye! \n");
#if defined(TERM_IS_TELNET)
      Console1.stop();
#endif
      delay(100);
      ESP.restart();
      break;
    case 'z':  //Reset
      Console1.printf("\nReset Integrations \n");
      BatDD = BatAD = BatLD = BatCD = BatMC = BatAC = BatLC = BatCC = BatMV = BatOV = 0;  //  Number of Overvoltages
      break;
#if defined(TERM_IS_TELNET)
    case 'Q':  // Quit Telnet
      Console1.println("bye bye");
      Console1.flush();
      TelnetStream.stop();
      break;
#endif
      /*
    case 'S':  // Swap Serial
      Console1.println("Swapping Serial");
      Serial.flush();
      Serial.swap();
      break;
      */
    case 'B':  //Battery Report
      Console1.printf("\n Battery Stats\n");
      serialPage = 'B';
      break;
    case 'D':                               //Debug Report
      Console1.printf("\nDebug Report\n");  // this report changes as programmers test
      serialPage = 'D';
      break;
    case 'V':  //Values Report
      Console1.printf("\nValues Report\n");
      serialPage = 'V';
      break;
    case 'J':  //Debug Report
      Console1.printf("\nJob Timing\n");
      serialPage = 'J';
      break;
    case ' ':  //Wait for input, clear Serial page and Display page
      Console1.printf("\nWaiting for input\n");
      serialPage = serialReceived;
      displayPage = serialReceived;
      break;
    case 'j':  //Reset Job Maxes
      Console1.printf("\nReset Job Timings \n");
      for (int i = 14; i < 21; i++) RunMillis[i] = 0;  // Reset job timing stats
      break;
    case 'W':  //Weather Plot
      serialPage = 'W';
      Console1.printf("\nWeather list :\n");
      break;
  }
}
