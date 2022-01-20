#ifndef __LIST_TESTS_H__
#define __LIST_TESTS_H__
#include "../src/list.h"

void list_tests();

void listNew_isNotNull();
void listFreeNull_doNotCrash();
void onListNull_listLength_is0();
void onEmptyList_listLength_is0();

#endif