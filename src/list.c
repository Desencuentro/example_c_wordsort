#include <stdlib.h>

#include "list.h"

typedef struct node node_t;

struct list {
    node_t* first;
};

struct list_iterator {
    node_t* current;
};

struct node {
    node_t* next;
    char* value;
};

errorcode_t list_add_ordered(list_t* list, char* value)
{
    if( (NULL == list) || (NULL == value) ) {
        return ERROR_ARGS;
    }

    node_t* node = calloc(1,sizeof(node_t));
    if(NULL == node) {
        return ERROR_MEMORY;
    }
    node->value = value;
    node_t** pointer = &(list->first);
    *pointer = node;
    return ERROR_NONE;
}

void list_free(list_t* list)
{
    if(NULL == list) {
        return;
    }
    node_t* node = list->first;
    while(NULL != node) {
        node_t* next = node->next;
        free(node->value);
        free(node);
        node = next;
    }
    free(list);
}

void list_iterator_free(list_iterator_t* iterator)
{
    free(iterator);
}

bool list_iterator_is_empty(list_iterator_t* iterator)
{
    return (NULL == iterator) || (NULL == iterator->current);
}

list_iterator_t* list_iterator_new(list_t* list)
{
    list_iterator_t* iterator = calloc(1, sizeof(list_iterator_t*));
    iterator->current = (NULL==list) ? NULL : list->first;
    return iterator;
}

size_t list_length(list_t* list)
{
    size_t length = 0;
    node_t* node = (NULL == list) ? NULL : list->first;
    while(NULL != node) {
        length++;
        node = node->next;
    }
    return length;
}

list_t* list_new()
{
    return calloc(1,sizeof(list_t));
}

