/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:26:40 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 01:27:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"


static void			read_room(t_ant *ant, char *line)
{
	t_b_tree		*b_tree;
	char			**room_info;
	int16_t			i;

	room_info = ft_strsplit(line, ' ');
	i = 0;
	while (room_info[i] != NULL)
		i++;
	i == 3 ? 0 : lem_error("r has more than 3 values [r name][x][y]");
	i = -1;
	while (room_info[1][i])
		if (ft_isdigit(room_info[1][i] == 0))
			lem_error("r x coordinate format is wrong [number]");
	i = -1;
	while (room_info[2][i])
		if (ft_isdigit(room_info[2][i] == 0))
			lem_error("r y coordinate format is wrong [number]");
	b_tree = NULL;
	if (ant->room == NULL)
		ant->room = init_b_tree(ft_strdup(room_info[0]));
	else
		b_tree = find_room(ant->room, ft_strdup(room_info[0]));
	b_tree == NULL ? b_tree = ant->room : 0;
	fill_room_info(b_tree, ft_atoi(room_info[1]), ft_atoi(room_info[2]));
	free_strsplit(room_info);
}

/*
** Unknown command will be ignored.
** # Comments will be ignored.
** If there isn't enought data to process print out "ERROR"
*/

static void			read_command(t_ant *ant, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (get_next_line(0, &line) > 0)
			read_room(ant, line);
		else
			ant_error();
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		if (get_next_line(0, &line) > 0)
			read_room(ant, line);
		else
			ant_error();
	}
	ft_strdel(&line);
}

static void			read_ant_number(t_ant *ant, char *line)
{
	int16_t			i;

	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i] == 0))
			lem_error("Ant number format is wrong [number]");
	}
	ant->ant_number = ft_atoi(line);
}

void				read_file(t_ant *ant)
{
	char			*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ant->ant_number == 0)
			read_ant_number(ant, line);
		else if (line[0] == '#')
			read_command(ant, line);
		ft_strdel(&line);
	}
}
