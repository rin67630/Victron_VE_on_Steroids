
// Serial Handling Victron
// ---
// This block handles the serial reception of the data in a
// non blocking way. It checks the Serial line for characters and
// parses them in fields. If a block of data is send, which always ends
// with "Checksum" field, the whole block is checked and if deemed correct
// copied to the 'value' array.

void RecvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  while (Serial.available() > 0 && new_data == false) {
    rc = Serial.read();
    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= buffsize) {
        ndx = buffsize - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      new_data = true;
    }
    yield();
  }
}

void HandleNewData() {
  // We have gotten a field of data
  if (new_data == true)
  {
    //Copy it to the temp array because parseData will alter it.
    //    digitalWrite(GRNLED, true);
    strcpy(tempChars, receivedChars);
    ParseData();
    GatherValues();
    new_data = false;
    //    digitalWrite(GRNLED, false);
  }
}

void ParseData() {
  char * strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(tempChars, "\t");     // get the first part - the label
  // The last field of a block is always the Checksum
  if (strcmp(strtokIndx, "Checksum") == 0) {
    blockend = true;
  }
  strcpy(recv_label[blockindex], strtokIndx); // copy it to label

  // Now get the value
  strtokIndx = strtok(NULL, "\r");    // This continues where the previous call left off until '/r'.
  if (strtokIndx != NULL) {           // We need to check here if we don't receive NULL.
    strcpy(recv_value[blockindex], strtokIndx);
  }
  blockindex++;

  if (blockend) {
    // We got a whole block into the received data.
    // Check if the data received is not corrupted.
    // Sum off all received bytes should be 0;
    byte checksum = 0;
    for (int x = 0; x < blockindex; x++) {
      // Loop over the labels and value gotten and add them.
      // Using a byte so the the % 256 is integrated.
      char *v = recv_value[x];
      char *l = recv_label[x];
      while (*v) {
        checksum += *v;
        v++;
      }
      while (*l) {
        checksum += *l;
        l++;
      }
      // Because we strip the new line(10), the carriage return(13) and
      // the horizontal tab(9) we add them here again.
      checksum += 32;
    }
    // Checksum should be 0, so if !0 we have correct data.
    if (!checksum) {
      // Since we are getting blocks that are part of a
      // keyword chain, but are not certain where it starts
      // we look for the corresponding label. This loop has a trick
      // that will start searching for the next label at the start of the last
      // hit, which should optimize it.
      int start = 0;
      for (int i = 0; i < blockindex; i++) {
        for (int j = start; (j - start) < num_keywords; j++) {
          if (strcmp(recv_label[i], keywords[j % num_keywords]) == 0) {
            // found the label, copy it to the value array
            strcpy(value[j], recv_value[i]);
            start = (j + 1) % num_keywords; // start searching the next one at this hit +1
            break;
          }
        }
      }
    }
    // Reset the block index, and make sure we clear blockend.
    blockindex = 0;
    blockend = false;
  }
} // End Parse Date


void GatherValues()                   // Translate the Victron protocol Keywords/Values into Flioat variables
{
  float m;                          //  Memory for computing delta BatV and delta BatI

  for (int i = 0; i < num_keywords; i++)
  {
    if (String(keywords[i]) == "V")
    {
      m = payload.BatV;
      payload.BatV = atof(value[i]) / 1000;
      dBatV = payload.BatV - m;      // Used for internal resistance evaluation in Stats
    }
    if (String(keywords[i]) == "I")
    {
      m = payload.BatI;
      payload.BatI = atof(value[i]) / 1000;
      dBatI = payload.BatI - m;      // Used for internal resistance evaluation in Stats
    }
    if (String(keywords[i]) == "VPV")   payload.PanV = atof(value[i]) / 1000;
#ifndef ESTIMATE_PANEL_POWER
    if (String(keywords[i]) == "PPV")   payload.PanW = atof(value[i]) / 1000;
#endif
    if (String(keywords[i]) == "IL")    payload.LodI = atof(value[i]) / 1000;
    if (String(keywords[i]) == "CS")    payload.ChSt = atoi(value[i]);
    if (String(keywords[i]) == "ERR")   payload.Err = atoi(value[i]);
  }

  // ***Estimate battery's internal resistance***
  if ((dBatI < -0.1) || (dBatI > 0.1))  // only if variation strong enough.
  {
    m = dBatV / dBatI;          // ( r = dv / di)
    if (m < 0) m = -m ;
    payload.IOhm = + (m - payload.IOhm) / 100 ;      // Low pass filter to average IOhm
  }
} //End Gather Values
