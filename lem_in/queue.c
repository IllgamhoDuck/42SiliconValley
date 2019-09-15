/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:03:49 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 15:55:55 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int32_t				*init_path(int32_t len)
{
	int32_t			*path;

	if (!(path = (t_path *)ft_memalloc(sizeof(int32_t) * len)))
		malloc_error("path");
	return (path);
}

t_queue				*init_queue(int32_t i)
{
	t_queue			*queue;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		malloc_error("queue");
	queue->len = 1;
	queue->path = init_path(queue->len);
	queue->current = i;
	queue->path[0] = i;
	return (queue);
}

t_queue				*copy_queue(t_queue *q, int32_t index)
{
	t_queue			*c_q;
	int32_t			i;

	if (!(c-q = (t_queue *)ft_memalloc(sizeof(t_queue))))
		malloc_error("copy queue");
	c_q->len = q->len + 1;
	c_q->path = init_path(c_q->len);
	i = -1;
	while (++i < q->len)
		c_q->path[i] = q->path[i];
	c_q->path[i] = index;
	c_q->current = index;
	return (c_q);
}

void				push_queue(t_queue **q, t_queue *c, int32_t i)
{
	t_queue			*last;
	t_queue			*add;

	add = copy_queue(c, i);
	last = *q;
	if (last == NULL)
	{
		*q = add;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = add;
}

void				free_queue(t_queue *queue)
{
	if (queue)
	{
		if (queue->next)
			free_queue(queue->next);
		if (queue->path)
			free(queue->path);
		free(queue);
	}
}
