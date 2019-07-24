/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:06:05 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 17:01:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_push_params(int ac, char **av)
{
	t_list		*result;
	t_list		*node;

	if (ac <= 0)
		return (0);
	result = ft_create_elem(av[--ac]);
	if (!(result))
		return (0);
	node = result;
	while (ac > 0)
	{
		node->next = ft_create_elem(av[--ac]);
		if (!(node->next))
			return (result);
		node = node->next;
	}
	return (result);
}
