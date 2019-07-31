/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:34:35 by hypark            #+#    #+#             */
/*   Updated: 2019/07/31 01:16:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** free the memory
** and valid the piece. we checked everything
** but not the valid shape one
*/

int				main(int ac, char **av)
{
	t_input		*input;

	if (ac == 2)
	{
		if (!(input = process_file(open(av[1], O_RDONLY))))
		{
			print_error();
			exit(1);
		}
		printf("%d\n", input->reader->total);
		printf("%s\n", input->piece);
		printf("%s\n", input->next->piece);
		printf("%s\n", input->next->next->piece);
		printf("%s\n", input->next->next->next->piece);
	}
	else
		ft_putstr("usage: fillit source file\n");
	return (0);
}

