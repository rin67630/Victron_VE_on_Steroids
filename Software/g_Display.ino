void displayRun()
{
  yield();

//payload.BatV, payload.BatI, payload.BatW, payload.PanV, payload.PanI, payload.PanW, payload.LodI, payload.LodW, payload.IOhm

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
}
