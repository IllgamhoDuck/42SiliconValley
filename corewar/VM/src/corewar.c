/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:16:35 by hypark            #+#    #+#             */
/*   Updated: 2019/11/13 22:07:37 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Calls all the main functions required to run the virtual machine and
** inititalises the main structure used for the vm.
**
** {int} ac - Number of argument written on command line
** {char **} av - Array containing all the arguments written on command line.
** ----------------------------------------------------------------------------
*/

static void	corewar(int ac, char **av)
{
	t_cw	cw;

	corewar_env(&cw, ac, av);
	corewar_parser(&cw);
	corewar_run(&cw);
}

/*
** ----------------------------------------------------------------------------
** Main function: launches the virtual machine bu calling 'corewar' and prints
** usage if no argument are given.
**
** {int} ac - Number of argument written on command line
** {char **} av - Array containing all the arguments written on command line.
** ----------------------------------------------------------------------------
*/

int			main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("usage: ./corewar [-v] [-d <cycle>]");
		send_error(" [-n <n> champs.cor] champs.cor]\n");
	}
	corewar(--ac, ++av);
	return (0);
}
