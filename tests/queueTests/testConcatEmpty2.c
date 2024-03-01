/* 
 * testConcatEmpty2.c --- tests concatenating an empty queue to a queue.
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Concatenates an empty queue to a queue with something in it.
 * 
 */


#include "queue.h"
#include <stdlib.h>
#include <string.h>

#define MAXNM 20

// Person will be the datatype being stored in the queue.
typedef struct person {
	char name[MAXNM];
	int age;
	double rate;
} person_t;

/* 
 * allocates memory for new person and fill data fields
 * inputs: data that fills fields
 * output: pointer to person that was allocated
 */
person_t *allocatePerson(char *name, int age, double rate) {
	// Variable declaration and allocate space in memory for person.
	person_t *person = (person_t *)malloc(sizeof(person_t));

	// Fill datafields.
	strcpy(person->name, name);
	person->age = age;
	person->rate = rate;
	
	return person;
}

int main(void) {
	//Variable declarations.
	queue_t *q1, *q2;
	person_t *pp4;
	int32_t success;
	
	pp4 = allocatePerson("Noah", 20, 10);
		
	// Open queues.
	q1 = qopen();
	q2 = qopen();

	success = qput(q2, pp4);

	if (success != 0)
		exit(EXIT_FAILURE);
	
	// Concatenate empty queue 1 to queue 2.
	qconcat(q2, q1);

	// Close the remaining queue.
	qclose(q2);

	free(pp4);
	
	exit(EXIT_SUCCESS);
	
}
