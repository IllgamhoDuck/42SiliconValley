/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:34:35 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 12:30:11 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** time to make the recursion input is ready
** need to make a function that inputs the map and the pieces and where its
** possible to put there. after applying to map
** and that will be feed to next node.
*/

int					copy_between_map(char ***m1, char **m2, int size)
{
	unsigned short	i;
	unsigned short	j;

	if (*m1 == NULL)
	{
		if (!(*m1 = (char **)malloc(sizeof(char *) * size)))
			return (0);
		i = -1;
		while (++i < size)
			if (!((*m1)[i] = (char *)malloc(sizeof(char) * size)))
			{
				free(*m1);
				return (0);
			}
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			(*m1)[i][j] = m2[i][j];
	}
	return (1);
}

void				free_tetris(t_tetris *t)
{
	int				i;

	i = -1;
	free(t->pieces);
	free(t->piece_info);
	free(t->x_info);
	free(t->y_info);
	free(t->alphabet);
	free(t);
}

int					main(int ac, char **av)
{
	t_tetris		*t;
	char			**solution;

	if (ac == 2)
	{
		if (!(t = process_file(open(av[1], O_RDONLY))))
		{
			print_error();
			exit(1);
		}
		solution = NULL;
		if (!find_solution(t, &solution))
		{
			print_error();
			exit(1);
		}
		print_solution(solution, t);
		free_map(solution, t->m_size);
		free_tetris(t);
	}
	else
		ft_putstr("usage: fillit source file\n");
	return (0);
}
