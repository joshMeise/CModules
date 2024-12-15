/* 
 * testPush100Stack.c --- Pops 5 elements from a stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Tests pushing 100 elements to a stack and then popping 5 elements from that stack.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
	// Variable declarations.
	int i, *num, *popped;
	stackDS_t *stack;
		
	// Create a stack.
	if ((stack = stackOpen()) == NULL)
		printf("Failure opening stack.\n");

	// Loop 100 times to add 100 elements to stack.
	for (i = 0; i < 100; i++) {
		// Allocate space for a number.
		if ((num = (int *)malloc(sizeof(int))) == NULL)
			printf("Malloc failure.\n");
		else {
			// Give value to number.
			*num = i;
			
			// Push number to stack.
			if (stackPush(stack, num) != 0)
				exit(EXIT_FAILURE);
		}
	}

	// Pop last 5 elements from stack and compare to array.
	for (i = 0; i < 5; i++) {
		popped = (int *)stackPop(stack);

		if (*popped != 99 - i)
			exit(EXIT_FAILURE);

		// Free popped integer.
		free(popped);
	}
	
	// Free all integers in stack.
	stackApply(stack, free);

	stackClose(stack);

	exit(EXIT_SUCCESS);
	
}

	

	
