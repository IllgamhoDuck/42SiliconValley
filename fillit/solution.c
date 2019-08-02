/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:21:01 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 12:26:36 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					find_map_size(int total)
{
	int				map_size;
	int				piece_size;

	map_size = 2;
	piece_size = total * 4;
	while (map_size * map_size < piece_size)
		map_size++;
	return (map_size);
}

t_map				*init_piece(char *piece, int x_len, int y_len, t_tetris *t)
{
	int				i;
	int				j;
	t_map			*c_map;

	if (!(c_map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(c_map->map = (char **)malloc(sizeof(char *) * y_len)))
		return (0);
	i = -1;
	while (++i < y_len)
		if (!(c_map->map[i] = (char *)malloc(sizeof(char) * x_len)))
			return (0);
	i = -1;
	while (++i < y_len)
	{
		j = -1;
		while (++j < x_len)
			c_map->map[i][j] = piece[j + (i * x_len)];
	}
	c_map->x_len = x_len;
	c_map->y_len = y_len;
	c_map->c = '\0';
	c_map->m_size = t->m_size;
	c_map->error = 0;
	return (c_map);
}

char				**init_map(t_tetris *t)
{
	char			**map;
	unsigned short	i;
	unsigned short	j;

	if (!(map = (char **)malloc(sizeof(char *) * (t->m_size))))
		return (0);
	i = -1;
	while (++i < t->m_size)
		if (!(map[i] = (char *)malloc(sizeof(char) * (t->m_size))))
			return (0);
	i = 0;
	while (i < t->m_size)
	{
		j = 0;
		while (j < t->m_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int					search(char ***a, char **m, t_tetris *t, int iter_n)
{
	t_map			*c_m;
	char			**tmp_m;
	int				i;
	int				j;

	i = t->total - iter_n;
	if (!(c_m = init_piece(t->piece_info[t->pieces[i] - 1], \
				t->x_info[t->pieces[i] - 1], t->y_info[t->pieces[i] - 1], t)))
		return (free_error_no_c_m(m, t->m_size));
	c_m->c = t->alphabet[i];
	i = -1;
	while (++i < t->m_size - c_m->y_len + 1)
	{
		j = -1;
		while (++j < t->m_size - c_m->x_len + 1)
		{
			if ((tmp_m = valid_place(m, c_m, i, j)))
				if (*a || !(search_helper(a, tmp_m, t, iter_n)))
					return (free_with_c_m(m, c_m));
			if (*a || c_m->error == 1)
				return (free_with_c_m(m, c_m));
		}
	}
	free_search(m, c_m);
	return (1);
}

int					find_solution(t_tetris *t, char ***solution)
{
	char			**map;

	t->m_size = find_map_size(t->total);
	t->m_size--;
	while (*solution == NULL)
	{
		t->m_size++;
		map = init_map(t);
		if (!search(solution, map, t, t->total))
			if (*solution == NULL)
				return (0);
	}
	return (1);
}
