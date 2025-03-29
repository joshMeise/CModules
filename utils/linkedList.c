/* 
 * linkedList.c --- implememts the functions described in linked list.h
 * 
 * Author: Joshua Meise
 * Created: 06-20-2024
 * Version: 1.0
 * 
 * Description: Implements a doubly linked list.
 * 
 */

#include <linkedList.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * This structure contains an individual node of a linked list.
 * Each node coonstians data of some type.
 * It also contains a pointer to the next and the previous element.
 */
typedef struct listNode {
	void *data;
	struct listNode *next;
	struct listNode *prev;
} listNode_t;

/*
 * This structure contiins the hidden details of a linked list.
 * This contains the number of elements in the list as well as pointers to the first and last nodes.
 */
typedef struct privateList {
	int numEl;
	struct listNode *front;
	struct listNode *back;
} privateList_t;

/*
 * Creates a new list node with specified data.
 * Inputs: data to add.
 * Outputs: pointer to new list node, NULL if not successsful.
 */
static listNode_t *newNode(void *data) {
	// Variable declarations.
	listNode_t *newNode;

	// Check arguments.
	if (data == NULL) {
		fprintf(stderr, "Invalid argument.\n");
		return NULL;
	}
	
	// Allocate new node and fill fields.
	if((newNode = (listNode_t *)malloc(sizeof(listNode_t))) != NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = data;
	}

	return newNode;
}

/*
 * Create an empty list.
 * Inputs: Node.
 * Outputs: pointer to the next list that was created; NULL is unsuccessful.
 */
linkedList_t *llInit(void) {
	// Variable declarations.
	privateList_t *newList;

	// Allocate space for newlist object and initialise fields.
	if ((newList = (privateList_t *)malloc(sizeof(privateList_t))) != NULL) {
		newList->numEl = 0;
		newList->front = NULL;
		newList->back = NULL;
	}
	
	return (linkedList_t *)newList;
}

/*
 * Deallocate all memory allocated for list.
 * Inputs: List to be freed.
 * Outputs: None.
 */
void llClose(linkedList_t *list) {
	// Variable declarations.
	privateList_t *pl;
	listNode_t *ptr, *tmp;

	// Check argument.
	if (list == NULL) {
		fprintf(stderr, "Invalid argument.\n");
		return;
	}
	
	// Coerce to private list type.
	pl = (privateList_t *)list;
	
	// Start freeing from front of list.
	ptr = pl->front;

	// Free each element in the list.
	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}

	// Free the list itself.
	free(pl);
}

/*
 * Insert an element at the front of the list.
 * Inputs: list to insert to, data to insert
 * Outputs: 0 if successful, 1 if not successful.
 */
int32_t llPutFront(linkedList_t *list, void *element) {
	// Variable declarations.
	listNode_t *node;
	privateList_t *pl;
	
	// Check arguments.
	if (list == NULL || element == NULL) {
		fprintf(stderr, "Invalid argument(s).\n");
		return 1;
	}

	// Coerce into valid datatyype.
	pl = (privateList_t *)list;

	// Create node.
	if ((node = newNode(element)) == NULL) {
		fprintf(stderr, "Failed to create node.\n");
		return 1;
	}

	// Insert node into list.
	node->next = pl->front;
	pl->front->prev = node;
	pl->front = node;

	// Increase number of elements in list.
	(pl->numEl)++;

	return 0;
}


/* Insert an element at the back of the list.
 * Inputs: list to insert to, data to insert
 * Outputs: 0 if successful, 1 if not successful
 */
int32_t llPutBack(linkedList_t *list, void *element) {
	// Variable declarations.
	listNode_t *node;
	privateList_t *pl;
	
	// Check arguments.
	if (list == NULL || element == NULL) {
		fprintf(stderr, "Invalid argument(s).\n");
		return 1;
	}

	// Coerce into valid datatyype.
	pl = (privateList_t *)list;

	// Create node.
	if ((node = newNode(element)) == NULL) {
		fprintf(stderr, "Failed to create node.\n");
		return 1;
	}

	// Insert node into list.
	node->prev = pl->back;
	pl->back->next = node;
	pl->back = node;

	// Increase number of elements in list.
	(pl->numEl)++;

	return 0;
}

/* Insert an element at a given index of a list
 * Inputs: list to insert to, index at which to insert, data to insert
 * Outputs: 0 if successful, 1 if not successful
 */
int32_t llPut(linkedList_t *list, int index, void *element) {
	// Variable declarations.
	listNode_t *node, *cur;
	privateList_t *pl;
	int i;
	
	// Check arguments.
	if (list == NULL || element == NULL) {
		fprintf(stderr, "Invalid argument(s).\n");
		return 1;
	}

	// Coerce into valid datatyype.
	pl = (privateList_t *)list;

	// Check valid index.
	if (index < 0 || index > pl->numEl) {
		fprintf(stderr, "Invalid index.\n");
		return 1;
	}

	// If index corresponds to fonr or back.
	if (index == 0)
		return llPutFront(list, element);
	else if (index == pl->numEl)
		return llPutBack(list, element);
	
	// Create node.
	if ((node = newNode(element)) == NULL) {
		fprintf(stderr, "Failed to create node.\n");
		return 1;
	}
	
	i = 0;
	cur = pl->front;
	
	// Find position of node in list.
	while (i < index) {
		cur = cur->next;
		i++;
	}

	// Insert node into list.
	node->next = cur;
	node->prev = cur->prev;
	cur->prev->next = node;
	cur->prev = node;

	// Increase number of elements in list.
	(pl->numEl)++;

	return 0;

}
