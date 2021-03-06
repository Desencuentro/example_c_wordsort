#ifndef __LIST_H__
#define __LIST_H__
#include <stdbool.h>
#include <stddef.h>
#include "errors.h"

typedef struct list list_t;
typedef struct list_iterator list_iterator_t;

/**
 * Add the given value to the list, while keeping the ordering criteria,
 * which is latin alphabetical like strcmp but case-insensitve.
 * @param list A non-null list, empty or with the same criteria.
 *             On success, this value will be freed whithin the list;
 *             otherwise, the user must free it on error.
 * @param value The new given non-null value (repeated elements are allowed).
 * @return An errorcode_t which is ERROR_NONE on success.
 **/
errorcode_t list_add_ordered(list_t* list, char* value);

/**
 * Frees a list.
 * @param list A non-null non-freed linked list.
 **/
void list_free(list_t* list);

/**
 * Returns the current element of the iterator.
 * @param An iterator.
 * @return The current value at the iterator, or NULL.
 **/
char* list_iterator_current(list_iterator_t* iterator);

/**
 * Frees a linked list iterator.
 * @param iterator A non-null non-freed iterator created with list_iterator_new.
 **/
void list_iterator_free(list_iterator_t* iterator);

/**
 * Indicates if iterator current value is valid.
 * @param iterator An iterator created with list_iterator_new().
 * @return If iterator is null or there is not a current value,
 **/
bool list_iterator_is_empty(list_iterator_t* iterator);

/**
 * Allocates a new iterator for the given list.
 * @param list A list to iterate, must not be modified while operating iterator.
 * @return NULL if not memory, a newly allocated iterator pointer otherwise.
 **/
list_iterator_t* list_iterator_new(list_t* list);

/**
 * Advances (if possible) the iterator to the next element.
 * @param iterator An iterator created with list_iterator_new().
 * @return If there are more elements (a.k.a. if iterator is not empty)
 **/
bool list_iterator_next(list_iterator_t* iterator);

/**
 * Get the length of a list.
 * @param list A list or NULL.
 * @return The amount of elements in the list (or 0 if list is NULL).
 */
size_t list_length(list_t* list);

/**
 * Allocates a new empty linked list.
 * @return A pointer to a newly allocated list_t, or NULL if not enough memory.
 */
list_t* list_new();

#endif