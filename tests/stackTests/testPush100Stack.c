/* 
 * testPush100Stack.c --- Push 100 elements to a stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Tests pushing 100 elements to a stack.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
	// Variable declarations.
	int i, *num;
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
			// Give value to num.
			*num = i;
			
			// Push number to stack.
			if (push(stack, num) != 0)
				exit(EXIT_FAILURE);
		}
	}

	// Free all integers in stack.
	stackApply(stack, free);

	stackClose(stack);

	exit(EXIT_SUCCESS);
	
}

	

	
