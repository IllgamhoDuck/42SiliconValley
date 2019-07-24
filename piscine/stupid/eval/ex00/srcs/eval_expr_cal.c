/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_cal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 19:27:55 by hypark            #+#    #+#             */
/*   Updated: 2018/06/02 21:15:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "eval_expr.h"

int			ft_operator(char op, int first, int second)
{
	if (!op)
		return (0);
	if (op == '+')
		return (first + second);
	else if (op == '-')
		return (first - second);
	else if (op == '*')
		return (first * second);
	else if (op == '/')
		return (first / second);
	else if (op == '%')
		return (first % second);
	else
		return (0);
}

void		ft_cal_div_mod(t_list *node)
{
	t_list	*next;
	char	op;

	while (node->next)
	{
		op = (node->next)->op;
		if ((op == '/' || op == '%') && (node->next)->next)
		{
			next = node->next;
			node->nb = ft_operator(op, node->nb, (next->next)->nb);
			if ((next->next)->next)
				node->next = (next->next)->next;
			else
				node->next = 0;
			free(next->next);
			free(next);
		}
		else
			node = node->next;
	}
}

void		ft_cal_mul(t_list *node)
{
	t_list	*next;
	char	op;

	while (node->next)
	{
		op = (node->next)->op;
		if (op == '*' && (node->next)->next)
		{
			next = node->next;
			node->nb = ft_operator(op, node->nb, (next->next)->nb);
			if ((next->next)->next)
				node->next = (next->next)->next;
			else
				node->next = 0;
			free(next->next);
			free(next);
		}
		else
			node = node->next;
	}
}

void		ft_cal_add_minus(t_list *node)
{
	t_list	*next;
	char	op;

	while (node->next)
	{
		op = (node->next)->op;
		if ((op == '+' || op == '-') && (node->next)->next)
		{
			next = node->next;
			node->nb = ft_operator(op, node->nb, (next->next)->nb);
			if ((next->next)->next)
				node->next = (next->next)->next;
			else
				node->next = 0;
			free(next->next);
			free(next);
		}
		else
			node = node->next;
	}
}

int			ft_cal_eval(t_list *node)
{
	ft_cal_div_mod(node);
	ft_cal_mul(node);
	ft_cal_add_minus(node);
	return (node->nb);
}
