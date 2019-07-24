/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_data_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:24:10 by hypark            #+#    #+#             */
/*   Updated: 2018/06/02 21:24:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "eval_expr.h"

t_list		*ft_create_elem(char op, int nb)
{
	t_list	*elem;

	elem = 0;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!(elem))
		return (0);
	if (op)
	{
		elem->op = op;
		elem->nb = 0;
		elem->next = 0;
	}
	else
	{
		elem->op = 0;
		elem->nb = nb;
		elem->next = 0;
	}
	return (elem);
}

void		ft_free_memory(t_list *node)
{
	if (node->next)
		ft_free_memory(node->next);
	free(node);
}
