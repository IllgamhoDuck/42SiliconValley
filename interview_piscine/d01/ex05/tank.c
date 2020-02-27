/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:04:31 by hypark            #+#    #+#             */
/*   Updated: 2020/02/27 00:00:48 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	tank = (struct s_tank *)malloc(sizeof(struct s_tank));
	tank->n = 1;
	tank->stacks = (struct s_stack **)malloc(sizeof(struct s_stack *));
	tank->stacks[0] = (struct s_stack *)malloc(sizeof(struct s_stack));
	tank->stacks[0]->elem = NULL;
	tank->stacks[0]->sum = 0;
	return tank;
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_elem *elem;
	struct s_stack *stack = NULL;
	struct s_stack **new_stacks = NULL;
	int	i = -1;

	elem = (struct s_elem *)malloc(sizeof(struct s_elem));
	elem->energy = energy;
	elem->next = NULL;

	while (++i < tank->n)
	{
		if (tank->stacks[i]->sum + energy > 1000)
			continue ;
		stack = tank->stacks[i];
	}
	if (stack == NULL)
	{
		tank->n++;
		new_stacks = (struct s_stack **)malloc(sizeof(struct s_stack *) * tank->n);
		i = -1;
		while (++i < tank->n - 1)
			new_stacks[i] = tank->stacks[i];
		new_stacks[i] = (struct s_stack *)malloc(sizeof(struct s_stack));
		new_stacks[i]->elem = NULL;
		new_stacks[i]->sum = 0;
		tank->stacks = new_stacks;
		stack = tank->stacks[i];
	}
	if (stack->elem == NULL)
	{
		stack->elem = elem;
		stack->sum = elem->energy;
	}
	else
	{
		elem->next = stack->elem;
		stack->elem = elem;
		stack->sum += elem->energy;
	}
	printf("Energy %d pushed\n", energy);
}

int tankPop(struct s_tank *tank)
{
	struct s_elem *elem;
	struct s_stack *stack = NULL;
	struct s_stack **new_stacks = NULL;
	int	i = -1;

	stack = tank->stacks[tank->n - 1];
	if (stack->sum == 0)
		return 0;
	elem = stack->elem;
	stack->elem = elem->next;
	stack->sum -= elem->energy;

	if (stack->sum == 0 && tank->n != 1)
	{
		tank->n--;
		new_stacks = (struct s_stack **)malloc(sizeof(struct s_stack *) * tank->n);
		i = -1;
		while (++i < tank->n)
			new_stacks[i] = tank->stacks[i];
		tank->stacks = new_stacks;
	}
	printf("Energy %d popped\n", elem->energy);
	return elem->energy;
}
