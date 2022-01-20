#ifndef __SORTFILE_H__
#define __SORTFILE_H__

#include <stdio.h>

#include "errors.h"

/**
 * Reads a word from a given file.
 * @param input File to read from.
 * @param result Where to put operation result, ignored if NULL.
 * @return A newly allocated string with the readed word that user must free(), on success.
 * If there are no more words, NULL is returned and result is ERROR_NONE.
 * On failure, also NULL is returned, but user must check result.
 **/
char* sortfile_readword(FILE* input, errorcode_t *result);

#endif