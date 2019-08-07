/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:10:18 by hypark            #+#    #+#             */
/*   Updated: 2019/08/06 17:56:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			decide_color(int z)
{
	if (z >= 5)
		return (GOLD);
	else if (z >= -5 && z < 5)
		return (YELLOW);
	else
		return (LIGHT_GOLD);
}

static t_reader		*read_coord(char *coord)
{
	t_reader		*reader;
	char			**coord_info;
	char			*z;
	char			*color;

	coord_info = ft_strsplit(coord, ',');
	z = coord_info[0];
	color = coord_info[1];
	if (coord_info[1])
		reader = init_reader(ft_atoi(z), atoi_h(color));
	else
		reader = init_reader(ft_atoi(z), decide_color(ft_atoi(z)));
	return (reader);
}

static t_reader		*read_line(char **line, t_map *map, t_reader *reader)
{
	t_reader		*temp;
	int				width;
	int				i;

	width = 0;
	i = -1;
	while (line[++i])
	{
		temp = read_coord(line[i]);
		if (reader == NULL)
			reader = temp;
		else
		{
			reader->next = temp;
			reader = reader->next;
		}
		width++;
	}
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
		print_error("The map width size is not equal! Not a square!");
	return (reader);
}

void				reader_data_to_map(t_map *map, t_reader *reader)
{
	t_reader		*temp;
	int				total;
	int				i;
	int				z_total;

	i = -1;
	temp = reader;
	z_total = 0;
	total = map->width * map->height;
	if (!(map->position = (int *)ft_memalloc(sizeof(int) * total)))
		print_error("Memory allocating fail");
	if (!(map->color = (int *)ft_memalloc(sizeof(int) * total)))
		print_error("Memory allocating fail");
	while (++i < total)
	{
		map->position[i] = reader->z;
		z_total += reader->z;
		map->color[i] = reader->color;
		if (reader->next)
			reader = reader->next;
	}
	map->width_c = map->width / 2;
	map->height_c = map->height / 2;
	map->altitude_c = z_total / total;
	free_reader(temp);
}

t_reader			*process_file(int fd, t_map *map)
{
	t_reader		*reader;
	t_reader		*current;
	char			*line;
	int				result;

	reader = NULL;
	current = NULL;
	while ((result = get_next_line(fd, &line)))
	{
		if (result == -1)
		{
			free(map);
			print_error("Error occured while reading the file");
		}
		current = read_line(ft_strsplit(line, ' '), map, current);
		if (reader == NULL)
			reader = current;
		map->height++;
	}
	return (reader);
}
