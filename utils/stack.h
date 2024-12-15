/* 
 * stack.h --- interface for stack data structure.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Defines common functions implemented on a stack data structure.
 * 
 */

#pragma once

/* Stack object available to users. */
typedef void stackDS_t;

/* Create an empty stack. */
stackDS_t *stackOpen(void);

/* Deallocate stack and free everything in it. */
void stackClose(stackDS_t *sp);

/* Removes top element of stack. */
void *stackPop(stackDS_t *sp);

/* Add element to top of stack. */
int stackPush(stackDS_t *sp, void *elementp);

/* Apply function to every element in stack. */
void stackApply(stackDS_t *sp, void (*fn)(void *elementp));
