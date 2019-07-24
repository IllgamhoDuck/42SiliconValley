/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:19:37 by hypark            #+#    #+#             */
/*   Updated: 2018/05/27 20:40:30 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <unistd.h>

int			ft_find_empty_block(char **sudoku, int *row, int *col)
{
	while (*row < 9)
	{
		while (*col < 9)
		{
			if (sudoku[*row][*col] == '.')
				return (0);
			*col += 1;
		}
		*col = 0;
		*row += 1;
	}
	return (1);
}

int			ft_check_available(char **sudoku, int row, int col, int num)
{
	int		rowstart;
	int		colstart;
	int		i;

	i = 0;
	rowstart = (row / 3) * 3;
	colstart = (col / 3) * 3;
	while (i < 9)
	{
		if (sudoku[row][i] == (num + '0'))
			return (0);
		else if (sudoku[i][col] == (num + '0'))
			return (0);
		else if (sudoku[rowstart + (i % 3)][colstart + (i / 3)] == (num + '0'))
			return (0);
		i++;
	}
	return (1);
}

int			ft_sudoku_solver(char **origin, char **copy, int row, int col)
{
	int		number;
	char	**next_copy;

	number = 0;
	if (ft_find_empty_block(copy, &row, &col))
	{
		ft_copy(origin, copy);
		return (1);
	}
	next_copy = ft_copy_malloc(copy);
	while (++number < 10)
	{
		if (ft_check_available(next_copy, row, col, number))
		{
			next_copy[row][col] = number + '0';
			if (ft_sudoku_solver(origin, next_copy, row, col))
			{
				free(next_copy);
				return (1);
			}
			next_copy[row][col] = '.';
		}
	}
	free(next_copy);
	return (0);
}

int			main(int argc, char *argv[])
{
	char	**copy;
	char	**origin;

	origin = 0;
	if (argc == 10)
	{
		if (ft_check_input(argv) || ft_check_len(argv))
		{
			ft_print_error();
			return (0);
		}
		origin = ft_copy_malloc_main(argv);
		copy = origin;
		if (ft_sudoku_solver(origin, copy, 0, 0))
			ft_print_sudoku(origin);
		else
			ft_print_error();
	}
	else
		ft_print_error();
	free(origin);
	return (0);
}
