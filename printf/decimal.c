/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:39:50 by hypark            #+#    #+#             */
/*   Updated: 2019/08/15 22:40:53 by hypark           ###   ########.fr       */
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

/*
** the round is treated differently as the precision number
** I'm not sure this is right or not but i supposed
** if precision goes bigger than 6 than we need to be little more general
** so we can say if we need to print out more than 6 precision
** simply say round at 4999.
** Im not sure this is right. original was just n < 5 and if not than round
*/

inline static int	decimal_round(int p_n, t_dec *current, uintmax_t n)
{
	if (n < 5000 && p_n <= 6)
		return (0);
	if (n < 4999 && p_n > 6)
		return (0);
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
			return (0);
		}
	}
	return (1);
}

inline static int	store_decimal(int p_n, t_dec **b, long double f, int len)
{
	uintmax_t		integer;
	t_dec			*current;
	t_dec			*prev;
	int				i;

	i = 0;
	current = *b;
	prev = current;
	while (i++ < len)
	{
		f *= 10;
		integer = (uintmax_t)f;
		f -= integer;
		current->next = init_decimal(integer);
		current = current->next;
		current->prev = prev;
		prev = current;
	}
	prev = *b;
	*b = prev->next;
	(*b)->prev = NULL;
	free(prev);
	f *= 10000;
	integer = (uintmax_t)f;
	return (decimal_round(p_n, current, integer));
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
	if (store_decimal(p->p, &start, f, len))
		p->output[p->print_len - 2] += 1;
	i = 0;
	while (i++ < len)
	{
		p->output[p->print_len++] = start->n + '0';
		start = start->next;
	}
}
