#include <stdio.h>
#include "./flagutils.h"

int main (int argc, char *argv[]) {
	int flagVal = flagch(argc,argv);
	printf("%d\n", flagVal);
}
