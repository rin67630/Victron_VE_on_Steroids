The project began as logger for my small Victron 75/15 SCC
It has now been extended to several options:
a) plain Victron logger from the VE-direct port.
b) Vendor-agnostic smart shunt based on the INA226 chip and an extra shunt.
c) Extra-voltage measurement that can be used to measure half-battery voltage or double battery voltage*

* Remark for Smart shunt Option: the INA226 chip can measure up to 36V off-rails. Also the small DC-DC converters are usually limited to 28V max.  
So if you have a 48V battery system, you must feed the measurement from the lowest 24V battery, and use the extra-voltage measurement to get the full battery voltage.   
If you have two 12V batteries and a 24V system, you feed the measurement normally from 24V and use the extra-voltage measurement to get the half battery voltage.

Please have a look on the schematic diagram:
https://github.com/rin67630/Victron_VE_on_Steroids/tree/main/Hardware/Victron-on-Steroids-Smarter-Shunt_Schematic.png
(if you just want a Victron logger, you just need a Wemos D1, a micro bucket converter and a few wires).

