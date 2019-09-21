/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:39:49 by hypark            #+#    #+#             */
/*   Updated: 2019/09/19 00:00:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void			b_sort(t_ant *ant, t_queue **current, t_queue **prev)
{
	if (*current == ant->queue)
	{
		ant->queue = (*current)->next;
		(*current)->next = (*current)->next->next;
		ant->queue->next = (*current);
		*prev = ant->queue;
	}
	else
	{
		(*prev)->next = (*current)->next;
		(*current)->next = (*current)->next->next;
		(*prev)->next->next = *current;
		(*prev) = (*prev)->next;
	}
}

void				sort_path(t_ant *ant)
{
	t_queue			*current;
	t_queue			*prev;
	int8_t			finish;

	finish = 1;
	while (finish)
	{
		finish = 0;
		current = ant->queue;
		prev = current;
		while (current && current->next)
		{
			if (current->len > current->next->len)
			{
				finish = 1;
				b_sort(ant, &current, &prev);
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
	}
}
