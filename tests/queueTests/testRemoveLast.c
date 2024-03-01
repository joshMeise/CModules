/* 
 * testRemoveLast.c --- remove last person from queue
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Test removing the last person from a queue.
 * 
 */


//Libraries to include
#include "queue.h"
#include <stdio.h>
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
 * prints out the details of a person
 * inputs: accpets a pointer to a person - as a void pointer
 * outputs: nothing
 */
void printperson(void *p){
	// Cast the data input to the function to a perso datatype.
	person_t* funp = (person_t*)p;

	printf("Name: %s\n", funp->name);
	printf("Age: %d\n", funp->age);
	printf("Rating: %.1lf\n", funp->rate);
	printf("---------\n");
	
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
 	person_t *pp1, *pp2, *pp3, *pp4, *removep;
 	int removeAge = 20;
	queue_t *qp;
	int32_t success;

	// Allocate the people.
	pp1 = allocatePerson("Fred", 12, 3);
	pp2 = allocatePerson("Bob", 78, 10);
	pp3 = allocatePerson("Pers", 34, 4);
	pp4 = allocatePerson("Noah", 20, 10);
	
	// Open a new queue.
	qp = qopen();

	// Put 4 people into queue.
	success = qput(qp, pp1);

	if (success != 0)
		exit(EXIT_FAILURE);

	success = qput(qp, pp2);

	if (success != 0)
		exit(EXIT_FAILURE);

	success = qput(qp, pp3);

	if (success != 0)
		exit(EXIT_FAILURE);

	success = qput(qp, pp4);

	if (success != 0)
		exit(EXIT_FAILURE);

	// Remove the first person in the queue.
	removep = qremove(qp, searchfunc, (void *)&removeAge);

	printperson(removep);

	qapply(qp, printperson);
	
	if (removep != pp4)
		exit(EXIT_FAILURE);
	
	// Close queue.
	qclose(qp);

	// Free people that were created.
	free(pp1);
	free(pp2);
 	free(pp3);
	free(pp4);
	
	exit(EXIT_SUCCESS);
}
