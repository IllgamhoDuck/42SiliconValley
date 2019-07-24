/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:48:15 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 13:56:17 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*tmp;

	tmp = ft_create_elem(data);
	if (!(begin_list))
		return ;
	if (!(tmp))
		return ;
	if (!(*begin_list))
		*begin_list = tmp;
	else
	{
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
}
