/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:56:00 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 12:56:46 by exam             ###   ########.fr       */
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

int				ft_isbraket(char c)
{
	return (c == '{' || c == '[' || c == '(' || c == '}' || c == ']' || c == ')');
}

int				ft_isbracket_left(char c)
{
	return (c == '{' || c == '[' || c == '(');
}

int				ft_isbracket_right(char c)
{
	return (c == '}' || c == ']' || c == ')');
}

int				compare_bra(char c1, char c2)
{
	if (c1 == '{' && c2 == '}')
		return (1);
	if (c1 == '[' && c2 == ']')
		return (1);
	if (c1 == '(' && c2 == ')')
		return (1);
	return (0);
}

int				brackets_recursive(char **s)
{
	char		pre_bra;
	char		aft_bra;
	int			result;

	pre_bra = 0;
	aft_bra = 0;
	result = 0;
	while (ft_isspace(**s))
		(*s)++;
	while (**s)
	{
		if (ft_isbraket(**s))
		{
			if (ft_isbracket_right(**s))
				return (1);
			if (ft_isbracket_left(**s))
				pre_bra = **s;
			(*s)++;
			result = brackets_recursive(s);
			if (result == 0)
				return (0);
			aft_bra = **s;
			if (compare_bra(pre_bra, aft_bra) == 0)
				return (0);
		}
		if (ft_isspace(**s))
		{
			if (ft_isend(*s))
				return (0);
			while (ft_isspace(**s))
				(*s)++;
			(*s)--;
		}
		if (**s == '\0')
			return (0);
		(*s)++;
	}
	return (0);
}

int				brackets(char *s)
{
	char		pre_bra;
	char		aft_bra;
	int			result;

	pre_bra = 0;
	aft_bra = 0;
	result = 0;
	while (ft_isspace(*s))
		s++;
	while (*s)
	{
		if (ft_isbraket(*s))
		{
			pre_bra = *s;
			if (ft_isbracket_right(*s))
				return (0);
			s++;
			result = brackets_recursive(&s);
			if (result == 0)
				return (0);
			aft_bra = *s;
			if (compare_bra(pre_bra, aft_bra) == 0)
				return (0);
		}
		if (ft_isspace(*s))
		{
			if (ft_isend(s))
				return (1);
			while (ft_isspace(*s))
				s++;
			s--;
		}
		if (*s == '\0')
			return (1);
		s++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	int 		result;
	int			i;

	i = 1;
	result = 0;
	if (ac >= 2)
	{
		while (i < ac)
		{
			result = brackets(av[i]);
			if (result == 0)
				ft_putstr("Error");
			if (result == 1)
				ft_putstr("OK");
			if (i != ac - 1)
				ft_putstr("\n");
			i++;
		}
	}
	ft_putstr("\n");
	return (0);
}
