#ifndef FLAG_UTILS_H
#define FLAG_UTILS_H

#include <string.h>
#include <stdlib.h>

/* this is all a bit over-commented because im scared i might forget how it works */

int flagchk(int argc, char *argv[]) { /* only checks argv[1]*/
	/* -1 if fail, 0-x if succesful */
	int flagVal = -1;

	/* array that contains all flags used in the project this will be in
	 starts with -h and --help by default, remove if those are uneeded */
	const char *pflags[] = {"--help","-h"};
	const int arrlen = sizeof(pflags) / sizeof(pflags[0]);

	/* return -1  */
	if (argc < 2) return flagVal;

	/* compares arg to all entries and returns val */
	for (int i = 0; i < arrlen; i++) {
		if (strcmp(argv[1], pflags[i]) == 0) {
			flagVal = i;
			return flagVal;
		}
	}
	return flagVal;
}
// ^ old code, only checks argv[1]

int *mapflags(int argc, char *argv[], int arr[]) { /* get arr from caller */
	const char *pflags[] = {"--help","-h"};
	const int tflags = sizeof(pflags) / sizeof(pflags[0]);
	memset(arr,-1,sizeof(*arr));

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
