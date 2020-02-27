/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:15:10 by hypark            #+#    #+#             */
/*   Updated: 2020/02/26 22:36:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_stack *initStack()
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return stack;
}

int pop(struct s_stack *stack)
{
	struct s_item *item;

	if (stack->item == NULL)
		return -1;
	item = stack->item;
	stack->item = stack->item->next;
	return item->idx;
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item;

	item = (struct s_item *)malloc(sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char *console(void)
{
	struct s_stack *stack;
	char *input;
	char message[256];
	char *result;
	int	result_len;
	int	idx;
	int	stack_idx;
	size_t word_len;

	idx = 0;
	stack = initStack();
	input = (char *)malloc(sizeof(char) * 256);
	message[0] = '\0';
	while (1)
	{
		printf("?: ");
		getline(&input, &word_len, stdin);
		word_len = strlen(input) - 1;
		input[word_len] = '\0';
		if (strcmp(input, "UNDO") == 0)
		{
			stack_idx = pop(stack);
			if (stack_idx == -1)
				;
			else if (stack_idx == 0)
			{
				message[0] = '\0';
				idx = stack_idx;
			}
			else
			{
				message[stack_idx - 1] = '\0';
				idx = stack_idx - 1;
			}
			printf("%s\n\n", message);
		}
		else if (strcmp(input, "SEND") == 0)
			break ;
		else
		{
			if (idx == 0)
			{
				strncpy(message + idx, input, word_len);
				push(stack, idx);
				idx += word_len;
				message[idx] = '\0';
			}
			else
			{
				message[idx] = ' ';
				strncpy(message + idx + 1, input, word_len);
				push(stack, idx + 1);
				idx = idx + word_len + 1;
				message[idx] = '\0';
			}
			printf("%s\n\n", message);
		}
	}
	result_len = strlen(message);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	strncpy(result, message, result_len);
	result[result_len] = '\0';
	return result;
}
