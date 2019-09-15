/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:26:40 by hypark            #+#    #+#             */
/*   Updated: 2019/09/15 00:02:46 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** "g_index" is used for the room index
** This is used at "binary_tree.c" file "fill_room_info()" fuction
** "g_start" is used for knowing this this room is the start
** "g_end" is used for knowing this this room is the end
*/

uint32_t g_index = 0;
uint32_t g_start = 0;
uint32_t g_end = 0;

static void			read_link(t_ant *ant, char *line)
{
	t_b_tree		*link1;
	t_b_tree		*link2;
	char			**link_info;
	int16_t			i;

	link_info = ft_strsplit(line, '-');
	i = 0;
	while (link_info[i] != NULL)
		i++;
	valid_link(ant, link_info, i);
	link1 = find_room(ant->room, link_info[0]);
	link2 = find_room(ant->room, link_info[1]);
	is_empty(&(ant->adj[link1->i])) ? init_link(ant, link1) : 0;
	is_empty(&(ant->adj[link2->i])) ? init_link(ant, link2) : 0;
	push_adj(&(ant->adj[link1->i].next), link2->i);
	push_adj(&(ant->adj[link2->i].next), link1->i);
	free_strsplit(link_info);
	ant->link_number++;
}

static void			read_room(t_ant *ant, char *line)
{
	t_b_tree		*room;
	char			**room_info;
	int16_t			i;

	room_info = ft_strsplit(line, ' ');
	i = 0;
	while (room_info[i] != NULL)
		i++;
	valid_room(ant, room_info, i);
	room = NULL;
	if (ant->room == NULL)
		ant->room = init_b_tree(ft_strdup(room_info[0]));
	else
		room = build_ant_room(ant->room, ft_strdup(room_info[0]));
	room == NULL ? room = ant->room : 0;
	fill_room_info(room, ft_atoi(room_info[1]), ft_atoi(room_info[2]));
	g_start ? ant->start_room = room : 0;
	g_end ? ant->end_room = room : 0;
	free_strsplit(room_info);
	++ant->room_number ? g_index++ : 0;
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
		g_start = 1;
		if (get_next_line(3, &line) > 0)
			read_room(ant, line);
		else
			ant_error();
		g_start = 0;
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		g_end = 1;
		if (get_next_line(3, &line) > 0)
			read_room(ant, line);
		else
			ant_error();
		g_end = 0;
	}
	ft_strdel(&line);
}

static void			read_ant_number(t_ant *ant, char *line)
{
	int16_t			i;

	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) == 0)
			lem_error("Ant number format is wrong, usage : [number]");
	}
	ant->ant_number = ft_atoi(line);
}

void				read_file(t_ant *ant)
{
	char			*line;

	line = NULL;
	while (get_next_line(3, &line) > 0)
	{
		if (ant->ant_number == 0)
			read_ant_number(ant, line);
		else if (line[0] == '#')
			read_command(ant, line);
		else if (ft_strchr(line, ' '))
			read_room(ant, line);
		else if (ft_strchr(line, '-'))
		{
			if (ant->adj == NULL)
				ant->adj = INIT_ADJ_LIST;
			read_link(ant, line);
		}
		else
		{
			ft_printf("%2@%s\n", line);
			lem_error("Invalid line has been inputed");
		}
		ft_strdel(&line);
	}
	valid_input(ant);
}
