/* 
 * testGetEmpty.c --- get from empty queue
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Tests getting an element from an empty queue.
 * 
 */


//Libraries to include
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXNM 20

// Person will be the datatype being stored in the queue.
typedef struct person {
	char name[MAXNM];
	int age;
	double rate;
} person_t;

int main(void) {
 	person_t *removep;
	queue_t *qp;

	// Open a new queue.
	qp = qopen();

	// Gt first person from empty queue.
	removep = (person_t *)qget(qp);

	if (removep != NULL)
		exit(EXIT_FAILURE);
	
	// Close queue.
	qclose(qp);

	exit(EXIT_SUCCESS);
}
