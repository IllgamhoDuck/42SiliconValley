#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue *queue;

	/*-------------------
	launch your test here
	--------------------*/
	queue = queueInit();
	printf("isEmpty : %d\n", isEmpty(queue));
	enqueue(queue, "first message");
	printf("isEmpty : %d\n", isEmpty(queue));
	enqueue(queue, "second message");
	printf("peek : %s\n", peek(queue));
	printf("dequeue : %s\n", dequeue(queue));
	printf("dequeue : %s\n", dequeue(queue));
	printf("dequeue : %s\n", dequeue(queue));

	return (0);
}



// Function used for the test
// Don't go further :)

