#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include "sortfile.h"

const int EXPECTED_ARGUMENTS = 3;

void show_help()
{
    printf("\nUse: ./wordsort.o INPUT_FILE OUTPUT_FILE\n\n");
    printf("* INPUT_FILE A text file to sort, or - for use stdin.\n");
    printf("* OUTPUT_FILE A text file to create with sorted words, or - for use stdout.\n\n");
    fprintf(stderr, "wordsort requires exactly 2 arguments.\n\n");
}

errorcode_t print_file_error(char* filekind, char* path)
{
    fprintf(stderr, "Error %i opening %s file '%s'.\n", errno, filekind, path);
    return ERROR_FILE;
}

int main(int argc, char** argv)
{
    if(EXPECTED_ARGUMENTS != argc) {
        show_help();
        return ERROR_ARGS;
    }
    FILE* input = sortfile_openarg(argv[1], "r", stdin);
    if(NULL == input) {
        return print_file_error("input", argv[1]);
    }

    FILE* output = sortfile_openarg(argv[2], "w", stdout);
    if(NULL == output) {
        fclose(input);
        return print_file_error("output", argv[2]);
    }

    errorcode_t error = ERROR_NONE;
    list_t* list = sortfile_readfile(input, &error);
    list_iterator_t* iter = list_iterator_new(list);
    while(!list_iterator_is_empty(iter)) {
        fprintf(output, "%s\n", list_iterator_current(iter));
        list_iterator_next(iter);
    }
    list_iterator_free(iter);
    list_free(list);

    fclose(input);
    fclose(output);
    return (ERROR_NONE == error) ? EXIT_SUCCESS : error;
}