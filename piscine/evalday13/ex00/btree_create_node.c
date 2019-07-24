/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:25:28 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 22:57:47 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree			*btree_create_node(void *item)
{
	t_btree		*init;

	init = (t_btree *)malloc(sizeof(t_btree));
	if (!(init))
		return (0);
	init->right = 0;
	init->left = 0;
	init->item = item;
	return (init);
}
