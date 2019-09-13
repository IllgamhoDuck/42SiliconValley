/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:52:01 by hypark            #+#    #+#             */
/*   Updated: 2019/09/11 00:23:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void				print_map(t_filler *filler)
{
	int				map_size;
	int				i;

	map_size = filler->map_x * filler->map_y;
	i = -1;
	while (++i < map_size)
	{
		if (i % filler->map_x == 0)
			ft_putchar('\n');
		ft_printf("%3d", filler->map[i]);
	}
}

void				print_my_map(t_filler *filler)
{
	int				map_size;
	int				i;

	map_size = filler->map_x * filler->map_y;
	i = -1;
	while (++i < map_size)
	{
		if (i % filler->map_x == 0)
			ft_putchar('\n');
		ft_printf("%3d", filler->map_mine[i]);
	}
}

void				print_enemy_map(t_filler *filler)
{
	int				map_size;
	int				i;

	map_size = filler->map_x * filler->map_y;
	i = -1;
	while (++i < map_size)
	{
		if (i % filler->map_x == 0)
			ft_putchar('\n');
		ft_printf("%3d", filler->map_enemy[i]);
	}
}
