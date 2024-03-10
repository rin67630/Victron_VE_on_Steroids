To compile correctly for the TTGO display, you MUST replace the file User_Setup.h in /libraries/TFT_eSPI/ with the file provided in /Libraries.
This is also required after an update of the TFT-eSPI library.

If you don't your, sketch will issue the error TFT_BL is not defined.


This repacement is only required fir TTGO displays, it is not required if you use an OLED display or no displaa at all.

