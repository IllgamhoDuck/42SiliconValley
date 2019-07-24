/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:52:31 by hypark            #+#    #+#             */
/*   Updated: 2018/06/05 18:29:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char			**ft_1d_2d(char *str, int row, int col)
{
	char		**arr;
	int			i;
	int			j;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * row);
	while (i < row)
	{
		arr[i] = (char *)malloc(sizeof(char) * (col + 1));
		j = 0;
		while (j < col)
		{
			arr[i][j] = str[i * (col + 1) + j];
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

int				**ft_char_int(char **c_arr, int row, int col, t_map *map)
{
	int			**i_arr;
	int			i;
	int			j;

	i = 0;
	i_arr = (int **)malloc(sizeof(int *) * row);
	while (i < row)
	{
		i_arr[i] = (int *)malloc(sizeof(int) * col);
		j = 0;
		while (j < col)
		{
			if (c_arr[i][j] == map->empty)
				i_arr[i][j] = 1;
			else if (c_arr[i][j] == map->obstacle)
				i_arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (i_arr);
}

char			**ft_int_char(int **i_arr, int row, int col, t_map *map)
{
	char		**c_arr;
	int			i;
	int			j;

	i = 0;
	c_arr = (char **)malloc(sizeof(char *) * row);
	while (i < row)
	{
		c_arr[i] = (char *)malloc(sizeof(char) * (col + 1));
		j = 0;
		while (j < col)
		{
			if (i_arr[i][j] == 0)
				c_arr[i][j] = map->obstacle;
			else if (i_arr[i][j] == 1)
				c_arr[i][j] = map->empty;
			else if (i_arr[i][j] == 2)
				c_arr[i][j] = map->full;
			j++;
		}
		c_arr[i][j] = '\0';
		i++;
	}
	return (c_arr);
}

int				**ft_int_2d(int row, int col)
{
	int			**i_arr;
	int			i;

	i = 0;
	i_arr = (int **)malloc(sizeof(int *) * row);
	while (i < row)
	{
		i_arr[i] = (int *)malloc(sizeof(int) * col);
		i++;
	}
	return (i_arr);
}
