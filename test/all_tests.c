#include "list_tests.h"
#include "sortfile_tests.h"
#include "smalltests.h"
#include <stdlib.h>

int main()
{
    list_tests();
    sortfile_tests();
    smalltests_summary();
    return EXIT_SUCCESS;
}
