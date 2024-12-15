/* 
 * testPop1Stack.c --- Pop 1 element from a stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Tests pushing a single element to an empty stack and then popping that element.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
	// Variable declarations.
	int num = 4, *popped;
	stackDS_t *stack;
	
	// Create a stack.
	if ((stack = stackOpen()) == NULL)
		printf("Failure opening stack.\n");

	// Push number to stack.
	if (stackPush(stack, &num) != 0)
		exit(EXIT_FAILURE);

	// Pop element from stack.
	popped = (int *)stackPop(stack);

	// Check value.
	if (*popped != num)
		exit(EXIT_FAILURE);

	stackClose(stack);

	exit(EXIT_SUCCESS);

}

	

	
