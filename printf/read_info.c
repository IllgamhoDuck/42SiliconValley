/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:51:24 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 01:58:49 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline const char	*read_flag(const char *s, t_print *p)
{
	while (*s == ' ' || *s == '+' || *s == '-' || *s == '0' || *s == '#')
	{
		if (*s == ' ')
			p->f |= FLS;
		else if (*s == '+')
			p->f |= FLP;
		else if (*s == '-')
			p->f |= FLM;
		else if (*s == '0')
			p->f |= FLZ;
		else if (*s == '#')
			p->f |= FLH;
		s++;
	}
	return (s);
}

static inline const char	*read_width(const char *s, t_print *p)
{
	if (*s == '*')
	{
		p->w_a = 1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
		p->w = p->w * 10 + (*(s++) - '0');
	if (*s == '*')
	{
		p->w_a = 1;
		s++;
	}
	return (s);
}

static inline const char	*read_precision(const char *s, t_print *p)
{
	if (*s == '.' && (p->p = 0) == 0)
	{
		if (*(++s) == '*')
		{
			p->p_a = 1;
			s++;
		}
		s--;
		while (*(++s) <= '9' && *s >= '0')
			p->p = p->p * 10 + (*s - '0');
		if (*s == '*')
		{
			p->p_a = 1;
			s++;
		}
	}
	return (s);
}

/*
** %[flag][width][.precision][length][cvs]
** the && s++ trick is simply increasing the s address when it is right
*/

static inline const char	*read_length(const char *s, t_print *p)
{
	if (*s == 'h' && *(s + 1) == 'h' && s++ && s++)
		p->f |= HH;
	else if (*s == 'l' && *(s + 1) == 'l' && s++ && s++)
		p->f |= LL;
	else if (*s == 'h' && s++)
		p->f |= H;
	else if (*s == 'l' && s++)
		p->f |= L;
	else if (*s == 'L' && s++)
		p->f |= L2;
	return (s);
}

const char					*read_information(const char *s, t_print *p)
{
	s = read_flag(s, p);
	s = read_width(s, p);
	s = read_precision(s, p);
	s = read_length(s, p);
	p->cvs = *s;
	return (s);
}
