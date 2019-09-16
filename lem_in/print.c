/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:05:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 23:25:00 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void				print_ant(t_ant *ant)
{
	int32_t			i;
	t_adj			*current;

	ft_printf("ANT NUMBER : %d\n", ant->ant_number);
	ft_printf("ROOM NUMBER : %d\n", ant->room_number);
	ft_printf("LINK NUMBER : %d\n", ant->link_number);
	ft_printf("START : %s\n", ant->start_room->room_name);
	ft_printf("END : %s\n", ant->end_room->room_name);
	i = -1;
	while (++i < ant->room_number)
	{
		ft_printf("ROOM NAME : %s ,", ant->adj[i].room_name);
		current = ant->adj[i].next;
		while (current)
		{
			ft_printf("%d -> ", current->i);
			current = current->next;
		}
		ft_printf("\n");
	}
}

void				print_path(t_ant *ant)
{
	int32_t			path;
	int32_t			i;
	t_queue			*q;

	q = ant->queue;
	path = 1;
	while (q)
	{
		ft_printf("path %d : ", path++);
		i = -1;
		while (++i < q->len)
			ft_printf("%d->", q->path[i]);
		ft_putchar('\n');
		q = q->next;
	}
}

void				print_adj_01(t_ant *ant)
{
	int32_t			i;
	int32_t			j;

	i = -1;
	while (++i < ant->room_number)
	{
		ft_printf("room %d : ", i);
		j = -1;
		while (++j < ant->room_number)
			ft_printf("%d ", ant->adj_01[i][j]);
		ft_putchar('\n');
	}
}
