/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:21:46 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/17 13:36:21 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		main(int ac, char **av)
{
	t_error	err;

	err = NULL;
	if (ac == 2)
	{
		err = assembler(av[1]);
		if (err)
		{
			ft_putstr(err);
			ft_putchar('\n');
			free(err);
			return (1);
		}
	}
	else
		ft_printf("usage: ./asm monchampion.s\n");
	return (0);
}
