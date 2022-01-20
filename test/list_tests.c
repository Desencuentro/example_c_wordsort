#include "list_tests.h"
#include "smalltests.h"

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

void list_tests()
{
    listNew_isNotNull();
    listFreeNull_doNotCrash();
    onListNull_listLength_is0();
    onEmptyList_listLength_is0();
}
