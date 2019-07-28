/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:50:38 by hypark            #+#    #+#             */
/*   Updated: 2019/07/28 07:53:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				get_next_char(t_finfo *f)
{
	if (f->index < f->length)
		return (f->buf[f->index++]);
	f->length = read(f->fd, f->buf, BUFF_SIZE);
	f->index = 0;
	if (f->length <= 0)
		return (0);
	else
		return (f->buf[r->index++]);
}

void				init(t_finfo *f, const int fd)
{
	f->buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	f->index = 0;
	f->length = 0;
	f->fd = fd;
	f->next = NULL;
}

one function if for searching fd and return the address of f

	if fd isn't on the linked list than init
	{
	init(f, fd);
	and connect it at the end of the linked list
	}
	if fd is on the linked list than put it out

	and return address of f

one function is to find the appropriate index where to save the line

the linux system will remember how far i parsed the text
so what i need to store is how far i stored the buffer.
int					get_next_line(const int fd, char **line)
{
	t_finfo			*f;
	static t_finfo	*linked list;
	unsigned int	i;
	unsigned int	j;
	char			word;

	i = 0;
	j = 0;

	while (1)
	{
		word = get_next_char(f);
		if (word == 0 || word == '\0')
			return (0);
		if (word == '\n')
			return (1);
		line[i][j++] = word;
	}
}
