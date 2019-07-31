/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:35:10 by exam              #+#    #+#             */
/*   Updated: 2018/06/01 19:43:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_delimit(char c)
{
	return (c == ' ' || c == '\t');
}

void		ft_putstr(char *str)
{
	while (*str && (ft_delimit(*str) == 0))
	{
		ft_putchar(*str);
		str++;
	}
}

int			ft_check_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void		ft_upper(char *c)
{
	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
	{
		if (*c >= 'a' && *c <= 'z')
			*c -= 32;
	}
	else
	{
		while ((ft_delimit(*c) == 0) && (ft_check_alpha(*c) == 0))
			c--;
		if (ft_delimit(*c) == 0)
		{
			if (*c >= 'a' && *c <= 'z')
				*c -= 32;
		}
	}
}

void		ft_low(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void		ft_rstr(char *str)
{
	char	*word;

	word = 0;
	while (*str)
	{
		while (ft_delimit(*str) && *str)
		{
			ft_putchar(*str);
			str++;
		}
		word = str;
		while ((ft_delimit(str[1]) == 0 && str[1] != '\0') && *str)
		{
			ft_low(str);
			str++;
		}
		if ((ft_delimit(str[1]) || str[1] == '\0') && *str)
			ft_upper(str);
		if (*str)
		{
			ft_putstr(word);
			str++;
		}
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			ft_rstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
