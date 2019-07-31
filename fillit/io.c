/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:58:36 by hypark            #+#    #+#             */
/*   Updated: 2019/07/31 01:00:45 by hypark           ###   ########.fr       */
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
		r->total += r->len;
		c = r->buff[r->i++];
		if (!valid_char(c) || c <= 0)
			return (0);
		else
			return (c);
	}
}

t_input				*process_file(int fd)
{
	t_reader		*r;
	t_input			*input;

	if (!(r = init_reader(fd)))
		return (0);
	input = init_input();	
	input->reader = r;
	if (!(fill_input(r, input)))
		return (0);
	if (!(fill_repeat(r, input)))
		return (0);
	return (input);
}
