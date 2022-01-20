#include "smalltests.h"
#include <stdio.h>

int _smalltests_passed = 0;
int _smalltests_total = 0;

void smalltests_summary()
{
    printf("**************** TESTS SUMMARY: %i/%i. ****************\n",
        _smalltests_passed, _smalltests_total);
}