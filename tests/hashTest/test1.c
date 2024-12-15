/* 
 * test1.c --- opens andcloses a hash table of size 1
 * 
 * Author: Joshua M. Meise
 * Created: 10-10-2024
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include <stdlib.h>
#include <hash.h>
#include <stdio.h>

int main(void) {
	// Variable declarations.
	hashtable_t *h;

	if ((h = hopen(10)) == NULL) {
		fprintf(stderr, "Failure opening hash table.\n");
		exit(EXIT_FAILURE);
	}

	hclose(h);

	exit(EXIT_SUCCESS);
}
