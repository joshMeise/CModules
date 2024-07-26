/* 
 * testContainsNotFound.c --- find existent element in vector
 * 
 * Author: Joshua M. Meise
 * Created: 07-26-2024
 * Version: 1.0
 * 
 */

#include <stdlib.h>
#include <vector.h>
#include <stdbool.h>

static bool compareInt(void *vp1, void *vp2) {
	int *i, *j;

	i = (int *)vp1;
	j = (int *)vp2;

	if (*i == *j) return true;
	else return false;
}

int main(void) {
	// Variable declarations.
	int i, search, success, *ins;
	vector_t *vec;

	if ((vec = vectorInit()) == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < 50; i++) {
		if ((ins = (int *)malloc(sizeof(int))) == NULL)
			exit(EXIT_FAILURE);

		*ins = i;
		
		if (vectorInsertBack(vec, (void *)ins) != 0)
			exit(EXIT_FAILURE);
	}
	
	search = 100;
	
	if (vectorContains(vec, compareInt, (void *)&search)) success = 0;
	else success = 1;

	vectorApply(vec, free);
	vectorFree(vec);
	
	if (success == 1) exit(EXIT_SUCCESS);
	else exit(EXIT_FAILURE);
		
}
