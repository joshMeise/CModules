/* 
 * testInsertGetSize.c --- insert a single element to a vector and get sizze
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
	int i, success;
	vector_t *vec;

	if ((vec = vectorInit()) == NULL)
		exit(EXIT_FAILURE);

	i = 4;
	
	if (vectorInsertBack(vec, &i) != 0)
		exit(EXIT_FAILURE);

	if (vectorGetSize(vec) == 1) success = 1;
	else success = 0;
	
	vectorFree(vec);

	if (success == 1) exit(EXIT_SUCCESS);
	else exit(EXIT_FAILURE);
	
}
