#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_tests.h"
#include "../src/list.h"
#include "smalltests.h"

/** Allocates a string given a template.
 * @param template Texto to copy from.
 * @return NULL if not memory, a newly allocated string on success.
 **/
void* alloc_text(const char* template)
{
    if(NULL == template)
    {
        return NULL;
    }

    char* text = malloc(strlen(template)+1);
    if(NULL == text)
    {
        return NULL;
    }

    strcpy(text, template);
    return text;
}

void listNew_isNotNull()
{
    list_t* list = list_new();
    assertNotEquals("list_new() is not NULL", NULL, list);
    list_free(list);
}

void listFreeNull_doNotCrash()
{
    smalltests_do_start_test("list_free(NULL) should not crash");
    list_free(NULL);
    smalltests_do_pass();
}

void onListNull_listLength_is0()
{
    size_t len = list_length(NULL);
    assertEquals("list_length(NULL) is 0", 0, len);
}

void onEmptyList_listLength_is0()
{
    list_t* list = list_new();
    size_t len = list_length(list);
    assertEquals("On empty list, list_length() is 0", 0, len);
    list_free(list);
}

void onListNull_listAddOrdered_isErrorArgs()
{
    errorcode_t error;
    char* someText = alloc_text("some text");
    error = list_add_ordered(NULL, someText);
    
    assertEquals("list_add_ordered(NULL, someText) gives ERROR_ARGS",
        ERROR_ARGS, error);

    smalltests_do_start_test("free someText not added do not fails");
    free(someText);
    smalltests_do_pass();
}

void onEmptyListNullValue_listAddOrdered_isErrorArgs()
{
    errorcode_t error;
    list_t* empty_list = list_new();

    error = list_add_ordered(empty_list, NULL);
    
    assertEquals("list_add_ordered(empty_list, NULL) gives ERROR_ARGS",
        ERROR_ARGS, error);

    list_free(empty_list);
}

void onListNullNullValue_listAddOrdered_isErrorArgs()
{
    errorcode_t error = list_add_ordered(NULL, NULL);
    
    assertEquals("list_add_ordered(NULL, NULL) gives ERROR_ARGS",
        ERROR_ARGS, error);
}

void onAddOrdered1Element_listLength_is1()
{
    list_t* list = list_new();
    list_add_ordered(list, alloc_text("some text"));
    size_t len = list_length(list);
    assertEquals("On add ordered 1 element, list_length() is 1", 1, len);
    list_free(list);
}

void onIteratorNUll_listIteratorFree_doNotCrash()
{
    smalltests_do_start_test("list_iterator_free(NULL) do not crash");
    list_iterator_free(NULL);
    smalltests_do_pass();
}

void onListNull_listIteratorNew_isNotNull()
{
    list_iterator_t* iter = list_iterator_new(NULL);
    assertNotEquals("list_iterator_new(NULL) is not NULL", NULL, iter);
    list_iterator_free(iter);
}

void list_tests()
{
    printf("\n\n");
    printf("****************************************************************\n");
    printf("* TESTING: list                                                *\n");
    printf("****************************************************************\n\n");
    listNew_isNotNull();
    listFreeNull_doNotCrash();
    onListNull_listLength_is0();
    onEmptyList_listLength_is0();
    onListNull_listAddOrdered_isErrorArgs();
    onEmptyListNullValue_listAddOrdered_isErrorArgs();
    onListNullNullValue_listAddOrdered_isErrorArgs();
    onAddOrdered1Element_listLength_is1();
    onIteratorNUll_listIteratorFree_doNotCrash();
    onListNull_listIteratorNew_isNotNull();
}
