/* 
 * testPush2Stack.c --- Push two elements to a stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Tests pushing 2 elements to a stack.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
	// Variable declarations.
	int num1 = 4, num2 = 3;
	stackDS_t *stack;
		
	// Create a stack.
	if ((stack = stackOpen()) == NULL)
		printf("Failure opening stack.\n");

	// Push number to stack.
	if (push(stack, &num1) != 0)
		exit(EXIT_FAILURE);

	// Push number to stack.
	if (push(stack, &num2) != 0)
		exit(EXIT_FAILURE);

	stackClose(stack);

	exit(EXIT_SUCCESS);
	
}

	

	
