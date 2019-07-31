/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:29:23 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 10:47:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void			expand_str(char *s)
{
	while (ft_isspace(*s))
		s++;
	while (*s)
	{
		if (ft_isspace(*s))
		{
			if (ft_isend(s))
				return ;
			ft_putstr("   ");
			while (ft_isspace(*s))
				s++;
		}
		ft_putchar(*s);
		s++;
	}
}

int				main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	ft_putstr("\n");
	return (0);
}
