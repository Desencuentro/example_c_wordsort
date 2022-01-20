#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortfile.h"

const char* const ARG_DEFAULT_FILE = "-";

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

FILE* sortfile_openarg(char* arg, char* modes, FILE* default_file)
{
    if( (NULL == arg) || (0 == arg[0]) || (0 == strcmp(ARG_DEFAULT_FILE, arg)) ) {
        return default_file;
    }
    return fopen(arg,modes);
}

list_t* sortfile_readfile(FILE* input, errorcode_t *result)
{
    char EMPTY[2] = "";
    errorcode_t error = ERROR_NONE;
    list_t* list = NULL;
    if(NULL == input) {
        error = ERROR_ARGS;
    } else {
        list = list_new();
        if(NULL == list) {
            error = ERROR_MEMORY;
        }
    }

    char* word = EMPTY;
    while( (NULL != word) && (ERROR_NONE == error) ) {
        word = sortfile_readword(input, &error);

        if(NULL != word) {
            error = list_add_ordered(list, word);
        }
        
        if(ERROR_NONE != error) {
            free(list);
            list = NULL;
        }
    }

    if(NULL != result) {
        (*result) = error;
    }
    return list;
}

char* sortfile_readword(FILE* input, errorcode_t *result)
{
    errorcode_t error = ERROR_NONE;
    char* word = NULL;
    size_t len = 0;
    
    if(NULL == input) {
        error = ERROR_ARGS;
    } 

    bool started = false, finished = false;
    while(!finished && (ERROR_NONE == error) && !feof(input) && !ferror(input)) {
        int read = fgetc(input);
        if(is_valid_read(read)) {
            started = true;
            char* newword = word_putc(word, (char) read, &len);
            if(NULL != newword) {
                word = newword;
            } else {
                error = ERROR_MEMORY;
                free(word);
                word = NULL;
            }
        } else if(started) {
            finished = true;
        }
    }

    if(NULL != result) {
        (*result) = error;
    }
    return word;
}