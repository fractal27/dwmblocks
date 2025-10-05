//Modify this file to change what commands output to your statusbar, and recompile using the make command.

//
// if you want to change location, you should create location.h
// that contains the location of the city that you want to use
// this is so, the developers of the project can use its repository AND
// not redact every time the city they live in for PRIVACY reasons.
//
// #include "location.h" // defines LOC

#ifndef LOC
#define LOC
#endif
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                                /*Update Interval*/	/*Update Signal*/
	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }'",	                30,		0},
	{"Weather:", "LOC=" LOC ";weather",	                                                    1000,   0},
	{"", "date '+%b %d (%a) %I:%M%p'",					                    5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
