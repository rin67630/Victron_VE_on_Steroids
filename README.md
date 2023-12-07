# Victron_VE_on_Steroids
Use an ESP to log values from Victron devices and much, much more.  

The project now has several options:  
a) plain Victron logger from the VE-direct port.  
b) Vendor-agnostic smart shunt based on the INA226 chip and an extra shunt.  
c) Extra-voltage measurement that can be used to measure half-battery voltage or double battery voltage*  

Please have a look on the schematic diagram:
https://github.com/rin67630/Victron_VE_on_Steroids/tree/main/Hardware/Victron-on-Steroids-Smarter-Shunt_Schematic.png
(if you just want a Victron logger, you just need a Wemos D1, a micro bucket converter and a few wires).

## Victron_VE_on_Steroids design

Victron_VE_on_Steroids is designed to deliver the full power of SCC / battery logging on a single ESP8366 device.
You just don't need any additional hardware. You see gorgeous dashborads wordwide on the Internet, can downloads historic data to Excel etc.

But Victron_VE_on_Steroids is designed for more. It is an ecosystem. You use one ESP8266 for one SCC and a battery.  
The devices can communicate in the LAN over the UDP protocol and exchange their measurements.  
You can e.g. use a second remote ESP8266 with a display to display your values in the living room. Wirelessly, of course.
And finally I project to programm an ESP32 to aggregate several ESP8266 mesurements to one single thinger.io dashboard.


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
For that sake i am using the services of Thinger.io  
https://github.com/rin67630/Victron_VE_on_Steroids/blob/main/Documentation/Thinger.io.md

I have used Thinger for a couple of other projects like Drok-Juntek-on Steroids, which is a Home Brew MPPT controler built on commercial buck converters.  
https://github.com/rin67630/Drok-Juntek-on-steroids   
(you can have a look there to see the dashboards and onboard screens)  
I can re-use a lot of code from this project on Victron-on Steroids.  

More to come...


