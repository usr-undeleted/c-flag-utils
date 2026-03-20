#ifndef FLAG_UTILS_H
#define FLAG_UTILS_H

#include <complex.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

// check all args and see if they match SPECIFIC
// flags. Good for stuff like '--mkdir' in mount, for example
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

// check for a '-' or '--' in argv[n], and with
// a struct, define toggles in a struct incase
// flag matched are found. return struct at the end
// remember that YOU have to edit this as needed
// ^ good for checking single chars, not stuff like
// '--'

// define struct, edit as needed
typedef struct {
    int H_EXISTS;
    int I_EXISTS;
    int F_EXISTS;
    int INVALID_FLAG; // incase user puts wrong input
    int NO_FLAG; // incase no flag is even inputted
} FOUND_FLAGS;

// find all args with '-',
// start loop that uses funcs to loop
// trough chars after '-', see if they match entries,
// return edited struct if successful, return error
// if failed, return NULL

static inline FOUND_FLAGS getflagstruct (int argc, char *argv[], FOUND_FLAGS s) {

    // toggle that will see if no valid flags
    // were found (therefore, chk = 0)
    int chk = 0;

    // first loop will cycle trough all args
    for (int i = 1; i < argc; i++) {

        // check if '-' exists
        if (argv[i][0] == '-') {

            // second loop to check all chars
            // after '-'
            for (int j = 0; j < strlen(argv[i]); j++) {

                if (argv[i][1] == '\0') { // incase no flag is even inputted
                    s.NO_FLAG = 1;
                    break;
                }

                // compare all chars
                // this is where youll edit the header
                chk = 0;
                if (argv[i][j] == 'h') {
                    s.H_EXISTS = 1;
                    chk++;
                } else if (argv[i][j] == 'i') {
                    s.I_EXISTS = 1;
                    chk++;
                } else if (argv[i][j] == 'f') {
                    s.F_EXISTS = 1;
                    chk++;
                }
            }
        }
    }

    // incase an invalid flag is found
    if (!chk) {
        s.INVALID_FLAG = 1;
    }

    return s;
}

#endif
