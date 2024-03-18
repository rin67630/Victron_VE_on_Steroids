# Victron_VE_on_Steroids
Use an ESP to log values from Victron devices and much, much more.  

The project now has several options:  
a) plain Victron logger from the VE-direct port.  
b) Vendor-agnostic smart shunt based on the INA226 chip and an extra shunt.  
c) Extra-voltage measurement that can be used to measure half-battery voltage or double battery voltage*  
d) BME386 Temp/Pressure/Humidity monitoring

Please have a look on the schematic diagram:
https://github.com/rin67630/Victron_VE_on_Steroids/tree/main/Hardware/Victron-on-Steroids-Smarter-Shunt_Schematic.png
(if you just want a Victron logger, you just need a Wemos D1, a micro bucket converter and a few wires).

## Victron_VE_on_Steroids design

Victron_VE_on_Steroids is designed to deliver the full power of SCC / battery logging on a single ESP8366 device ($4).
You just don't need any additional hardware, nor computer, nor gateway, nor subscription. 
You see gorgeous dashboards wordwide on the Internet, can downloads historic data to Excel etc.

But Victron_VE_on_Steroids is designed for more. It is an ecosystem. You use one ESP8266 for one SCC and a battery.  
The devices can communicate in the LAN over the UDP protocol and exchange their measurements.  
You can e.g. use a second remote ESP moduel with a display to display your values in the living room. Wirelessly, of course.

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
For that sake i am using the free basic services of Thinger.io  
https://github.com/rin67630/Victron_VE_on_Steroids/blob/main/Documentation/Thinger.io.md

I have used Thinger for a couple of other projects like Drok-Juntek-on Steroids, which is a Home Brew MPPT controler built on commercial buck converters.  
https://github.com/rin67630/Drok-Juntek-on-steroids. I could re-use a lot of code from this project on Victron-on Steroids.  
The current default Thinger Screen with a one minute pace looks like that:   
![image](https://github.com/rin67630/Victron_VE_on_Steroids/assets/14197155/c0101e71-e32b-41d9-9b46-56e4ddd9a320)  
You can get a one second-pace as well (however only building up when page is active to limit server load)
![image](https://github.com/rin67630/Victron_VE_on_Steroids/assets/14197155/3b21a957-1d55-4a91-ba97-a3c7f1078e52)   
Finally you can see the MPPT algorithm working!

But everyone is free to design his own dashboard online !  
You can get all that from a cheap ESP8266 like a Wemos D1 clone for less than 4$. 

## Remote screen
Additionally, a remote display running on an ESP32 TTGO T1 (~20$) is an optional part of the ecosystem:  
![image](https://github.com/rin67630/Victron_VE_on_Steroids/assets/14197155/f60c3fa4-3f4f-4f22-b111-eb11b96d373e)  
You can switch between the 6 screens using the 2 hardware buttons of the TTGO module, or over the Telnet Menu using your computer. 
The communication occurs over WiFi, not using the range limited  Bluetooth.


## Work progress
 
- Victron Input processing:  Working for SmartSolar 75/15, looking for confimations for other modules especially SmartShunts.  
- Victron Input Translation: Working  
- Shunt INA 226 input processing : Working  
- A0 input processing: Easy, but not yet done.
- OLED Display: Working
- Weather Data: Working
- Thinger dashboard: Working  
- Serial communication: Working for Telnet, SoftwareSerial and Serial (on receiver only)  
- UDP synchronization between Sender-Receiver: Working
- Evaluation of battery internal resistance: apparently Working, plausible results.
- Evaluation of SOC: ideas not yet done. 
- Making integration data reset-proof: Working  
- Coulomb counting by hours: Working  
- Streamlined configuration, Switching options: Working  
- Menu over Serial, Telnet, SoftwareSerial: Working  
- Reports: Working

## My Todo List
- ESP32 Gateway and Domotic processing  Transmission working, need to convert the program to handle all data in arrays 
- Battery capacity measurement (over full cycle) currently doable with the existing B report  
- Other domotic sensors (Temperature, Humidity, Light flash counter, whatever...)
- Other domotic actuators (Relays, Heating valves, Sender for wireless plugs...
- Documentation, documentation, documentation...

## Input required !
- Test with other Victron products  
- Provide other manufacturer serial processing?  
- Provide algorithm to evaluate SOC  
- Provide input for Battery capacity measurement (over full cycle)  
- Proofread my documentation tell me where it's hard to understand. 
- Make the Victron serial processing working without configutation files  
- Reasonable improvement suggestions, especially to streamline the code (while keeping readability)




More to come...


