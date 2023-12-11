void menuRun()
{
  switch (Console1.read())
  {
    case 'Z':   // Reset ESP
      Console1.printf ("\nReset Device, Bye! \n");
#if defined(TERM_IS_TELNET)
      Console1.stop();
#endif
      delay(100);
      ESP.reset();
      break;
    case 'z':  //Reset 
      Console1.printf ("\nReset Integrations \n");
      BatDD = BatAD = BatLD = BatCD = BatMC = BatAC = BatLC = BatCC = BatMV = BatOV = 0 ;          //  Number of Overvoltages
      break;
#if defined(TERM_IS_TELNET)
    case 'Q':   // Quit Telnet
      Console1.println("bye bye");
      Console1.flush();
      TelnetStream.stop();
      break;
#endif
    case 'S':  // Swap Serial
      Console1.println("Swapping Serial");
      Serial.flush();
      Serial.swap();
      break;
    case 'A':  //A0 Report
      Console1.printf ("\nA0 Report\n");
      serialPage = 'A';
      break;
    case 'D':  //Debug Report
      Console1.printf ("\nDebug Report\n");   // this report changes as programmers test
      serialPage = 'D';
      break;
    case 'V':  //Values Report
      Console1.printf ("\nValues Report\n");
      serialPage = 'V';
      break;
    case 'I':  //Victron VE stream Report
      Console1.printf ("\nVictron Report\n");
      serialPage = 'I';
      break;
    case 'J':  //Debug Report
      Console1.printf ("\nJob Timing\n");
      serialPage = 'J';
      break;
    case ' ':  //Wait for input
      Console1.printf ("\nWaiting for input\n");
      serialPage = ' ';
      break;
    case 'j':  //Reset Job Maxes
      Console1.printf ("\nReset Job Timings \n");
      for (int i = 14; i < 21; i++) RunMillis[i] = 0;  // Reset job timing stats
      break;
      case 'W':  //Weather Plot
      serialPage = 'W';
      Console1.printf ("\nWeather list :\n");
      break;
  }
}
