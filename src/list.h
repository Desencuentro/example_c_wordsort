#ifndef __LIST_H__
#define __LIST_H__
#include <stddef.h>

typedef struct list list_t;

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