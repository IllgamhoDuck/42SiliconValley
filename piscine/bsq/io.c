/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:06:58 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:12:30 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_u8			next_input(t_reader *r)
{
	if (r->index < r->length)
		return (r->buf[r->index++]);
	r->length = read(r->fd, r->buf, BUF_SIZE);
	r->index = 0;
	if (r->length <= 0)
		return (0);
	else
		return (r->buf[r->index++]);
}

void			set_row(t_u8 *row, t_bsq *bsq, t_map_info *map_info,
					unsigned int j)
{
	unsigned int	i;
	unsigned int	end_y;
	unsigned int	end_x;

	end_y = bsq->sol_y + bsq->sol_size;
	end_x = bsq->sol_x + bsq->sol_size;
	i = 0;
	while (i < map_info->width)
	{
		if (j >= bsq->sol_y && j < end_y && i >= bsq->sol_x && i < end_x)
			row[i] = map_info->full;
		else
			row[i] = get_bit(bsq->map_bits[j], i) ? map_info->empty :
				map_info->obs;
		i++;
	}
}

void			print_solution(t_bsq *bsq, t_map_info *map_info)
{
	unsigned int	j;
	t_u8			*row;

	row = malloc(sizeof(*row) * map_info->width);
	j = 0;
	while (j < map_info->height)
	{
		set_row(row, bsq, map_info, j);
		free(bsq->map_bits[j]);
		bsq->map_bits[j] = NULL;
		write(1, row, map_info->width);
		write(1, "\n", 1);
		j++;
	}
	free(row);
}
