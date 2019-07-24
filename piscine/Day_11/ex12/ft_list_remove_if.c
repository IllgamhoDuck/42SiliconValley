/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:50 by hypark            #+#    #+#             */
/*   Updated: 2018/05/30 12:24:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_not_match(t_list **prev, t_list **node)
{
	*prev = *node;
	*node = (*node)->next;
}

void	ft_match_prev(t_list **begin_list, t_list **del, t_list **node)
{
	*begin_list = (*node)->next;
	*del = *node;
	*node = (*node)->next;
	free(*del);
}

void	ft_match_no_prev(t_list **prev, t_list **node, t_list **del)
{
	(*prev)->next = (*node)->next;
	*del = *node;
	*node = (*node)->next;
	free(*del);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev;
	t_list	*node;
	t_list	*del;

	if (!(begin_list) || !(*begin_list))
		return ;
	prev = 0;
	del = 0;
	node = *begin_list;
	while (node)
	{
		if (cmp(node->data, data_ref) == 0)
		{
			if (prev == 0)
				ft_match_prev(begin_list, &del, &node);
			else
				ft_match_no_prev(&prev, &node, &del);
		}
		else
			ft_not_match(&prev, &node);
	}
}
