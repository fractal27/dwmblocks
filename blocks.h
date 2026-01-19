//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define NO_SIGNAL  0


static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal(SIGSEGV,ecc...)*/
	{" Mem: \3 ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }'",						30,     NO_SIGNAL},
	{" Eth: ",
		"VAR=$(ip a | grep eno1\\: | awk '// {print $9;}');"
		"if [ \"$VAR\" = \"UP\" ]; then"
		"	printf '\\6 '$VAR;"
		"else printf '\\7 '$VAR;"
		"fi",																		2,		NO_SIGNAL},
	{" Date: \5 ", "date '+%d (%a) %H:%M:%S'",										1,		NO_SIGNAL},
	{" hdd: \4 ", "df -h /|tail -1|rev|cut -d ' ' -f2|rev",							50,		NO_SIGNAL}
};

// \3, \4 \5 are the colorschemes

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char startdelim[] = "";
static char delim[] = " \1 ";
static char enddelim[] = " ";
static unsigned int delimLen = sizeof(delim) / sizeof(char);
static unsigned int startdelimLen = sizeof(startdelim) / sizeof(char);
static unsigned int enddelimLen = sizeof(enddelim) / sizeof(char);
