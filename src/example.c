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
