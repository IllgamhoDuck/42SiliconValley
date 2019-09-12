/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:50:38 by hypark            #+#    #+#             */
/*   Updated: 2019/09/12 01:16:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	return (i);
}

char	*ft_str_ljoin(char **s1, char **s2)
{
	char	*without_leaks;

	without_leaks = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!*s1 && *s2)
	{
		without_leaks = *s2;
		*s2 = NULL;
	}
	else if (!*s2 && *s1)
	{
		without_leaks = *s1;
		*s1 = NULL;
	}
	else
	{
		without_leaks = ft_strjoin(*s1, *s2);
		ft_strdel(s1);
		ft_strdel(s2);
	}
	return (without_leaks);
}

void	get_tail(const int fd, char *buf, t_line **head)
{
	t_line	*tail;
	t_line	*ptr;
	char	*tmp;
	int		start;

	tail = NULL;
	ptr = *head;
	start = len(buf, '\n') + 1;
	while (ptr && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr == NULL || *head == NULL)
	{
		tail = (t_line*)malloc(sizeof(t_line) * 1);
		tail->fd = fd;
		tail->next = *head ? *head : NULL;
		if (!(tail->str = ft_strsub(buf, start, ft_strlen(buf) - start)))
			ft_memdel((void**)tail);
		*head = tail;
	}
	if (ptr)
	{
		tmp = ptr->str;
		ptr->str = ft_strsub(buf, start, ft_strlen(buf) - start);
		tmp ? ft_strdel(&tmp) : 0;
	}
}

int		reading(int fd, char **line, t_line **head)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
		{
			tmp = ft_strsub(buf, 0, len(buf, '\n'));
			*line = ft_str_ljoin(line, &tmp);
			get_tail(fd, buf, head);
			return (1);
		}
		else
		{
			tmp = ft_strdup(buf);
			*line = ft_str_ljoin(line, &tmp);
		}
	}
	if (ret < 0)
		return (-1);
	return (*line ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_line	*head = NULL;
	t_line			*ptr;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (head)
	{
		ptr = head;
		while (ptr && ptr->fd != fd)
			ptr = ptr->next;
		if (ptr && ptr->str && ft_strchr(ptr->str, '\n') != NULL)
		{
			*line = ft_strsub(ptr->str, 0, len(ptr->str, '\n'));
			get_tail(fd, ptr->str, &head);
			return (1);
		}
		if (ptr && ptr->str && !ft_strchr(ptr->str, '\n')
			&& !ft_strequ(ptr->str, ""))
		{
			*line = ptr->str;
			ptr->str = NULL;
		}
	}
	return (reading(fd, line, &head));
}
