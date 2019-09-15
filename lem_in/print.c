/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:05:28 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 00:35:01 by hypark           ###   ########.fr       */
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
