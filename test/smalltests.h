#ifndef __SMALLTESTS_H__
#define __SMALLTESTS_H__
#include <stddef.h>
#include <stdint.h>

#define assertEquals(message, expected, actual) _assertEquals(message, (uintmax_t) expected, (uintmax_t) actual)
/**
 * Assert that the `actual` and `expected` values are equal.
 * @param message Assertion message to display.
 * @param expeted Expected value.
 * @param actual Actual value.
 **/
void _assertEquals(char* message, uintmax_t expected, uintmax_t actual);

#define assertNotEquals(message, unexpected, actual) _assertNotEquals(message, (uintmax_t) unexpected, (uintmax_t) actual)
/**
 * Assert that the `actual` and `unexpected` values are not equal.
 * @param message Assertion message to display.
 * @param expeted Value not expected.
 * @param actual Actual value.
 **/
void _assertNotEquals(char* message, uintmax_t unexpected, uintmax_t actual);

/** Passes and ends the currently started test with `smalltests_do_start_test`. **/
void smalltests_do_pass();

/**
 * Starts a tests with the given `message`.
 * @param message Should not be NULL.
 **/
void smalltests_do_start_test(char* message);

/** Shows a summary of tests that passed vs. tests executed. **/
void smalltests_summary();

#endif