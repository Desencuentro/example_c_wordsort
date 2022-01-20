#include "list_tests.h"
#include "smalltests.h"

void listNew_isNotNull()
{
    list_t* list = list_new();
    assertNotEquals("list_new() is not NULL", NULL, list);
    list_free(list);
}

void list_tests()
{
    listNew_isNotNull();
}
