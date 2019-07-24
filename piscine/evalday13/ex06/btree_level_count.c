/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:44:46 by hypark            #+#    #+#             */
/*   Updated: 2018/05/31 22:16:33 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int				btree_level_count(t_btree *root)
{
	int			result_left;
	int			result_right;

	result_left = 0;
	result_right = 0;
	if (!(root))
		return (0);
	if (root->left)
		result_left = btree_level_count(root->left);
	if (root->right)
		result_right = btree_level_count(root->right);
	if (result_left > result_right)
		return (result_left + 1);
	return (result_right + 1);
}
