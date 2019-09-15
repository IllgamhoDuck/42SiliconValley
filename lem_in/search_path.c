/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 01:26:34 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 15:56:15 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** Check this index is a way i passed before
*/

static void			valid_i(t_queue *q, int32_t index)
{
	int32_t			i;

	i = -1;
	while (++i < q->len)
		if (q->path[i] == index)
			return (0);
	return (1);
}

static void			push_queue_to_ant(t_ant *ant, t_queue *q)
{
	t_queue			*current;

	current = ant->queue;
	if (current == NULL)
	{
		ant->queue = q;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = q;
}

/*
** "push_queue" add the new index i to the path and push to the queue
*/

static void			breath_first_search(t_ant *ant, t_queue **queue)
{
	t_queue			*current_q;
	t_adj			*adj;

	while (*queue)
	{
		current_q = *queue;
		current_q->next = NULL;
		*queue = *queue->next;
		adj = ant->adj[current_q->current_i].next;
		while (adj)
		{
			if (adj->i == ant->end_room->i)
			{
				push_queue_to_ant(ant, copy_queue(current_q, adj->i));
				continue ;
			}
			if (valid_i(current_q, adj->i))
				push_queue(queue, current_q, adj->i);
			adj = adj->next;
		}
		free_queue(current_q);
	}
}

void				search_path(t_ant *ant)
{
	t_queue			*queue;

	queue = init_queue(ant->start_room->i);
	breath_first_search(ant, &queue);
}
