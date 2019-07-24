/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:06:17 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 14:56:06 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_last(t_list *begin_list)
{
	if (!(begin_list))
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
