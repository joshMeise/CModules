/* 
 * testApplyEmpty.c --- apply function to empty queue
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Test applying a function to an empty queue.
 * 
 */


//Libraries to include
#include <queue.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
	printf("Rate: %lf\n", funp->rate);
	printf("---------\n");
	
}

int main(void) {
	queue_t *qp;

	// Open a new queue.
	qp = qopen();

	qapply(qp, printperson);

	// Close queue.
	qclose(qp);

	exit(EXIT_SUCCESS);
}
