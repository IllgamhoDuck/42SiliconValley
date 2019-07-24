/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:52:58 by hypark            #+#    #+#             */
/*   Updated: 2018/06/05 18:47:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

void			ft_bsq(char *str)
{
	int			row;
	int			*col_arr;
	char		**c_arr;
	int			**i_arr;
	t_map		*map;

	printf("Given the following data!\n\n");
	ft_putstr(str);
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
	ft_putstr("Every test is passed and now work on the bsq!\n");
	ft_putstr("Suscessfully checked the map information!\n\n");
	ft_putstr(str);
	printf("\nBSQ Map row is %d, column is %d\n", row, col_arr[0] - 1);
	printf("Map line number is %d\n", map->line);
	printf("Map empty character is %c\n", map->empty);
	printf("Map obstacle character is %c\n", map->obstacle);
	printf("Map full character is %c\n", map->full);
	printf("\nTranslating 1D -> 2D...\n\n");
	c_arr = ft_1d_2d(str, row, col_arr[0] - 1);
	ft_print_char_2d(c_arr, row, col_arr[0] - 1);
	printf("\nTranslating char 2D -> int 2D...\n\n");
	i_arr = ft_char_int(c_arr, row, col_arr[0] - 1, map);
	free(c_arr);
	ft_print_int_2d(i_arr, row, col_arr[0] - 1);
	ft_square_finder(i_arr, row, col_arr[0] - 1, map);
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
