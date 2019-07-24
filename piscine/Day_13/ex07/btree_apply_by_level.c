/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:54:28 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 23:03:56 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int				ft_count_level(t_btree *node)
{
	int			count;

	count = 0;
	if (!(node))
		return (-1);
	while (node->parent)
	{
		count++;
		node = node->parent;
	}
	return (count);
}

int				ft_check_is_first(t_btree *node)
{
	t_btree		*origin;
	int			count;

	count = 0;
	if (!(node))
		return (-1);
	origin = node;
	while (node->parent)
	{
		count++;
		node = node->parent;
	}
	while (count)
	{
		node = node->left;
		count--;
	}
	if (origin == node)
		return (1);
	return (0);
}

void			btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int			level;
	int			is_first;

	if (!(root))
		return ;
	level = ft_count_level(root);
	is_first = ft_check_is_first(root);
	applyf(root->item, level, is_first);
	if (root->left)
		btree_apply_by_level(root->left, applyf);
	if (root->right)
		btree_apply_by_level(root->right, applyf);
}
