/* 
 * testSearchEmpty.c --- search empty list
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Test searhcing though an empty queue.
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

/* searches for a person by age
 * inputs: pointer to a person, pointer to age
 * outputs: TRUE is match, FALSE if no match
 */
bool searchfunc(void *p, const void* keyp){
	// Variable declarations.
	person_t *funp;
	int *key;

	// Coerce to valid datatypes.
	funp = (person_t *)p;
	key = (int *)keyp;

	// Check if the age is equal to the age being searched for.
	if (funp->age == *key){
		return true;
	}
	else {
		return false;
	}
	
}

int main(void) {
 	person_t *searchp;
	queue_t *qp;
	int32_t searchage;

		// Open a new queue.
	qp = qopen();

	searchage = 12;
	
	// Searhc the empty queue.
	searchp = (person_t *)qsearch(qp, searchfunc, (void *)&searchage);

	if (searchp != NULL)
		exit(EXIT_FAILURE);
	
	// Close queue.
	qclose(qp);

	exit(EXIT_SUCCESS);
}
