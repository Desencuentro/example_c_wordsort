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
void onIteratorNull_listIteratorFree_doNotCrash();
void onListNull_listIteratorNew_isNotNull();
void onIteratorNull_listIteratorIsEmpty_isTrue();
void onListNull_listIteratorIsEmpty_isTrue();
void onEmptyList_listIteratorIsEmpty_isTrue();
void onAddOrdered1Element_listIteratorIsEmpty_isFalse();
void onNullIterator_listIteratorCurrent_isNull();
void onEmptyIterator_listIteratorCurrent_isNull();
void onNullIterator_listIteratorNext_isFalse();
void onEmptyIterator_listIteratorNext_isFalse();
void onIteratorOf1Element_3listIteratorNext_isAlwaysFalse();
void onIteratorOf2Element_3listIteratorNext_isTrueFalseFalse();
void onListOf3Elements_listLength_is3();
void iteratingListOf_a_L_Z_5listIteratorCurrent_are_a_L_Z_2NULL();
void iteratingListOf_Z_b_L_5listIteratorCurrent_are_a_L_Z_2NULL();

#endif