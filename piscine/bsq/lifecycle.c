/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:42:10 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:08:14 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			grow_squares_array(t_bsq *bsq)
{
	t_u8			*new_squares;
	t_u8			*old_squares;
	unsigned int	i;

	bsq->capacity *= 2;
	new_squares = malloc(sizeof(*new_squares) * bsq->capacity);
	i = 0;
	while (i < bsq->x)
	{
		new_squares[i] = bsq->squares_initial[i];
		i++;
	}
	old_squares = bsq->squares_initial;
	bsq->squares_initial = new_squares;
	free(old_squares);
}

void			init(t_reader *reader, t_bsq *bsq, int fd)
{
	reader->length = 0;
	reader->index = 0;
	reader->fd = fd;
	bsq->map_bits = NULL;
	bsq->squares_initial = NULL;
	bsq->squares = NULL;
	bsq->trailing_square = 0;
	bsq->capacity = START_SIZE;
	bsq->x = 0;
	bsq->y = 0;
	bsq->sol_x = 0;
	bsq->sol_y = 0;
	bsq->sol_size = 0;
}

void			cleanup(t_bsq *bsq, t_map_info *map_info)
{
	unsigned int	i;

	if (bsq->map_bits)
	{
		i = 0;
		while (i < map_info->height)
		{
			if (bsq->map_bits[i])
				free(bsq->map_bits[i]);
			i++;
		}
		free(bsq->map_bits);
	}
	if (bsq->squares)
		free(bsq->squares);
}
