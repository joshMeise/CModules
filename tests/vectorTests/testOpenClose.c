/* 
 * testOpenClose.c --- opens and then closees a vector
 * 
 * Author: Joshua M. Meise
 * Created: 07-26-2024
 * Version: 1.0
 * 
 */

#include <vector.h>
#include <stdlib.h>

int main(void) {
	vector_t *vec;

	if ((vec = vectorInit()) == NULL)
		exit(EXIT_FAILURE);

	vectorFree(vec);
	
	exit(EXIT_SUCCESS);
}
