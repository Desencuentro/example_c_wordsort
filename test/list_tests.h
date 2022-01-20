#ifndef __LIST_TESTS_H__
#define __LIST_TESTS_H__

void list_tests();

void listNew_isNotNull();
void listFreeNull_doNotCrash();
void onListNull_listLength_is0();
void onEmptyList_listLength_is0();
void onListNull_listAddOrdered_isErrorArgs();
void onEmptyListNullValue_listAddOrdered_isErrorArgs();
void onListNullNullValue_listAddOrdered_isErrorArgs();
void onAddOrdered1Element_listLength_is1();

#endif