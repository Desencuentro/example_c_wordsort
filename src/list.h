#ifndef __LIST_H__
#define __LIST_H__
#include <stddef.h>
#include "errors.h"

typedef struct list list_t;
//typedef int errorcode_t;

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