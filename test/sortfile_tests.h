#ifndef __SORTFILE_TESTS_H__
#define __SORTFILE_TESTS_H__

void sortfile_tests();

void onNullFile_sortfileReadword_isNull_andErrorIsArgs();
void onEmptyFile_sortfileReadword_isNull_andErrorIsNone();
void onEmptyLineFile_sortfileReadword_isNull_andErrorIsNone();
void onWordFile_sortfileReadword_isWord_andErrorIsNone();

#endif