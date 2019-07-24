/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:38:12 by hypark            #+#    #+#             */
/*   Updated: 2018/06/05 18:42:13 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				ft_square_min(int i, int j, int k)
{
	int			min;

	min = 2147483647;
	if (i < min)
		min = i;
	if (j < min)
		min = j;
	if (k < min)
		min = k;
	return (min);
}

int				**ft_square_preprocess(int **i_arr, int row, int col)
{
	int			i;
	int			j;
	int			**r_arr;

	r_arr = ft_int_2d(row, col);
	i = -1;
	j = -1;
	while (++i < row)
		r_arr[i][0] = i_arr[i][0];
	while (++j < col)
		r_arr[0][j] = i_arr[0][j];
	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			if (i_arr[i][j] == 1)
				r_arr[i][j] = ft_square_min(r_arr[i][j - 1],
						r_arr[i - 1][j], r_arr[i - 1][j - 1]) + 1;
			else
				r_arr[i][j] = 0;
		}
	}
	return (r_arr);
}

void			ft_square_max(int **r_arr, t_max *max, int row, int col)
{
	int			i;
	int			j;

	max->max_r = r_arr[0][0];
	max->max_i = 0;
	max->max_j = 0;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (max->max_r < r_arr[i][j])
			{
				max->max_r = r_arr[i][j];
				max->max_i = i;
				max->max_j = j;
			}
		}
	}
}

int				**ft_square_sol(int **i_arr, t_max *max)
{
	int			i;
	int			j;

	i = max->max_i;
	while (i > max->max_i - max->max_r)
	{
		j = max->max_j;
		while (j > max->max_j - max->max_r)
		{
			i_arr[i][j] = 2;
			j--;
		}
		i--;
	}
	return (i_arr);
}

void			ft_square_finder(int **i_arr, int row, int col, t_map *map)
{
	t_max		max;
	int			**r_arr;
	char		**c_arr;

	c_arr = 0;
	ft_putstr("\nPreprocessing the map\n\n");
	r_arr = ft_square_preprocess(i_arr, row, col);
	ft_print_int_2d(r_arr, row, col);
	ft_putstr("\nFinding the MAX coordinate!\n");
	ft_square_max(r_arr, &max, row, col);
	if (max.max_r == 0)
	{
		ft_putstr("\nThere is no solution in this map!\n");
		return ;
	}
	ft_putstr("\nFound the the solution!\n\n");
	i_arr = ft_square_sol(i_arr, &max);
	ft_print_int_2d(i_arr, row, col);
	ft_putstr("\nTransfering int 2d -> char 2d...\n\n");
	c_arr = ft_int_char(i_arr, row, col, map);
	ft_print_char_2d(c_arr, row, col);
	ft_putstr("\nBSQ DONE\n");
}
