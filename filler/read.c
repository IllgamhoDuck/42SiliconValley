/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:36:00 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 03:26:12 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void				convert_map_to_int(t_filler *filler, char *map)
{
	int					map_size;
	int					i;

	map_size = filler->map_x * filler->map_y;
	i = -1;
	while (++i < map_size)
	{
		if (map[i] == '.')
			filler->map[i] = -3;
		else if (map[i] == 'o' || map[i] == 'O')
			filler->map[i] = filler->player == 1 ? -1 : -2;
		else if (map[i] == 'x' || map[i] == 'X')
			filler->map[i] = filler->player == 2 ? -1 : -2;
	}
	free(map);
}

/*
** What is a read map?
** ===========================
** 1. map 1d array
** 2. init map 1d int array
*/

static char				*read_map(t_filler *filler)
{
	char				**info;
	char				*map;
	char				*temp;
	char				*line;
	int					i;

	i = -1;
	map = "\0";
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++i < filler->map_y)
	{
		get_next_line(0, &line);
		info = ft_strsplit(line, ' ');
		ft_strdel(&line);
		temp = map;
		map = ft_strjoin(map, info[1]);
		i != 0 ? free(temp) : 0;
		free_str(info);
	}
	return (map);
}

/*
** What is a base information?
** ===========================
** 1. player number
** 2. map size (x, y)
** 3. piece size (x, y)
** 4. piece 1d array
*/

static void				read_map_info(t_filler *filler, char *line)
{
	char				**info;
	char				*map;
	int					map_size;

	if (filler->map_x == 0)
	{
		info = ft_strsplit(line, ' ');
		filler->map_y = ft_atoi(info[1]);
		filler->map_x = ft_atoi(info[2]);
		free_str(info);
	}
	map = read_map(filler);
	map_size = filler->map_x * filler->map_y;
	filler->map = (int *)malloc(sizeof(int) * map_size);
	convert_map_to_int(filler, map);
}

static void				read_piece(t_filler *filler, char *line)
{
	char				**info;
	char				*temp;
	int					i;

	info = ft_strsplit(line, ' ');
	filler->piece_y = ft_atoi(info[1]);
	filler->piece_x = ft_atoi(info[2]);
	free_str(info);
	filler->piece = "\0";
	i = -1;
	while (++i < filler->piece_y)
	{
		get_next_line(0, &line);
		temp = filler->piece;
		filler->piece = ft_strjoin(filler->piece, line);
		ft_strdel(&line);
		i != 0 ? free(temp) : 0;
	}
}

int						process_file(t_filler *filler)
{
	char				**info;
	char				*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) >= 3 && ft_strncmp(line, "$$$", 3) == 0)
		{
			info = ft_strsplit(line, ' ');
			filler->player = ft_strcmp(info[2], "p1") ? 2 : 1;
			free_str(info);
		}
		else if (ft_strlen(line) >= 7 && ft_strncmp(line, "Plateau", 7) == 0)
			read_map_info(filler, line);
		else if (ft_strlen(line) >= 5 && ft_strncmp(line, "Piece", 5) == 0)
		{
			read_piece(filler, line);
			//ft_printf("%2@map!\n");
			process_map(filler);
			//ft_printf("%2@solution!\n");
			process_solution(filler);
			reset_filler(filler);
			ft_printf("%d %d\n", Y(SOLUTION), X(SOLUTION));
		}
		ft_strdel(&line);
	}
	return (1);
}
