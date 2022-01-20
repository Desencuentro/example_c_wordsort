#include "smalltests.h"
#include <stdio.h>

int _smalltests_passed = 0;
int _smalltests_total = 0;

void _assertEquals(char* message, uintmax_t expected, uintmax_t actual)
{
    smalltests_do_start_test(message);
    if(expected == actual) {
        smalltests_do_pass();
    } else {
        printf("FAILED, expected %lx, actual %lx\n", (long unsigned) expected, (long unsigned) actual);
    }
}

void _assertNotEquals(char* message, uintmax_t unexpected, uintmax_t actual)
{
    smalltests_do_start_test(message);
    if(unexpected != actual) {
        smalltests_do_pass();
    } else {
        printf("FAILED, unexpected %lx\n", (long unsigned) actual);
    }
}


void smalltests_do_pass()
{
    _smalltests_passed++;
    printf("Ok.\n");
}

void smalltests_do_start_test(char* message)
{
    printf("%s... ",message);
    _smalltests_total++;
}

void smalltests_summary()
{
    printf("**************** TESTS SUMMARY: %i/%i. ****************\n",
        _smalltests_passed, _smalltests_total);
}