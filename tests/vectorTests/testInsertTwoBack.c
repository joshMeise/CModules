/* 
 * testInsertOneBack.c --- insert a single element to a vector
 * 
 * Author: Joshua M. Meise
 * Created: 07-26-2024
 * Version: 1.0
 * 
 */

#include <stdlib.h>
#include <vector.h>
#include <stdio.h>

int main(void) {
	// Variable declarations.
	int *i, success, *got1, *got2;
	vector_t *vec;

	if ((vec = vectorInit()) == NULL)
		exit(EXIT_FAILURE);

	i = (int *)malloc(sizeof(int));
	*i = 4;
	
	if (vectorInsertBack(vec, (void *)i) != 0)
		exit(EXIT_FAILURE);

	i = (int *)malloc(sizeof(int));
	*i = 6;

	if (vectorInsertBack(vec, (void *)i) != 0)
		exit(EXIT_FAILURE);

	if ((got1 = (int *)vectorGetElement(vec, 0)) == NULL)
		exit(EXIT_FAILURE);

	if ((got2 = (int *)vectorGetElement(vec, 1)) == NULL)
		exit(EXIT_FAILURE);

	if (*got1 != 4 || *got2 != 6 || vectorGetSize(vec) != 2) success = 0;
	else success = 1;

	vectorApply(vec, free);
	
	vectorFree(vec);
	
	if (success == 1)	exit(EXIT_SUCCESS);
	else exit(EXIT_FAILURE);
}
