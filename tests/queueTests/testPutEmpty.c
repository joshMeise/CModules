/*
 * testPutEmpty.c --- tests putting a person to an empty queue
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: This program tests putting a person into an empty queue.
 * 
 */

//Libraries to include
#include "queue.h"
#include <string.h>
#include <stdlib.h>

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
 	person_t *pp1;
	queue_t *qp;
	int32_t success;

	// Allocate the people.
	pp1 = allocatePerson("Fred", 12, 3);
	
	// Open a new queue.
	qp = qopen();

	// Put 4 people into queue.
	success = qput(qp, pp1);

	if (success != 0)
		exit(EXIT_FAILURE);
	
	// Close queue.
	qclose(qp);

	// Free people that were created.
	free(pp1);
	
	exit(EXIT_SUCCESS);
}
