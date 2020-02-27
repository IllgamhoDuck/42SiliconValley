/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:40:28 by hypark            #+#    #+#             */
/*   Updated: 2020/02/26 22:58:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *node;

	node = queue->first;
	if (node)
	{
		queue->first = node->next;
		if (queue->first == NULL)
			queue->last = NULL;
		return node->message;
	}
	else
		return NULL;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->message = message;
	node->next = NULL;

	if (queue->last)
		queue->last->next = node;
	else
		queue->first = node;
	queue->last = node;
}

char *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return NULL;
	else
		return queue->first->message;
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return 1;
	else
		return 0;
}
