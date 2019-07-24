/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:09:16 by hypark            #+#    #+#             */
/*   Updated: 2018/06/01 23:00:20 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct			s_btree
{
	struct s_btree		*right;
	struct s_btree		*left;
	void				*item;
}						t_btree;

void					*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *));

#endif
