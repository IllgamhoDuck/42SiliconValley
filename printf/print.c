/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:40:29 by hypark            #+#    #+#             */
/*   Updated: 2019/08/13 00:20:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

inline void			print_sign(t_print *p)
{
	if (p->f & NEG)
		p->output[p->print_len++] = '-';
	else if (p->f & FLP)
		p->output[p->print_len++] = '+';
	else if (p->f & FLS)
		p->output[p->print_len++] = ' ';
}

inline void			print_c(t_print *p, char c, int n)
{
	int				i;

	i = 0;
	while (i++ < n)
		p->output[p->print_len++] = c;
}

inline void			print_s(t_print *p, char *str)
{
	int				i;

	i = 0;
	while (str[i])
		p->output[p->print_len++] = str[i++];
}

/*
**void				print_info(t_print *p)
**{
**	int				i;
**
**	i = 0;
**	printf("\n");
**	printf("The flag ' ' is : %d\n", p->f & FLS);
**	printf("The flag '+' is : %d\n", p->f & FLP);
**	printf("The flag '-' is : %d\n", p->f & FLM);
**	printf("The flag '0' is : %d\n", p->f & FLZ);
**	printf("The flag '#' is : %d\n", p->f & FLH);
**	printf("p->f : %d\n", p->f);
**	printf("The width is : %d\n", p->w);
**	printf("The width asterisk is : %d\n", p->w_a);
**	printf("The precision is : %d\n", p->p);
**	printf("The precision asterisk is : %d\n", p->p_a);
**	printf("The l is : %d\n", p->f & L);
**	printf("The ll is : %d\n", p->f & LL);
**	printf("The L is : %d\n", p->f & L2);
**	printf("The h is : %d\n", p->f & H);
**	printf("The hh is : %d\n", p->f & HH);
**	printf("The conversion is : %c\n", p->cvs);
**}
*/
