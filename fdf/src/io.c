/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:10:18 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 22:18:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_reader		*read_coord(char *coord)
{
	t_reader		*reader;
	char			**coord_info;
	char			*z;
	char			*color;

	coord_info = ft_strsplit(coord, ',');
	z = coord_info[0];
	color = coord_info[1];
	if (color < 0)
		print_error("Invalid color!!");
	if (coord_info[1])
		reader = init_reader(ft_atoi(z), atoi_h(color));
	else
		reader = init_reader(ft_atoi(z), -1);
	free_str(coord_info);
	return (reader);
}

static t_reader		*read_line(char **line, t_map *map, t_reader *reader)
{
	int				width;
	int				i;

	width = 0;
	i = -1;
	while (line[++i])
	{
		reader->next = read_coord(line[i]);
		reader = reader->next;
		width++;
	}
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
		print_error("The map width size is not equal! Not a square!");
	free_str(line);
	return (reader);
}

void				reader_data_to_map(t_map *map, t_reader *reader)
{
	t_reader		*temp;
	int				total;
	int				i;

	i = -1;
	temp = reader;
	total = map->width * map->height;
	if (!(map->position = (int *)ft_memalloc(sizeof(int) * total)))
		print_error("Memory allocating fail");
	if (!(map->color = (int *)ft_memalloc(sizeof(int) * total)))
		print_error("Memory allocating fail");
	while (++i < total)
	{
		map->position[i] = reader->z;
		map->color[i] = reader->color;
		if (reader->z > map->z_max)
			map->z_max = reader->z;
		if (reader->z < map->z_min)
			map->z_min = reader->z;
		if (reader->next)
			reader = reader->next;
	}
	free_reader(temp);
}

t_reader			*process_file(int fd, t_map *map)
{
	t_reader		*reader;
	t_reader		*current;
	char			*line;
	int				result;

	reader = init_reader(0, 0);
	current = reader;
	while ((result = get_next_line(fd, &line)))
	{
		if (result == -1)
		{
			free(map);
			print_error("Error occured while reading the file");
		}
		current = read_line(ft_strsplit(line, ' '), map, current);
		map->height++;
		free(line);
	}
	current = reader->next;
	free(reader);
	reader = current;
	return (reader);
}
