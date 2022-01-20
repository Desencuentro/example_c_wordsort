#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortfile_tests.h"
#include "smalltests.h"
#include "../src/sortfile.h"

void onNullFile_sortfileReadword_isNull_andErrorIsArgs()
{
    errorcode_t error = ERROR_UNKNOWN;
    char* word = sortfile_readword(NULL, &error);
    assertEquals("On null file, sortfile_readword returns NULL.",
        NULL, word);
    assertEquals("On null file, sortfile_readword error is ERROR_ARGS.",
        ERROR_ARGS, error);
    free(word);
}

void onEmptyFile_sortfileReadword_isNull_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/empty.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertEquals("On empty file, sortfile_readword returns NULL.",
        NULL, word);
    assertEquals("On empty file, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);

    free(word);
    fclose(f);
}

void onEmptyLineFile_sortfileReadword_isNull_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/emptyLine.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertEquals("On empty line file, sortfile_readword returns NULL.",
        NULL, word);
    assertEquals("On empty line file, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);

    free(word);
    fclose(f);
}

void onWordFile_sortfileReadword_isWord_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/wordNoLine.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertNotEquals("On file with word, sortfile_readword returns not NULL.",
        NULL, word);
    int cmp = (NULL == word) ? 0x1986 : strcmp("word", word);
    assertEquals("On file with word, strcmp sortfile_readword with word is 0.",
        0, cmp);
    assertEquals("On file with word, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);

    free(word);
    fclose(f);
}

void sortfile_tests()
{
    printf("\n\n");
    printf("****************************************************************\n");
    printf("* TESTING: sortfile                                            *\n");
    printf("****************************************************************\n\n");

    onNullFile_sortfileReadword_isNull_andErrorIsArgs();
    onEmptyFile_sortfileReadword_isNull_andErrorIsNone();
    onEmptyLineFile_sortfileReadword_isNull_andErrorIsNone();
    onWordFile_sortfileReadword_isWord_andErrorIsNone();
}