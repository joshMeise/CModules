/* 
 * llTestOpenClose.c --- opens and closes an empty linked list.
 * 
 * Author: Joshua M. Meise
 * Created: 03-29-2025
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <linkedList.h>

int main(void) {
	// Variable declarations.
	linkedList_t *list;

	// Open linked list.
	if ((list = llInit()) == NULL) {
		fprintf(stderr, "Failed to open linked list.\n");
		exit(EXIT_FAILURE);
	}

	// Close linked list.
	llClose(list);

	return (EXIT_SUCCESS);
}
	

					 
