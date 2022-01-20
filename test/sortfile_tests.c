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

void onWordLineFile_2sortfileReadword_isWordNull_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/wordNoLine.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertNotEquals("On file with word and linebreak, sortfile_readword returns not NULL.",
        NULL, word);
    int cmp = (NULL == word) ? 0x1987 : strcmp("word", word);
    assertEquals("On file with word and linebreak, strcmp sortfile_readword with word is 0.",
        0, cmp);
    assertEquals("On file with word and linebreak, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    error = ERROR_UNKNOWN;
    word = sortfile_readword(f, &error);
    assertEquals("On file with word and linebreak, sortfile_readword twice returns NULL.",
        NULL, word);
    assertEquals("On file with word and linebreak, sortfile_readword twice, error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    fclose(f);
}

void on2wordsFile_2sortfileReadword_isTwo_Words_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/2words.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertNotEquals("On file with two words, sortfile_readword returns not NULL.",
        NULL, word);
    int cmp = (NULL == word) ? 1990 : strcmp("Two", word);
    assertEquals("On file with two words, strcmp sortfile_readword with Two is 0.",
        0, cmp);
    assertEquals("On file with two words, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    error = ERROR_UNKNOWN;
    word = sortfile_readword(f, &error);
    cmp = (NULL == word) ? 1990 : strcmp("words.", word);
    assertNotEquals("On file with two words, 2º sortfile_readword is not NULL.",
        NULL, word);
    assertEquals("On file with two words, 2º strcmp sortfile_readword with 'words.' is 0.",
        0, cmp);
    assertEquals("On file with two words, sortfile_readword twice, error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    fclose(f);
}

void on2linesFile_3sortfileReadword_is2_lines_NULL_andErrorIsNone()
{
    FILE *f = fopen("test/testfiles/2lines.txt", "r");
    errorcode_t error = ERROR_UNKNOWN;

    char* word = sortfile_readword(f, &error);

    assertNotEquals("On file with two words, sortfile_readword returns not NULL.",
        NULL, word);
    int cmp = (NULL == word) ? 1991 : strcmp("2", word);
    assertEquals("On file with two words, strcmp sortfile_readword with 2 is 0.",
        0, cmp);
    assertEquals("On file with two words, sortfile_readword error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    error = ERROR_UNKNOWN;
    word = sortfile_readword(f, &error);
    cmp = (NULL == word) ? 1992 : strcmp("lines", word);
    assertNotEquals("On file with two words, 2º sortfile_readword is not NULL.",
        NULL, word);
    assertEquals("On file with two words, 2º strcmp sortfile_readword with 'lines' is 0.",
        0, cmp);
    assertEquals("On file with two words, sortfile_readword twice, error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    error = ERROR_UNKNOWN;
    word = sortfile_readword(f, &error);
    assertEquals("On file with two words, 3º sortfile_readword is NULL.",
        NULL, word);
    assertEquals("On file with two words, 3º sortfile_readword, error is ERROR_NONE.",
        ERROR_NONE, error);
    free(word);

    fclose(f);
}

void onNullFile_sortfileReadfile_isNull_andErrorIsArgs()
{
    errorcode_t error = ERROR_UNKNOWN;
    list_t* list = sortfile_readfile(NULL, &error);
    assertEquals("sortfile_readfile(NULL,&error) is NULL",
        NULL, list);
    assertEquals("On sortfile_readfile(NULL,&error), error is ERROR_ARGS",
        ERROR_ARGS, error);
    list_free(list);
}

void onEmptyFile_sortfileReadfile_isEmptyList_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/empty.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read empty file, list is not NULL",
        NULL, list);
    assertEquals("On read empty file, length is 0",
        0, list_length(list));
    assertEquals("On read empty file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_free(list);
    fclose(f);
}

void onEmptyLineFile_sortfileReadfile_isEmptyList_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/emptyLine.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read empty line file, list is not NULL",
        NULL, list);
    assertEquals("On read empty line file, length is 0",
        0, list_length(list));
    assertEquals("On read empty line file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_free(list);
    fclose(f);
}

void onWordFile_sortfileReadfile_hasWord_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/wordNoLine.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read word file, list is not NULL",
        NULL, list);
    assertEquals("On read word file, length is 1",
        1, list_length(list));
    assertEquals("On read word file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_iterator_t* iter = list_iterator_new(list);
    char* word = list_iterator_current(iter);
    int cmp = (NULL == word) ? 0x1988 : strcmp(word,"word");

    assertNotEquals("On read word file, iterator is not NULL",
        NULL, iter);
    assertNotEquals("On read word file, iterator current is not NULL",
        NULL, word);
    assertEquals("On read word file, first word is equal to word",
        0, cmp);

    list_iterator_free(iter);
    list_free(list);
    fclose(f);
}

void onWordLineFile_sortfileReadfile_hasWord_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/wordLine.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read word line file, list is not NULL",
        NULL, list);
    assertEquals("On read word line file, length is 1",
        1, list_length(list));
    assertEquals("On read word line file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_iterator_t* iter = list_iterator_new(list);
    char* word = list_iterator_current(iter);
    int cmp = (NULL == word) ? 0x1988 : strcmp(word,"word");

    assertNotEquals("On read word line file, iterator is not NULL",
        NULL, iter);
    assertNotEquals("On read word line file, iterator current is not NULL",
        NULL, word);
    assertEquals("On read word line file, first word is equal to word",
        0, cmp);

    list_iterator_free(iter);
    list_free(list);
    fclose(f);
}

void on2wordsFile_sortfileReadfile_hasTwo_Words_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/2words.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read two word file, list is not NULL",
        NULL, list);
    assertEquals("On read two word file, length is 2",
        2, list_length(list));
    assertEquals("On read two word file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_iterator_t* iter = list_iterator_new(list);
    char* word = list_iterator_current(iter);
    int cmp = (NULL == word) ? 0x1988 : strcmp(word,"Two");

    assertNotEquals("On read two word file, first word is not NULL",
        NULL, word);
    assertEquals("On read two word file, first word is equal to 'Two'",
        0, cmp);

    list_iterator_next(iter);
    word = list_iterator_current(iter);
    cmp = (NULL == word) ? 0x1989 : strcmp(word,"words.");

    assertNotEquals("On read two word file, second word is not NULL",
        NULL, word);
    assertEquals("On read two word file, second word is equal to 'words.'",
        0, cmp);

    list_iterator_free(iter);
    list_free(list);
    fclose(f);
}

void on2linesFile_sortfileReadfile_has2_lines_andErrorIsNone()
{
    errorcode_t error = ERROR_UNKNOWN;
    FILE *f = fopen("test/testfiles/2lines.txt", "r");

    list_t* list = sortfile_readfile(f, &error);

    assertNotEquals("On read two lines file, list is not NULL",
        NULL, list);
    assertEquals("On read two lines file, length is 2",
        2, list_length(list));
    assertEquals("On read two lines file, error is ERROR_NONE",
        ERROR_NONE, error);
    
    list_iterator_t* iter = list_iterator_new(list);
    char* word = list_iterator_current(iter);
    int cmp = (NULL == word) ? 0x1996 : strcmp(word,"2");

    assertNotEquals("On read two lines file, first word is not NULL",
        NULL, word);
    assertEquals("On read two lines file, first word is equal to '2'",
        0, cmp);

    list_iterator_next(iter);
    word = list_iterator_current(iter);
    cmp = (NULL == word) ? 0x1997 : strcmp(word,"lines");

    assertNotEquals("On read two lines file, second word is not NULL",
        NULL, word);
    assertEquals("On read two lines file, second word is equal to 'lines'",
        0, cmp);

    list_iterator_free(iter);
    list_free(list);
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
    onWordLineFile_2sortfileReadword_isWordNull_andErrorIsNone();
    on2wordsFile_2sortfileReadword_isTwo_Words_andErrorIsNone();
    on2linesFile_3sortfileReadword_is2_lines_NULL_andErrorIsNone();
    onNullFile_sortfileReadfile_isNull_andErrorIsArgs();
    onEmptyFile_sortfileReadfile_isEmptyList_andErrorIsNone();
    onEmptyLineFile_sortfileReadfile_isEmptyList_andErrorIsNone();
    onWordFile_sortfileReadfile_hasWord_andErrorIsNone();
    onWordLineFile_sortfileReadfile_hasWord_andErrorIsNone();
    on2wordsFile_sortfileReadfile_hasTwo_Words_andErrorIsNone();
    on2linesFile_sortfileReadfile_has2_lines_andErrorIsNone();
}