/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:08:50 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 12:25:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				free_list(t_tetris *t, t_input *input, int iter_num)
{
	if (iter_num == 1)
	{
		t->pieces[t->total - iter_num] = input->piece;
		t->pieces[t->total] = '\0';
		free(input);
		return ;
	}
	else
	{
		t->pieces[t->total - iter_num] = input->piece;
		free_list(t, input->next, iter_num - 1);
		free(input);
		return ;
	}
}

void				free_map(char **map, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void				free_search(char **map, t_map *c_map)
{
	int				size;

	size = c_map->m_size;
	free_map(map, size);
	free_map(c_map->map, c_map->y_len);
	free(c_map);
}

int					free_error_no_c_m(char **map, int size)
{
	free_map(map, size);
	return (0);
}

int					free_with_c_m(char **map, t_map *c_map)
{
	free_search(map, c_map);
	return (0);
}
