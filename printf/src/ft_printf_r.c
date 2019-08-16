/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:55:04 by hypark            #+#    #+#             */
/*   Updated: 2019/08/16 00:42:51 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				printf_0_11(t_print *p, uint8_t i)
{
	if (i == 0)
		print_str_unlimit(p, "[NULL]", 6);
	else if (i == 1)
		print_str_unlimit(p, "[SOH]", 5);
	else if (i == 2)
		print_str_unlimit(p, "[STX]", 5);
	else if (i == 3)
		print_str_unlimit(p, "[ETX]", 5);
	else if (i == 4)
		print_str_unlimit(p, "[EOT]", 5);
	else if (i == 5)
		print_str_unlimit(p, "[ENQ]", 5);
	else if (i == 6)
		print_str_unlimit(p, "[ACK]", 5);
	else if (i == 7)
		print_str_unlimit(p, "[BEL]", 5);
	else if (i == 8)
		print_str_unlimit(p, "[BS]", 4);
	else if (i == 9)
		print_str_unlimit(p, "[HT]", 4);
	else if (i == 10)
		print_str_unlimit(p, "[LF]", 4);
	else if (i == 11)
		print_str_unlimit(p, "[VT]", 4);
}

static void				printf_12_23(t_print *p, uint8_t i)
{
	if (i == 12)
		print_str_unlimit(p, "[FF]", 4);
	else if (i == 13)
		print_str_unlimit(p, "[CR]", 4);
	else if (i == 14)
		print_str_unlimit(p, "[SO]", 4);
	else if (i == 15)
		print_str_unlimit(p, "[SI]", 4);
	else if (i == 16)
		print_str_unlimit(p, "[DLE]", 5);
	else if (i == 17)
		print_str_unlimit(p, "[DC1]", 5);
	else if (i == 18)
		print_str_unlimit(p, "[DC2]", 5);
	else if (i == 19)
		print_str_unlimit(p, "[DC3]", 5);
	else if (i == 20)
		print_str_unlimit(p, "[DC4]", 5);
	else if (i == 21)
		print_str_unlimit(p, "[NAK]", 5);
	else if (i == 22)
		print_str_unlimit(p, "[SYN]", 5);
	else if (i == 23)
		print_str_unlimit(p, "[ETB]", 5);
}

static void				printf_24_31(t_print *p, uint8_t i)
{
	if (i == 24)
		print_str_unlimit(p, "[CAN]", 5);
	else if (i == 25)
		print_str_unlimit(p, "[EM]", 4);
	else if (i == 26)
		print_str_unlimit(p, "[SUB]", 5);
	else if (i == 27)
		print_str_unlimit(p, "[ESC]", 5);
	else if (i == 28)
		print_str_unlimit(p, "[FS]", 4);
	else if (i == 29)
		print_str_unlimit(p, "[GS]", 4);
	else if (i == 30)
		print_str_unlimit(p, "[RS]", 4);
	else if (i == 31)
		print_str_unlimit(p, "[US]", 4);
}

static void				printf_0_31(t_print *p, uint8_t i)
{
	if (i >= 0 && i <= 11)
		printf_0_11(p, i);
	else if (i >= 12 && i <= 23)
		printf_12_23(p, i);
	else if (i >= 24 && i <= 31)
		printf_24_31(p, i);
}

void					ft_printf_r(t_print *p)
{
	int					i;
	char				*s;

	i = -1;
	if (p->p == -1)
	{
		s = va_arg(p->ap, char *);
		if (s == NULL)
		{
			print_str_unlimit(p, "(null)", 6);
			return ;
		}
		while (s[++i])
		{
			if (s[i] >= 0 && s[i] <= 31)
				printf_0_31(p, s[i]);
			else
				print_c_unlimit(p, s[i], 1);
		}
		p->total_len += p->print_len;
	}
	else
		while (++i <= 31)
			printf_0_31(p, i);
}
