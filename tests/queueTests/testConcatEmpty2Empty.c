/* 
 * testConcatEmpty2Empty.c --- tests contatenating 2 empty queues
 * 
 * Author: Joshua M. Meise
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: Concatenates two empty queues together.
 * 
 */

#include "queue.h"
#include <stdlib.h>

int main(void) {
	//Variable declarations.
	queue_t *q1, *q2;

	// Open queues.
	q1 = qopen();
	q2 = qopen();

	// Concatenate 2 empty queues.
	qconcat(q1, q2);

	// Close the remaining queue.
	qclose(q1);
	
	exit(EXIT_SUCCESS);
	
}
