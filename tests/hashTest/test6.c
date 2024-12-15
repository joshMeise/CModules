/* 
 * test6.c --- remove entry from table that was added first
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
#include <stdbool.h>

/*
 * Compares 2 integers.
 * Inputs: pointers to 2 integers.
 * Outputs: true if same, false if not.
 */
static bool searchFunc(void *d1, const void *d2) {
	// Variable declarations.
	int *i, *j;

	i = (int *)d1;
	j = (int *)d2;

	if (*i == *j) return true;
	else return false;
}

int main(void) {
	// Variable declarations.
	hashtable_t *h;
	int *i, cnt, *src;

	// Open hash table.
	if ((h = hopen(10)) == NULL) {
		fprintf(stderr, "Failure opening hash table.\n");
		exit(EXIT_FAILURE);
	}

	for (cnt = 0; cnt < 100; cnt++) {
		if ((i = (int *)malloc(sizeof(int))) == NULL) {
			fprintf(stderr, "Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}

		*i = cnt;
		
		if (hput(h, (void*)i, (const char *)&cnt, sizeof(cnt)) != 0) {
			fprintf(stderr, "Failure putting element to hash table.\n");
			exit(EXIT_FAILURE);
		}
	}

	cnt = 0;
	
	if ((src = (int *)hremove(h, searchFunc, (const char *)&cnt, sizeof(cnt))) == NULL) {
		fprintf(stderr, "Could not find entry in table.\n");
		exit(EXIT_FAILURE);
	}
		
	if (cnt != *src) {
		fprintf(stderr, "Did not remove correct entry.\n");
		exit(EXIT_FAILURE);
	}

	free(src);
	
	// Free all memory.
	happly(h, free);

	// Close hash table.
	hclose(h);
	
	exit(EXIT_SUCCESS);
}
