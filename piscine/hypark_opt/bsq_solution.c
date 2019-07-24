/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:38:12 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 01:30:39 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				ft_pre_value(int **i_arr, int *r_arr, int i, int j)
{
	int			r;

	r = 0;
	if (i_arr[i][j] == 1)
	{
		if (j == 1)
		{
			r = ft_min(r_arr[1], i_arr[i - 1][0], i_arr[i][0]) + 1;
			r_arr[0] = r_arr[1];
			r_arr[1] = r;
		}
		else
		{
			r = ft_min(r_arr[0], r_arr[j - 1], r_arr[j]) + 1;
			r_arr[0] = r_arr[j];
			r_arr[j] = r;
		}
		return (r);
	}
	else
	{
		r_arr[0] = r_arr[j];
		r_arr[j] = 0;
	}
	return (0);
}

void			ft_pre_max(t_max *max, int r, int i, int j)
{
	if (max->max_r < r)
	{
		max->max_r = r;
		max->max_i = i;
		max->max_j = j;
	}
}

void			ft_preprocess(int **i_arr, t_max *max, int row, int col)
{
	int			i;
	int			j;
	int			r;
	int			*r_arr;

	i = -1;
	j = -1;
	r_arr = (int *)malloc(sizeof(int) * col);
	while (++j < col)
		r_arr[j] = i_arr[0][j];
	ft_square_max(i_arr, max, row, col);
	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			r = ft_pre_value(i_arr, r_arr, i, j);
			ft_pre_max(max, r, i, j);
		}
	}
	free(r_arr);
}

void			ft_square_max(int **i_arr, t_max *max, int row, int col)
{
	int			i;
	int			j;

	j = -1;
	max->max_r = i_arr[0][0];
	while (++j < col)
	{
		if (max->max_r < i_arr[0][j])
		{
			max->max_r = i_arr[0][j];
			max->max_i = 0;
			max->max_j = j;
		}
	}
	i = 0;
	while (++i < row)
	{
		if (max->max_r < i_arr[i][0])
		{
			max->max_r = i_arr[i][0];
			max->max_i = i;
			max->max_j = 0;
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
