/* 
 * testHash.c --- test a hash table
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Test a hash table.
 * 
 */

#include <stdio.h>
#include "hash.h"
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
	person_t *p1, *p2;
	hashtable_t *table;
	int32_t success, key1;
	
	table = hopen(10);
	
	p1 = allocatePerson("Fred", 20, 10);
	p2 = allocatePerson("Dean", 31, 3);

	key1 = p1->age%10;
	
	success = hput(table, p1, (const char *)&(key1), sizeof(key1));

	if (success != 0)
		exit(EXIT_FAILURE);

 	key1 = p2->age%10;
	
	success = hput(table, p2, (const char *)&(key1), sizeof(key1));

	if (success != 0)
		exit(EXIT_FAILURE);

	hclose(table);

	free(p1);
	free(p2);
	
	exit(EXIT_SUCCESS);
}

