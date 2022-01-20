#include <stdbool.h>
#include <stdlib.h>
#include "sortfile.h"

/**
 * Put a char at end of word, reallocating if necessary.
 * @param word Old word allocated buffer, starting with NULL, or reallocable block.
 * @param newchar Char to put at the end.
 * @param pLen Pointer to length of word (word before, return after), starting at 0.
 * @return NULL if no memory avaible, or same or reallocated string.
 * User must free() return, or if NULL must free oldword.
 **/
char* word_putc(char* word, char newchar, size_t* pLen)
{
    size_t len = (*pLen);
    // If emty, place for newchar and zero, otherwise already have zero.
    len += (0 == len) ? 2 : 1;
    word = realloc(word, len);
    if(NULL != word) {
        word[len - 2] = newchar;
        word[len - 1] = 0;
        *pLen = len;
    }
    return word;
}

/** Check if is a valid part of word.
 * @param readed Return of fgetc() or similar.
 * @return true if is >32 and not EOF.
 **/
bool is_valid_read(int readed)
{
    return (readed > 32) && (EOF != readed);
}

char* sortfile_readword(FILE* input, errorcode_t *result)
{
    errorcode_t error = ERROR_NONE;
    char* word = NULL;
    size_t len = 0;
    
    if(NULL == input) {
        error = ERROR_ARGS;
    } 

    while((ERROR_NONE == error) && !feof(input) && !ferror(input)) {
        int read = fgetc(input);
        if(is_valid_read(read)) {
            char* newword = word_putc(word, (char) read, &len);
            if(NULL != newword) {
                word = newword;
            } else {
                error = ERROR_MEMORY;
                free(word);
                word = NULL;
            }
        }
    }

    if(NULL != result) {
        (*result) = error;
    }
    return word;
}