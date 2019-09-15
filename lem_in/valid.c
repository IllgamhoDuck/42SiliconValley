/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:48:57 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 22:05:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void				valid_room(t_ant *ant, char **room_info, int16_t i)
{
	if (ant->link_number)
		lem_error("room information cannot be between the link information");
	if (i != 3)
		lem_error("room is not 3 values, usage : [room name][ ][x][ ][y]");
	i = -1;
	while (room_info[1][++i])
		if (ft_isdigit(room_info[1][i] == 0))
			lem_error("room x coordinate format is wrong, usage : [number]");
	i = -1;
	while (room_info[2][++i])
		if (ft_isdigit(room_info[2][i] == 0))
			lem_error("room y coordinate format is wrong, usage : [number]");
	if (room_info[0][0] == 'L')
		lem_error("room name cannot start with 'L' or '#'");
}

void				valid_link(t_ant *ant, char **link_info, int16_t i)
{
	if (ant->room_number == 0)
		lem_error("link information cannot come before room information");
	if (i != 2)
		lem_error("room is not 2 values, usage : [room name1][-][room name2]");
	if (find_room(ant->room, link_info[0]) == NULL)
	{
		ft_printf("%2@There is no [room name1] : %s\n", link_info[0]);
		exit(1);
	}
	if (find_room(ant->room, link_info[1]) == NULL)
	{
		ft_printf("%2@There is no [room name2] : %s\n", link_info[1]);
		exit(1);
	}
}

void				valid_input(t_ant *ant)
{
	if (ant->ant_number == 0)
	{
		ft_printf("%2@ant number %d is not valid\n", ant->ant_number);
		ant_error();
	}
	else if (ant->room_number == 0)
	{
		ft_printf("%2@room number %d is not valid\n", ant->room_number);
		ant_error();
	}
	else if (ant->link_number == 0)
	{
		ft_printf("%2@link number %d is not valid\n", ant->link_number);
		ant_error();
	}
}
