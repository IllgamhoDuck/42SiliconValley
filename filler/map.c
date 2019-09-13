/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 00:35:29 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 03:41:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
** 0 means where I can put the pieces on to. and means the distance from me.
** "find" the block and change it "when" it is the number
** -1 : my block
** -2 : enemy block
** -3 : empty
*/

static void				generate_0(t_filler *filler, int find, int when)
{
	int					map_size;
	int					i;

	map_size = MAP_X * MAP_Y;
	i = -1;
	while (++i < map_size)
	{
		if (filler->map[i] == find)
		{
			if (VALID_OFFSET(i, -1, 0) && OFFSET(i, -1, 0) == when)
				filler->map[i] = 0;
			else if (VALID_OFFSET(i, 1, 0) && OFFSET(i, 1, 0) == when)
				filler->map[i] = 0;
			else if (VALID_OFFSET(i, 0, -1) && OFFSET(i, 0, -1) == when)
				filler->map[i] = 0;
			else if (VALID_OFFSET(i, 0, 1) && OFFSET(i, 0, 1) == when)
				filler->map[i] = 0;
		}
	}
}

static void				generate_0_enemy(t_filler *filler)
{
	int					map_size;
	int					i;

	map_size = MAP_X * MAP_Y;
	i = -1;
	while (++i < map_size)
		if (filler->map[i] == -2)
			filler->map[i] = 0;
}

static int				decide_number(t_filler *filler, int i)
{
	int					min;
	int					x;
	int					y;

	min = INT_MAX;
	x = -2;
	while (++x < 2)
	{
		y = -2;
		while (++y < 2)
		{
			if (x != y && ((-1 * x) != y))
			{
				if (VALID_OFFSET(i, x, y) && NOT_123(OFFSET(i, x, y)))
					OFFSET(i, x, y) < min ? min = OFFSET(i, x, y) : 0;
			}
		}
	}
	return (min);
}

static void				generate_map(t_filler *filler)
{
	int					map_size;
	int					i;
	int					min;

	map_size = MAP_X * MAP_Y;
	i = -1;
	while (++i < map_size)
	{
		if (filler->map[i] == -3)
		{
			if ((min = decide_number(filler, i)) != INT_MAX)
				filler->map[i] = min + 1;
		}
		if (i == map_size - 1)
		{
			i = -1;
			while (++i < map_size)
				if (filler->map[i] == -3)
					break ;
			i = i == map_size ? map_size : i - 1;
		}
	}
}

void					process_map(t_filler *filler)
{
	int					*temp;

	filler->map_original = copy_map(filler, filler->map);
	generate_0(filler, -1, -3);
	filler->map_mine = copy_map(filler, filler->map);
	delete_12_map(filler);
	generate_map(filler);
	recover_12_map(filler, filler->map_mine);
	temp = filler->map_mine;
	filler->map_mine = filler->map;
	filler->map = temp;
	free(filler->map);
	filler->map = copy_map(filler,filler->map_original);
	generate_0_enemy(filler);
	filler->map_enemy = copy_map(filler, filler->map);
	delete_12_map(filler);
	generate_map(filler);
	temp = filler->map_enemy;
	filler->map_enemy = filler->map;
	filler->map = temp;
	free(filler->map);
	filler->map = copy_map(filler,filler->map_original);
	//print_my_map(filler);
}
