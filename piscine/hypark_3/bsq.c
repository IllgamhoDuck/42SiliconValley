/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:52:58 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 14:27:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUFSIZE 20000
#include <stdio.h>

void			ft_square_finder(int **i_arr, int row, int col, t_map *map)
{
	t_max		*max;
	char		**c_arr;

	max = (t_max *)malloc(sizeof(t_max));
	max->max_i = 0;
	max->max_j = 0;
	c_arr = 0;
	ft_preprocess(i_arr, max, row, col);
	if (max->max_r == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	i_arr = ft_square_sol(i_arr, max);
	c_arr = ft_int_char(i_arr, row, col, map);
	ft_print_char_2d(c_arr, row, col);
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
		return ;
	str = ft_delete_map_info(str);
	row = ft_valid_check(str, &col_arr, map);
	if (!row)
	{
		write(2, "map error\n", 10);
		return ;
	}
	c_arr = ft_1d_2d(str, row, col_arr[0] - 1);
	i_arr = ft_char_int(c_arr, row, col_arr[0] - 1, map);
	free(c_arr);
	ft_square_finder(i_arr, row, col_arr[0] - 1, map);
	free(map);
}

void			ft_allo(int fd) 
{
	int			ret;
	char		*buf;
	
	buf = (char *)malloc(sizeof(char) * 20000000);
	if ((ret = read(fd, buf, 20000000)) > 0)
	{
		printf("working!");
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_bsq(buf);
	}
	else
		write(2, "map error\n", 10);
	close(fd);
}
		
int				main(int argc, char **argv)
{
	int			fd;
	
	if (argc == 1)
		ft_allo(0);
	else
	{
		while (--argc > 0)
		{
			if ((fd = open(*argv, O_RDONLY)) == -1)
				write(2, "map error\n", 10);
			else
				ft_allo(fd);
			close(fd);
		}
	}
	return (0);
}
