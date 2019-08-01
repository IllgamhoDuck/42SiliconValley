/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:34:35 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 03:25:37 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** time to make the recursion input is ready
** need to make a function that inputs the map and the pieces and where its
** possible to put there. after applying to map
** and that will be feed to next node.
*/

int					main(int ac, char **av)
{
	t_tetris		*t;
	int				i;

	if (ac == 2)
	{
		if (!(t = process_file(open(av[1], O_RDONLY))))
		{
			print_error();
			exit(1);
		}
		printf("The total number of pieces are : %d\n", t->total);
		printf("The pieces that were inputed were\n\n");
		i = 0;
		while (t->pieces[i])
			printf("%d\n", t->pieces[i++]);
	}
	else
		ft_putstr("usage: fillit source file\n");
	return (0);
}

