void setup() {
// Initialize Serial Victron
#if defined(TERM_IS_SOFTSER)
#if defined(D7_IS_VICTRON) || defined (D7_IS_DROK)
  SoftwareSerial SwSerial(1, 3);  // SoftwareSerial goes to the regular Serial ports
#else
  SoftwareSerial SwSerial(13, 15);  // SoftwareSerial goes to D7,D8
#endif
#endif

  //Initialize Serial Terminal for Boot
  Serial.begin(SERIAL_SPEED);
  Serial.setRxBufferSize(1024);
  //Initialize Second Serial for Victron
#if defined(D7_IS_VICTRON) && defined(ARDUINO_ARCH_ESP32)
  Serial2.begin(115200, SERIAL_8N1, 13);  //define Serial input 2 on d7 (GPIO13)
#endif
  // Serial.setDebugOutput(true);
  delay(1000);  // Wait for serial monitor to be started
  Serial.print("\n\n\nCompiled from: ");
  Serial.println(__FILE__);
  Serial.print("on ");
  Serial.print(__DATE__);
  Serial.print(" at ");
  Serial.println(__TIME__);
  Serial.printf("Victron/INA226 Logger at work: %s Serial @ %u Baud\n", DEVICE_NAME, SERIAL_SPEED);

  //Initialize I2C
  Wire.begin(SDA, SCL);

  //Restart pin
#ifdef RST
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(10);
  digitalWrite(16, HIGH);
#endif

#ifdef SCREEN_IS_TTGO
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(16, OUTPUT);       //I2C Restart
  ledcSetup(1, 2000, 8);     // 11 bit resolution@ 2Khz
  ledcAttachPin(TFT_BL, 1);  // Display backlight control pin
  ledcWrite(1, BRIGHTNESS);
  tft.init();  // TTGO e_SPI TFT 240*135 pixel
  tft.setCursor(0, 0, 2);
  tft.fillScreen(TFT_BLACK);
  delay(50);
 #ifdef SCREEN_IS_REVERSED
  tft.setRotation(1);
 #endif
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
#endif //SCREEN_IS_TTGO

#if not defined (SCREEN_IS_NONE) && not defined (SCREEN_IS_TTGO)
  //Initialize OLED Screens
  display.init();
  //  display.clear();
  display.setColor(WHITE);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
 #ifdef SCREEN_IS_REVERSED
  display.flipScreenVertically();
 #endif
#endif // OLED Screens

  pinMode(REDLED, OUTPUT);  // Tx0 after Serial.Swap()
  pinMode(GRNLED, OUTPUT);  // For debugging
  pinMode(LED_BUILTIN, OUTPUT);  // Onboard LED 
#if defined (D7_IS_VICTRON) || defined (D7_IS_DROK)
  pinMode(BLULED, INPUT);   // Rx0 after Serial.Swap()
#else
  pinMode(BLULED, OUTPUT);  // Use normally
#endif

#if defined(SCREEN_IS_64x48) || defined(SCREEN_IS_128x64) || defined(SCREEN_IS_WEMOS32) || defined(SCREEN_IS_HELTEC)
  // Initialising the UI will init the display too.
  display.drawString(0, 0, "Device Name: ");
  display.drawString(64, 0, DEVICE_NAME);
  display.drawString(0, 12, "Try connect ");
  display.display();
#endif

#ifdef SCREEN_IS_TTGO
  tft.print("Device Name: ");
  tft.println(DEVICE_NAME);
  tft.println("Try connect...  ");
#endif

  // Networking and Time
  getWiFi();

  digitalWrite(BLULED, false);

#if defined(SCREEN_IS_64x48) | defined(SCREEN_IS_128x64) | defined(SCREEN_IS_WEMOS32) || defined(SCREEN_IS_HELTEC)
  sprintf(charbuff, "IP= ..%03d.%03d", ip[2], ip[3]);
  display.drawString(0, 24, charbuff);
  display.drawString(0, 36, "Connected");
  display.display();
  delay(2000);
#endif

#ifdef SCREEN_IS_TTGO
  tft.print("Connected to: ");
  tft.println(WIFI_SSID);
  sprintf(charbuff, "IP= %03d . %03d . %03d . %03d", ip[0], ip[1], ip[2], ip[3]);
  tft.println(charbuff);
#endif

  getNTP();
  delay(6000);
  getEpoch();  // writes the Epoch (Numbers of seconds till 1.1.1970...
  Serial.print("Got Epoch, ");
  getTimeData();  // breaks down the Epoch into discrete values.
  sprintf(charbuff, "Now: %02d:%02d, %02d %s %04d", Hour, Minute, Day, MonthName, Year);
  Serial.println(charbuff);

#if defined(SCREEN_IS_64x48) | defined(SCREEN_IS_128x64) | defined(SCREEN_IS_WEMOS32) || defined(SCREEN_IS_HELTEC)
  display.drawString(0, 60, charbuff);
  display.display();
#endif

#ifdef SCREEN_IS_TTGO
  tft.println(charbuff);
#endif

  initOTA();
//  ArduinoOTA.setHostname(DEVICE_NAME);
  Serial.print("Start OTA, ");
  ArduinoOTA.begin();
  delay(500);

#ifndef UDP_IS_NONE
  UDP.begin(ESP_UDP_PORT);
  Serial.printf("Start UDP: %u\n", ESP_UDP_PORT);
#endif

  Serial.print("Menu ready on ");
#if defined(TERM_IS_SOFTSER)
  Serial.println("SoftSerial");
#endif

#if defined(TERM_IS_SERIAL)
  Serial.println("Serial");
#endif

#if defined(TERM_IS_TELNET)
  TelnetStream.begin();
  Serial.println("Telnet"),
  Serial.flush();
  delay(500);
#endif

#if defined(D7_IS_VICTRON) || defined(D7_IS_DROK) && defined(ARDUINO_ARCH_ESP8266)
  Serial.println("Serial Swap to D7/D8");
  Serial.flush();
  delay(500);
  Serial.swap();
#endif

#if defined(D7_IS_VICTRON) && defined(ARDUINO_ARCH_ESP32)
  Serial.println("Serial start on GPIO16,17");
  Serial2.begin(SERIAL_SPEED);
#endif

#if defined INA_IS_226
  // INA 226 Panel Sensor
  INA.begin(AMPERE0, SHUNT0, 0);          // Define max Ampere, Shunt value, Address
  INA.setBusConversion(100);              // Maximum conversion time 100ms
  INA.setShuntConversion(100);            // Maximum conversion time 100ms
  INA.setAveraging(32);                   // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH);  // Bus/shunt measured continuously
  //  INA.alertOnPowerOverLimit(true;450000); //Set alert when power over 45W.
  Serial.println("\nINA Ready");
#endif

#ifdef WEATHER_SOURCE_IS_BME680  // Local Temperature / Pressure / Humidity sensor
  if (not bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }
bme.setTemperatureOversampling(BME680_OS_8X);
bme.setHumidityOversampling(BME680_OS_2X);
bme.setPressureOversampling(BME680_OS_4X);
#endif

#if defined(DASHBRD_IS_THINGER)
  // *** Thinger configuration ***
  // definition of structures for transmission
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  // resource output example (i.e. reading a sensor value) https://docs.thinger.io/coding#define-output-resources
  // https://docs.thinger.io/coding#read-multiple-data
  // it is a bit confusing, but Thinger code placed in setup will be executed when required by the payload.

  // Device
  thing["menu"] << [](pson& in) {
    displayPage = in["displayPage"];
    displaySubPage = in["displaySubPage"];
    serialPage = in["serialPage"];
    wirelessPage = in["wirelessPage"];
  };

  thing["measure"] >> [](pson& out) {
    out["PanV"] = payload.PanV;
    out["PanI"] = payload.PanI;
    out["PanW"] = payload.PanW;
    out["BatV"] = payload.BatV;
    out["BatI"] = payload.BatI;
    out["BatW"] = payload.BatW;
    out["BatI"] = payload.BatI;
    out["LodW"] = payload.LodW;
    out["LodI"] = payload.LodI;
    out["Iohm"] = payload.IOhm * 1000;
    out["CStr"] = StateKeywords[payload.ChSt];
    out["PoC"]  = BatPoC;
    out["CelV"] = CellV;
  };

  thing["weather"] >> [](pson& out) {
    out["temperature"] = temperature;
    out["humidity"] = humidity;
    out["pressure"] = pressure;
    out["wind"] = wind_speed;
    out["direction"] = wind_direction;
    out["cloudiness"] = cloudiness;
    out["summary"] = weather_summary;
  };

  thing["DAY"] >> [](pson& out) {
    out["BAhDay"] = BatAh[27];
    out["B00Ah"] = BatAh[0];
    out["B01Ah"] = BatAh[1];
    out["B02Ah"] = BatAh[2];
    out["B03Ah"] = BatAh[3];
    out["B04Ah"] = BatAh[4];
    out["B05Ah"] = BatAh[5];
    out["B06Ah"] = BatAh[6];
    out["B07Ah"] = BatAh[7];
    out["B08Ah"] = BatAh[8];
    out["B09Ah"] = BatAh[9];
    out["B10Ah"] = BatAh[10];
    out["B11Ah"] = BatAh[11];
    out["B12Ah"] = BatAh[12];
    out["B13Ah"] = BatAh[13];
    out["B14Ah"] = BatAh[14];
    out["B15Ah"] = BatAh[15];
    out["B16Ah"] = BatAh[16];
    out["B17Ah"] = BatAh[17];
    out["B18Ah"] = BatAh[18];
    out["B19Ah"] = BatAh[19];
    out["B20Ah"] = BatAh[20];
    out["B21Ah"] = BatAh[21];
    out["B22Ah"] = BatAh[22];
    out["B23Ah"] = BatAh[23];

    out["BVDay"] = BatVavg[27];
    out["B00V"] = BatVavg[0];
    out["B01V"] = BatVavg[1];
    out["B02V"] = BatVavg[2];
    out["B03V"] = BatVavg[3];
    out["B04V"] = BatVavg[4];
    out["B05V"] = BatVavg[5];
    out["B06V"] = BatVavg[6];
    out["B07V"] = BatVavg[7];
    out["B08V"] = BatVavg[8];
    out["B09V"] = BatVavg[9];
    out["B10V"] = BatVavg[10];
    out["B11V"] = BatVavg[11];
    out["B12V"] = BatVavg[12];
    out["B13V"] = BatVavg[13];
    out["B14V"] = BatVavg[14];
    out["B15V"] = BatVavg[15];
    out["B16V"] = BatVavg[16];
    out["B17V"] = BatVavg[17];
    out["B18V"] = BatVavg[18];
    out["B19V"] = BatVavg[19];
    out["B20V"] = BatVavg[20];
    out["B21V"] = BatVavg[21];
    out["B22V"] = BatVavg[22];
    out["B23V"] = BatVavg[23];
  };

  thing["HOUR"] >> [](pson& out) {
    out["BatV"] = payload.BatV;
    out["BatI"] = payload.BatI;
    out["BatW"] = payload.BatW;
    out["PanI"] = payload.PanI;
    out["PanV"] = payload.PanV;
    out["PanW"] = payload.PanW;
    out["Ohm"] = payload.IOhm;
    out["BatAh"] = BatAh[25];
    out["percent_charged"] = payload.ChSt;

    out["temperature"] = temperature;
    out["humidity"] = humidity;
    out["pressure"] = pressure;
    out["wind"] = wind_speed;
    out["direction"] = wind_direction;
    out["summary"] = weather_summary;
  };

  thing["MIN"] >> [](pson& out) {
    out["BatI"] = payload.BatI;
    out["BatV"] = payload.BatV;
    out["BatW"] = payload.BatW;
    out["PanI"] = payload.PanI;
    out["PanV"] = payload.PanV;
    out["PanW"] = payload.PanW;
    out["BatI"] = payload.BatI;
    out["LodW"] = payload.LodW;
    out["BatAh"] = BatAh[24];  //  Current Hour
  };

  thing["EVENT"] >> [](pson& out) {
    out["BatI"] = payload.BatI;
    out["BatV"] = payload.BatV;
    out["PanV"] = payload.PanV;
    out["BatI"] = payload.BatI;
    out["BatAh"] = BatAh[25];
  };

  //Communication with Thinger.io
  thing.handle();
  delay(1000);  // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
  thing.get_property("persistance", persistance);
  currentInt = persistance["currentInt"];
  nCurrent = persistance["nCurrent"];
  temperature = persistance["temperature"];
  humidity = persistance["humidity"];
  pressure = persistance["pressure"];
  wind_speed = persistance["wind"];
  wind_direction = persistance["direction"];

  pson input;
  thing.get_property("input", input);
  resetCoulomb = input["resetCoulomb"];
  restart = input["restart"];
  freezePsonUpdate = input["freezePsonUpdate"];

  pson statAh;
  thing.get_property("statAh", statAh);  // 0..23=hour, 25=payload.PanI, 26=statAh 24h, 27= BatAhDay, 28=BatAhNight, 29=BatAh22-24
  BatAh[0] = statAh["00h"];
  BatAh[1] = statAh["01h"];
  BatAh[2] = statAh["02h"];
  BatAh[3] = statAh["03h"];
  BatAh[4] = statAh["04h"];
  BatAh[5] = statAh["05h"];
  BatAh[6] = statAh["06h"];
  BatAh[7] = statAh["07h"];
  BatAh[8] = statAh["08h"];
  BatAh[9] = statAh["09h"];
  BatAh[10] = statAh["10h"];
  BatAh[11] = statAh["11h"];
  BatAh[12] = statAh["12h"];
  BatAh[13] = statAh["13h"];
  BatAh[14] = statAh["14h"];
  BatAh[15] = statAh["15h"];
  BatAh[16] = statAh["16h"];
  BatAh[17] = statAh["17h"];
  BatAh[18] = statAh["18h"];
  BatAh[19] = statAh["19h"];
  BatAh[20] = statAh["20h"];
  BatAh[21] = statAh["21h"];
  BatAh[22] = statAh["22h"];
  BatAh[23] = statAh["23h"];
  BatAh[24] = statAh["CurrHour"]; 
  BatAh[25] = statAh["Last Hour"];
  BatAh[26] = statAh["Today"];
  BatAh[27] = statAh["Yesterday"];
  BatAh[28] = statAh["D-2"];
  BatAh[29] = statAh["D-3"];
  BatAh[30] = statAh["D-4"];
  BatAh[31] = statAh["D-5"];
  BatAh[32] = statAh["D-6"];
  BatAh[33] = statAh["D-7"];

  pson statVh;
  thing.get_property("statVh", statVh);  // 0..23=hour, 25=payload.PanI, 26=statVh 24h, 27= BatAhDay, 28=BatAhNight, 29=BatAh22-24
  BatVavg[0] = statVh["00h"];
  BatVavg[1] = statVh["01h"];
  BatVavg[2] = statVh["02h"];
  BatVavg[3] = statVh["03h"];
  BatVavg[4] = statVh["04h"];
  BatVavg[5] = statVh["05h"];
  BatVavg[6] = statVh["06h"];
  BatVavg[7] = statVh["07h"];
  BatVavg[8] = statVh["08h"];
  BatVavg[9] = statVh["09h"];
  BatVavg[10] = statVh["10h"];
  BatVavg[11] = statVh["11h"];
  BatVavg[12] = statVh["12h"];
  BatVavg[13] = statVh["13h"];
  BatVavg[14] = statVh["14h"];
  BatVavg[15] = statVh["15h"];
  BatVavg[16] = statVh["16h"];
  BatVavg[17] = statVh["17h"];
  BatVavg[18] = statVh["18h"];
  BatVavg[19] = statVh["19h"];
  BatVavg[20] = statVh["20h"];
  BatVavg[21] = statVh["21h"];
  BatVavg[22] = statVh["22h"];
  BatVavg[23] = statVh["23h"];
  BatVavg[25] = statVh["LastHour"];
  BatVavg[27] = statVh["Today"];
  BatVavg[28] = statVh["Yesterday"];
  BatVavg[29] = statVh["D-2"];
  BatVavg[30] = statVh["D-3"];
  BatVavg[31] = statVh["D-4"];
  BatVavg[32] = statVh["D-5"];
  BatVavg[33] = statVh["D-6"];
  BatVavg[34] = statVh["D-7"];
#endif  // defined (DASHBRD_IS_THINGER)

#ifdef COM_IS_HOURLY
  // print the header for the UDP report
  UDP.beginPacket(COM_UDP_ADDR, COM_UDP_PORT);
  sprintf(charbuff, " \nHourly Report");
  UDP.print(charbuff);
  UDP.print("\n   Date Hour   | Bat Ah   | Bat Volt  | Weather");
#endif

  // *** Defaults to start with ***
  wirelessPage = ' ';
  serialPage = ' ';
  displayPage = '1';

  payload.BatV = float(cha[5] * NUMBER_CELLS) / 100;  // Begin with 1/2 charged cells
  payload.IOhm = 0.0154; 
  payload.LodI = float(AH_CELLS) / 51;

  digitalWrite(GRNLED, false);

  delay(10000);

#ifdef SCREEN_IS_TTGO
  tft.fillScreen(TFT_BLACK);
#endif

}  //End Setup
