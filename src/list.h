#ifndef __LIST_H__
#define __LIST_H__
#include <stddef.h>

typedef struct list list_t;

/**
 * Frees a list.
 * @param list A non-null non-freed list.
 **/
void list_free(list_t* list);

/**
 * Allocates a new empty list.
 * @return A pointer to a newly allocated list_t, or NULL if not enough memory.
 */
list_t* list_new();

#endif