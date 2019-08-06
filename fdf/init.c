/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:37:25 by hypark            #+#    #+#             */
/*   Updated: 2019/08/06 03:08:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map				*init_map(void)
{
	t_map			*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		print_error("Memory allocating fail"); 
	map->width = 0;
	map->height = 0;
	map->position = NULL;
	map->color = NULL;
	return (map);
}

t_reader			*init_reader(int z, int color)
{
	t_reader		*reader;

	if (!(reader = (t_reader *)ft_memalloc(sizeof(t_reader))))
		print_error("Memory allocating fail"); 
	reader->z = z;
	reader->color = color;
	reader->next = NULL;
	return (reader);
}
