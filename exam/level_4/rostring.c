/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:54:38 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 11:48:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int				ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int				ft_isend(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

int				counting(char *s)
{
	int			count;

	count = 0;
	while (ft_isspace(*s))
		s++;
	while (*s)
	{
		if (ft_isspace(*s))
		{
			count++;
			if (ft_isend(s))
				return (count);
			while (ft_isspace(*s))
				s++;
			s--;
		}
		s++;
	}
	count++;
	return (count);
}

int				charlen(char *s)
{
	int			len;

	len = 0;
	while (!(ft_isspace(*s)) && *s)
	{
		len++;
		s++;
	}
	return (len);
}

void			ft_store(char *s, char **storage)
{
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	while (ft_isspace(*s))
		s++;
	while (*s)
	{
		len = charlen(s);
		storage[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (!(ft_isspace(*s)) && *s)
		{
			storage[i][j] = *s;
			s++;
			j++;
		}
		storage[i][j] = '\0';
		i++;
		if (ft_isspace(*s))
		{
			if (ft_isend(s))
				return ;
			while (ft_isspace(*s))
				s++;
			s--;
		}
		if (*s == '\0')
			return ;
		s++;
	}
}

void			rostring(char *s)
{
	char		**storage;
	int			len;
	int			i;

	i = 1;
	len = counting(s);
	storage = (char **)malloc(sizeof(char *) * len);
	ft_store(s, storage);
	if (len == 1)
		ft_putstr(storage[0]);
	else if (len > 1)
	{
		while (i <= (len - 1))
		{
			ft_putstr(storage[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putstr(storage[0]);
	}
	else
		return ;
}

int				main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	ft_putstr("\n");
	return (0);
}
