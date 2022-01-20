#include <stdlib.h>

#include "list.h"

typedef struct node node_t;

struct list {
    node_t* first;
};

struct node {
    node_t* next;
    char* value;
};

list_t* list_new()
{
    return calloc(1,sizeof(list_t));
}

void list_free(list_t* list)
{
    free(list);
}