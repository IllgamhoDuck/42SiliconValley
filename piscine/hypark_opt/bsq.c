/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:52:58 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 01:39:34 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

void			ft_square_finder(int **i_arr, int row, int col, t_map *map)
{
	t_max		*max;
	char		**c_arr;

	max = (t_max *)malloc(sizeof(t_max));
	max->max_i = 0;
	max->max_j = 0;
	c_arr = 0;
	ft_putstr("\nPreprocessing the map\n\n");
	ft_preprocess(i_arr, max, row, col);
	if (max->max_r == 0)
	{
		ft_putstr("\nThere is no solution in this map!\n");
		return ;
	}
	ft_putstr("\nFound the the solution!\n\n");
	i_arr = ft_square_sol(i_arr, max);
	ft_print_int_2d(i_arr, row, col);
	ft_putstr("\nTransfering int 2d -> char 2d...\n\n");
	c_arr = ft_int_char(i_arr, row, col, map);
	ft_print_char_2d(c_arr, row, col);
	ft_putstr("\nBSQ DONE\n");
	free(max);
}

void			ft_bsq(char *str)
{
	int			*col_arr;
	char		**c_arr;
	int			**i_arr;
	int			row;
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (ft_check_map_info(str, map))
	{
		ft_putstr("Invalid map information");
		return ;
	}
	str = ft_delete_map_info(str);
	row = ft_valid_check(str, &col_arr, map);
	if (row)
		ft_putstr("\nValid test past!\n");
	else
	{
		ft_putstr("\nValid test fail!\n");
		return ;
	}
	c_arr = ft_1d_2d(str, row, col_arr[0] - 1);
	ft_print_char_2d(c_arr, row, col_arr[0] - 1);
	i_arr = ft_char_int(c_arr, row, col_arr[0] - 1, map);
	free(c_arr);
	ft_print_int_2d(i_arr, row, col_arr[0] - 1);
	ft_square_finder(i_arr, row, col_arr[0] - 1, map);
	free(map);
}

int				main(void)
{
	char		buf[20000];
	int			ret;

	if ((ret = read(0, buf, 20000)) != -1)
		buf[ret] = '\0';
	else
	{
		ft_putstr("No valid input!\n");
		return (0);
	}
	ft_bsq(buf);
	return (0);
}
