/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:50:38 by hypark            #+#    #+#             */
/*   Updated: 2019/07/30 03:21:38 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_finfo		*init(const int fd)
{
	t_finfo			*f;

	if (!(f = (t_finfo *)malloc(sizeof(t_finfo))))
		return (0);
	if (!(f->storage = (char *)malloc(sizeof(char) * 1)))
		return (0);
	f->storage[0] = '\0';
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

static t_finfo		*find_f(t_finfo *b_list, const int fd)
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

static int			fill_line(t_finfo *f, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while (f->storage[i] != '\n' && f->storage[i] != '\0')
		i++;
	*line = ft_strsub(f->storage, 0, i);
	if (f->storage[i] == '\n')
	{
		tmp = ft_strdup(&(f->storage[i + 1]));
		free(f->storage);
		f->storage = tmp;
	}
	else if (f->storage[i] == '\0')
	{
		free(f->storage);
		if (!(f->storage = (char *)malloc(sizeof(char) * 1)))
			return (0);
		f->storage[0] = '\0';
	}
	return (1);
}

static int			print_result(t_finfo *f, int result, char **line)
{
	if (result < 0)
		return (-1);
	if (result == 0 && f->storage[0] == '\0')
		return (0);
	return (fill_line(f, line));
}

int					get_next_line(const int fd, char **line)
{
	t_finfo			*f;
	static t_finfo	*b_list;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				result;

	if (!b_list)
		if (!(b_list = init(fd)))
			return (-1);
	if ((!line) || (fd < 0) || !(f = find_f(b_list, fd)))
		return (-1);
	while ((result = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[result] = '\0';
		tmp = ft_strjoin(f->storage, buf);
		free(f->storage);
		f->storage = tmp;
		if (ft_strchr(f->storage, '\n'))
			break ;
	}
	return (print_result(f, result, line));
}
