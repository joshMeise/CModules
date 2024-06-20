/* 
 * linkedList.h --- describes functions used to implememt a doubly linked list
 * 
 * Author: Joshua Meise
 * Created: 06-20-2024
 * Version: 1.0
 * 
 * Description: Implements a doubly linked list.
 * 
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

/* Public representation of a linked list. */
typedef void linkedList_t;

/* Create an empty list */
linkedList_t *llinit(void);

/* Deallocate a list */
void llClose(linkedList_t *list);

/* Insert an element at the front of the list */
int32_t llPutFront(linkedList_t *list, void *element);

/* Insert an element at the back of the list */
int32_t llPutBack(linkedList_t *list, void *element);

/* Insert an element at a given index of a list */
int32_t llPutFront(linkedList_t *list, int index, void *element);
