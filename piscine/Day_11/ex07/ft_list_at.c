/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:20:12 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 19:44:50 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!(begin_list))
		return (0);
	while (i < nbr)
	{
		if (!(begin_list->next))
			return (0);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
