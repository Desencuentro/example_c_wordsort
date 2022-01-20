#ifndef __SORTFILE_H__
#define __SORTFILE_H__

#include <stdio.h>

#include "errors.h"
#include "list.h"

/**
 * Reads a file, word by word, and returns a linked list alphabetically sorted.
 * The criteria for sorting is the same as list_add_ordeded().
 * @param input A file with read access, to read from.
 * @param result Where to put operation result, ignored if NULL. On success, ERROR_NONE.
 * @return A list pointer on success that user must free();
 *         otherwise NULL, user must check result.
 **/
list_t* sortfile_readfile(FILE* input, errorcode_t *result);

/**
 * Reads a word from a given file.
 * @param input File to read from.
 * @param result Where to put operation result, ignored if NULL. On success, ERROR_NONE.
 * @return A newly allocated string with the readed word that user must free(), on success.
 * If there are no more words, NULL is returned and result is ERROR_NONE.
 * On failure, also NULL is returned, but user must check result.
 **/
char* sortfile_readword(FILE* input, errorcode_t *result);

#endif