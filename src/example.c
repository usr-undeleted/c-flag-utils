#include <stdio.h>
#include <stdlib.h>
#include "flagutils.h"

void fhelp(int num); /* -h and --help */

int main (int argc, char *argv[]) {
		int *arrPointer = mapflags(argc, argv);
		if (arrPointer != NULL) { /* incase the arr isnt null, its set to null if the memory fails to allocate */
			for (int i = 0; i < argc; i++) {
				printf("Argc %d (%s) returned: %d\n", i, argv[i], arrPointer[i]);
			}
		}

		free(arrPointer); /* de-allocate memory */
		arrPointer = NULL; /* set pointer to null to prevent bad de-references */
		/* ^ new func that uses all args, old func below */
		printf("---\n"); /* cosmetic separator */

		if (argc == 2) { /* can be just argc > 1 */
			int val = flagchk(argc,argv);
			printf("Returned argv[1] val:%d\n", val);

		} else printf("Invalid num of args!\n");
		return 0;
}

void fhelp(int argc) { /* help function */
	printf("Help message!\n");
}
