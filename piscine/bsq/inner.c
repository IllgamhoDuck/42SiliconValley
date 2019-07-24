/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hule <hule@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:57:36 by hule              #+#    #+#             */
/*   Updated: 2018/06/06 23:14:52 by hule             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			update_square(t_bsq *bsq, unsigned int square_size)
{
	unsigned int	old_trailing_square;

	old_trailing_square = bsq->trailing_square;
	bsq->trailing_square = bsq->squares[bsq->x];
	if (bsq->x == 0)
		bsq->squares[bsq->x] = square_size;
	else
		bsq->squares[bsq->x] = square_size ? MIN(old_trailing_square,
			MIN(bsq->squares[bsq->x - 1], bsq->squares[bsq->x])) + 1 : 0;
}

void			update_solution_initial(t_bsq *bsq)
{
	if (bsq->squares_initial[bsq->x] > bsq->sol_size)
	{
		bsq->sol_size = bsq->squares_initial[bsq->x];
		bsq->sol_x = bsq->x - (bsq->sol_size - 1);
		bsq->sol_y = bsq->y - (bsq->sol_size - 1);
	}
}

void			update_solution(t_bsq *bsq)
{
	if (bsq->squares[bsq->x] > bsq->sol_size)
	{
		bsq->sol_size = bsq->squares[bsq->x];
		bsq->sol_x = bsq->x - (bsq->sol_size - 1);
		bsq->sol_y = bsq->y - (bsq->sol_size - 1);
	}
}

int				append_to_map_initial(t_bsq *bsq, t_map_info *map_info, t_u8 c)
{
	t_u8		square_size;

	square_size = c == map_info->empty ? 1 : 0;
	if (c != map_info->obs && c != map_info->empty)
		return (-1);
	if (bsq->squares_initial == NULL)
		bsq->squares_initial =
			malloc(sizeof(*bsq->squares_initial) * bsq->capacity);
	if (bsq->x >= bsq->capacity)
		grow_squares_array(bsq);
	bsq->squares_initial[bsq->x] = square_size;
	update_solution_initial(bsq);
	bsq->x++;
	return (0);
}

int				append_to_map(t_bsq *bsq, t_map_info *map_info, t_u8 c)
{
	unsigned int	square_size;
	unsigned int	i;
	unsigned int	size;

	square_size = c == map_info->empty ? 1 : 0;
	if (c != map_info->obs && c != map_info->empty)
		return (-1);
	if (square_size)
		set_bit(bsq->map_bits[bsq->y], bsq->x);
	update_square(bsq, square_size);
	update_solution(bsq);
	if (++bsq->x >= map_info->width)
	{
		bsq->x = 0;
		if (++bsq->y < map_info->height && !bsq->map_bits[bsq->y])
		{
			bsq->map_bits[bsq->y] = malloc(sizeof(**bsq->map_bits) *
				map_info->width);
			size = (map_info->width + UINT_SIZE - 1) / UINT_SIZE;
			i = 0;
			while (i < size)
				bsq->map_bits[bsq->y][i++] = 0;
		}
	}
	return (0);
}
