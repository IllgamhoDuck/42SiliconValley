/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:50:38 by hypark            #+#    #+#             */
/*   Updated: 2019/07/30 23:23:43 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** what i need to fix here is to make able to handle the text that 
** ends without \n. In this code the get_text_char function gives
** one character by one and it doesn't return \0. So when the case
** of the text that ends without \n, fill_text function cannot
** catch this case because there is no if statement that could
** recognized this part.
** 
** I'm thinking about the solution like but not sure.
** f->length == f->index && f->length < BUFF_SIZE
** 
** I tried to apply this but failed.
*/

char				get_next_char(t_finfo *f)
{
	if (f->index < f->length)
		return (f->buf[f->index++]);
	f->length = read(f->fd, f->buf, BUFF_SIZE);
	if (f->length < 0)
		return (0);
	f->index = 0;
	if (f->length = 0)
		return (0);
	else
		return (f->buf[f->index++]);
}

t_finfo				*init(const int fd)
{
	t_finfo			*f;
	int				i;

	i = 0;
	if (!(f = (t_finfo *)malloc(sizeof(t_finfo))))
		return (0);
	if (!(f->buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while (i < BUFF_SIZE)
		f->buf[i++] = '\0';
	f->index = 0;
	f->length = 0;
	f->fd = fd;
	f->right = NULL;
	f->left = NULL;
	return (f);
}

/*
** Searching the binary tree and search for the appropriate file
** information of fd.
** if there is file information return it or if there isn't
** create the file information and return it.
*/

t_finfo				*find_f(t_finfo *b_list, const int fd)
{
	while (1)
	{
		if (b_list->fd == fd)
			return (b_list);
		if (b_list->fd < fd)
		{
			if (b_list->right == NULL)
			{
				b_list->right = init(fd);
				b_list = b_list->right;
				return (b_list);
			}
			b_list = b_list->right;
		}
		else
		{
			if (b_list->left == NULL)
			{
				b_list->left = init(fd);
				b_list = b_list->left;
				return (b_list);
			}
			b_list = b_list->left;
		}
	}
}

int					fill_text(t_finfo *f, char **line)
{
	char			word;
	char			*copy;
	char			*tmp;

	*line = (char *)malloc(sizeof(char) * 1);
	line[0][0] = '\0';
	while (1)
	{
		word = get_next_char(f);
		if (f->length < 0)
			return (-1);
		if (word == '\n')
			return (1);
		if (f->length == f->index && f->length < BUFF_SIZE)
			return (1);
		if (f->length == 0 || word == '\0')
			return (0);
		copy = (char *)malloc(sizeof(char) * 2);
		copy[0] = word;
		copy[1] = '\0';
		tmp = copy;
		copy = ft_strjoin(*line, copy);
		free(tmp);
		tmp = *line;
		line[0] = copy;
		free(tmp);
	}
}

int					get_next_line(const int fd, char **line)
{
	t_finfo			*f;
	static t_finfo	*b_list;
	unsigned int	i;
	int				result;

	f = NULL;
	i = 0;
	if (!b_list)
		if (!(b_list = init(fd)))
			return (-1);
	if ((!line) || (fd < 0) || !(f = find_f(b_list, fd)))
		return (-1);
	result = fill_text(f, line);
	return (result);
}
