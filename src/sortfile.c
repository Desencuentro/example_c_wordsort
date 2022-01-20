#include "sortfile.h"

#define READSIZE ((size_t) 8)

char* sortfile_readword(FILE* input, errorcode_t *result)
{
    errorcode_t error = ERROR_NONE;
    if(NULL == input) {
        error = ERROR_ARGS;
    }

    if(NULL != result) {
        (*result) = error;
    }
    return NULL;
}