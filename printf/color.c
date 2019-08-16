/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 00:46:49 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 01:14:20 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void		modify_color(t_print *p)
{
	if (ft_strcmp(p->color, "eos") == 0)
		ft_putstr("\033[0m");
	else if (ft_strcmp(p->color, "red") == 0)
		ft_putstr("\033[0;31m");
	else if (ft_strcmp(p->color, "green") == 0)
		ft_putstr("\033[0;32m");
	else if (ft_strcmp(p->color, "yellow") == 0)
		ft_putstr("\033[0;33m");
	else if (ft_strcmp(p->color, "blue") == 0)
		ft_putstr("\033[0;34m");
	else if (ft_strcmp(p->color, "magenta") == 0)
		ft_putstr("\033[0;35m");
	else if (ft_strcmp(p->color, "cyan") == 0)
		ft_putstr("\033[0;36m");
	else
		print_error(ft_strjoin(p->color, " is non existing color!"));
}

const char				*color(const char *s, t_print *p)
{
	uint8_t				i;

	i = 0;
	while (*s != '}' && *s)
	{
		p->color[i] = *s;
		i++;
		s++;
	}
	if (*s == '\0')
		print_error("Color bracket should be closed correctly!");
	p->color[i] = '\0';
	modify_color(p);
	return (s);
}
