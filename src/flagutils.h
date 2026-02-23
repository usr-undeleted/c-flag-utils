#ifndef FLAG_UTILS_H
#define FLAG_UTILS_H

#include <string.h>
#include <stdlib.h>

/* this is all a bit over-commented because im scared i might forget how it works */

int flagchk(int argc, char *argv[]) { /* only checks argv[1]*/
	/* int used in returns, return -1 if failed, rest is added on */
	int flagVal = -1;

	/* array that contains all flags used in the project this will be in
	 starts with -h and --help by default, remove if those are uneeded */
	const char *pflags[] = {"--help","-h"};
	const int arrlen = sizeof(pflags) / sizeof(pflags[0]);

	// argc check, returns 0 if there is just one arg
	if (argc < 2) return flagVal;

	/* while loop that compares flag arg to entries in pflags then updates and returns the appropriate flagval */
	for (int i = 0; i < arrlen; i++) {
		if (strcmp(argv[1], pflags[i]) == 0) {
			flagVal = i;
			return flagVal;
		}
	}
	return flagVal;
}
// ^ old code, should only be used if you want more simplicity. will be kept here because im proud of it <3

int *mapflags(int argc, char *argv[], int arr[]) { /* make an array in heap memory containing entries, checks all args */
	const char *pflags[] = {"--help","-h"};
	const int tflags = sizeof(pflags) / sizeof(pflags[0]);

	for (int i = 0; i < argc; i++) {
		arr[i] = -1; /* by default, entry is -1 as it didnt find a match */

		for (int j = 0; j < tflags; j++) { /* j will be the entry of pflags incase there is a match */
			if (strcmp(argv[i], pflags[j]) == 0) { /* if the entry matches one of the entries inside pflags*/
				arr[i] = j; /* pflags gets translated into an int (j) and then put into map */
				break;
			}
		}
	}
	return arr;
}

#endif
