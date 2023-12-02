Victron_VE_on_Steroids can be controlled remotely using Telnet.

Upon booting the ESP reports its IP address on the serial monitor, after finishing initialization the Serial UART is swapped to Victron and the communication goes forth on Telnet.

Telnet [the IP of the ESP] enters the menu.  (On Windows you might have to install Telnet separately)

The menu is based on single character terminated by [return]

[space]   stops report end enters snooze mode (doing nothing)
Z         resets the ESP
Q         quits Telnet. You can reconnect by typing Telnet [the IP of the ESP] again
A         prints the A0 report (just showing the A0 value, will be replaced by the Ah report later
D         prints the Debugging report (content variable depending on what to debug) 
V         Prints the Values as Floating values
I         Prints the Victron Internal representation of the transmitted information
J         Prints a Job report showing how many mS every task takes.
j         Resets the max counter for every job.

more commands will come.
