/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:09:54 by exam              #+#    #+#             */
/*   Updated: 2018/06/01 21:11:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list			*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list		*result;
	t_list		*prev;
	int			done;
	
	if (!(lst) || !(cmp))
		return (0);
	result = lst;
	done = 0;
	while (done == 0)
	{
		prev = 0;
		done = 1;
		lst = result;
		while (lst->next)
		{
			if (cmp(lst->data, (lst->next)->data) == 0)
			{
				done = 0;
				if (prev == 0)
				{
					result = lst->next;
					lst->next = result->next;
					result->next = lst;
					prev = result;
				}
				else
				{
					prev->next = lst->next;
					lst->next = (lst->next)->next;
					(prev->next)->next = lst;
					prev = prev->next;
				}
			}
			else
			{
				prev = lst;
				lst = lst->next;
			}
		}
	}
	return (result);
}
