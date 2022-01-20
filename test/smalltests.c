#include "smalltests.h"
#include <stdio.h>

int _smalltests_passed = 0;
int _smalltests_total = 0;

void _assertNotEquals(char* message, uintmax_t unexpected, uintmax_t actual)
{
    printf("%s... ",message);
    if(unexpected != actual) {
        _smalltests_passed++;
        printf("Ok.\n");
    } else {
        printf("FAILED, unexpected %lx\n", (long unsigned) actual);
    }
    _smalltests_total++;
}

void smalltests_summary()
{
    printf("**************** TESTS SUMMARY: %i/%i. ****************\n",
        _smalltests_passed, _smalltests_total);
}