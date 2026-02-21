#include <stdio.h>
#include "./flagutils.h"

int main (int argc, char *argv[]) {
	int flagVal = flagchk(argc,argv); /* sets flagVal to the output of flag */
	printf("%d\n", flagVal);
}
