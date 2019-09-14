/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:38:43 by hypark            #+#    #+#             */
/*   Updated: 2019/09/14 01:06:08 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void				fill_room_info(t_b_tree *b_tree, int16_t x, int16_t y)
{
	b_tree->x = x;
	b_tree->y = y;
}

t_b_tree			*find_room(t_b_tree *b_tree, char *room)
{
	while (1)
	{
		if (ft_strcmp(b_tree->room_name, room_name) == 0)
			return (b_tree);
		if (ft_strcmp(b_tree->room_name, room_name) < 0)
		{
			if (b_tree->right == NULL)
			{
				b_tree->right = init_b_tree(room_name);
				b_tree = b_tree->right;
				return (b_tree);
			}
			b_tree = b_tree->right;
		}
		else
		{
			if (b_tree->left == NULL)
			{
				b_tree->left = init_b_tree(room_name);
				b_tree = b_tree->left;
				return (b_tree);
			}
			b_tree = b_tree->left;
		}
	}
}
