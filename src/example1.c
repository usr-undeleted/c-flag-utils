#include <stdio.h>
#include <stdlib.h>
#include "flagutils.h"

void fhelp(int num); /* -h and --help */

int main (int argc, char *argv[]) {
	/* the array to be edited */
	int arr[argc];
	/* function usage: */
	mapflags(argc,argv,arr);

	/* array will be mapped out following the args */

		for (int i = 0; i < argc; i++) {
			printf("Argc %d (%s) returned: %d\n", i, argv[i], arr[i]);
		}
}

void fhelp(int argc) { /* help function */
	printf("Help message!\n");
}
