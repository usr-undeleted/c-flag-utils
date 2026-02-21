#ifndef FLAG_UTILS_H
#define FLAG_UTILS_H

#include <stdio.h>
#include <string.h>

int flagch(int argc, char *argv[]) {
	// int used in returns, return 0 if failed, rest is added on
	int flagVal = 0;
	// array that contains all flags used in the project this will be in
	// starts with -h and --help by default, remove if those are uneeded
	const static char *pflags[] = {"--help","-h"};

	// argc check
	if (argc != 2) return flagVal;

	// checks for flags
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		flagVal = 1;
		return flagVal;
	}
	return 0;
}

#endif
