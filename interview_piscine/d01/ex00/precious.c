/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:53:54 by hypark            #+#    #+#             */
/*   Updated: 2020/02/26 20:28:19 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_node *init_node(char c)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->c = c;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

struct s_node *generate_list(void)
{
	struct s_node *start;
	struct s_node *current;
	int		i = -1;
	int		cs_len = strlen(CS);

	while (++i < cs_len)
	{
		if (i == 0)
		{
			start = init_node(CS[i]);
			current = start;
		}
		else if (i != cs_len - 1)
		{
			current->next = init_node(CS[i]);
			current->next->prev = current;
			current = current->next;
		}
		else
		{
			current->next = init_node(CS[i]);
			current->next->prev = current;
			current = current->next;
			current->next = start;
			start->prev = current;
		}
	}
	return start;
}

char machine(struct s_node **list, int move)
{
	if (move == 0)
		;
	else if (move < 0)
	{
		while (move++ != 0)
			(*list) = (*list)->prev;
	}
	else
	{
		while (move-- != 0)
			(*list) = (*list)->next;
	}
	return (*list)->c;
}

char *precious(int *text, int size)
{
	struct s_node *list;
	char	*txt;
	int		i = -1;

	list = generate_list();
	txt = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		txt[i] = machine(&list, text[i]);
	txt[i] = '\0';
	return txt;
}
