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

int main(void) {
	// Variable declarations.
	int i;
	vector_t *vec;

	if ((vec = vectorInit()) == NULL)
		exit(EXIT_FAILURE);

	i = 4;
	
	if (vectorInsertBack(vec, &i) != 0)
		exit(EXIT_FAILURE);

	vectorFree(vec);
	
	exit(EXIT_SUCCESS);
}
