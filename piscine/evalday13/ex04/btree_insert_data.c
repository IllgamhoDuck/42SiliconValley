/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:56:39 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 23:01:43 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void			ft_helper_right(t_btree **root, void *item)
{
	t_btree		*create;

	create = btree_create_node(item);
	(*root)->right = create;
}

void			ft_helper_left(t_btree **root, void *item)
{
	t_btree		*create;

	create = btree_create_node(item);
	(*root)->left = create;
}

void			btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!(root) || !(cmpf))
		return ;
	if (!(*root))
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if ((*root)->right)
			btree_insert_data(&((*root)->right), item, cmpf);
		else
			ft_helper_right(root, item);
	}
	else
	{
		if ((*root)->left)
			btree_insert_data(&((*root)->left), item, cmpf);
		else
			ft_helper_left(root, item);
	}
}
