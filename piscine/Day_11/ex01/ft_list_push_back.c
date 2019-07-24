/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:44:18 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 13:44:25 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;
	t_list	*node;

	tmp = ft_create_elem(data);
	if (!(begin_list))
		return ;
	if (!(tmp))
		return ;
	if (!(*begin_list))
		*begin_list = tmp;
	else
	{
		node = *begin_list;
		while (node->next)
			node = node->next;
		node->next = tmp;
	}
}
