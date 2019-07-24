/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:30:14 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/06/03 23:31:49 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int				*ft_col_arr(char *str, int row)
{
	char		*start;
	int			*col_arr;
	int			col;
	int			i;
	
	col = 0;
	i = 0;
	start = str;
	col_arr = (int *)malloc(sizeof(int) * row);
	while (*str)
	{
		col++;
		if (*str == '\n')
		{
			col_arr[i] = col;
			start = str + 1;
			i++;
			col = 0;
		}
		str++;
	}
	if (*start)
		col_arr[i] = col;
	return (col_arr);
}

int				*ft_str_array(char *str, int *row)
{
	int			col;
	int			*col_arr;

	*row = ft_row_len(str);
	col_arr = ft_col_arr(str, *row);
	return (col_arr);
}

int				ft_check_same(int *arr, int size)
{
	int			i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] != arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void			ft_row_col(char *str)
{
	int			same;
	int			row;
	int			*col_arr;
	int			or;

	or = 0;
	col_arr = ft_str_array(str, &row);
	same = ft_check_same(col_arr, row);
	if (!same)
	{
		ft_putstr("error!");
		return ;
	}
	ft_rush0(str, col_arr[0] - 1, row, or);
}
