/* 
 * stack.h --- implements functions described in stack.h.
 * 
 * Author: Joshua Meise
 * Created: 02-24-2024
 * Version: 1.0
 * 
 * Description: Allows for functionality defined in stack interface to be implemented.
 * 
 */

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
	// Variable declarations.
	privateStack_t *sp;

	// Allocate memory for stack.
	if ((sp = (privateStack_t *)malloc(sizeof(privateStack_t))) == NULL)
		return NULL;
	
	// Initialise top pointer.
	sp->top = NULL;
	
	// Coerce and return.
	return (stackDS_t *)sp;
}
		

/*
 * Deallocate stack and free everything in it.
 * Inputs: Pointer to stack.
 * Output: Node.
 */
void stackClose(stackDS_t *sp) {
	// Variable declarations.
	stackNode_t *curr, *tmp;
	privateStack_t *s;

	// Coerce.
	s = (privateStack_t *)sp;

	// Start at top of stack.
	curr = s->top;

	// Loop until bottom of stack.
	while (curr != NULL) {
		// Save current position.
		tmp = curr;

		// Move current to node below.
		curr = curr->prev;

		// Free memory.
		free(tmp);
	}

	// Free the stack itself.
	free(s);
}
		
		
/*
 * Removes top element of stack.
 * Inputs: Pointer to stack.
 * Outputs: Pointer to data portion of top element; NULL if empty.
 */
void *pop(stackDS_t *sp) {
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
 * Add element to top of stack.
 * Inputs: Stack upon which to add, data for element.
 * Outputs: 0 for success, non-zero otehrwise
 */
int push(stackDS_t *sp, void *elementp) {
	// Variable declarations.
	privateStack_t *s;
	stackNode_t *node;
	
	// Check validity of arguments.
	if (sp == NULL || elementp == NULL)
		return 1;
	
	// Coerce.
	s = (privateStack_t *)sp;

	// Create a new node.
	if ((node = (stackNode_t *)malloc(sizeof(stackNode_t))) == NULL)
		return 1;

	// Fill fields of new node.
	node->data = elementp;
	node->prev = NULL;

	// Add node on top of stack.
	node->prev = s->top;
	s->top = node;

	return 0;
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
