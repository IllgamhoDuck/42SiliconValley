/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:39:50 by hypark            #+#    #+#             */
/*   Updated: 2019/08/14 04:44:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static t_dec	*init_decimal(uint8_t n)
{
	t_dec			*prec;

	if (!(prec = (t_dec *)malloc(sizeof(t_dec))))
		print_error("Memory allocation failed at t_dec!");
	prec->n = n;
	prec->next = NULL;
	prec->prev = NULL;
	return (prec);
}

inline static void	decimal_round(t_dec *current, uint8_t n)
{
	if (n < 5)
		return ;
	while (current)
	{
		if (current->n + 1 > 9)
		{
			current->n = (current->n + 1) % 10;
			current = current->prev;
		}
		else
		{
			current->n = current->n + 1;
			return ;
		}
	}
}

inline static void	store_decimal(t_dec **begin, long double f, int len)
{
	uint8_t			integer;
	t_dec			*current;
	t_dec			*prev;
	int				i;

	i = 0;
	current = *begin;
	prev = current;
	while (i++ < len)
	{
		f *= 10;
		integer = (uint8_t)f;
		f -= integer;
		current->next = init_decimal(integer);
		current = current->next;
		current->prev = prev;
		prev = current;
	}
	prev = *begin;
	*begin = prev->next;
	free(prev);
	f *= 10;
	integer = (uint8_t)f;
	decimal_round(current, integer);
}

/*
**static void			print_list(t_dec *list, int len)
**{
**	int				i;
**
**	i = 0;
**	while (i++ < len)
**	{
**		printf("%d", list->n);
**		list = list->next;
**	}
**}
*/

inline void			print_decimal(t_print *p, long double f, int len)
{
	t_dec			*start;
	int				i;

	start = init_decimal(0);
	store_decimal(&start, f, len);
	i = 0;
	while (i++ < len)
	{
		p->output[p->print_len++] = start->n + '0';
		start = start->next;
	}
}
