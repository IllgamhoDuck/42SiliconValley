/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:59:29 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 14:01:18 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_list_size(t_list *begin_list)
{
	int			list_len;

	list_len = 0;
	while (begin_list)
	{
		list_len++;
		begin_list = begin_list->next;
	}
	return (list_len);
}
