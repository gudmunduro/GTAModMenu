			This menu base was used in Menyoo (a fcn beast), but due to signed/unsigned probs, that went to sh*t.
											See ya next month.
									This sh*t should be simple enough.
			It's using namespaces cuz hiding sh*t doesn't stick, and doing it in header files f*cks the compile up.
				CREDITS: Alejandro [ScriptHook V], MAFINS [Menya Baes], 2much4u [xsc menu scroll]. 


// Keep in mind that wherever I say 'string', I actually mean char or char*.

Bugs:
1. Option Breaks (they're a thing) are counted as options. So they'll be in the option count. I tried fixing it using l33t hax
but unfortunately it'll require more changes to the base, so fk it. They're ugly anyway.
2. Different screen resolutions will mess different sh*t up.


// This section contains info on how to do sh*t, ya n00bs.

Subroutines:

AddTitle << Add a title : [1st parameter = string]; // Title shouldn't be over 32 characters.

AddOption << Add a normal option : [1st = string] & [2nd = variable you want to set to true / Make null if none] & [3rd = void (void) function you want to execute / make nullFunc if none] & [4th = submenu index *enum* / leave parameter if none];

AddToggle << Add a toggleable (looped) ON/OFF option : [1st = string] & [2nd = boolean variable that you want to inverse] & [3rd = boolean for option ON or when the loop bool is set to false] & [4th = boolean for option OFF or when the loop bool is set to true];

AddLocal << Add a toggleable ON/OFF option which runs on a condition : [1st = string] & [2nd = condition *variable or function*] & [3rd = boolean for option ON or when the condition is false] & [4th = boolean for option OFF or when the condition is true];

AddBreak << Adds an ugly option break ('tis like a sub title and it f*cks sh*t up) : [1st = string];

AddNumber << Adds an option with a horizontal scroller for a long/float/int variable/function : [1st = string] & [2nd = value] & [3rd = decimal places] & [4rd = bool variable for option press] & [5th = bool variable for right/NUM6 press] & [6th = bool variable for left/NUM4 press];

AddteleOption << Adds an option for teleporting to specific coords (idek why) : [1st = string] & [2nd = X coord] & [3rd = Y coord] & [4th = Z coord] & [5th = bool to set to true for executing extra option code];


keyboard << Pull open the keyboard for input. Pressing Enter will return the input : no params;

AddStrings << Concatenate 2 strings : [1st = first char(*)] & [2nd = second char(*)];

AddInt_S << Add an integer to the end of a string : [1st = char* string] & [2nd = integer];

StringToInt << Uses a native function (not stoi/atoi) to convert a char(*) to an integer : [1st = string];

VectorToFloat << Store the values of a Vector3 (struct) in an array : [1st: Vector3] & [2nd: Array pointer];

PrintStringBottomCentre << Print a message at the bottom of the screen : [1st = string];

PrintFloatBottomCentre << Print a message at the bottom of the screen : [1st = float value] & [2nd = decimal places];

Check_compare_string_length << Check the length of one string with an amount. Retuns true if less than or equal to the amount/range : [1st = string] & [2nd = max size];


setupdraw << Set text attributes to the Baes defaults (via natives) : no params;

drawstring << Draw a string on the screen : [1st = string] & [2nd = X coord] & [3rd = Y coord];

drawinteger << Draw an integer on the screen : [1st = integer] & [2nd = X coord] & [3rd = Y coord];

drawfloat << Draw a float on the screen : [1st = float] & [2nd = decimal places] & [3nd = X coord] & [4rd = Y coord];

------------------------------------------------------------------------------------------------------

Guide:

How to add a submenu:
	
	1. Open the namespace 'SUB' and the enum within it (if collapsed) and add an enumerator for a new submenu.
	2. Now in menu::submenu_switch, make a case to call your submenu, 
																	e.g. case SUB::YOURSUB: sub::YourSub(); break;
	3. Now in namespace 'sub', define + declare your submenu procedure.
																	e.g. void YourSub()  { --code-- };

	4. Smd.


How to change opening binds:
	
	1. In the function menu::isBinds(), change the binds, ya wee faeg. // The default binds are RB+LB / NUM4 + NUM6
	2. Smd


How to make L33T H4X:

	1. Consult step 4 of the submenu creation guide.
