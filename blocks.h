//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define NO_SIGNAL  0


static const Block blocks[] = {
	/*Icon*/	/*Command*/		                                /*Update Interval*/	/*Update Signal(SIGSEGV,ecc...)*/
	{"\3 Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }'",	                30,		NO_SIGNAL},
	// {"\4 Weather:", "weather",	                                                1000,   NO_SIGNAL},
	{"\5 ", "date '+(%a) %H:%M:%S'",					                            1,		NO_SIGNAL},
	{"\6 HDD:", "df -h /|tail -1|rev|cut -d ' ' -f2|rev",					    50,		SIGUSR1}
};

// \3, \4 \5 are the colorschemes

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char startdelim[] = "";
static char delim[] = " \1 ";
static char enddelim[] = " \1";
static unsigned int delimLen = sizeof(delim) / sizeof(char);
static unsigned int startdelimLen = sizeof(startdelim) / sizeof(char);
static unsigned int enddelimLen = sizeof(enddelim) / sizeof(char);
