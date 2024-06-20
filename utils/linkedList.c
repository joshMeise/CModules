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
	privateList_t *newlist;

	// Allocate space for newlist object and initialise fields.
	if ((newList = (privateList_t *)malloc(sizeof(privateList_t))) != NULL)
		newList->numEL = 0;
		front = NULL;
		back = NULL;
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

}

/* Insert an element at the back of the list */
int32_t llPutBack(linkedList_t *list);

/* Insert an element at a given index of a list */
int32_t llPutFront(linkedList_t *list, int index);
