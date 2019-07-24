/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:10:33 by hypark            #+#    #+#             */
/*   Updated: 2018/05/29 19:09:46 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void			ft_list_clear(t_list **begin_list)
{
	if (!(begin_list))
		return ;
	if (!(*begin_list))
		return ;
	ft_list_clear(&((*begin_list)->next));
	free(*begin_list);
	*begin_list = NULL;
}
