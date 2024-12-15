/*
 * stack.c --- implements functions described in stack.h interface
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Implements the functionality fo a stack using a linked list data structure.
 *
 * I included this pice of code in my application as I believe it exemplifies the elegance of writing modular data structures in C.
 * Even though C is not an object-oriented language, one can still take advantage of the reusability and maintainability that is provided by using an object-oriented language through modular programming.
 * In doing so, one is able to keep the advantages that come with C (speed, and less abstraction) while writing easlity maintainable code.
 * This is not the most complex piece of code or the most complicated data structure, but I believe that it portrays my understanding and implementation of the stack data structure within the application's limit on the number of lines of code.
 * I believe that coding is a form of art and this program clearly depicts my coding style.
 * Additional stack functionality (such as stackClose(), stackPop(), stackApply(), etc.) ommitted due to 100 line limit on application.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

/*
 * Individual node of the stack.
 * Data pointer, and pointer to node below it.
 */
typedef struct stackNode {
	void *data;
	struct stackNode *prev;
} stackNode_t;

/*
 * Hidden aspects of a stack.
 * Each stack has a pointer to the top element.
 */
typedef struct privateStack {
	struct stackNode *top;
} privateStack_t;

/*
 * Create an empty stack.
 * Inputs: Node.
 * Outputs: Pointer to the stack that was just created; NULL if failure.
 */
stackDS_t *stackOpen(void) {
	privateStack_t *sp;

	// Allocate memory for stack data structure.
	if ((sp = (privateStack_t *)malloc(sizeof(privateStack_t))) == NULL) {
		fprintf(stderr, "Memory allocation failed in function stackOpen().\n");
		return NULL;
	}
	
	// Initialise stack to point to NULL signifying empty stack
	sp->top = NULL;
	
	return (stackDS_t *)sp;
}


/*
 * Add element to top of stack.
 * Inputs: Stack upon which to add, data element to add to stack.
 * Outputs: 0 for success, non-zero otehrwise
 */
int stackPush(stackDS_t *sp, void *elementp) {
	privateStack_t *s;
	stackNode_t *node;
	
	// Check validity of arguments.
	if (sp == NULL || elementp == NULL) {
		fprintf(stderr, "Invalid argument(s) to function stackPush().\n");
		return 1;
	}
	
	s = (privateStack_t *)sp;

	// Create a new node for stack.
	if ((node = (stackNode_t *)malloc(sizeof(stackNode_t))) == NULL) {
		fprintf(stderr, "Memory allocation failed in function stackPush().\n");
		return 1;
	}

	// Initialise fields of new node.
	node->data = elementp;
	node->prev = NULL;
	
	// Add node on top of stack.
	node->prev = s->top;
	s->top = node;

	return 0;
}

/*
 * Additional stack functionality (such as stackClose(), stackPop(), stackApply(), etc.) ommitted due to line limit on application.
 */

/*
 * Deallocate stack and free everything in it.
 * Inputs: Pointer to stack.
 * Output: Node.
 */
void stackClose(stackDS_t *sp) {
	stackNode_t *curr, *tmp;
	privateStack_t *s;

	// Check validity of arguments.
	if (sp == NULL) {
		fprintf(stderr, "Invalid argument(s) to function stackClose().\n");
		return;
	}

	s = (privateStack_t *)sp;

	// Begin freeing from top of stack.
	curr = s->top;

	// Free until reaching bottom of stack (empty stack).
	while (curr != NULL) {
		// Save current position and move to node below in stack.
		tmp = curr;
		curr = curr->prev;

		// Free current node of stack.
		free(tmp);
	}

	// Free the stack data structure itself.
	free(s);
}

/*
 * Removes top element of stack.
 * Inputs: Pointer to stack.
 * Outputs: Pointer to data portion of top element; NULL if empty.
 */
void *stackPop(stackDS_t *sp) {
	// Variable declarations.
	privateStack_t *s;
	stackNode_t *ptr;
	void *data;

	// Coerce.
	s = (privateStack_t *)sp;

	// If stack is empty or invalid argument, return NULL
	if (s->top == NULL || sp == NULL)
		return NULL;

	// Keep track of current top.
	ptr = s->top;
	
	// Make top of the stack point to the previous element.
	s->top = s->top->prev;

	// Store data to be returned.
	data = ptr->data;

	// Free element.
	free(ptr);

	return(data);
}

/*
 * Apply function to every element in stack.
 * Inputs: Pointer to relevant stack; function pointer.
 * Outputs: None.
 */
void stackApply(stackDS_t *sp, void (*fn)(void *elementp)) {
	// Variable declarations.
	stackNode_t *curr;
	privateStack_t *s;
	
	// Coerce.
	s = (privateStack_t *)sp;
	
	// Start at top of stack.
	curr = s->top;
	
	// Loop until bottom of stack.
	while (curr != NULL) {
		// Call function on current.
		fn(curr->data);
		
		// Move current to node below.
		curr = curr->prev;
	}
}
