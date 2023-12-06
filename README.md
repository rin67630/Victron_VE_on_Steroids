# Victron_VE_on_Steroids
Use an ESP to log values from Victron devices and much more.
The project now has several options:  
a) plain Victron logger from the VE-direct port.  
b) Vendor-agnostic smart shunt based on the INA226 chip and an extra shunt.  
c) Extra-voltage measurement that can be used to measure half-battery voltage or double battery voltage*  

Please have a look on the schematic diagram:
https://github.com/rin67630/Victron_VE_on_Steroids/blob/main/Victron-on-Steroids-Smarter-Shunt_Schematic.png
(if you just want a Victron logger, you just need a Wemos D1, a micro bucket converter and a few wires).


*the INA226 chip can measure up to 36V off-rails. Also the small DC-DC converters are usually limited to 40V max.  
So if you have a 48V battery system, you must feed the measurement from the lowest 24V battery, and use the extra-voltage measurement to get the full battery voltage.  
If you have two 12V batteries and a 24V system, you feed the measurement normally from 24V and use the extra-voltage measurement to get the half battery voltage.  

## History
The project started with forking https://github.com/datjan/esp8266-victron-mppt-solarchargecontroller.
From that I created a variant that does not use SoftwareSerial (a resource hog) and reports on Telnet instead:
https://github.com/rin67630/esp8266-victron-mppt-solarchargecontroller-Telnet

Then having the primary measurements, I decides to go further and provide additional information derived from the given data:
- Power values where not provided  
- Battery monitoring (internal resistance, SOC)  
- long time integrations (battery capacity, Coulomb integration etc...)  

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

So comes time to introduce __Karajan__:  
Karajan is a framework and collaborative scheduler that I wrote years ago to facilite my developments on Arduino/ESP devices.  
I am an engineer, not a programmer.   
I hate it, when programms are written in Volapük, (my expression to describe code that has nothing left with natural language).  
Karajan is written for flexibility: it works intensively with computer directives to adapt the code to different 
situations.  
The Arduino IDE has a great feature: tabs.  
Karajan makes use of the Tabs features of the Arduino IDE to split the code like an orchestral partition into clear subparts  
for each instrument (purpose):  
-Configuration  
-Credentials (not to be published)  
-Libraries and global variables  
-Network functions  
-User functions  
-Setup  
-Menu for user interaction.  
-Fast data (to be processed at 125mS pace)  
-Slow data (to be processed at 1S pace)  
-Statistics (to be processed at 1S pace)  
-Display (to be processed at 1S pace)  
-Serial communiction (to be processed at 1S pace)  
-Wireless comminucation (to be processed at 1S pace)  
and finally the scheduler itself.  
With that organisation the developer can easily jump to the desired part of the code to make correction without searching pages of code for the right place.  
All jobs to be processed at 1S pace are distributed in 125mS slices, so to dispatch the processing time and avoid to do 
everything at the same time.  
Karajan provides a measuring/reporting function for the time taken by every task.  

It provides all initializations for WiFi and time synchronization, so you can just start with your part.  

It provides variables to do a lot of stuff at given times and gives global variables as e.g.  
Bytes:  
- Second, Minute, Hour...  
Boolean:  
- NewMinute, MinuteExpiring, NewHour, HourExpiring and so forth..  
so you can write code to be executed at given times in natural language.  

https://github.com/rin67630/ESP8266_Karajan

More to come...


