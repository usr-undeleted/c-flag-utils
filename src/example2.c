#include <flagutils.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    // initialize struct with all zeroes
    FOUND_FLAGS s = { 0 };

    if (argc < 2) {
        fputs("You need atleast 1 argument!\n", stderr);
        return 1;
    }

    s = getflagstruct(argc, argv, s);

    if (s.NO_FLAG) {
        fputs("You didn't input any chars!\n", stderr);
        return 3;
    }

    // incase an invalid flag is found
    if (s.INVALID_FLAG) {
        fputs("You used an invalid flag!\n" , stderr);
        return 2;
    }

    printf("H_EXISTS = %d\nI_EXISTS = %d\nF_EXISTS = %d\n", s.H_EXISTS, s.I_EXISTS, s.F_EXISTS);

    return 0;
}
