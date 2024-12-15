/* 
 * test8.c --- puts 10000 elements into a 100 slot hash table
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
	int *i, cnt;

	// Open hash table.
	if ((h = hopen(100)) == NULL) {
		fprintf(stderr, "Failure opening hash table.\n");
		exit(EXIT_FAILURE);
	}

	for (cnt = 0; cnt < 10000; cnt++) {
		if ((i = (int *)malloc(sizeof(int))) == NULL) {
			fprintf(stderr, "Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}

		*i = cnt;
		
		if (hput(h, (void*)i, (const char *)i, sizeof(i)) != 0) {
			fprintf(stderr, "Failure putting element to hash table.\n");
			exit(EXIT_FAILURE);
		}
	}

	// Free all memory.
	happly(h, free);

	// Close hash table.
	hclose(h);
	
	exit(EXIT_SUCCESS);
}
