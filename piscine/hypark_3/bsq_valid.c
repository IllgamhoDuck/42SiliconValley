/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:39:01 by hypark            #+#    #+#             */
/*   Updated: 2018/06/06 01:43:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				ft_check_col(int *col_arr, int size)
{
	int			i;

	i = 0;
	while (i < size - 1)
	{
		if (col_arr[i] != col_arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void			ft_col_arr(char *str, int **col_arr, int row)
{
	char		*start;
	int			col;
	int			i;

	col = 0;
	i = 0;
	start = str;
	*col_arr = (int *)malloc(sizeof(**col_arr) * row);
	while (*str)
	{
		col++;
		if (*str == '\n')
		{
			col_arr[0][i] = col;
			start = str + 1;
			i++;
			col = 0;
		}
		str++;
	}
	if (*start)
		col_arr[0][i] = col;
}

/*
** Brokes at row 90 col 90 and row 50 col 200 don't know the reason
*/

void			ft_row_newline(char *str, int *row, int *newline)
{
	while (*str)
	{
		if (*str == '\n')
		{
			(*newline)++;
			(*row)++;
		}
		str++;
	}
	if (*(str - 1) != '\n')
		(*row)++;
}

int				ft_char_check(char *str, t_map *map)
{
	while (*str)
	{
		if (*str != map->empty && *str != map->obstacle && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

int				ft_valid_check(char *str, int **col_arr, t_map *map)
{
	int			row;
	int			newline;

	row = 0;
	newline = 0;
	if (*str == '\0' || *str == '\n')
		return (0);
	if (ft_char_check(str, map))
		return (0);
	ft_row_newline(str, &row, &newline);
	if (row != newline)
		return (0);
	if (row != map->line)
		return (0);
	ft_col_arr(str, col_arr, row);
	if (ft_check_col(*col_arr, row))
		return (0);
	return (row);
}
