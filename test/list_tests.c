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

void onIteratorNull_listIteratorFree_doNotCrash()
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

void onIteratorNull_listIteratorIsEmpty_isTrue()
{
    assertEquals("list_iterator_is_empty(NULL) is true",
        true, list_iterator_is_empty(NULL));
}

void onListNull_listIteratorIsEmpty_isTrue()
{
    list_iterator_t* iter = list_iterator_new(NULL);
    assertEquals("On iterator of null list, list_iterator_is_empty is true",
        true, list_iterator_is_empty(iter));
    list_iterator_free(iter);
}

void onEmptyList_listIteratorIsEmpty_isTrue()
{
    list_t* empty_list = list_new();
    list_iterator_t* iter = list_iterator_new(empty_list);
    assertEquals("On iterator of empty list, list_iterator_is_empty(NULL) is true",
        true, list_iterator_is_empty(iter));
    list_iterator_free(iter);
    list_free(empty_list);
}

void onAddOrdered1Element_listIteratorIsEmpty_isFalse()
{
    list_t* list = list_new();
    list_add_ordered(list, alloc_text("1 element"));
    list_iterator_t* iter = list_iterator_new(list);
    assertEquals("On list with 1 element, list_iterator_is_empty is false",
        false, list_iterator_is_empty(iter));
    list_iterator_free(iter);
    list_free(list);
}

void onNullIterator_listIteratorCurrent_isNull()
{
    assertEquals("list_iterator_current(NULL) is NULL",
        NULL, list_iterator_current(NULL));
}

void onEmptyIterator_listIteratorCurrent_isNull()
{
    list_iterator_t* empty_iterator = list_iterator_new(NULL);
    assertEquals("list_iterator_current(empty_iterator) is NULL",
        NULL, list_iterator_current(empty_iterator));
    list_iterator_free(empty_iterator);
}

void onNullIterator_listIteratorNext_isFalse()
{
    assertEquals("list_iterator_next(NULL) is false",
        false, list_iterator_next(NULL));
}

void onEmptyIterator_listIteratorNext_isFalse()
{
    list_iterator_t* iter = list_iterator_new(NULL);
    assertEquals("On empty iterator, list_iterator_next is false",
        false, list_iterator_next(iter));
    list_iterator_free(iter);
}

void onIteratorOf1Element_3listIteratorNext_isAlwaysFalse()
{
    list_t* list = list_new();
    list_add_ordered(list, alloc_text("1 element"));
    list_iterator_t* iter = list_iterator_new(list);

    assertEquals("On list with 1 element, list_iterator_next is false 1º time",
        false, list_iterator_next(iter));
    assertEquals("On list with 1 element, list_iterator_next is false 2º time",
        false, list_iterator_next(iter));
    assertEquals("On list with 1 element, list_iterator_next is false 3º time",
        false, list_iterator_next(iter));

    list_iterator_free(iter);
    list_free(list);
}

void onIteratorOf2Element_3listIteratorNext_isTrueFalseFalse()
{
    list_t* list = list_new();
    list_add_ordered(list, alloc_text("element 1"));
    list_add_ordered(list, alloc_text("element 2"));
    list_iterator_t* iter = list_iterator_new(list);

    assertEquals("On list with 1 element, list_iterator_next is true 1º time",
        true, list_iterator_next(iter));
    assertEquals("On list with 1 element, list_iterator_next is false 2º time",
        false, list_iterator_next(iter));
    assertEquals("On list with 1 element, list_iterator_next is false 3º time",
        false, list_iterator_next(iter));

    list_iterator_free(iter);
    list_free(list);
}

void onListOf3Elements_listLength_is3()
{
    list_t* list = list_new();
    list_add_ordered(list, alloc_text("element 1"));
    list_add_ordered(list, alloc_text("element 2"));
    list_add_ordered(list, alloc_text("element 3"));

    size_t len = list_length(list);
    assertEquals("On list with 3 elements, list_length() is 3", 3, len);

    list_free(list);
}

void iteratingListOf_a_L_Z_5listIteratorCurrent_are_a_L_Z_2NULL()
{
    char *a = alloc_text("a");
    char *L = alloc_text("L");
    char *Z = alloc_text("Z");
    list_t* list = list_new();
    list_add_ordered(list, a);
    list_add_ordered(list, L);
    list_add_ordered(list, Z);

    list_iterator_t* iter = list_iterator_new(list);

    assertEquals("On list with a, L, Z, list_iterator_current is a 1º time",
        a, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with a, L, Z, calling list_iterator_next once, list_iterator_current is L",
        L, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with a, L, Z, calling list_iterator_next twice, list_iterator_current is Z",
        Z, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with a, L, Z, list_iterator_next 3 times, list_iterator_current is NULL",
        NULL, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with a, L, Z, list_iterator_next 4 times, list_iterator_current is NULL",
        NULL, list_iterator_current(iter));

    list_iterator_free(iter);
    list_free(list);
}

void iteratingListOf_Z_b_L_5listIteratorCurrent_are_a_L_Z_2NULL()
{
    char *b = alloc_text("b");
    char *L = alloc_text("L");
    char *Z = alloc_text("Z");
    list_t* list = list_new();
    list_add_ordered(list, Z);
    list_add_ordered(list, b);
    list_add_ordered(list, L);

    list_iterator_t* iter = list_iterator_new(list);

    assertEquals("On list with Z, a, L, list_iterator_current is b 1º time",
        b, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with Z, a, L, calling list_iterator_next once, list_iterator_current is L",
        L, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with Z, a, L, calling list_iterator_next twice, list_iterator_current is Z",
        Z, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with Z, a, L, list_iterator_next 3 times, list_iterator_current is NULL",
        NULL, list_iterator_current(iter));
    list_iterator_next(iter);
    assertEquals("On list with Z, a, L, list_iterator_next 4 times, list_iterator_current is NULL",
        NULL, list_iterator_current(iter));

    list_iterator_free(iter);
    list_free(list);
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
    onIteratorNull_listIteratorFree_doNotCrash();
    onIteratorNull_listIteratorIsEmpty_isTrue();
    onListNull_listIteratorNew_isNotNull();
    onListNull_listIteratorIsEmpty_isTrue();
    onEmptyList_listIteratorIsEmpty_isTrue();
    onAddOrdered1Element_listIteratorIsEmpty_isFalse();
    onNullIterator_listIteratorCurrent_isNull();
    onEmptyIterator_listIteratorCurrent_isNull();
    onNullIterator_listIteratorNext_isFalse();
    onEmptyIterator_listIteratorNext_isFalse();
    onIteratorOf1Element_3listIteratorNext_isAlwaysFalse();
    onIteratorOf2Element_3listIteratorNext_isTrueFalseFalse();
    onListOf3Elements_listLength_is3();
    iteratingListOf_a_L_Z_5listIteratorCurrent_are_a_L_Z_2NULL();
    iteratingListOf_Z_b_L_5listIteratorCurrent_are_a_L_Z_2NULL();
}
