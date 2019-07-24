/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:44:36 by hypark            #+#    #+#             */
/*   Updated: 2018/05/27 19:13:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_copy(char **dest, char **copy)
{
	int		row;
	int		col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			dest[row][col] = copy[row][col];
			col++;
		}
		row++;
	}
}

char		**ft_copy_malloc(char **copy)
{
	char	**next_copy;
	int		i;

	i = 0;
	next_copy = (char **)malloc(sizeof(char *) * 9);
	while (i < 9)
	{
		next_copy[i] = (char *)malloc(sizeof(char) * 9);
		i++;
	}
	ft_copy(next_copy, copy);
	return (next_copy);
}

void		ft_copy_main(char **dest, char **copy)
{
	int		row;
	int		col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			dest[row][col] = copy[row + 1][col];
			col++;
		}
		row++;
	}
}

char		**ft_copy_malloc_main(char **main_arg)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * 9);
	while (i < 9)
	{
		copy[i] = (char *)malloc(sizeof(char) * 9);
		i++;
	}
	ft_copy_main(copy, main_arg);
	return (copy);
}
