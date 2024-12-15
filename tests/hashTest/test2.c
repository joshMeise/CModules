/* 
 * test2.c --- puts 1 element into a 10 slot hash table
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
	int three;

	// Open hash table.
	if ((h = hopen(10)) == NULL) {
		fprintf(stderr, "Failure opening hash table.\n");
		exit(EXIT_FAILURE);
	}

	three = 3;
	
	if (hput(h, (void*)&three, (const char *)&three, sizeof(three)) != 0) {
		fprintf(stderr, "Failure putting element to hash table.\n");
		exit(EXIT_FAILURE);
	}

	// Close hash table.
	hclose(h);
	
	exit(EXIT_SUCCESS);
}
