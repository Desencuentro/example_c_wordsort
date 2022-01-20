#include <stdio.h>
#include <stdlib.h>
#include "sortfile_tests.h"
#include "smalltests.h"
#include "../src/sortfile.h"

void onNullFile_sortfileReadword_isNull_andErrorIsArgs()
{
    errorcode_t error = ERROR_NONE;
    char* word = sortfile_readword(NULL, &error);
    assertEquals("On null file, sortfile_readword returns NULL.",
        NULL, word);
    assertEquals("On null file, sortfile_readword error is ERROR_ARGS.",
        ERROR_ARGS, error);
    free(word);
}

void sortfile_tests()
{
    printf("\n\n");
    printf("****************************************************************\n");
    printf("* TESTING: sortfile                                            *\n");
    printf("****************************************************************\n\n");

    onNullFile_sortfileReadword_isNull_andErrorIsArgs();
}