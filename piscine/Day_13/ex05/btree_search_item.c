/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:54:25 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 23:00:44 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void			*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void		*result;

	result = 0;
	if (!(root) || !(cmpf))
		return (0);
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (result)
		return (result);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	if (result)
		return (result);
}
