/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:36:00 by hypark            #+#    #+#             */
/*   Updated: 2019/09/11 04:28:26 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int g_first = 1;

/*
** Read the input from standard input and return the necessary information
*/

//static char				**read_stdin(void)
//{
//	char				*buff;
//	char				*temp;
//	char				**line;
//	int					len;
//
//	buff = (char *)malloc(sizeof(char) * BUFF_SIZE_FILLER);
//	len = read(0, buff, BUFF_SIZE_FILLER);
//	if (len == 0)
//	{
//		free(buff);
//		return (NULL);
//	}
//	temp = buff;
//	buff = ft_strnew(len);
//	ft_memcpy(buff, temp, len);
//	free(temp);
//	buff = stdin_filler();
//	if (buff == 0)
//		return (NULL);
//	line = ft_strsplit(buff, '\n');
//	free(buff);
//	return (line);
//}

/*
** What is a base information?
** ===========================
** 1. player number
** 2. map size (x, y)
** 3. piece size (x, y)
** 4. piece 1d array
*/

static void				read_base_info(t_filler *filler, char **line)
{
	char				**info;
	char				*piece;
	char				*temp;
	int					i;

	info = ft_strsplit(line[0], ' ');
	filler->player = ft_strcmp(info[2], "p1") ? 2 : 1;
	free_str(info);
	info = ft_strsplit(line[1], ' ');
	filler->map_y = ft_atoi(info[1]);
	filler->map_x = ft_atoi(info[2]);
	free_str(info);
	info = ft_strsplit(line[3 + filler->map_y], ' ');
	filler->piece_y = ft_atoi(info[1]);
	filler->piece_x = ft_atoi(info[2]);
	free_str(info);
	filler->piece = "\0";
	i = -1;
	while (++i < filler->piece_y)
	{
		piece = line[4 + filler->map_y + i];
		temp = filler->piece;
		filler->piece = ft_strjoin(filler->piece, piece);
		i != 0 ? free(temp) : 0;
	}
}

static void				read_base_info_2(t_filler *filler, char **line)
{
	char				**info;
	char				*piece;
	char				*temp;
	int					i;

	info = ft_strsplit(line[0], ' ');
	filler->map_y = ft_atoi(info[1]);
	filler->map_x = ft_atoi(info[2]);
	free_str(info);
	info = ft_strsplit(line[2 + filler->map_y], ' ');
	filler->piece_y = ft_atoi(info[1]);
	filler->piece_x = ft_atoi(info[2]);
	free_str(info);
	filler->piece = "\0";
	i = -1;
	while (++i < filler->piece_y)
	{
		piece = line[3 + filler->map_y + i];
		temp = filler->piece;
		filler->piece = ft_strjoin(filler->piece, piece);
		i != 0 ? free(temp) : 0;
	}
}

/*
** What is a read map?
** ===========================
** 1. map 1d array
** 2. init map 1d int array
*/

static char				*read_map(t_filler *filler, char **line)
{
	char				**info;
	char				*map;
	char				*temp;
	int					i;
	int					map_size;

	i = -1;
	map = NULL;
	while (++i < filler->map_y)
	{
		info = ft_strsplit(line[(g_first == 1 ? 3 : 2) + i], ' ');
		if (map == NULL)
			map = ft_strdup(info[1]);
		else
		{
			temp = map;
			map = ft_strjoin(map, info[1]);
			free(temp);
		}
		free_str(info);
	}
	map_size = filler->map_x * filler->map_y;
	filler->map = (int *)malloc(sizeof(int) * map_size);
	free_str(line);
	return (map);
}

/*
** What is a convert map to int?
** ===========================
** map is sended as a 1d char array and we need to change this to...
** 1. my piece -> -1
** 2. enemy piece -> -2
** 3. '.' -> -3
*/

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
	g_first = 0;
}

int						process_file(t_filler *filler)
{
	char				**line;
	char				*map;

	line = stdin_filler();
	if (line == NULL)
		return (0);
	if (g_first == 1)
		read_base_info(filler, line);
	else
		read_base_info_2(filler, line);
	map = read_map(filler, line);
	convert_map_to_int(filler, map);
	return (1);
}
