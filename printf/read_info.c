/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:51:24 by hypark            #+#    #+#             */
/*   Updated: 2019/08/11 02:01:02 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*read_flag(const char *s, t_print *p_info)
{
	while (*s == ' ' || *s == '+' || *s == '-' || *s == '0' || *s == '#')
	{
		p_info->flag[p_info->flag_total] = *(s++);
		p_info->flag_total++;
	}
	return (s);
}

static const char	*read_width(const char *s, t_print *p_info)
{
	if (*s == '*')
	{
		p_info->w_a = 1;
		s++;
		return (s);
	}
	while (*s <= '9' && *s >= '0')
		p_info->width = p_info->width * 10 + (*(s++) - '0');
	return (s);
}

static const char	*read_precision(const char *s, t_print *p_info)
{
	if (*s == '.' && (p_info->precision = (*s == '.' ? 0 : 0)) == 0)
	{
		if (*(++s) == '*')
		{
			p_info->p_a = 1;
			s++;
			return (s);
		}
		s--;
		while (*(++s) <= '9' && *s >= '0')
			p_info->precision = p_info->precision * 10 + (*s - '0');
	}
	return (s);
}

/*
** %[flag][width][.precision][length][format]
** the *(s++) trick is simply increasing the s address when it is right
** for example (*s == 'l' && *(s++) == 'l')
** if *s is not 'l' then it will just pass with same address s
** but if *s is 'l' then it will go to the right and s will be
** increased by the syntax *(s++) = 'l' after checking it valid
*/

static const char	*read_length(const char *s, t_print *p_info)
{
	if (*s == 'h' && *(s + 1) == 'h' && *(s++) == 'h' && *(s++) == 'h')
		p_info->length = "hh";
	else if (*s == 'l' && *(s + 1) == 'l' && *(s++) == 'l' && *(s++) == 'l')
		p_info->length = "ll";
	else if (*s == 'h' && *(s++) == 'h')
		p_info->length = "h";
	else if (*s == 'l' && *(s++) == 'l')
		p_info->length = "l";
	else if (*s == 'L' && *(s++) == 'L')
		p_info->length = "L";
	return (s);
}

const char			*read_information(const char *s, t_print *p_info)
{
	if (*s == '%')
		return (s);
	s = read_flag(s, p_info);
	s = read_width(s, p_info);
	s = read_precision(s, p_info);
	s = read_length(s, p_info);
	p_info->format = *s;
	return (s);
}
