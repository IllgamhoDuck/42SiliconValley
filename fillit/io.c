/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:58:36 by hypark            #+#    #+#             */
/*   Updated: 2019/08/01 03:32:20 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_reader			*init_reader(int fd)
{
	t_reader		*r;

	if (!(r = (t_reader *)malloc(sizeof(t_reader))))
		return (0);
	if (!(r->buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if (!(r->sharp = (char *)malloc(sizeof(char) * 4)))
		return (0);
	r->sharp_num = 0;
	r->dot_num = 0;
	r->i = 0;
	r->len = 0;
	r->fd = fd;
	r->total = 0;
	return (r);
}

char				get_next_char(t_reader *r)
{
	char			c;

	if (r->i < r->len)
	{
		c = r->buff[r->i++];
		if (!valid_char(c) || c <= 0)
			return (0);
		else
			return (c);
	}
	if ((r->len = read(r->fd, r->buff, BUFF_SIZE)) < 0)
		return (-1);
	r->i = 0;
	if (r->len == 0)
		return (0);
	else
	{
		c = r->buff[r->i++];
		if (!valid_char(c) || c <= 0)
			return (0);
		else
			return (c);
	}
}

t_tetris				*compress_input(t_reader *r, t_input *input)
{
	t_tetris			*t;

	t = (t_tetris *)malloc(sizeof(t_tetris));
	t->total = r->total;
	if (!(t->pieces = (char *)malloc(sizeof(char) * (t->total + 1))))
		return (0);
	free(r->buff);
	free(r->sharp);
	free(r);
	free_list(t, input, t->total);
	return (t);
}

t_tetris				*process_file(int fd)
{
	t_reader		*r;
	t_input			*input;
	t_tetris		*t;

	if (fd < 0)
		return (0);
	if (!(r = init_reader(fd)))
		return (0);
	input = init_input();	
	input->reader = r;
	if (!(fill_input(r, input)))
		return (0);
	r->total += 1;
	if (!(fill_repeat(r, input)))
		return (0);
	if (!(t = compress_input(r, input)))
		return (0);
	return (t);
}
