/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 02:31:45 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 03:07:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void				delete_12_map(t_filler *filler)
{
	int					map_size;
	int					i;

	map_size = MAP_X * MAP_Y;
	i = -1;
	while (++i < map_size)
		if (NOT_12(filler->map[i]) == 0)
			filler->map[i] = -3;
}

void				recover_12_map(t_filler *filler, int *map)
{
	int					map_size;
	int					i;

	map_size = MAP_X * MAP_Y;
	i = -1;
	while (++i < map_size)
		if (NOT_12(map[i]) == 0)
			filler->map[i] = map[i];
}
