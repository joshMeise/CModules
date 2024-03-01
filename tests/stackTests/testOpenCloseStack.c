/* 
 * testOpenCloseStack.c --- Open and close an empty stack.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Opens and closes an empty stack looking for errors.
 * 
 */

#include <stack.h>
#include <stdlib.h>

int main(void) {
	// Variable declarations.
	stack_t *stack;

	// Open stack.
	if ((stack = stackOpen()) == NULL)
		exit(EXIT_FAILURE);

	// Close stack.
	stackClose(stack);

	exit(EXIT_SUCCESS);
}
