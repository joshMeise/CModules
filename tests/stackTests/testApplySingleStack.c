/* 
 * testApplySingleStack.c --- KApply a function to a single element stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Tests applying a function to a single element stack.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

void adder(void *ep) {
	// Variable declaration and coercion.
	int *num = (int *)ep;

	(*num) += 3;
}

int main(void) {
	// Variable declarations.
	int num = 4;
	stackDS_t *stack;
	
	// Create a stack.
	if ((stack = stackOpen()) == NULL)
		printf("Failure opening stack.\n");

	// Push number to stack.
	if (stackPush(stack, &num) != 0)
		exit(EXIT_FAILURE);

	// Add 3 one the number in the stack.
	stackApply(stack, adder);

	// Check if result is as expected.
	if (num - 3 != 4)
		exit(EXIT_FAILURE);
	
	stackClose(stack);

	exit(EXIT_SUCCESS);

}

	

	
