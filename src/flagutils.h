#ifndef FLAG_UTILS_H
#define FLAG_UTILS_H

#include <string.h>
#include <stdlib.h>

/* get arr from caller */
int *mapflags(int argc, char *argv[], int arr[]) {
	/* the flags the program will check */
	const char *pflags[] = {"--help","-h","-i"};
	const int tflags = sizeof(pflags) / sizeof(pflags[0]);

	for (int i = 0; i < argc; i++) {
		arr[i] = -1; /* by default, entry is -1 as it didnt find a match */

		for (int j = 0; j < tflags; j++) {
			if (strcmp(argv[i], pflags[j]) == 0) {
				arr[i] = j;
				break; /* for i loop restarts for j loop */
			}
		}
	}
	return arr;
}

#endif
