# Victron_VE_on_Steroids
Use an ESP to log values from Victron devices and much more.  
The project now has several options:  
a) plain Victron logger from the VE-direct port.  
b) Vendor-agnostic smart shunt based on the INA226 chip and an extra shunt.  
c) Extra-voltage measurement that can be used to measure half-battery voltage or double battery voltage*  

Please have a look on the schematic diagram:
https://github.com/rin67630/Victron_VE_on_Steroids/tree/main/Hardware/Victron-on-Steroids-Smarter-Shunt_Schematic.png
(if you just want a Victron logger, you just need a Wemos D1, a micro bucket converter and a few wires).

## History
The project started with forking https://github.com/datjan/esp8266-victron-mppt-solarchargecontroller.
From that I created a variant that does not use SoftwareSerial (a resource hog) and reports on Telnet instead:
https://github.com/rin67630/esp8266-victron-mppt-solarchargecontroller-Telnet

Then having the primary measurements, I decides to go further and provide additional information derived from the given data:
- Power values where not provided  
- Battery monitoring (internal resistance, SOC)  
- long time integrations (battery capacity, Coulomb integration, Hourly statistics etc...)  

For these last functions one need a data persistance that survives resets and also the ability to enter some variables.
EEPROM is... Bah. Not really useful if you need to swap ESP devices.  

So comes the time to introduce __thinger.io__ :  
Thinger is a dashboard SaaS that let you use two devices free of charge. Forever.  
Thinger does _not_ primarily use MQTT. It uses a proprietary JSON based transmission directly from the device to the servers of thinger.io  
You don't need a broker and you are not limited by broker's restriction on how fast you transmit data. Sub-second updates are not a problem.  
And Thinger provides Device Properties storage, that is much more powerful than EEPROM.  
Thinger does _not_ need a Grafana server to build Dashboards. You can do that directly on-site.  

So the bottom line: with thinger.io you don't need nothing more than your ESP device and a WiFi internet connection. 
No additional computer, no broker, no subscription. No cost (for 2 devices).  
You get:  
- gorgeous dashboards, (up to 4 free of charge)  
- buckets to store long term data (up to 4 free of charge)  
- device properties (up to 4 free of charge)  

I have used Thinger for a couple of other projects like Drok-Juntek-on Steroids, which is a Home Brew MPPT controler built on commercial buck converters.  
https://github.com/rin67630/Drok-Juntek-on-steroids   
(you can have a look there to see the dashboards and onboard screens)  
I can re-use a lot of code from this project on Victron-on Steroids.  

More to come...


