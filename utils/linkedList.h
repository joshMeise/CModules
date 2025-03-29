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

/*
 * Create an empty list.
 * Inputs: Node.
 * Outputs: pointer to the next list that was created; NULL is unsuccessful.
 */
linkedList_t *llInit(void);

/*
 * Deallocate all memory allocated for list.
 * Inputs: List to be freed.
 * Outputs: None.
 */
void llClose(linkedList_t *list);

/*
 * Insert an element at the front of the list.
 * Inputs: list to insert to, data to insert
 * Outputs: 0 if successful, 1 if not successful.
 */
int32_t llPutFront(linkedList_t *list, void *element);

/* Insert an element at the back of the list.
 * Inputs: list to insert to, data to insert
 * Outputs: 0 if successful, 1 if not successful
 */
int32_t llPutBack(linkedList_t *list, void *element);

/* Insert an element at a given index of a list
 * Inputs: list to insert to, index at which to insert, data to insert
 * Outputs: 0 if successful, 1 if not successful
 */
int32_t llPut(linkedList_t *list, int index, void *element);
