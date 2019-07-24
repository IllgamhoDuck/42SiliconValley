/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:35:15 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:17:30 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			copy_sq_init_to_map(t_bsq *bsq, t_map_info *map_info)
{
	unsigned int	i;

	i = 0;
	while (i < map_info->width)
	{
		if (bsq->squares_initial[i])
			set_bit(bsq->map_bits[0], i);
		i++;
	}
	free(bsq->squares_initial);
}

void			alloc_map_initial(t_bsq *bsq, t_map_info *map_info)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	size;

	bsq->map_bits = malloc(sizeof(*bsq->map_bits) * map_info->height);
	size = (map_info->width + UINT_SIZE - 1) / UINT_SIZE;
	j = 0;
	while (j < map_info->height)
	{
		if (j < 2)
		{
			bsq->map_bits[j] = malloc(sizeof(**bsq->map_bits) * size);
			i = 0;
			while (i < size)
				bsq->map_bits[j][i++] = 0;
		}
		else
			bsq->map_bits[j] = 0;
		j++;
	}
	copy_sq_init_to_map(bsq, map_info);
}

void			init_map(t_bsq *bsq, t_map_info *map_info)
{
	unsigned int	i;
	unsigned int	*old_squares;

	alloc_map_initial(bsq, map_info);
	old_squares = bsq->squares;
	bsq->squares = malloc(sizeof(*bsq->squares) * map_info->width);
	bsq->capacity = map_info->width;
	free(old_squares);
	i = 0;
	while (i < map_info->width)
	{
		bsq->squares[i] = get_bit(bsq->map_bits[0], i);
		i++;
	}
	bsq->y = 1;
	bsq->x = 0;
}

int				process_rest_of_file(t_bsq *bsq, t_map_info *map_info,
					t_reader *reader)
{
	unsigned int	j;
	unsigned int	i;
	t_u8			c;

	j = 1;
	while (j++ < map_info->height)
	{
		i = 0;
		while (i++ < map_info->width)
		{
			if (!(c = next_input(reader)) || append_to_map(bsq, map_info, c))
				return (-1);
		}
		if (!(c = next_input(reader)) || c != '\n')
			return (-1);
	}
	if ((c = next_input(reader)))
		return (-1);
	return (0);
}

int				process_file(int fd)
{
	t_reader		reader;
	t_bsq			bsq;
	t_map_info		map_info;
	t_u8			c;

	init(&reader, &bsq, fd);
	if (read_header(&reader, &map_info))
		return (-1);
	if (!is_header_valid(&map_info))
		return (-1);
	while ((c = next_input(&reader)) && c != '\n')
		if (append_to_map_initial(&bsq, &map_info, c))
			return (-1);
	if (c != '\n')
		return (-1);
	if ((map_info.width = bsq.x) < 1)
		return (-1);
	init_map(&bsq, &map_info);
	if (process_rest_of_file(&bsq, &map_info, &reader))
		return (-1);
	print_solution(&bsq, &map_info);
	cleanup(&bsq, &map_info);
	return (0);
}
