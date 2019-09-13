/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 00:00:47 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 02:58:27 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int				*copy_map(t_filler *filler, int *copy_map)
{
	int			map_size;
	int			*map;
	int			i;

	map_size = MAP_X * MAP_Y;
	map = (int *)malloc(sizeof(int) * map_size);
	i = -1;
	while (++i < map_size)
		map[i] = copy_map[i];
	return (map);
}
