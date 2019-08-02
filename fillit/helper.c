/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 22:53:24 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 12:30:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**copy_map(char **m, t_map *c_m, int y, int x)
{
	char			**copied_map;
	unsigned short	i;
	unsigned short	j;

	if (!(copied_map = (char **)malloc(sizeof(char *) * c_m->m_size)))
	{
		c_m->error = 1;
		return (0);
	}
	i = -1;
	while (++i < c_m->m_size)
		if (!(copied_map[i] = (char *)malloc(sizeof(char) * (c_m->m_size))))
		{
			c_m->error = 1;
			return (0);
		}
	i = -1;
	while (++i < c_m->m_size)
	{
		j = -1;
		while (++j < c_m->m_size)
			copied_map[i][j] = m[i][j];
	}
	return (apply_to_map(copied_map, c_m, y, x));
}

char				**apply_to_map(char **cp_m, t_map *c_m, int y, int x)
{
	unsigned short	i;
	unsigned short	j;

	i = -1;
	while (++i < c_m->y_len)
	{
		j = -1;
		while (++j < c_m->x_len)
			if (c_m->map[i][j] == '#')
				cp_m[y + i][x + j] = c_m->c;
	}
	return (cp_m);
}

int					search_helper(char ***a, char **m, t_tetris *t, int iter_n)
{
	if (iter_n == 1)
	{
		if (!(store_result(a, m, t)))
			return (0);
		return (1);
	}
	if (!(search(a, m, t, iter_n - 1)))
		return (0);
	return (1);
}

int					store_result(char ***a, char **m, t_tetris *t)
{
	if (*a == NULL)
	{
		if (!(copy_between_map(a, m, t->m_size)))
			return (0);
		return (1);
	}
	return (0);
}
