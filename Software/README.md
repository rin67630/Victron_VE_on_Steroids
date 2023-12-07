This is a highly configurable project.

I am an engineer, not a programmer.  
I hate it, when programms are written in Volapük, (my expression to describe obfuscated code that has nothing left with natural language).  
My programs are written for flexibility and readabilty and are extensively commented and documented.

I use the Noob-friendly Arduino IDE to develop, which made great efforts to make things simple for no-programmers.   
That Arduino IDE has a great –but less used– feature: tabs.  
With tabs one can split the code into chunks doing a clearly defined task: 
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
-Serial communication (to be processed at 1S pace)  
-Wireless communication (to be processed at 1S pace)  
-Scheduler (the main task driving the others)

Beside that, definitions and constants specific to hardware options are moved to xxx.h configuration files located in the Config_Files 
located in the library folder of your default sketch folder. So you just include them to configure.

When you work on the project you frequently must adapt several parts e.g. the menu and the serial communication: with tabs you can just 
jump on the corresponding tab, the cursor ist where you left it last time.

That principle is defined in my framework project: Karajan https://github.com/rin67630/ESP8266_Karajan, which I reuse on every project.

The program works also intensively with computer directives to adapt the code to different situations/configurations. 
