/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:59:48 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 03:08:16 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_input				*init_input(void)
{
	t_input			*input;

	if (!(input = (t_input *)malloc(sizeof(t_input))))
		return (0);
	input->piece = 0;
	input->next = NULL;
	input->reader = NULL;
	return (input);
}

void				translate_coord(t_reader *r)
{
	int				i;
	int				x;
	int				y;
	unsigned short	min_x;
	unsigned short	min_y;
	
	i = -1;
	min_x = 5;
	min_y = 5;
	while (++i < 4)
	{
		if (min_x > (r->sharp[i] % 5))
			min_x = (r->sharp[i] % 5);
		if (min_y > (r->sharp[i] / 5))
			min_y = (r->sharp[i] / 5);
	}
	i = -1;
	while (++i < 4)
	{
		x = r->sharp[i] % 5;
		y = r->sharp[i] / 5;
		r->sharp[i] = (x - min_x) + 5 * (y - min_y);
	}
}

int					count_char(t_reader *r, char c, int i)
{
	if (r->sharp_num == 5)
		return (0);
	if (c == '#')
	{
		r->sharp[r->sharp_num++] = i;
		return (1);
	}
	if (c == '.')
	{
		r->dot_num++;
		return (1);
	}
	return (0);
}

int					fill_input(t_reader *r, t_input *input)
{
	int				i;
	char			c;

	i = 0;
	while (i < 20)
	{
		if (!(c = get_next_char(r)))
			return (0);
		if (i != 4 && i != 9 && i != 14 && i != 19) 
		{
			if (!(c = count_char(r, c, i)))
				return (0);
		}
		else
		{
			if (c != '\n')
				return (0);
		}
		i++;
	}
	if (r->sharp_num != 4 || r->dot_num != 12)
		return (0);
	translate_coord(r);
	if (!(c = valid_piece(r, input)))
		return (0);
	return (1);
}

int					fill_repeat(t_reader *r, t_input *input)
{
	char			c;
	t_input			*current;

	current = input;
	while (1)
	{
		c = get_next_char(r);
		if (c == '\0')
			return (1);
		else if (c == '\n')
		{
			current->next = init_input();
			current = current->next;
			if (!(fill_input(r, current)))
				return (0);
			r->total += 1;
		}
		else
			return (0);
	}
}
