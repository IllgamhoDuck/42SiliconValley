/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 00:40:17 by hypark            #+#    #+#             */
/*   Updated: 2019/07/27 23:41:31 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*list;
	t_list			*current;

	if (!lst)
		return (NULL);
	if (!(list = f(lst)))
		return (NULL);
	current = list;
	lst = lst->next;
	while (lst)
	{
		if (!(current->next = f(lst)))
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	current->next = NULL;
	return (list);
}
