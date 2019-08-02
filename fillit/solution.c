/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:21:01 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 17:58:12 by hypark           ###   ########.fr       */
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

char				**init_piece(char *piece, int x_len, int y_len)
{
	int				i;
	int				j;
	char			**map;

	if (!(map = (char **)malloc(sizeof(char *) * y_len)))
		return (0);
	i = -1;
	while (++i < y_len)
		if (!(map[i] = (char *)malloc(sizeof(char) * x_len)))
			return (0);
	i = 0;
	while (i < y_len)
	{
		j = 0;
		while (j < x_len)
		{
			map[i][j] = piece[j + (i * x_len)];
			j++;
		}
		i++;
	}
	return (map);
}

int					search(char **a, char **m, t_tetris *t, int iter_n)
{
	char			**c_m;
	int				x_len;
	int				y_len;
	int				i;

	a = 0;
	m = 0;
	i = t->total - iter_n;
	x_len = t->x_info[i];
	y_len = t->y_info[i];
	if (!(c_m = init_piece(t->piece_info[i], x_len, y_len)))
		return (0);
	while (1)
		return (1);
}

int					find_solution(t_tetris *t, char **solution)
{
	char			**map;
	unsigned short	i;

	t->m_size = find_map_size(t->total);
	while (solution == NULL)
	{
		if (!(map = (char **)malloc(sizeof(char *) * (t->m_size))))
			return (0);
		i = -1;
		while (++i < t->m_size)
			if (!(map[i] = (char *)malloc(sizeof(char) * (t->m_size))))
				return (0);
		if(!search(solution, map, t, t->total))
			return (0);
	}
	return (1);
}
