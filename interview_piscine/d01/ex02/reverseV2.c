/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:48:17 by hypark            #+#    #+#             */
/*   Updated: 2020/02/26 21:11:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return stack;
}

void *pop(struct s_stack *stack)
{
	struct s_item *item;

	if (stack->item == NULL)
		return NULL;
	item = stack->item;
	stack->item = stack->item->next;
	return item->word;
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *item;

	item = (struct s_item *)malloc(sizeof(struct s_item));
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;
	char *word;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (1)
	{
		word = pop(stack);
		if (word)
			printf("%s", word);
		word = pop(stack);
		if (word)
		{
			printf(" ");
			push(stack, word);
		}
		else
		{
			printf("\n");
			break ;
		}
	}
}
