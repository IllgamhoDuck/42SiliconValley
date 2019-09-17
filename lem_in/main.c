/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:17:08 by hypark            #+#    #+#             */
/*   Updated: 2019/09/16 20:59:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <fcntl.h>

int					main(int ac, char **av)
{
	t_ant			*ant;

	if (ac == 2)
		open(av[1], O_RDONLY);
	ant = init_ant();
	read_file(ant);
	search_path(ant);
	print_ant(ant);
	print_adj_matrix(ant);
	print_path(ant);
	free_ant(ant);
	return (0);
}
