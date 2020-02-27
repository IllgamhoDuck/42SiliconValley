#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void print_tank(struct s_tank *tank)
{
	int	i = -1;
	while (++i < tank->n)
		printf("Tank %d : %d\n", i, tank->stacks[i]->sum);
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	print_tank(tank);
	tankPush(tank, 50);
	print_tank(tank);
	tankPush(tank, 350);
	print_tank(tank);
	tankPush(tank, 450);
	print_tank(tank);
	tankPush(tank, 150);
	print_tank(tank);
	tankPush(tank, 550);
	print_tank(tank);
	tankPush(tank, 150);
	print_tank(tank);
	tankPush(tank, 450);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	tankPop(tank);
	print_tank(tank);
	return (0);
}

// Function used for the test
// Don't go further :)
