/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:05:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/18 12:37:29 by hypark           ###   ########.fr       */
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
		ft_printf("ROOM NAME : %s ,", ant->adj_list[i].room_name);
		current = ant->adj_list[i].next;
		while (current)
		{
			ft_printf("%s -> ", ant->adj_list[current->i].room_name);
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
			ft_printf("%s->", ant->adj_list[q->path[i]].room_name);
		ft_putchar('\n');
		q = q->next;
	}
}

void				print_adj_matrix(t_ant *ant)
{
	int32_t			i;
	int32_t			j;

	i = -1;
	while (++i < ant->room_number)
	{
		ft_printf("room %d : ", i);
		j = -1;
		while (++j < ant->room_number)
			ft_printf("%d ", ant->adj_matrix[i][j]);
		ft_putchar('\n');
	}
}
