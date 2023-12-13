Victron_VE_on_Steroids can be controlled remotely using Telnet.

Upon booting the ESP reports its IP address on the serial monitor, after finishing initialization the Serial UART is swapped to Victron and the communication goes forth on Telnet.  

Telnet [the IP of the ESP] enters the menu.  (On Windows you might have to install Telnet separately)  

The menu is based on single character terminated by [return]  

[space]   stops *periodic* reports and enters snooze mode (doing nothing)  
Z resets the ESP, which will reboot
Q quits Telnet. You can reconnect by typing Telnet [the IP of the ESP] again (does nothing on Serial)  
A prints the A0 report (just showing the A0 value, will be replaced by the Ah report later  
D *prints the Debugging report (content variable depending on what to debug)*   
V *prints the Values as Floating values*
S swaps the serial port between Victron EV read and Serial monitor  
I prints the Victron Internal representation of the transmitted information   
J *prints a Job report showing how many mS every task takes*   
j resets the max counter for every job 

more commands will come.
