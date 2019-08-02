/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:42:22 by hypark            #+#    #+#             */
/*   Updated: 2019/08/02 02:38:47 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					fill_alphabet(t_tetris *t)
{
	unsigned short	i;
	char			c;
	char			*alpha;

	i = 0;
	c = 'A';
	if (!(alpha = (char *)malloc(sizeof(char) * 27)))
		return (0);
	while (i < 26)
		alpha[i++] = c++;
	alpha[i] = '\0';
	t->alphabet = alpha;
	return (1);
}

void				fill_x_len(t_tetris *t)
{
	unsigned short	i;

	i = 0;
	t->x_info[i++] = 4;
	t->x_info[i++] = 1;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 3;
	t->x_info[i++] = 2;
	t->x_info[i++] = 2;
	t->x_info[i] = '\0';
}

void				fill_y_len(t_tetris *t)
{
	unsigned short	i;

	i = 0;
	t->y_info[i++] = 1;
	t->y_info[i++] = 4;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i++] = 3;
	t->y_info[i++] = 2;
	t->y_info[i] = '\0';
}

void				fill_piece_info(t_tetris *t)
{
	unsigned short	i;

	i = 0;
	t->piece_info[i++] = "####\0";
	t->piece_info[i++] = "####\0";
	t->piece_info[i++] = "##..##\0";
	t->piece_info[i++] = ".####.\0";
	t->piece_info[i++] = ".####.\0";
	t->piece_info[i++] = "#.##.#\0";
	t->piece_info[i++] = "####..\0";
	t->piece_info[i++] = "#.#.##\0";
	t->piece_info[i++] = "..####\0";
	t->piece_info[i++] = "##.#.#\0";
	t->piece_info[i++] = "###..#\0";
	t->piece_info[i++] = "###.#.\0";
	t->piece_info[i++] = "#..###\0";
	t->piece_info[i++] = ".#.###\0";
	t->piece_info[i++] = "###.#.\0";
	t->piece_info[i++] = ".###.#\0";
	t->piece_info[i++] = ".#.###\0";
	t->piece_info[i++] = "#.###.\0";
	t->piece_info[i++] = "####\0";
	t->piece_info[i++] = NULL;
}

int					fill_info(t_tetris *t)
{
	int				i;

	i = 0;
	t->m_size = 0;
	if (!(fill_alphabet(t)))
		return (0);
	if (!(t->x_info = (char *)malloc(sizeof(char) * 20)))
		return (0);
	if (!(t->y_info = (char *)malloc(sizeof(char) * 20)))
		return (0);
	fill_x_len(t);
	fill_y_len(t);
	if (!(t->piece_info = (char **)malloc(sizeof(char *) * 20)))
		return (0);
	while (i < 19)
	{
		if (!(t->piece_info[i] = (char *)malloc(sizeof(char) * 7)))
			return (0);
		i++;
	}
	fill_piece_info(t);
	return (1);
}
