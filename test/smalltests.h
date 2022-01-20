#ifndef __SMALLTESTS_H__
#define __SMALLTESTS_H__
#include <stddef.h>
#include <stdint.h>

/** Shows a summary of tests that passed vs. tests executed. **/
void smalltests_summary();

#define assertNotEquals(message, unexpected, actual) _assertNotEquals(message, (uintmax_t) unexpected, (uintmax_t) actual)
/**
 * Assert that the `actual` and `unexpected` values are not equal.
 * @param message Assertion message to display.
 * @param expeted Value not expected.
 * @param actual Actual value.
 **/
void _assertNotEquals(char* message, uintmax_t unexpected, uintmax_t actual);

#endif